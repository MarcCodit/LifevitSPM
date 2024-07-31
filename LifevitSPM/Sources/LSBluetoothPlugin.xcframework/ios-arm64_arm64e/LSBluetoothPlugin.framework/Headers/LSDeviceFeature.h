//
//  LSDeviceFeature.h
//  LSDeviceBluetooth
//
//  Created by caichixiang on 2017/6/27.
//  Copyright © 2017年 sky. All rights reserved.

//  Added in version 1.0.6 build-1

#import <Foundation/Foundation.h>

#pragma mark - Added In Version 1.1.0

typedef NS_ENUM(NSUInteger,LSScaleCommandProfile)
{
    LSScaleCmdUnknown=0x00,
    LSScaleCmdRegisterDeviceID=0x0001,       //注册设备ID通知
    LSScaleCmdResponseDeviceID=0x0002,       //设备对App注册设备ID通知的响应
    LSScaleCmdBinding=0x0003,                //绑定通知
    LSScaleCmdResponseBind=0x0004,           //设备对App绑定通知的响应
    LSScaleCmdUnbinding=0x0005,              //解绑通知
    LSScaleCmdResponseUnbind=0x0006,         //设备对App解绑通知的响应
    LSScaleCmdRequestAuth=0x0007,            //设备上传的登录请求
    LSScaleCmdResponseAuth=0x0008,           //App对设备上传的登录请求进行响应
    LSScaleCmdRequestInit=0x0009,            //设备上传的初始化请求
    LSScaleCmdResponseInit=0x000A,           //App对设备上传的初始化请求进行响应
    
#pragma mark - psuh cmd
    
    LSScaleCmdResponseSetting=0x1000,        //设备对App的push指令响应
    LSScaleCmdPushUserInfo=0x1001,           //App写用户信息指令
    LSScaleCmdPushTime=0x1002,               //App写时间指令
    LSScaleCmdPushTarget=0x1003,             //App写目标信息指令
    LSScaleCmdPushUnit=0x1004,               //App写单位信息指令
    LSScaleCmdPushClearData=0x1005,          //App写清除数据指令
    
    
#pragma mark - scale's info cmd
    
    LSScaleCmdResponseSettingInfo=0x2000,    //App对设备上传的设置信息，响应码
    LSScaleCmdUserInfo=0x2001,               //设备上传用户信息，响应码
    LSScaleCmdTargetInfo=0x2003,             //设备上传目标信息
    LSScaleCmdUnitInfo=0x2004,               //设备上传单位信息
    
#pragma mark - scale's measure data cmd
    
    LSScaleCmdSyncingData=0x4801,           //App写数据同步通知命令字
    LSScaleCmdMeasureData=0x4802,           //设备上传测量数据，命令字
    LSScaleCmdHeartbeatData=0x4803,         //体重秤心跳包测量数据，命令字

    LSScaleCmdResponseSettingBpm=0x1100,     //设备对App的push指令响应

    LSScaleCmdSyncingDataBpm=0x4901,         //App写数据同步通知命令字
    LSScaleCmdMeasureDataBpm=0x4902,         //设备上传测量数据，命令字
    
    LSScaleCmdMeasurementStatus=0x2102,      //血压计上传测量状态
    LSScaleCmdErrorStatus=0x2103,            //血压计上传错误状态
    
    LSScaleCmdBloodOxygenData=0x4a02,        //血氧数据
    LSScaleCmdPulseWaveData=0x4a04,          //脉搏波体积描记图数据上传
    LSScaleCmdPushPulseWaveState=0x1101,     //App写脉搏波数据同步指令
    
    LSScaleCmdTemperatureData=0x4b02,        //体温数据

};

/**
 * 血糖仪测量状态
 */
typedef NS_ENUM(NSUInteger, BGStatus) {
    BGStatusTestResult=0x10,       //上次测试结果
    BGStatusInsertStrip=0x11,      //请插入试纸
    BGStatusCollecting=0x22,       //数据采集中
    BGStatusCollected=0x33,        //采集完成
    BGStatusResult=0x44,           //返回结果
    BGStatusAlarm=0x55,            //警告信息
    BGStatusPowerOff=0xDD,         //拉出试纸 或熄屏关机
};

/**
 * 血糖仪测量状态
 */
typedef NS_ENUM(NSUInteger, BGErrorCode) {
    /**
     * Please replace with a new strip and test again
     */
    BGErrorCodeE0=0x00,
    
    /**
     * Please add samples after the interface of waiting to add blood appears
     */
    BGErrorCodeE1=0x01,
    
    /**
     *The test strip has been used. Please replace it with a new strip and test it again
     */
    BGErrorCodeE2=0x02,
    
    /**
     Blood glucose test strip does not match, please change a new blood glucose test strip
     */
    BGErrorCodeE3=0x03,
    
    /**
     The sample is abnormal and only human blood and associated quality control fluid can be used for testing
     */
    BGErrorCodeE4=0x04,
    
    /**
     Please move to a suitable temperature, wait for 20 minutes and retest
     */
    BGErrorCodeE5=0x05,
    
    /**
     The device is abnormal, please restart the blood glucose meter and replace with a new test strip
     */
    BGErrorCodeE6=0x06,
    
    /**
     Please replace the new test strip and test again. The test sample is insufficient
     */
    BGErrorCodeE7=0x07,
    
    /**
     Please unplug the charging cord of the glucose meter, and switch it on again for blood glucose test
     */
    BGErrorCodeE8=0x08,
    
    /**
     Please replace the new test strip and test it again, and make sure that the sample is sufficient
     */
    BGErrorCodeE9=0x09,
    
    /**
     Please replace the new test strip and test it again, and make sure that the sample is sufficient
     */
    BGErrorCodeE10=0x0A,

};


/**
 * 设备功能描述基类
 */
@interface LSDeviceFeature : NSObject
@property(nonatomic,strong)NSString *broadacstId;   //设备广播ID
@property(nonatomic,strong)NSString *deviceId;      //设备ID
@end


/**
 * 秤支持的功能特征
 */
@interface LSScaleProfile : LSDeviceFeature

@property(nonatomic,strong)NSData *srcData;
@property(nonatomic,assign)BOOL isSupportBind;                  //是否支持绑定
@property(nonatomic,assign)BOOL isSupportUnBind;                //是否支持解除绑定
@property(nonatomic,assign)BOOL isSupportUtc;                   //是否支持UTC设置
@property(nonatomic,assign)BOOL isSupportTimezone;              //是否支持时区设置
@property(nonatomic,assign)BOOL isSupportTimeStamp;             //是否支持时间戳设置
@property(nonatomic,assign)BOOL isSupportMultiUser;             //是否支持多用户
@property(nonatomic,assign)BOOL isSupportBodyFatPercentage;     //是否支持脂肪率
@property(nonatomic,assign)BOOL isSupportBasalMetabolism;       //是否支持基础代谢
@property(nonatomic,assign)BOOL isSupportMusclePercentage;      //是否支持肌肉含量
@property(nonatomic,assign)BOOL isSupportMuscleMass;            //是否支持肌肉质量
@property(nonatomic,assign)BOOL isSupportFatFreeMass;           //是否支持无脂肪质量
@property(nonatomic,assign)BOOL isSupportSoftLeanMass;          //是否支持软肌肉计算
@property(nonatomic,assign)BOOL isSupportBodyWaterMass;         //是否支持水分含量计算
@property(nonatomic,assign)BOOL isSupportImpedance;             //是否支持阻抗测量
@property(nonatomic,assign)BOOL isSupportBabyWeight;            //是否支持婴儿体重
@property(nonatomic,assign)BOOL isSupportRegisterState;         //是否注册状态标志位
@end


/**
 * 血压计支持的功能特征
 */
@interface LSBloodPressureProfile : LSDeviceFeature

@property(nonatomic,assign)BOOL isSupportBind;                  //是否支持绑定
@property(nonatomic,assign)BOOL isSupportUnBind;                //是否支持解除绑定
@property(nonatomic,assign)BOOL isSupportUtc;                   //是否支持UTC设置
@property(nonatomic,assign)BOOL isSupportTimezone;              //是否支持时区设置
@property(nonatomic,assign)BOOL isSupportTimeStamp;             //是否支持时间戳设置
@property(nonatomic,assign)BOOL isSupportMultiUser;             //是否支持多用户
@property(nonatomic,assign)BOOL isSupportPulseRate;             //是否支持脉搏检测
@property(nonatomic,assign)BOOL isSupportBodyMovement;          //是否支持体动检测
@property(nonatomic,assign)BOOL isSupportCuffFit;               //是否支持袖带检测
@property(nonatomic,assign)BOOL isSupportIrregularPulse;        //是否支持脉搏检测
@property(nonatomic,assign)BOOL isSupportMeasurementPosition;   //是否支持位置检测
@property(nonatomic,assign)BOOL isSupportMultipleBond;          //是否支持重复绑定
@property(nonatomic,assign)BOOL isRegistered;                   //设备是否已注册
@end


/**
 * 血压测量状态
 */
@interface BPMeasurementStatus : NSObject

/**
 * 0=No body movement
 * 1=Body movement during measurement
 */
@property(nonatomic,assign)int bodyMovement;

/**
 * 0=Cuff fits properly
 * 1=Cuff too loose
 */
@property(nonatomic,assign)int cuffFit;

/**
 * 0=No irregular pulse detected
 * 1=Irregular pulse detected
 */
@property(nonatomic,assign)int irregularPulse;

/**
 * 0=Pulse rate is within the range
 * 1=Pulse rate exceeds upper limit
 * 2=Pulse rate is less than lower limit
 */
@property(nonatomic,assign)int pulseRateRange;

/**
 * 0=Proper measurement position
 * 1=Improper measurement position
 */
@property(nonatomic,assign)int measurementPosition;

/**
 * 是否重复绑定
 */
@property(nonatomic,assign)int duplicateBind;

/**
 * HSD 状态
 */
@property(nonatomic,assign)int statusOfHSD;

/**
 * source data
 */
@property(nonatomic,strong)NSData *data;

-(instancetype)initWithData:(NSData *)data;

+(BPMeasurementStatus *)parseA6Status:(NSUInteger)flags;
@end
