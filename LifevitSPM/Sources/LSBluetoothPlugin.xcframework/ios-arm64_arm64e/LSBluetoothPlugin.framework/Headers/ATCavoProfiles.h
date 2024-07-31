//
//  ATCavoProfiles.h
//  LSBluetoothPlugin
//
//  Created by sky.cai on 2023/8/17.
//  Copyright © 2023 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 资源类型
 */
typedef NS_ENUM(NSUInteger,ATCavoResource) {
    ATCavoResourceMain = 0x00,          //主显示资源
    ATCavoResourceWatchFace=0x04,       //表盘资源
};


/**
 * 控制指令
 */
typedef NS_ENUM(NSUInteger,ATCavoControlCmd){
    ATCavoControlCmdUnknown=0x00,
    ATCavoControlCmdSetting=0x02,
    ATCavoControlCmdBind=0x03,
    ATCavoControlCmdReminder=0x04,
    ATCavoControlCmdExercise=0x05,
    ATCavoControlCmdFactoryTest=0x06,
    ATCavoControlCmdControlNotify=0x07,     //手机控制通知
};


/**
 * 绑定指令
 */
typedef NS_ENUM(NSUInteger,ATCavoBindCmd){
    ATCavoBindCmdUnknown=0x00,
    ATCavoBindCmdRequest=0x01,
    ATCavoBindCmdResponse=0x02,
    ATCavoBindCmdLogin=0x03,
    ATCavoBindCmdLoginResp=0x04,
    ATCavoBindCmdUnbind=0x05,
};


/**
 * 数据指令
 */
typedef NS_ENUM(NSUInteger,ATCavoDataCmd) {
    ATCavoDataCmdUnknown=0x00,
    ATCavoDataCmdSync=0x01,
    ATCavoDataCmdStepData=0x02,                 //步数
    ATCavoDataCmdSleepData=0x03,                //睡眠数据
    ATCavoDataCmdStepReminder=0x06,             //计步提醒设置
    ATCavoDataCmdStartOfHistoryData=0x07,       //历史数据同步开始
    ATCavoDataCmdEndOfHistoryData=0x08,         //历史数据同步结束

    ATCavoDataCmdSingleHeartRate=0x09,          //单次心率采集检测开关
    ATCavoDataCmdContinuousHeartRate=0x10,      //连续心率采集检测
    ATCavoDataCmdGetStepSummary=0x0B,              //当前步数
    ATCavoDataCmdStepSummary=0x0C,              //当前步数

    ATCavoDataCmdRespHeartRateSwitch=0x12,        //连续心率检测参数返回

    ATCavoDataCmdExerciseData=0x16,             //运动数据
    ATCavoDataCmdExerciseMode=0x17,             //运动模式
    ATCavoDataCmdHeartRateInterval=0x18,        //心率采集间隔
    ATCavoDataCmdSetExerciseHeartRate=0x19,     //运动心率检测功能控制开关
    ATCavoDataCmdRespExerciseHeartRate=0x1A,    //运动心率检测功能控制开关返回

    ATCavoDataCmdHeartRateSummary=0x1B,         //心率数据批量返回
    ATCavoDataCmdSyncEnd=0x1C,                  //数据同步结束通知

    ATCavoDataCmdStartMeasureTemperature=0x20,  //开启温度测量
    ATCavoDataCmdTemperatureData=0x21,          //温度数据

    ATCavoDataCmdSetTemperatureConfig=0x22,     //设置温度监测参数
    ATCavoDataCmdGetTemperatureConfig=0x23,     //获取温度监测参数
    ATCavoDataCmdRespTemperatureConfig=0x24,    //获取温度监测参数返回

    ATCavoDataCmdHeartRates=0x29,               //多笔心率与测温数据
    ATCavoDataCmdHeartRate=0x0F,                //单笔心率与测温数据

    ATCavoDataCmdSpo2HistoryData=0x2C,         //血氧历史数据
    ATCavoDataCmdSetSpo2Switch=0x2D,           //设置血氧监测开关
    ATCavoDataCmdRespSpo2Switch=0x2E,          //设置血氧监测开关的响应

    ATCavoDataCmdSetContinuousSpo2=0x33,       //设置连续血氧采集检测
    ATCavoDataCmdGetContinuousSpo2=0x34,       //查询连续血氧采集检测
    ATCavoDataCmdRespContinuousSpo2=0x35,      //查询连续血氧采集检测返回
    ATCavoDataCmdDeviceInfo=0x52,              //设备信息
    ATCavoDataCmdRepeatUpload=0xFA,            //控制手环数据重复上传标志位
};


/**
 * DFU 固件更新CMD
 */
typedef NS_ENUM(NSUInteger,ATCavoDfuCmd){
    ATCavoDfuCmdUnknown=0x00,
    ATCavoDfuCmdCheckBufferSize=0x09,                 //缓存大小检测
    ATCavoDfuCmdUpdateConnectionParameter=0x07,       //更新连接参数
    ATCavoDfuCmdSetTargetImage=0x06,                  //设置文件ID
    ATCavoDfuCmdStartDfu=0x01,                        //写文件头内容
    ATCavoDfuCmdSetImageSize=0x02,                    //写目标文件大小
    ATCavoDfuCmdSetBlockConfirm=0x0A,                 //写文件块确认帧
    ATCavoDfuCmdSetValid=0x03,                        //写固件校验指令
    ATCavoDfuCmdSetActivate=0x04,                     //写重置，重启指令
};


/**
 * 消息提醒指令
 */
typedef NS_ENUM(NSUInteger,ATCavoMessageCmd){
    ATCavoMessageCmdUnknown=0x00,
    ATCavoMessageCmdIncomingCall=0x01,     //来电
    ATCavoMessageCmdAnswer=0x02,           //接听
    ATCavoMessageCmdHangup=0x03,           //挂断
    ATCavoMessageCmdNotify=0x04,           //消息通知
    ATCavoMessageCmdHangupOnDevice=0x05,
    ATCavoMessageCmdCharging=0x06,
    ATCavoMessageCmdAnswerOnDevice=0x07,
};


/**
 * 手环功能设置及读取响应
 */
typedef NS_ENUM(NSUInteger,ATCavoConfig) {
    ATCavoConfigUnknown=0x00,
    ATCavoConfigSetTime=0x01,
    ATCavoConfigSetAlarmClock=0x02,                //设置闹钟
    ATCavoConfigGetAlarmClocks=0x03,               //获取闹钟列表
    ATCavoConfigRespAlarmClocks=0x04,              //获取闹钟列表返回
    ATCavoConfigSetStepGoal=0x05,                  //设置步数据目标
    ATCavoConfigSetSleepGoal=0x06,                 //设置睡眠目标
    ATCavoConfigSetCalorieGoal=0x07,               //设置卡路里目标
    ATCavoConfigSetUserInfo=0x10,                  //设置用户信息
    ATCavoConfigSetSedentaryReminder=0x21,         //设置久坐提醒
    ATCavoConfigSetTemperatureUnit=0x22,           //设置温度单位

    ATCavoConfigSetPlatform=0x23,                  //设置系统平台
    ATCavoConfigSetMessageSwitch=0x25,             //设置消息提醒开关
    ATCavoConfigGetSedentaryReminder=0x26,         //获取久坐提醒
    ATCavoConfigRespSedentaryReminder=0x27,        //获取久坐提醒返回
    ATCavoConfigGetMessageSwitch=0x28,             //获取消息提醒开关
    ATCavoConfigRespMessageSwitch=0x29,            //获取消息提醒开关信息返回

    ATCavoConfigSetScreenPowerOn=0x2A,             //抬腕亮屏控制

    ATCavoConfigSetAllMessageSwitch=0x2D,          //设置消息提醒整体开关

    ATCavoConfigGetDeviceFeature=0x36,             //获取设备功能列表
    ATCavoConfigRespDeviceFeature=0x37,             //获取设备功能列表

    ATCavoConfigSetWatchFace=0x38,                 //表盘切换
    ATCavoConfigGetWatchFace=0x39,                 //表盘请求
    ATCavoConfigRespWatchFace=0x3A,                //表盘信息返回
    ATCavoConfigSetQuietMode=0x47,                 //设置忽扰模式
    ATCavoConfigGetQuietMode=0x48,                 //查询忽扰模式
    ATCavoConfigRespQuietMode=0x49,                //查询忽扰模式返回

    ATCavoConfigSetTimeFormat=0x41,                //设置小时制

    ATCavoConfigSetBrightnessTime=0x4A,            //设置亮度时间
    ATCavoConfigGetBrightnessTime=0x4B,            //查询亮度时间
    ATCavoConfigRespBrightnessTime=0x4C,           //查询亮度时间返回

    ATCavoConfigGetDeviceInfo=0x51,                //获取设备信息
    ATCavoConfigRespDeviceInfo=0x52,               //获取设备信息返回

    ATCavoConfigSetBrightness=0x53,                //设置亮度
    ATCavoConfigGetBrightness=0x54,                //查询亮度
    ATCavoConfigRespBrightness=0x55,               //查询亮度返回

    ATCavoConfigFirmwareUpdate=0xFF,               //进入OTA模式

    ATCavoConfigGetHeartRrateSwitch=0x11,          //读取心率检测开关
    ATCavoConfigSetHeartRrateSwitch=0x0E,          //设置连续心率检测开关

    ATCavoConfigSetContinuousSpo2=0x33,             //设置连续血氧检测开关
    ATCavoConfigGetContinuousSpo2=0x34,             //读取血氧检测开关

    ATCavoConfigSetHeartRateWarnging=0x75,         //设置心率预警设置信息
    ATCavoConfigGetHeartRateWarnging=0x76,         //请求心率预警设置信息
    ATCavoConfigRespHeartRateWarnging=0x77,         //返回心率预警设置信息

    ATCavoConfigGetExerciseHeartRateSwitch=0x19,    //请求运动心率检测开关
};


/**
 * 手环支持的消息提醒应用类型
 */
typedef NS_ENUM(NSUInteger,ATCavoAppType){
    ATCavoAppTypeOther=0x00,
    ATCavoAppTypeQQ=0x01,
    ATCavoAppTypeWechat=0x02,
    ATCavoAppTypeTim=0x03,
    ATCavoAppTypeSMS=0x04,
    ATCavoAppTypeGmail=0x05,
    ATCavoAppTypeDingTalk=0x06,
    ATCavoAppTypeWorkWechat=0x07,
    ATCavoAppTypeLine=0x08,
    ATCavoAppTypeTwitter=0x09,
    ATCavoAppTypeFacebook=0x0A,
    ATCavoAppTypeMessenger=0x0B,
    ATCavoAppTypeWhatsApp=0x0C,
    ATCavoAppTypeLinkedln=0x0D,
    ATCavoAppTypeInstagram=0x0E,
    ATCavoAppTypeSkype=0x0F,
    ATCavoAppTypeViber=0x10,
    ATCavoAppTypeKakaoTalk=0x11,
    ATCavoAppTypeVK=0x12,
    ATCavoAppTypeA=0x13,
    ATCavoAppTypeLianjia=0x14,
    ATCavoAppTypeBeike=0x15,
    ATCavoAppTypeLink=0x16,
    ATCavoAppTypeMail=0x17,
    ATCavoAppTypeCalendar=0x18,
};


/**
 * 运动类型
 */
typedef NS_ENUM(NSUInteger,ATCavoExercise){
    ATCavoExerciseRun=0x00,              //跑步
    ATCavoExerciseClimb=0x01,            //登山
    ATCavoExerciseFootball=0x02,         //足球
    ATCavoExerciseCycle=0x03,            //骑行
    ATCavoExerciseRope=0x04,             //跳绳
    ATCavoExerciseRunOutDoor=0x05,       //户外跑步
    ATCavoExerciseRideOutDoor=0x06,      //户外骑车
    ATCavoExerciseWalkOutDoor=0x07,      //户外徒步
    ATCavoExerciseRunInDoor=0x08,        //室内跑步
    ATCavoExerciseHIIT=0x09,             //自由训练
    ATCavoExercisePlank=0x0A,            //平板支撑
    ATCavoExerciseWalk=0x0B,             //健走
    ATCavoExercisePranayama=0x0C,        //呼吸训练
    ATCavoExerciseYoga=0x0D,             //瑜伽
    ATCavoExerciseHiking=0x0E,           //徒步
    ATCavoExerciseSpinning=0x0F,         //动感单车
    ATCavoExerciseRowing=0x10,           //划船机
    ATCavoExerciseStepper=0x11,          //踏步机
    ATCavoExerciseElliptical=0x12,       //椭圆机
    ATCavoExerciseBasketball=0x13,       //篮球
    ATCavoExerciseTennis=0x14,           //网球
    ATCavoExerciseBadminton=0x15,        //羽毛球
    ATCavoExerciseBaseball=0x16,         //棒球
    ATCavoExerciseRugby=0x17,            //橄榄球

    ATCavoExercisePingpong=0x18,         //乒乓球运动
    ATCavoExerciseSkiing=0x19,           //滑雪
    ATCavoExerciseCricket=0x1A,          //板球运动
    ATCavoExerciseBodyBuilding=0x1B,     //力量训练
};


/**
 * 历史数据项
 */
@interface ATCavoHistoryItem : NSObject

/**
 * 数据类型
 */
@property(nonatomic,assign) int type;

 /**
  * 记录条数
  */
@property(nonatomic,assign) int size;
@end


/**
 * 乐心手环6S协议及指令格式描述文件
 */
@interface ATCavoProfiles : NSObject

@end
