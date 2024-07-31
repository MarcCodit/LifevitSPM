//
//  AWCSData.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2022/9/9.
//  Copyright © 2022 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * EQ频段类型
 */
typedef NS_ENUM(NSUInteger,AWEqFrequencyType){
    AWEqFrequencyType0Hz  = 0x00,
    AWEqFrequencyType500Hz,
    AWEqFrequencyType1000Hz,
    AWEqFrequencyType1500Hz,
    AWEqFrequencyType2000Hz,
    AWEqFrequencyType2500Hz,
    AWEqFrequencyType3000Hz,
    AWEqFrequencyType3500Hz,
    AWEqFrequencyType4000Hz,
    AWEqFrequencyType4500Hz,
    AWEqFrequencyType5000Hz,
    AWEqFrequencyType5500Hz,
    AWEqFrequencyType6000Hz,
    AWEqFrequencyType6500Hz,
    AWEqFrequencyType7000Hz,
    AWEqFrequencyType7500Hz,
};

/**
 * EQ频段信息
 */
@interface AWUserEqItem : NSObject

/**
 * 频段类型
 */
@property(nonatomic,assign)AWEqFrequencyType type;

/**
 * EQ value range: -32dB(0xE0)~ 32dB(0x20)
 */
@property(nonatomic,assign)int value;
@end

/**
 * 侧听项信息
 */
@interface AWPuretoneItem : NSObject

@property(nonatomic,assign)BOOL enable;
@property(nonatomic,assign)int frequency;
@property(nonatomic,assign)int dBFS;
@end

/**
 *  User Gain
 */
@interface AWUserGainItem : NSObject

/**
 * EQ overall range: -32dB(0xE0)~ 32dB(0x20)
 */
@property(nonatomic,assign)int overall;

/**
 * EQ value range: -32dB(0xE0)~ 32dB(0x20)
 */
@property(nonatomic,strong)NSArray <AWUserEqItem *>* values;
@end

/**
 * Hearing Test Speaker
 */
@interface AWHearingTestSpeaker : NSObject
@property(nonatomic,strong)NSArray <NSNumber *>* values;
@end

/**
 * Audiowise BLE Control Service Data
 * 耳机数据基础类
 */
@interface AWDeviceData : NSObject

@property(nonatomic,assign)NSUInteger cmd;
@property(nonatomic,assign)NSUInteger utc;                      //测量时间，UTC
@property(nullable,nonatomic,strong)NSString *broadcastId;      //广播ID
@property(nullable,nonatomic,strong)NSString *deviceId;         //设备ID
@property(nullable,nonatomic,strong)NSString *deviceSN;         //设备SN
@property(nullable,nonatomic,strong)NSString *measureTime;      //测量时间，格式 yyyy-MM-dd HH:mm:ss
@property(nonatomic,assign)NSUInteger respCode;                 //响应状态
@property(nonatomic,strong,readonly)NSData * _Nullable srcData; //原始数据包

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;


-(instancetype _Nonnull)initWithCmd:(NSUInteger)cmd srcData:(NSData *_Nullable)data;


/**
 * 数据包解码，由子类重写
 */
-(void)decoding;

/**
 * 对象信息
 */
-(NSDictionary *_Nonnull)toString;

/**
 * 指令格式化
 */
-(NSData *)toBytes;
@end


/**
 * 耳机版本信息
 */
@interface AWVersion : AWDeviceData

/**
 * 左耳机版本
 */
@property(nonatomic,strong)NSString *leftEarVer;

/**
 * 右耳机版本
 */
@property(nonatomic,strong)NSString *rightEarVer;
@end


/**
 * 耳机信道状态信息
 */
@interface AWChannel : AWDeviceData

/**
 * GRS Channel
 */
@property(nonatomic,strong)NSString * _Nullable grsChannel;

/**
 * GRS State
 */
@property(nonatomic,strong)NSString * _Nullable grsState;
@end

/**
 * 耳机信道设置信息
 */
@interface AWChannelSettings : AWDeviceData

/**
 * Left GRS Channel
 */
@property(nonatomic,assign)BOOL leftChannel;

/**
 * GRS State
 */
@property(nonatomic,assign)BOOL grsState;
@end


/**
 * 耳机电量信息
 */
@interface AWBattery : AWDeviceData

/**
 * 左耳机电量
 */
@property(nonatomic,assign)NSUInteger leftBattery;

/**
 * 右耳机电量
 */
@property(nonatomic,assign)NSUInteger rightBattery;
@end


/**
 * 耳机模式状态
 */
@interface AWMode : AWDeviceData

/**
 * 当前模式索引，默认为-1，表示无效
 */
@property(nonatomic,assign)int mode;
@end


/**
 *  耳机音量信息
 */
@interface AWVolume : AWDeviceData

/**
 * 左耳机音量
 */
@property(nonatomic,assign)int leftVol;

/**
 * 右耳机音量
 */
@property(nonatomic,assign)int rightVol;

/**
 * 最大音量
 */
@property(nonatomic,assign)int maxVolume;

/**
 * 最大音量等级
 */
@property(nonatomic,assign)int maxLevel;

/**
 * 最多支持的模式索引
 */
@property(nonatomic,assign)int maxMode;
@end

/**
 * 侧听数据内容
 */
@interface AWPuretoneGenertor : AWDeviceData

/**
 * 左耳侧听信息
 */
@property(nonatomic,strong)AWPuretoneItem *left;

/**
 * 右耳侧听信息
 */
@property(nonatomic,strong)AWPuretoneItem *right;
@end


/**
 * User EQ SWITCH
 */
@interface AWUserEqSwitch : AWDeviceData
@property(nonatomic,assign)BOOL leftEnable;
@property(nonatomic,assign)BOOL rightEnable;
@end


/**
 * User EQ GAIN
 */
@interface AWUserEqGain : AWDeviceData

/**
 * Left Eq Gain
 */
@property(nonatomic,strong)AWUserGainItem * _Nullable leftGains;

/**
 * Right Eq value
 */
@property(nonatomic,strong)AWUserGainItem * _Nullable rightGains;
@end

/**
 * Speaker Reference
 */
@interface AWSpeakerReference : AWDeviceData

@property(nonatomic,assign)NSUInteger grsChannel;
@property(nonatomic,assign)NSUInteger version;
@property(nonatomic,strong)AWHearingTestSpeaker * _Nullable leftSpeaker;
@property(nonatomic,strong)AWHearingTestSpeaker * _Nullable rightSpeaker;
@end


