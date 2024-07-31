//
//  IDeviceSetting.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSUserInfo.h"
#import "AWDeviceData.h"

/**
 * 血糖仪产品查询指令
 */
typedef NS_ENUM(NSUInteger,BGQueryCmd){
    BGQueryCmdSN=0x7755,
    BGQueryCmdUnit=0xAA55,
    BGQueryCmdVersion=0x6655,
    BGQueryCmdHistoricalData=0xDD55,
};

/**
 * 耳机类产品控制指令
 */
typedef NS_ENUM(NSUInteger,AWControlCmd) {
    // AWCS command
    AWControlCmdGetVersion = 0x0001,
    AWControlCmdGetConnStatus = 0x0004,
    AWControlCmdGetBattery = 0x0005,
    AWControlCmdGetChannelSettings = 0x0007,
    // HA command
    AWControlCmdSetlevel = 0x8201,
    AWControlCmdGetlevel = 0x0201,

    AWControlCmdSetlevelUp = 0x8202,
    AWControlCmdSetlevelDown = 0x8203,
    AWControlCmdSetlevelSyncSwitch = 0x8204,
    AWControlCmdGetlevelSyncSwitch = 0x0204,

    AWControlCmdSetMode=0x8205,
    AWControlCmdGetMode=0x0205,
    
    AWControlCmdSetModeUp=0x8206,
    AWControlCmdSetModeDown=0x8207,
    
    AWControlCmdSetVolume = 0x821D,
    AWControlCmdGetVolume = 0x021D,
    AWControlCmdSetVolumeSyncSwitch = 0x8220,
    AWControlCmdGetVolumeSyncSwitch = 0x0220,
    
    // 0.9.24
    AWControlCmdSetEarDetectionSwitch = 0x8221,
    AWControlCmdGetEarDetectionSwitch = 0x0221,
    
    //New Changed
    AWControlCmdSetPuretoneGenerator= 0x820F,
    AWControlCmdGetPuretoneGenerator= 0x020F,
    
    AWControlCmdSetUserEqSwitch= 0x820C,
    AWControlCmdGetUserEqSwitch= 0x020C,
    
    AWControlCmdSetUserEqGain= 0x820D,
    AWControlCmdGetUserEqGain= 0x020D,
    
    AWControlCmdGetSpeakerReference= 0x020E,

};

@interface IBDeviceSetting : NSObject

@property(nonatomic,assign)NSUInteger cmd;               //CMD
@property(nonatomic,strong)NSString *broadcastId;        //设备广播ID
@property(nonatomic,strong)NSString *msgKey;             //消息Key
@property(nonatomic,strong)NSString *deviceModel;        //设备型号，用于区分指令下发所定义的CMD
@property(nonatomic,strong)NSData *cmdBytes;             //当前指令数据包
@property(nonatomic,assign)NSUInteger packetSeq;         //数据包序列号

-(NSData *)encodeCmdBytes;

/**
 * 手环6S设备型号判断
 */
-(BOOL)isCavoDevice;

/**
 * 手环8设备型号判断
 */
-(BOOL)isNewBand8;
@end


#pragma mark - WSUserInfoSetting

/**
 * 秤用户信息设置
 */
@interface WSUserInfoSetting : IBDeviceSetting
@property(nonnull,nonatomic,strong)LSUserInfo *userInfo;    //用户信息
@end

#pragma mark - WSUnitSetting

/**
 * 秤单位设置
 */
@interface WSUnitSetting : IBDeviceSetting

/**
 * 单位
 * 0x00=Kg
 * 0x01=Lb
 * 0x02=St
 * 0x03=斤
 * 0x04=公斤
 */
@property(nonatomic,assign)NSUInteger unit;
@end

#pragma mark - WSTargetSetting

/**
 * 秤目标设置
 */
@interface WSTargetSetting : IBDeviceSetting

/**
 * 用户编号
 * 0=客人/未识别用户
 * 1~4=已识别用户
 * 255=无效用户
 */
@property(nonatomic,assign)NSUInteger userNumber;

/**
 * 目标类型，默认为1
 * 0x01 = 体重目标
 */
@property(nonatomic,assign)NSUInteger targetType;

/**
 * 目标体重值(单位为 0.010kg)
 */
@property(nonatomic,assign)NSUInteger targetValue;
@end



#pragma mark - WSWifiSetting

/**
 * 秤Wifi配置
 */
@interface WSWifiSetting : IBDeviceSetting
@property(nonnull,nonatomic,strong)NSString *ssid;        //Wifi SSID
@property(nonnull,nonatomic,strong)NSString *password;    //Wifi Password
@end

#pragma mark - WSResetSetting

/**
 * 秤重置或清除数据设置
 */
@interface WSResetSetting : IBDeviceSetting

/**
 * 用户编号
 * 0=客人/未识别用户
 * 1~4=已识别用户
 * 255=无效用户
 */
@property(nonatomic,assign)NSUInteger userNumber;

/**
 * 数据重置类型
 */
@property(nonatomic,assign)WSResetType type;


/// 是否恢复原厂设置
@property(nonatomic,assign)BOOL reseting;

@end


#pragma mark - WSHeartRateSetting

/**
 * 秤心率检测设置
 */
@interface WSHeartRateSetting : IBDeviceSetting
/**
 * 心率检测开关
 * YES = 测量体重过程中，测量心率
 * NO  = 测量体重过程中，不测量心率
 */
@property(nonatomic,assign)BOOL enable;
@end


#pragma mark - BGQuerySetting

/**
 * 血糖仪数据查询设置
 */
@interface BGQuerySetting : IBDeviceSetting

/**
 * 查询类型
 */
@property(nonatomic,assign) BGQueryCmd queryCmd;

/**
 * 对象实例初始化
 */
-(instancetype)initWithQueryCmd:(BGQueryCmd)cmd;
@end


#pragma mark - BGRemoveSetting

/**
 * 血糖仪数据删除设置
 */
@interface BGRemoveSetting : IBDeviceSetting

/**
 * 是否清空所有数据
 */
@property(nonatomic,assign)  BOOL removeAll;
@end


#pragma mark - BGTimeSetting

/**
 * 血糖仪时间设置
 */
@interface BGTimeSetting : IBDeviceSetting

/**
 * 设置时间,单位秒
 */
@property(nonatomic,assign) long utc;
@end

#pragma mark - AWControlSetting

/**
 *  耳机功能控制或数据查询指令
 */
@interface AWControlSetting : IBDeviceSetting

/**
 * 设置指令时，需填充该内容
 */
@property(nonatomic,strong)AWDeviceData * _Nullable obj;
@end


#pragma mark - LSPulseWaveSetting

@interface LSPulseWaveSetting : IBDeviceSetting

/**
 * 脉搏波数据同步开关
 */
@property(nonatomic,assign)  BOOL enable;
@end
