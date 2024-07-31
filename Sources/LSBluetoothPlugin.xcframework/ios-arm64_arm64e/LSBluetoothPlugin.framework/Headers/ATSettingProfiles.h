//
//  ATSettingProfiles.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//

#ifndef ATSettingProfiles_h
#define ATSettingProfiles_h

/**
 * 消息提醒
 */
typedef NS_ENUM(NSUInteger,ATMessageRemindType) {
    ATMessageUnknown=0xFF,           //未知
    ATMessageAll=0x00,               //所有消息,总开关
    ATMessageIncomingCall=0x01,      //来电
    ATMessageDefaultMessage=0x02,    //消息提醒，包括短信和微信
    ATMessageAntilost=0x03,          //连接断开提醒，防丢
    ATMessageSms=0x04,               //短信
    ATMessageWechat=0x05,            //微信
    ATMessageQQ=0x06,                //QQ
    ATMessageFaceBook=0x07,          //FaceBoock
    ATMessageTwitter=0x08,           //Twitter
    ATMessageLine=0x09,              //Line
    ATMessageGmail=0x0A,             //Gmail
    ATMessageKakao=0x0B,             //Kakao
    ATMessageWhatsApp=0x0C,          //WhatsApp
    ATMessageInstagram=0x0D,         //Instagram
    ATMessageApplemusic=0x0E,        //Apple Music
    ATMessageGoogleMaps=0x0F,        //google maps
    ATMessageLikee=0x10,             //likee
    ATMessageLinkedIn=0x11,          //linked in
    ATMessageMessenger=0x12,         //Messenger
    ATMessageMomo=0x13,              //Momo
    ATMessageOdnoklassniki=0x14,     //Odnoklassniki
    ATMessagePrivat24=0x15,          //Privat 24
    ATMessageVK=0x16,                //VK
    ATMessageYouTube=0x17,           //YouTube
    ATMessageYouTubeMusic=0x18,      //YouTube Music
    ATMessageZoom=0x19,              //Zoom
    ATMessageSkype=0x1A,             //Skype
    ATMessageTelegram=0x1B,          //Telegram
    ATMessageTiktok=0x1C,            //Tiktok
    ATMessageViber=0x1D,             //Viber
    ATMessageLestfit=0x1E,           //lestfit
    ATMessageOutlook=0x1F,           //out look
    ATMessageCalendar=0x20,          //Calendar
    ATMessageSnapchat=0x21,          //Snapchat
    ATMessageMissedCall=0x22,        //未接来电
    ATMessageLifesense=0x23,         //乐心健康app
    ATMessageZhifubao=0x24,             //支付宝
    ATMessageDingding=0x25,             //钉钉
    ATMessageWorkWechat=0x26,          //企业微信
    ATMessageSeWellness=0xFE,           //SeWellness
    ATMessageOther=0xFD,                //其他应用
};


/**
 * 时间显示格式
 */
typedef NS_ENUM(NSUInteger,ATTimeFormat) {
    ATTimeFormatH24=0x00,       //24小时
    ATTimeFormatH12=0x01,       //12小时
};

/**
 * 距离计量单位
 */
typedef NS_ENUM(NSUInteger,ATDistanceFormat) {
    ATDistanceFormatKm=0x00,    //表示计量单位为公里，即公制
    ATDistanceFormatMile=0x01,  //表示计量单位为英里，即英制
};

/**
 * 目标鼓励类型
 */
typedef NS_ENUM(NSUInteger,ATEncourageType) {
    ATEncourageNone=0x00,               //无目标
    ATEncourageStep=0x01,               //步数
    ATEncourageCalories=0x02,           //卡路里
    ATEncourageDistance=0x03,           //距离
    ATEncourageSleep=0x04,              //睡眠提醒
    ATEncourageStandingTime=0x05,       //站立时长,单位秒
    ATEncourageExerciseTime=0x06,       //运动时长,单科秒
    ATEncourageNumOfSwimming=0x40,      //游泳圈数

};

/**
 * GPS 状态
 */
typedef NS_ENUM(NSUInteger,ATGpsStatus) {
    ATGpsStatusUnavailable=0x00,    //GPS不可用
    ATGpsStatusFailure=0x01,        //GPS开&尚未定位
    ATGpsStatusSuccess=0x03,        //GPS开&定位成功
    ATGpsStatusRefuse=0x80,         //手机app拒绝运动发起
};

/**
 * 事件提醒 类型
 */
typedef NS_ENUM(NSUInteger,ATEventReminderType){
    ATEventRemindAlarmClock=0x00,    //普通的闹钟提醒
    ATEventRemindDrinkWater=0x01,    //喝水提醒
    ATEventRemindAddMeal=0x02,       //加餐提醒
    ATEventRemindSleep=0x03,         //睡觉提醒
    ATEventRemindSedentary=0x04,     //久坐提醒
    ATEventRemindMeditation=0x05,    //冥想提醒
    ATEventRemindHeartRate=0x06,     //24小时心率提醒
    ATEventRemindGoalAchieved=0x07,  //目标完成提醒
    ATEventRemindNoDisturb=0x80,     //勿扰提醒


};

/**
 * 星期
 */
typedef NS_ENUM(NSUInteger,ATWeekDay) {
    ATWeekDayMon = 0x01,           //星期一
    ATWeekDayTue = 0x02,           //星期二
    ATWeekDayWed = 0x04,           //星期三
    ATWeekDayThur= 0x08,          //星期四
    ATWeekDayFri = 0x10,           //星期五
    ATWeekDaySat = 0x20,           //星期六
    ATWeekDaySun = 0x40            //星期天
};

/**
 * 振动方式
 */
typedef NS_ENUM(NSUInteger,ATVibrationMode) {
    ATVibrationContinuous=0X00,        // 持续震动
    ATVibrationIntermittent1=0X01,     //间歇震动，震动强度不变
    ATVibrationIntermittent2=0X02,     //间歇震动，震动强度由小变大
    ATVibrationIntermittent3=0X03,     //间歇震动，震动强度由大变小
    ATVibrationIntermittent4=0X04,     //震动强度大小循环
};

/**
 * 运动模式
 */
typedef NS_ENUM(NSUInteger,ATExerciseType) {
    
    ATExerciseTypeUnknown=0x00,
    ATExerciseTypeRunning=0x01,         //运动模式 - 跑步
    ATExerciseTypeWalking=0x02,         //运动模式 - 健走
    ATExerciseTypeCycling=0x03,         //运动模式 - 室外骑行
    ATExerciseTypeSwimming=0x04,        //运动模式 - 游泳
    ATExerciseTypeBodyBuilding=0x05,    //运动模式 - 健身/力量训练
    ATExerciseTypeNewRunning=0x06,      //运动模式 - 新跑步模式
    ATExerciseTypeIndoorRunning=0x07,   //运动模式 - 跑步机运动
    ATExerciseTypeElliptical=0x08,      //运动模式 - 椭圆机运动
    ATExerciseTypeAerobicSport=0x09,    //运动模式 - 有氧运动
    ATExerciseTypeBasketball=0x0A,      //运动模式 - 篮球运动
    ATExerciseTypeFootball=0x0B,        //运动模式 - 足球运动
    ATExerciseTypeBadminton=0x0C,       //运动模式 - 羽毛球运动
    ATExerciseTypeVolleyball=0x0D,      //运动模式 - 排球运动
    ATExerciseTypePingpong=0x0E,        //运动模式 - 乒乓球运动
    ATExerciseTypeYoga=0x0F,            //运动模式 - 瑜伽运动
    ATExerciseTypeGaming=0x10,          //运动模式 - 瑜伽运动
    ATExerciseTypeAerobicSport12=0x11,  //运动模式 - 有氧运动 12分钟跑
    ATExerciseTypeAerobicSport6=0x12,   //运动模式 - 有氧运动 6分钟走
    ATExerciseTypeFitnessDance=0x13,    //运动模式 - 健身舞
    ATExerciseTypeTaiChi=0x14,          //运动模式 - 太极
    ATExerciseTypeCricket=0x15,         //运动模式 - 板球运动
    ATExerciseTypeBoating=0x16,         //运动模式 - 划船
    ATExerciseTypeSpinningBike=0x17,    //运动模式 - 动感单车
    ATExerciseTypeIndoorCycling=0x18,   //运动模式 - 室内骑行
    ATExerciseTypeFreeMovement=0x19,    //运动模式 - 自由运动
    ATExerciseTypeJumpRope=0x1B,        //运动模式 - 跳绳
    ATExerciseTypeMountaineering=0x1C,  //运动模式 - 登山
    ATExerciseTypeHockey=0x1D,          //运动模式 - 曲棍球
    ATExerciseTypeTennis=0x1E,          //运动模式 - 网球
    ATExerciseTypeHilt=0x1F,            //运动模式 - HILT
    
   ATExerciseTypeIndoorWalk=0x20,           //室内步行
   ATExerciseTypeHorseRiding=0x21,          //骑马
   ATExerciseTypeShuttlecock=0x22,          //毽球
   ATExerciseTypeBoxing=0x23,               //拳击
   ATExerciseTypeTrailRunning=0x24,         //越野跑
   ATExerciseTypeSkiing=0x25,               //滑雪
   ATExerciseTypeGymnastics=0x26,           //体操
   ATExerciseTypeIceHockey=0x27,            //冰球
   ATExerciseTypeTaekwondo=0x28,            //跆拳道
   ATExerciseTypeAirWalker=0x29,            //漫步机
   ATExerciseTypeHiking=0x2A,               //徒步
   ATExerciseTypeDance=0x2B,                //跳舞
   ATExerciseTypeTrackField=0X2C,           //田径
   ATExerciseTypeWaistTraining=0X2D,        //腰腹训练
   ATExerciseTypeKarate=0X2E,               //空手道
   ATExerciseTypeCoolDown=0X2F,             //整体放松
   ATExerciseTypeCrossTraining=0X30,        //交叉训练
   ATExerciseTypePilates=0X31,              //普拉提
   ATExerciseTypeCrossFit=0X32,             //交叉配合
   ATExerciseTypeFunctionalTraining=0X33,   //功能性训练
   ATExerciseTypePhysicalTraining=0X34,     //体能训练
   ATExerciseTypeArchery=0X35,              //射箭
   ATExerciseTypeFlexibility=0X36,          //柔韧度
   ATExerciseTypeMixedCardio=0X37,          //混合有氧
   ATExerciseTypeLatinDance=0X38,           //拉丁舞
   ATExerciseTypeStreetDance=0X39,          //街舞
   ATExerciseTypeKickboxing=0X3A,           //自由搏击
   ATExerciseTypeBarre=0X3B,                //芭蕾舞
   ATExerciseTypeAustralianFootball=0X3C,   //澳式足球
   ATExerciseTypeMartialArts=0X3D,          //武术
   ATExerciseTypeStairs=0X3E,               //爬楼
   ATExerciseTypeHandball=0X3F,             //手球
   ATExerciseTypeBaseball=0X40,             //棒球
   ATExerciseTypeBowling=0X41,              //保龄球
   ATExerciseTypeRacquetball=0X42,          //壁球
   ATExerciseTypeCurling=0X43,              //冰壶
   ATExerciseTypeHunting=0X44,              //打猎
   ATExerciseTypeSnowboarding=0X45,         //单板滑雪
   ATExerciseTypePlay=0X46,                 //休闲运动
   ATExerciseTypeAmericanFootball=0X47,     //美式橄榄球
   ATExerciseTypeHandCycling=0X48,          //手摇车
   ATExerciseTypeFishing=0X49,              //钓鱼
   ATExerciseTypeDiscSports=0X4A,           //飞盘运动
   ATExerciseTypeRugby=0X4B,                //橄榄球
   ATExerciseTypeGolf=0X4C,                 //高尔夫
   ATExerciseTypeFolkDance=0X4D,            //民族舞
   ATExerciseTypeDownhillSkiing=0X4E,       //高山滑雪
   ATExerciseTypeSnowSports=0X4F,           //雪上运动
   ATExerciseTypeMindBody=0X50,             //舒缓冥想类运动
   ATExerciseTypeCoreTraining=0X51,         //核心训练
   ATExerciseTypeSkating=0X52,              //滑冰
   ATExerciseTypeFitnessGaming=0X53,        //健身游戏
   ATExerciseTypeAerobics=0X54,             //健身操
   ATExerciseTypeGroupTraining=0X55,        //团体操
   ATExerciseTypeKendo=0X56,                //搏击操
   ATExerciseTypeLacrosse=0X57,             //长曲棍球
   ATExerciseTypeRolling=0X58,              //泡沫轴筋膜放松
   ATExerciseTypeWrestling=0X59,            //摔跤
   ATExerciseTypeFencing=0X5A,              //击剑
   ATExerciseTypeSoftball=0X5B,             //垒球
   ATExerciseTypeSingleBar=0X5C,            //单杠
   ATExerciseTypeParallelBars=0X5D,         //双杠
   ATExerciseTypeRollerSkating=0X5E,        //轮滑
   ATExerciseTypeHulaHoop=0X5F,             //呼啦圈
   ATExerciseTypeDarts=0X60,                //飞镖
   ATExerciseTypePickleBall=0X61,           //匹克球
   ATExerciseTypeSitUp=0X62,                //仰卧起坐
   ATExerciseTypeStepTraining=0x63,         //踏步训练
   ATExerciseTypeOutdoorSwimming=0x64,      //室外游泳
};

/**
 * 天气类型
 */
typedef NS_ENUM(NSUInteger,ATWeatherType) {
    ATWeatherSunnyDay=0x00,             //晴（白天）
    ATWeatherSunnyNight=0x01,           //晴（夜晚）
    ATWeatherCloudy=0x02,               //多云
    ATWeatherFineCloudyDay=0x03,        //晴间多云（白天）
    ATWeatherFineCloudyNight=0x04,      //晴间多云（夜晚）
    ATWeatherMostCloudyDay=0x05,        //大部多云（白天）
    ATWeatherMostCloudyNight=0x06,      //大部多云（夜晚）
    ATWeatherOvercast=0x07,             //阴
    ATWeatherShower=0x08,               //阵雨
    ATWeatherThunderShower=0x09,        //雷阵雨
    ATWeatherHail=0x0a,                 //冰雹
    ATWeatherRainLight=0x0b,            //小雨
    ATWeatherRainModerate=0x0c,         //中雨
    ATWeatherRainHeavy=0x0d,            //大雨
    ATWeatherRainStorm=0x0e,            //暴雨
    ATWeatherRainBigHeavy=0x0f,         //大暴雨
    ATWeatherRainSuperStorm=0x10,       //特大暴雨
    ATWeatherRainIce=0x11,              //冻雨
    ATWeatherRainSnow=0x12,             //雨夹雪
    ATWeatherSnowShower=0x13,           //阵雪
    ATWeatherSnowLittle=0x14,           //小雪
    ATWeatherSnowModerate=0x15,         //中雪
    ATWeatherSnowHeavy=0x16,            //大雪
    ATWeatherSnowStorm=0x17,            //暴雪
    ATWeatherDust=0x18,                 //浮尘
    ATWeatherSandBlowing=0x19,          //扬沙
    ATWeatherSandStorm=0x1a,            //沙尘暴
    ATWeatherSandStrongStorm=0x1b,      //强沙尘暴
    ATWeatherFog=0x1c,                  //雾
    ATWeatherHaze=0x1d,                 //霾
    ATWeatherWing=0x1e,                 //风
    ATWeatherWingHigh=0x1f,             //大风
    ATWeatherHurricane=0x20,            //飓风
    ATWeatherTropicalStorm=0x21,        //热带风暴
    ATWeatherTornado=0x22,              //龙卷风
    ATWeatherInvalid=0xFF,              //无效值
};

/**
 * 控制指令
 */
typedef NS_ENUM(NSUInteger,ATControlCmd) {
    ATControlCmdUnknown=0x00,               //未知
    ATControlCmdEmergencyAlarm=0x01,        //紧急报警功能
    ATControlCmdPhoneLocation=0x02,         //找手机功能
    ATControlCmdTakePictures=0x03,          //遥控拍照
    ATControlCmdPlayMusic=0x04,             //播放音乐
    ATControlCmdPauseMusic=0x05,            //暂停音乐播放
    ATControlCmdPreviousMusic=0x06,         //上一首
    ATControlCmdNextMusic=0x07,             //下一首
    ATControlCmdVolumeUp=0x08,              //音量增加
    ATControlCmdVolumeDown=0x09,            //音量降低
    ATControlCmdStopPosition=0x0A,          //停止查找手机
    ATControlCmdStopClock=0x0B,             //停止手机闹钟
    ATControlCmdWeatherSyncRequest=0x0C,    //天气同步请求
    ATControlCmdAnswer=0x1000,              //接听
    ATControlCmdHangup=0x1001,              //挂断
    ATControlCmdMute=0x1002,                //静音
    ATControlCmdVolume=0x1003,              //音量控制
};

/**
 * 数据查询指令
 */
typedef NS_ENUM(NSUInteger,ATDataQueryCmd) {
    
    ATDataQueryCmdAll=0xFF,                         //所有数据
    ATDataQueryCmdMeasureData=0xFE,                 //所有测量数据
    ATDataQueryCmdBuriedPoint=0xF0,                 //埋点数据
    ATDataQueryCmdBuriedPointSummary=0xF1,          //埋点统计数据
    ATDataQueryCmdHeartRate=0x01,                   //常规心率数据
    ATDataQueryCmdSleep=0x02,                       //常规睡眠数据
    ATDataQueryCmdExerciseSpeed=0x03,               //运动配速数据
    ATDataQueryCmdExerciseHeartRate=0x04,           //运动心率数据
    ATDataQueryCmdExerciseCalories=0x05,            //运动卡路里数据
    ATDataQueryCmdRestingHeartRate=0x06,            //静息心率记录
    ATDataQueryCmdStepRecordOfHistory=0x07,         //常规计步明细记录,历史记录
    ATDataQueryCmdStepRecord=0x08,                  //当天常规计步明细记录
    ATDataQueryCmdHeartRateRecord=0x09,             //当天常规心率明细记录
    ATDataQueryCmdCharageRecord=0x0A,               //充电记录
    ATDataQueryCmdBacklightBrightness=0x0B,         //背光亮度查询
    ATDataQueryCmdDialStyle=0x0C,                   //表盘样式
    ATDataQueryCmdExerciseStep=0x0D,                //运动步频数据
    ATDataQueryCmdExerciseSpeedWithImperal=0x0E,    //运动配速数据（英制）
    ATDataQueryCmdHeartRateInterval=0x0F,           //区间心率数据
    ATDataQueryCmdStepOfHour=0x81,                  //每小时 日常总结数据
    ATDataQueryCmdStepOfDay=0x82,                   //每天 日常总结数据
    ATDataQueryCmdExercise=0x83,                    //运动数据
    ATDataQueryCmdBloodOxygen=0x84,                 //血氧数据
    ATDataQueryCmdMeditation=0x85,                  //冥想数据
    ATDataQueryCmdSleepReport=0x86,                 //睡眠数据
    ATDataQueryCmdBloodOxygenRecord=0x87,           //当天血氧测量报告
    ATDataQueryCmdCustomHeartRate=0x88,             //HB 自定义心率数据
    ATDataQueryCmdContinuousBloodOxygen=0x89,       //连续血氧数据
    ATDataQueryCmdStressTestReport=0x8B,            //压力测试报告
    ATDataQueryCmdManualHeartRate=0x8C,             //点测心率数据
    ATDataQueryCmdAppendData=0x8D,                  //附加数据，如站立时长报告
    ATDataQueryCmdTemperatureData=0x8E,             //体温数据
};

/**
 * 云端表盘同步状态
 */
typedef NS_ENUM(NSUInteger,ATDialSyncStatus){
    ATDialSyncStatusUnknown=0x00,        //未知
    ATDialSyncStatusSent=0x01,           //资源已发送
    ATDialSyncStatusVerifySuccess=0x02,  //资源校验成功
    ATDialSyncStatusVerifyFailure=0x03,  //资源校验失败
    ATDialSyncStatusInstallStart=0x04,   //开始安装表盘
    ATDialSyncStatusInstallSuccess=0x05, //表盘安装成功
    ATDialSyncStatusInstallFailure=0x06, //表盘安装失败
    ATDialSyncStatusCancelDownload=0x07, //取消当前推送
    ATDialSyncStatusCancelConfirm=0x08,  //确认取消推送
} ;

/**
 * 手表功能界面-应用列表
 */
typedef NS_ENUM(NSUInteger,ATWatchPage) {
    
    ATWatchPageExercise= 0x00,          //运动界面
    ATWatchPageBloodOxygen=0x01,        //血氧界面
    ATWatchPageHeartRate=0x02,          //心率界面
    ATWatchPageExerciseRecord=0x03,     //运动记录
    ATWatchPagePhonePositioning=0x04,   //寻找手机
    ATWatchPageAlarmClock=0x05,         //闹钟
    ATWatchPageTakePhotos=0x06,         //拍照
    ATWatchPageMeditation=0x07,         //冥想
    ATWatchPageSleepRecord=0x08,        //睡眠记录
    ATWatchPageWeather=0x09,            //天气
    ATWatchPageStopwatch=0x0A,          //秒表
    ATWatchPageMusic=0x0B,              //音乐播放
    ATWatchPageCountdown=0x0C,          //倒计时
    ATWatchPageSetting=0x0D,            //设置
    ATWatchPageRealmelinkIot=0x0E,      //realme link iot
    ATWatchPageMessage = 0x0F,          //消息
    ATWatchPageTools= 0x10,             //工具
    ATWatchPagePressure=0x11,           //压力测试
    ATWatchPageWomenHeealth=0x12,       //女性健康
    ATWatchPageEventReminder=0x13,      //事件提醒
    ATWatchPageFlashlight=0x14,         //手电筒
    ATWatchPageTodayOverview=0xFF,       //今日概述
};


/**
 * 读取类型
 */
typedef NS_ENUM(NSUInteger,ATReadType) {
    ATReadTypeBattery = 0x00         //读取电量百分比
};


/**
 * 配置项查询指令
 */
typedef NS_ENUM(NSUInteger,ATConfigQueryCmd) {
    ATConfigQueryCmdFlash=0x00,                //Flash信息
    ATConfigQueryCmdClock=0x02,                //普通闹钟
    ATConfigQueryCmdIncomingCallRemind=0x03,   //来电提醒设置
    ATConfigQueryCmdSedentaryRemind=0x05,      //久坐提醒设置
    //ATConfigQueryCmdStride=0x07,             //步长设置
    ATConfigQueryCmdVibrationIntensity=0x08,   //振动强度
    ATConfigQueryCmdDisplayBrightness=0x09,    //显示亮度
    ATConfigQueryCmdAlarmClock=0x0A,           //事件闹钟，无标签
    ATConfigQueryCmdSettings=0x0B,             //常规设置
    //ATConfigQueryCmdPairState=0x0C,          //获取系统蓝牙配对状态
    ATConfigQueryCmdExerciseInfo=0x0D,         //运动信息
    ATConfigQueryCmdEventClock = 0x10,         //事件闹钟，带标签
    ATConfigQueryCmdStride=0x0B0C,             //步长信息
    ATConfigQueryCmdNightMode=0x0B10,          //夜间模式
    ATConfigQueryCmdDisturbMode=0x0B20,        //勿扰模式
    ATConfigQueryCmdUserInfo=0x0B4000,         //用户信息
};

/**
 * 闹钟提醒状态
 */
typedef NS_ENUM(NSUInteger,ATEventClockState) {
    ATEventClockStateDisable=0x00,              //关提醒
    ATEventClockStateEnable=0x01,               //开提醒（关闭小睡）
    ATEventClockStateRemove=0x80,               //删除提醒
};

/**
 * 设备状态控制
 */
typedef NS_ENUM(NSUInteger,ATControlState) {
    ATControlStateLoginReset=0x00,              //登录复位
    ATControlStateDisconnect=0x01,              //断开蓝牙连接
    ATControlStateUnbind=0x02,                  //解除绑定
    ATControlStateRestart=0x03,                 //设备重启
    ATControlStateReset=0x04,                   //设备重置
    ATControlStateShutdown=0x05,                //设备关机
    ATControlStatePosition=0x06,                //开始查找手环、设备定位
    ATControlStateStopPosition=0x07,            //停止查找手环
    ATControlStateStopPhonePosition=0x08,       //停止查找手机
    ATControlStateBluetoothBond=0x09,           //发起系统蓝牙配对
};


/**
 * 设备功能列表
 */
typedef NS_ENUM(NSUInteger,ATFunctionType) {
    ATFunctionTypeUnknown=0xFFFF,               //未知
    ATFunctionTypeHeartbeatDataCollect=0x0100,  //心跳数据采集功能
    ATFunctionTypeScreenPowerOn=0X0200,         //抬腕亮屏功能
    ATFunctionTypeManualExerciseMode=0X0300,    //控制进入手动跑步模式
    ATFunctionTypeLowBatteryRemind=0x0400,      //低电量振动提醒
    ATFunctionTypeScrollDisplay=0x0500,         //信息滚动显示开关
    ATFunctionTypeIncomingCall=0x0800,          //来电提醒
    ATFunctionTypeMessageRemind=0x1000,         //消息提醒
};

/**
 * 应用消息类别 AppId
 */
typedef NS_ENUM(NSUInteger,ATAppCategory){
    ATAppCategoryIncomingcall=0x01,             //来电消息
    ATAppCategoryMessage=0x02,                  //应用消息
    ATAppCategoryWeather=0x03,                  //天气消息
    ATAppCategoryMusic=0x04,                    //音乐消息
    ATAppCategoryIotDevice=0x05,                //iOT设备消息
};

/**
 * 图片类型
 *
 * 来电 288 * 128,
 * 天气 320 * 32,
 * 音乐 1000 * 28,
 * iot设备 120*120,
 * 消息提醒 Message 288 * 440 ;
 */
typedef NS_ENUM(NSUInteger,ATImageType) {
    ATImageTypeIncomingCall=0x01, //来电消息图片，
    ATImageTypeWeather=0x02,      //天气城市图片
    ATImageTypeMusic=0x03,        //音乐图片
    ATImageTypeIotDevice=0x04,    //iOT设备图片
    ATImageTypeMessage=0x05,      //应该消息图片
};

/**
 * 文件传输协议，指令
 */
typedef NS_ENUM(NSUInteger,ATFileCmd){
    ATFileCmdProgress=0x00,             //文件进度
    ATFileCmdDevGotFileList=0x20,       //设备发起获取文件列表
    ATFileCmdAppGotFileList=0x40,       //App发起获取文件列表
    ATFileCmdDevGotFile=0x21,           //设备发起获取文件内容
    ATFileCmdAppGotFile=0x41,           //App发起获取文件内容
    ATFileCmdDevPushFile=0x22,          //设备推送文件
    ATFileCmdAppPushFile=0x42,          //App推送文件
    ATFileCmdDevFileConfirm=0x23,       //设备发送文件块确认
    ATFileCmdAppFileConfirm=0x43,       //App发送文件块确认
    ATFileCmdDevCancel=0x24,            //设备取消文件传输
    ATFileCmdAppCancel=0x44,            //App取消文件传输
    ATFileCmdDevFileCompleted=0x25,     //设备发送文件完成通知
    ATFileCmdAppFileCompleted=0x45,     //App发送文件完成通知
};

/**
 * 文件传输协议 状态码
 */
typedef NS_ENUM(NSUInteger,ATFileRespState) {
    ATFileRespStateSuccess=0x00,            //成功
    ATFileRespStateNotFound=0x01,           //没有对应的资源文件
    ATFileRespStateSystemBusy=0x02,         //系统繁忙/文件任务传输中
    ATFileRespStateParameterError=0x03,     //参数错误
    ATFileRespStateVerifyError=0x04,        //校验失败
    ATFileRespStateFileException=0x05,      //文件读写错误
    ATFileRespStateCancel=0x06,             //设备端取消
    ATFileRespStateCancelByApp=0x07,        //App端主动取消
    ATFileRespStateExisted=0x0A,            //资源文件已存在

};

/**
 * 文件传输协议 文件类型
 */
typedef NS_ENUM(NSUInteger,ATFileCategory) {
    ATFileCategoryUnknown=0x00,
    ATFileCategoryLog=0x01,                 //Log文件
    ATFileCategoryMusicBackground=0x02,     //音乐背景
    ATFileCategoryCallerAvatar=0x03,        //来电头像
    ATFileCategoryWatchFace=0x004,          //表盘
    ATFileCategoryAGPS=0x05,                //AGPS数据
    ATFileCategoryGPS=0x06,                 //GPS数据
    ATFileCategoryIotIcon=0x07,             //iot设备icon
    ATFileCategoryIotJson=0x08,             //iot设备json
    ATFileCategoryLog2=0x09,                //Log文件2

};

/**
 * iot设备类型
 */
typedef NS_ENUM(NSUInteger,ATIotCategory) {
    ATIotCategoryUnknown=0x00,              //未定义
    ATIotCategoryHeadset=0x01,              //耳机类
    ATIotCategoryLightBulb=0x02,            //灯泡类
    ATIotCategorySocket=0x03,               //插座
    ATIotCategoryAirConditioners=0x04,      //空调
    ATIotCategorySpeaker=0x05,              //音箱
    ATIotCategoryScale=0x06,                //智能秤
    ATIotCategoryCamera=0x07,               //摄像头
    ATIotCategoryCleanRobot=0x09,           //扫地机器人
};


/**
 * 一级页面
 */
typedef NS_ENUM(NSUInteger,ATWatchHotkey) {
    ATWatchHotkeyActivity=0x00,              //今日活动
    ATWatchHotkeySleep=0x01,                 //今日睡眠
    ATWatchHotkeyHeartRate=0x02,             //今日心率
    ATWatchHotkeyWeather=0x03,               //今日天气
    ATWatchHotkeyMusic=0x04,                 //音乐
    ATWatchHotkeyIot=0x05,                   //realme link iot
};

/**
 * 0x32 事件提醒重复类型
 */
typedef NS_ENUM(NSUInteger,ATRepeatType) {
    ATRepeatTypeOnce=1,                  //单次重复
    ATRepeatTypeEveryDay= 1<< 1,         //每日重复
    ATRepeatTypeEveryMonth= 1<< 2,       //每月重复
    ATRepeatTypeEveryYear= 1<< 3,        //每年重复
    ATRepeatTypeMonday=1<< 4,            //星期一
    ATRepeatTypeTuesday=1<< 5,           //星期二
    ATRepeatTypeWednesday=1<< 6,         //星期三
    ATRepeatTypeThursday=1 << 7,         //星期四
    ATRepeatTypeFriday=1 << 8,           //星期五
    ATRepeatTypeSaturday=1 << 9,         //星期六
    ATRepeatTypeSunday=1 << 10,          //星期日
    ATRepeatTypeEveryWeek=0x7F0,         //每周重复
    ATRepeatTypeWeekend = 0x600,         //每周重复
    ATRepeatTypeWorkingDay= 0x1F0,       //工作日重复

};

/**
 * 事件闹钟同步状态
 */
typedef NS_ENUM(NSUInteger,ATClockSyncState) {
    ATClockSyncStateUpdate=0x00,            //更新
    ATClockSyncStateAdd=0x01,               //新增
    ATClockSyncStateRemove=0x02,            //删除指定闹钟
    ATClockSyncStateRemoveAll=0x03          //删除所有闹钟
};


/**
 * 闹钟类型
 */
typedef NS_ENUM(NSUInteger,ATClockType) {
    ATClockTypeNormal=0x00,                //普通闹钟
    ATClockTypeEvent=0x01,                 //事件闹钟
};

/**
 * 睡眠状态
 */
typedef NS_ENUM(NSUInteger,ATSleepState) {
    /**
     * 清醒
     */
    ATSleepStateAwake = 0x01,

    /**
     * 浅睡
     */
    ATSleepStateLightSleep = 0x02,

    /**
     * 深睡
     */
    ATSleepStateDeepSleep=0x03,

    /**
     * 眼动
     */
    ATSleepStateEyeMovement=0x04,
};


/**
 * 步数记录类型
 */
typedef NS_ENUM(NSUInteger,ATStepType) {
    
    /**
     * 实时或当前步数汇总数据
     */
    ATStepTypeSummary = 0x00,
    
    /**
     * 小时数据
     */
    ATStepTypeHourly = 0x01,
    
    /**
     * 分钟数据
     */
    ATStepTypeMinute = 0x02,
};

#endif /* ATSettingProfiles_h */
