//
//  ATIotDevice.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/8/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"
#import "ATIotInfo.h"


/**
 * iot功能类别
 */
#define IOT_FUN_CATEGORY_SWITCH @"SWITCH"
#define IOT_FUN_CATEGORY_TEXT @"TEXT"
#define IOT_FUN_CATEGORY_FEATURE_LIST @"FEATURE_LIST"
#define IOT_FUN_CATEGORY_FLUCTUATE_SET @"FLUCTUATE_SET"

/**
 * iot功能项
 */
#define IOT_FUN_UNKNOWN @""
#define IOT_FUN_ONLINE @"ONLINE"
#define IOT_FUN_OFFLINE @"OFFLINE"

#define IOT_FUN_SWITCH @"SWITCH"
#define IOT_FUN_BRIGHT @"BRIGHT"
#define IOT_FUN_COLOR @"COLOR"
#define IOT_FUN_SCENE @"SCENE"

#define IOT_FUN_TEMPER @"TEMPER"
#define IOT_FUN_SPEED @"SPEED"
#define IOT_FUN_MODE @"MODE"

#define IOT_FUN_HEADSET_BATTERY @"HEADSET_BATTERY"
#define IOT_FUN_HEADSET_BATTERY_BOX @"HEADSET_BATTERY_BOX"
#define IOT_FUN_HEADSET_BATTERY_LEFT @"HEADSET_BATTERY_LEFT"
#define IOT_FUN_HEADSET_BATTERY_RIGHT @"HEADSET_BATTERY_RIGHT"
#define IOT_FUN_HEADSET_GAME_MODE @"HEADSET_GAME_MODE"
#define IOT_FUN_HEADSET_SOUND_EFFECT @"HEADSET_SOUND_EFFECT"
#define IOT_FUN_HEADSET_NOISE_REDUCTION @"HEADSET_NOISE_REDUCTION"

#define IOT_FUN_REMARK @"REMARK"
#define IOT_EXTRA_DEVICE_NAME @"EXTRA_DEVICE_RENAME"

/**
 * iOT设备工作状态
 */
typedef NS_ENUM(NSUInteger,ATIotWorkingState) {
    ATIotWorkingStateTurnOff=0x00,           //关闭
    ATIotWorkingStateOnline=0x01,            //在线
    ATIotWorkingStateOffline=0x02            //离线
};

/**
 * iOT设备同步状态
 */
typedef NS_ENUM(NSUInteger,ATIotSyncState) {
    ATIotSyncStateUpdate=0x00,           //更新
    ATIotSyncStateAdd=0x01,              //新增
    ATIotSyncStateRemove=0x02,           //删除
    ATIotSyncStateRemoveAll=0x03,        //清空
    ATIotSyncStateGetDevices=0x07,       //查询设备列表
    ATIotSyncStateUpdateName=0x08,       //更新设备名称
};

/**
 * 属性Id
 */
typedef NS_ENUM(NSUInteger,ATIotAttsId) {
    ATIotAttsIdUnknown=0x00,
    ATIotAttsIdName=0x01,
    ATIotAttsIdOnline=0x02,                           //在线
    ATIotAttsIdOffline=0x02,                          //离线
    ATIotAttsIdBattery=0x03,                          //耳机电量
    ATIotAttsIdBoxBattery=0x03,                       //耳机电池盒电量
    ATIotAttsIdLeftBattery=0x04,                      //左耳机电量
    ATIotAttsIdRightBattery=0x05 ,                    //右耳机电量
    ATIotAttsIdGameMode=0x06,                         //游戏模式
    ATIotAttsIdNoiseReduction=0x07,                   //降躁模式
    ATIotAttsIdSoundEffect=0x08,                      //音效
    ATIotAttsIdSwitch=0x09,                           //开关
    ATIotAttsIdBright=0x0A,                           //亮度
    ATIotAttsIdColor=0x0B,                            //颜色
    ATIotAttsIdScene=0x0C,                            //场景
    ATIotAttsIdTemperature=0x0D,                      //温度
    ATIotAttsIdMode=0x0E,                             //模式
    ATIotAttsIdWindSpeed=0x0F,                        //风速
    ATIotAttsIdWeight=0x10,                           //体重
    ATIotAttsIdBmi=0x11,                              //BMI
    ATIotAttsIdFat=0x12,                              //脂肪率
    ATIotAttsIdExtraDeviceName=0x13,                  //修改设备名称
    ATIotAttsIdRemark=0x14,                           //修改设备备注信息
};



/**
 * iOT功能列表
 */
@interface ATIotFunctions : NSObject

@property(nonatomic,assign) int currentValue ;                    //当前值
@property(nonatomic,assign) BOOL isModifyEnable;                  //是否允许修改
@property(nullable,nonatomic,strong) NSString *mFunctionName;     //功能名称
@property(nullable,nonatomic,strong) NSString *mFunctionNameEnum; //功能名称对应项
@property(nullable,nonatomic,strong) NSString *mType;             //功能项
@property(nullable,nonatomic,strong) NSArray *names;              //字段列表名称
@property(nullable,nonatomic,strong) NSArray *values;             //字段列表内容
@property(nonatomic,assign)int minValue;                          //最小值
@property(nonatomic,assign)int maxValue;                          //最大值
@property(nonatomic,assign)int stepValue;                         //步进

@property(nonatomic,assign)int attId;                              //属性id
@property(nonatomic,assign)int attType;                            //属性类型


/**
 * 根据属性Id,设置mFunctionNameEnum
 */
-(NSString *_Nonnull)toFunctionNameEnum:(int)attId;

/**
 * 根据属性Id,设置mFunctionType
 */
-(NSString *_Nonnull)toFunctionType:(int)attId;
@end


/**
 * IOT 设备信息
 */
@interface ATIotDevice : NSObject

/**
 * 设备序号 1~4,默认为1
 */
@property(nonatomic,assign) unsigned int index;

/**
 * iot 设备MAC 或 设备Id
 */
@property(nonatomic,strong) NSString *iotMac;

/**
 * 设备名称
 */
@property(nullable,nonatomic,strong) NSString *name;

/**
 * 节点状态
 * 0x00 = 未关联
 * 0x01 = 已关联
 */
@property(nonatomic,assign) unsigned int nodeState;

/**
 * 工作状态
 * 0x00 = 关闭
 * 0x01 = 开启
 * 0x02 = 离线
 */
@property(nonatomic,assign)ATIotWorkingState workingState;

/**
 * 同步状态
 * 0x00 = 更新
 * 0x01 = 新增
 * 0x02 = 删除
 */
@property(nonatomic,assign)ATIotSyncState syncState;

/**
 * ioT设备支持的状态量
 */
@property(nonatomic,assign) unsigned int feature;

/**
 * iot设备图片文件CRC
 */
@property(nonatomic,assign) unsigned int iconCrc;

/**
 * iot设备类别
 */
@property(nonatomic,assign) ATIotCategory iotCategory;

/**
 * iot状态控制码
 */
@property(nonatomic,assign) unsigned int controlCode;

/**
 * iot状态控制字段数据
 */
@property(nonatomic,strong,readonly)NSData * _Nullable controlBytes;

/**
 * iOT控制功能列表，用于返回设备端上传的控制项信息
 */
@property(nullable,nonatomic,strong) NSArray <ATIotFunctions *>*iotFunctions;

/**
 * 根据协议封装数据帧
 */
-(NSData *_Nullable)toBytes;

/**
 * 450天王星格式，子类重写
 */
-(NSData *_Nullable)toNewBytes;

/**
 * 对象信息
 */
-(NSDictionary *_Nullable)toString;

-(instancetype _Nonnull )initWithName:(NSString *_Nonnull)name;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATIotHeadset

/**
 * 耳机类设备
 *
 */
@interface ATIotHeadset : ATIotDevice

/**
 * 电池盒电量
 */
@property(nonatomic,assign) unsigned int battery;

/**
 * 左耳电量
 */
@property(nonatomic,assign) unsigned int leftBattery;

/**
 * 右耳电量
 */
@property(nonatomic,assign) unsigned int rightBattery;

/**
 * 游戏模式
 */
@property(nonatomic,assign) unsigned int gameMode;

/**
 * 降噪模式
 */
@property(nonatomic,assign) unsigned int noiseMode;

/**
 * 音效
 */
@property(nonatomic,assign) unsigned int soundEffect;
@end

#pragma mark - ATIotLightBulb

/**
 * 灯泡类设备
 */
@interface ATIotLightBulb : ATIotDevice

/**
 * 开关
 * 0x01 = 打开
 * 0x00 = 关闭
 */
@property(nonatomic,assign) unsigned int state;

/**
 * 亮度
 */
@property(nonatomic,assign) unsigned int brightness;

/**
 * 颜色索引
 */
@property(nonatomic,assign) unsigned int colour;

/**
 * 场景
 */
@property(nonatomic,assign) unsigned int scenes;
@end

#pragma mark - ATIotSocket

/**
 * 插座
 */
@interface ATIotSocket : ATIotDevice

/**
 * 开关
 * 0x01=打开
 * 0x00=关闭
 */
@property(nonatomic,assign) unsigned int state;
@end


#pragma mark - ATIotAirConditioners

/**
 * 空调
 */
@interface ATIotAirConditioners: ATIotDevice
/**
 * 开关
 * 0x01=打开
 * 0x00=关闭
 */
@property(nonatomic,assign) unsigned int state;

/**
 * 温度
 */
@property(nonatomic,assign) unsigned int temperature;

/**
 * 模式
 */
@property(nonatomic,assign) unsigned int mode;

/**
 * 风速
 */
@property(nonatomic,assign) unsigned int windSpeed;
@end


#pragma mark - ATIotSpeaker

/**
 * iOT音箱类设备
 */
@interface ATIotSpeaker : ATIotDevice

/**
 * 电量
 */
@property(nonatomic,assign) unsigned int battery;

/**
 * 游戏模式
 */
@property(nonatomic,assign) unsigned int gameMode;

/**
 * 降噪模式
 */
@property(nonatomic,assign) unsigned int noiseMode;

/**
 * 音效
 */
@property(nonatomic,assign) unsigned int soundEffect;
@end


#pragma mark - ATIotConfig

/**
 * iot设备配置信息
 */
@interface ATIotConfig : NSObject

/**
 * 设备名称
 */
@property(nullable,nonatomic,strong) NSString *name;

/**
 * 设备图标名称，固件端显示
 */
@property(nullable,nonatomic,strong) NSString *iconName;

/**
 * 设备图标MD5
 */
@property(nullable,nonatomic,strong) NSString *iconMd5;

/**
 * 设备id
 */
@property(nullable,nonatomic,strong) NSString *deviceId;

/**
 * realme link iot 设备类型
 *
 * 音箱：0x02
 * 耳机：0x03
 * 灯泡：0x04
 * 摄像头: 0x05
 * 智能秤: 0x06
 * 智能插座：0x07
 * 空调伴侣：0x08
 * 扫地机器人：0x09
 */
@property(nonatomic,assign) int typeInt;

/**
 * iot设备功能列表
 */
@property(nonatomic,strong) NSArray<ATIotFunctions *> *iotFunctions;


/**
 * 图标文件URL
 */
@property(nullable,nonatomic,strong) NSURL *iconUrl;

/**
 * 设备型号
 */
@property(nullable,nonatomic,strong) NSString *deviceModel;

/**
 * 备注信息，
 * 如添加空调时未绑定型号的提示文本信息
 */
@property(nullable,nonatomic,strong)  NSString *remark;
@end


#pragma mark - ATIotSummary


/**
 * Iot设备列表描述
 */
@interface ATIotSummary : NSObject

/**
 * 设备总数
 */
@property(nonatomic,assign)  int count;

/**
 * 当前上传的设备个数
 */
@property(nonatomic,assign)  int itemSize;

/**
 * 当前上传的设备列表
 */
@property(nullable,nonatomic,strong)  NSArray <NSString *>*iotDevices;
@end
