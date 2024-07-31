//
//  ATDataProfiles.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/11.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATDeviceData.h"
#import "ATFileData.h"



/**
 * 数据指令
 */
typedef NS_ENUM(NSUInteger,ATCommand)
{
    ATCommandInfo=0x50,                 //设备信息
    ATCommandStepOfHour=0x51,           //每天步数数据
    ATCommandStepOfDay=0x57,            //每小时步数数据
    ATCommandStandTime=0x58,            //每天站立时长数据
    ATCommandHeartRate=0x53,            //心率数据
    ATCommandSleep=0x52,                //睡眠数据
    ATCommandRunningStatus=0x72,        //跑步状态数据
    ATCommandRunningHeartRate=0x73,     //跑步心率数据
    ATCommandHeartRateStatistical=0x75, //心率统计数据
    ATCommandRunningCalories=0x7F,      //跑步卡路里数据
    ATCommandExerciseNotify=0xE1,       //运动通知
    ATCommandExercise=0xE2,             //运动数据
    ATCommandExerciseHeartRate=0xE5,    //运动心率数据
    ATCommandExerciseSpeed=0xE4,        //运动匹速数据
    ATCommandExerciseCalories=0xE6,     //运动卡路里数据
    ATCommandBindRequest=0x7B,          //绑定请求
    ATCommandBingConfirm=0xE3,          //绑定确认
    
    ATCommandSensor=0xE9,               //gSensor 传感器数据
    ATCommandLog=0xEA,                  //log 信息
    ATCommandControl=0xC0,              //控制指令数据
    ATCommandBuriedPoint=0x5B,          //埋点数据
    ATCommandMeditation=0x84,           //冥想数据
    ATCommandBloodOxygen=0x83,          //血氧数据
    ATCommandSleepReport=0x82,          //睡眠报告
    ATCommandRestingHR=0x85,            //静息心率数据
    ATCommandStepOfHistory=0x86,        //常规步数记录
    ATCommandChargeRecord=0x87,         //充电记录
    ATCommandStepOfRecord=0x88,         //当天计步明细记录
    ATCommandUploadDone=0x8B,           //上传完成
    ATCommandBacklight=0x8C,            //背光亮度
    ATCommandHeartRateRecord=0x89,      //当天常规计步心率
    ATCommandBloodOxygenRecord=0x8A,    //当天常规血氧数据
    ATCommandDialStyle=0xB7,            //表盘样式
    ATCommandDialInfo=0xBA,             //表盘详情
    ATCommandDialSyncState=0xB9,        //表盘同步状态
    ATCommandDialInfoResp=0xF9,         //表盘详情确认
    ATCommandIotDevice = 0x8D,          //iot设备信息
    
    //LS437-B HB 新增命令字
    ATCommandHeartRateOfHB = 0x10,         //自定义心率数据
    ATCommandBuriedPointOfHB = 0x11,       //埋点统计数据
    ATCommandExerciseSpeedOfHB = 0x12,     //英制配速数据
    ATCommandExerciseStepOfHB = 0x13,      //运动步频数据
    ATCommandExerciseDataOfHB = 0x14,      //运动总结数据
    ATCommandBloodOxygenOfHB = 0x8E,       //血氧数据
    
    ATCommandConfigItemQuery = 0x66,       //查询配置项数据
    ATCommandConfigItemData = 0x67,        //配置项数据
    
    ATCommandStateControl = 0xA9,          //状态控制指令
    ATCommandWorkStateData = 0x1A,         //工作状态数据
    ATCommandNewStepSummary = 0x1B,        //带静息心率的步数记录
    ATCommandUserInfo = 0xB5,              //用户信息
    
    //LS450 天王星新增命令字
    ATCommandIotSyncReq = 0x8F,            //iot设备状态同步请求
    ATCommandIotControlReq = 0x26,         //iot设备状态控制请求

    //LS453 路易斯新增数据结构
    ATCommandStressTestReport=0x1D,       //压力测试报告
    ATCommandIotControlResp=0x27,         //iot控制指令响应
    ATCommandIotControl=0x1E,             //iot控制指令请求
    ATCommandManualHeartRate=0x1F,        //点测量心率数据

    //心情数据
    ATCommandMoodData=0xC1,              //心情记录数据
    
    //LS411-B新增
    ATCommandTemperatuerData = 0x54,     //体温数据
};


@interface ATDataProfiles : NSObject

/**
 * 单例
 */
+(instancetype)defaultProfiles;

/**
 * 注册设备指令对应的数据解析类
 */
-(void)registerDeviceCmd:(ATCommand)cmd cls:(NSString *)clsName;

/**
 * 数据帧内容解析
 */
-(ATDeviceData *)parse:(NSData *)data forCmd:(NSUInteger)cmd;

/**
 * UTC 时间格式化
 */
-(NSString *)formatUtcTime:(long)utc;

@end

