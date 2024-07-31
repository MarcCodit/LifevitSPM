//
//  ATUnitItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/29.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBDeviceSetting.h"
#import "ATSettingProfiles.h"
#import "ATTargetItem.h"
#import "LSBluetoothManagerProfiles.h"
#import "ATWatchFaceElement.h"

/**
 * 设备配置项类型
 */
typedef NS_ENUM(NSUInteger,ATConfigType){
    
    ATConfigTypeTemperature = 0x01,             //温度单位
    ATConfigTypeVibration =   0x02,             //振动强度
    ATConfigTypeBrightness = 0x03,              //亮度显示
    ATConfigTypeHotkey = 0x04,                  //快捷页面设置
    ATConfigTypeUniversalUnit = 0x05,           //长度、体重、身高单位
    ATConfigTypeLengthUnit = 0x06,              //单独的长度单位设置
    ATConfigTypeWeightUnit = 0x07,              //单独的体重单位设置
    ATConfigTypeHeightUnit = 0x08,              //单独的身高单位设置
    ATConfigTypeWeekStart = 0x09,               //星期开始
    ATConfigTypeWatchFace = 0x0A,               //表盘显示元素设置
    ATConfigTypeTime = 0x0B,                    //时间设置
    ATConfigTypeSleepWakeup= 0x0C,              //浅睡唤醒设置
    ATConfigTypeWalkStrid = 0x0D,               //行走步长设置
    ATConfigTypeRunStrid = 0x0E,                //跑走步长设置
    ATConfigTypeGoalMain = 0x0F,                //主目标设置
    ATConfigTypeGoalStep = 0x10,                //步数目标设置
    ATConfigTypeGoalDistance= 0x11,             //距离目标设置
    ATConfigTypeGoalCalories=0x12,              //卡路里目标设置
    ATConfigTypeNightMode=0x13,                 //夜间模式设置
    ATConfigTypeDisturb=0x14,                   //勿扰模式设置
    ATConfigTypeHeartRate=0x15,                 //心率预警
    ATConfigTypeSedentary=0x16,                 //久坐提醒
    ATConfigTypeLanguage=0x17,                  //语言设置
    ATConfigTypeHeartRateSwitch=0x18,           //智能心率开关
    ATConfigTypeUserInfo=0x19,                  //用户信息
    ATConfigTypeBloodOxygenMonitor = 0x20,      //连续血氧监测开关设置
    ATConfigTypeMessageRemind=0x21,             //消息提醒开关
    ATConfigTypeMusicControl=0x22,              //音乐控制开关
    ATConfigTypeDrinkWater=0x23,                //喝水提醒开关
    ATConfigTypeMeditation=0x24,                //冥想提醒开关
    ATConfigTypeHeartRateSwitchOf24=0x25,       //24小时心率检测开关
    ATConfigTypeTargetRemind=0x26,              //目标提醒开关
    ATConfigTypeSleepQuality=0x27,              //睡眠呼吸质量开关
    ATConfigTypeFemaleHealth=0x28,              //女性健康数据设置
    ATConfigTypePeriodRemind=0x29,              //经期提醒开关
    ATConfigTypePregnancyRemind=0x2A,           //易孕期提醒
    ATConfigTypeExerciseTarget=0x2B,            //运动目标设置信息
    ATConfigTypeExerciseMinute=0x2C,            //锻炼分钟数目标设置
    ATConfigTypeActiveHours=0x2D,               //活跃小时目标设置
    ATConfigTypeWalkStep=0x2E,                  //走动提醒步数阈值
    ATConfigTypeCustomHeartRate=0x2F,           //达到保存条件的心率值
    ATConfigTypeWatchPage= 0x30,                //应用列表
    ATConfigTypeWatchHotKey= 0x31,              //一级页面
    ATConfigTypePhonePosition= 0x32,            //手环查找手机开关状态
    ATConfigTypeWatchFaceSummary= 0x33,         //表盘安装能力概要描述
    ATConfigTypeWatchFaceRemove= 0x34,          //表盘删除
    ATConfigTypeSleepPlan= 0x35,                //睡眠计划

    ATConfigTypeSportTimeTarget = 0x36,         //运动时长
    ATConfigTypeSportHrWarning=0x37,            //运动心率预警
    ATConfigTypeTimeFormat=0x38,                // 时间显示格式
    ATConfigTypeSleepRemind=0x39,               //入睡提醒
    ATConfigTypeHeartRateDetection=0x3a,        //心率监测周期和心率区间
    ATConfigTypeBrightnessTime=0x3b,            //亮屏时长
    ATConfigTypeTemperatureControl=0x3c,        //体温检测开关
    ATConfigTypeExerciseMode=0x3d,              //运动模式列表
    ATConfigTypeTakePictureControl=0x3e,        //拍照控制开关
    ATConfigTypeBrightScreen=0x3f,              //抬腕亮屏控制开关
    
    ATConfigTypeTemperatureCompensation=0x80,   //温度补偿

} ;


/**
 * 表盘内容显示元素
 */
typedef NS_ENUM(NSUInteger,ATDisplayItem) {
    ATDisplayItemTime=0x01,                 //时间
    ATDisplayItemBluetooth=0x02,            //蓝牙连接状态
    ATDisplayItemPower=0x04,                //电量
    ATDisplayItemStep=0x08,                 //步数
    ATDisplayItemDate=0x10,                 //日期
    ATDisplayItemWeek=0x20,                 //星期
    ATDisplayItemMonth=0x0040,              //月份
    ATDisplayItemHeartRate=0x0080,          //最近心率值
    ATDisplayItemExerciseMinutes=0x0100,    //锻炼分钟数
    ATDisplayItemActiveHours=0x0200,        //活跃小时数
};


/**
 * 手环语言编码
 */
typedef NS_ENUM(NSUInteger,ATLanguageCode) {
    
    ATLanguageCodeChinese=0x00,     //中文(简体)
    ATLanguageCodeEnglish=0x01,     //英语
};


@interface ATConfigItem : IBDeviceSetting


/**
 * 配置项类型
 */
@property(nonatomic,assign) ATConfigType type;

/**
 * 配置项数
 */
-(NSUInteger)countOfItem;

/**
 * 对象信息
 */
-(NSDictionary *_Nullable)toString;
@end



#pragma mark - ATTemperatureUnit

/**
 * 温度单位设置
 */
@interface ATTemperatureUnit : ATConfigItem

/**
 * 单位类型
 * 0x00=摄氏度
 * 0x01=华氏
 */
@property(nonatomic,assign)  int unit;

-(instancetype)initWithData:(NSData *)data;
@end


#pragma mark - ATBloodOxygenMonitor
/**
 * 血氧监测开关
 */
@interface ATBloodOxygenMonitor : ATConfigItem

@property(nonatomic,assign)  BOOL enable;

/**
 * 监测模式
 * 0x00=关闭，
 * 0x01=连续血氧
 * 0x02=点测模式
 * 0x03=5分钟检测
 */
@property(nonatomic,assign)  int mode;

-(instancetype _Nonnull )initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATBrightness

@interface ATBrightness : ATConfigItem

/**
 * 亮度百分比
 *
 * 值范围:0< n(整数)< 11，比如5表示 亮度50%
 *
 */
@property(nonatomic,assign)  int value;

-(instancetype _Nonnull )init;

-(instancetype _Nonnull )initWithData:(NSData * _Nullable)data;

@end


#pragma mark - ATHotkeyPage

@interface ATHotkeyPage : ATConfigItem
/**
 * 当前页面
 */
@property(nonatomic,assign)  ATWatchPage page;

-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;

@end


#pragma mark - ATMeasureUnit

@interface ATMeasureUnit : ATConfigItem

/**
 * 单位
 * 0x00 = 公制(公里/公斤/厘米)
 * 0x01 = 英制(英里/磅/英尺)
 */
@property(nonatomic,assign)  int unit;

/**
 * 单位设置类型，默认为0x05
 *
 * 0x05 = 长度/体重/身 高单位设置
 * 0x06 = 单独的长度单位设置
 * 0x07 = 单独的体重单位设置
 * 0x08 = 单独的身高单位设置
 */
@property(nonatomic,assign)  int unitType;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data tag:(NSUInteger)tag;
@end


#pragma mark - ATStrideInfo

@interface ATStrideInfo : ATConfigItem

/**
 * 跑步步长，单位CM
 */
@property(nonatomic,assign)  int runningStride;

/**
 * 行走步长，单位CM
 */
@property(nonatomic,assign)  int walkingStride;


-(instancetype _Nonnull)init;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATVibrationIntensity

/**
 * 震动强度设置
 */
@interface ATVibrationIntensity : ATConfigItem

/**
 * 强度等级
 *
 * 0x01:一档(低)
 * 0x02:二档(中)
 * 0x03:三档(高)
 */
@property(nonatomic,assign)  int level;

-(instancetype _Nonnull)init;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATWatchFace

/**
 * 表盘内容显示元素设置
 */
@interface ATWatchFace : ATConfigItem

/**
 * 表盘序号，默认为1
 */
@property(nonatomic,assign) int index;

/**
 * 功能字段标志位
 */
@property(nonatomic,assign) int flag;

/**
 * 表盘类型
 * 0x00 = 本地表盘
 * 0x01 = 相册表盘
 * 0x02 = 云端表盘
 */
@property(nonatomic,assign) int typeOfWatchFace;

/**
 * 显示项内容 参考ATDisplayItem定义
 */
@property(nullable,nonatomic,strong) NSArray *items;


/**
 * 内置表盘显示元素设置项 参考ATWatchFaceElement定义
 */
@property(nullable,nonatomic,strong) NSArray *elements;


-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATWeekStart

/**
 * 周开始日设置
 */
@interface ATWeekStart : ATConfigItem

/**
 * 0x00 = 星期六
 * 0x01 = 星期日
 * 0x02 = 星期一
 */
@property(nonatomic,assign)  int week;
@end


#pragma mark - ATTime

@interface ATTime : ATConfigItem

/**
 * UTC时间
 */
@property(nonatomic,assign)  int utc;

/**
 * 时区，参考设备端的时区定义
 */
@property(nonatomic,assign)  int timeZone;

/**
 * 时间制式
 */
@property(nonatomic,assign)ATTimeFormat format;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATSleepWakeup

@interface ATSleepWakeup : ATConfigItem

/**
 * 唤醒开关
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 提前唤醒时间设置，单位分钟
 */
@property(nonatomic,assign)  int wakeupTime;
@end

#pragma mark - ATTarget

@interface ATTarget : ATConfigItem

/**
 * 主要目标，默认为步数
 */
@property(nonatomic,assign)  ATEncourageType mainGoal;

/**
 * 目标项
 */
@property(nullable,nonatomic,strong)  NSArray<ATTargetItem *> *items;
@end

#pragma mark - ATDisturbMode

@interface ATDisturbMode : ATConfigItem

/**
 * 勿扰模式是否生效状态标志位
 */
@property(nonatomic,assign) BOOL status;

/**
 * 自动勿扰模式是否生效状态标志位
 */
@property(nonatomic,assign) BOOL autoState;

/**
 * 自动勿扰模式生效的开始时间段，格式：12:09
 */
@property(nullable,nonatomic,strong) NSString *startTime;

/**
 * 自动勿扰模式生效的结束始时间段,格式：13:09
 */
@property(nullable,nonatomic,strong) NSString *endTime;

/**
 * 在自动勿扰模式下，允许使用或设置禁用的设备功能列表
 */
@property(nullable,nonatomic,strong) NSArray *functions;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;

@end


#pragma mark - ATNightMode

@interface ATNightMode : ATConfigItem

/**
 * 夜间模式生效状态
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 自动夜间模式控制开关
 */
@property(nonatomic,assign) BOOL autoState;

/**
 * 自动夜间模式生效开始时间
 */
@property(nullable,nonatomic,strong) NSString *startTime;

/**
 * 自动夜间夜间模式生效截止时间
 */
@property(nullable,nonatomic,strong) NSString *endTime;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;

@end


#pragma mark - ATNapRemind

/**
 * 小睡提醒设置项
 */
@interface ATNapRemind : ATConfigItem

/**
 * 提醒开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 小睡提醒时间，单位分钟
 */
@property(nonatomic,assign)  int napTime;

@end


#pragma mark - ATMessageItem

/**
 * 消息提醒设置项
 */
@interface ATMessageItem : ATConfigItem

/**
 * 消息提醒类型
 */
@property(nonatomic,assign)ATMessageRemindType msgType;

/**
 * 消息提醒开关
 */
@property(nonatomic,assign)BOOL enable;
@end


#pragma mark - ATHeartRateAlert

@interface ATHeartRateAlert : ATConfigItem

/**
 * 启动最低与最高心率预警功能
 */
@property(nonatomic,assign)BOOL enableAll;

/**
 * 启动最低心率预警功能
 */
@property(nonatomic,assign)BOOL enableMinAlert;

/**
 * 启动最高心率预警功能
 */
@property(nonatomic,assign)BOOL enableMaxAlert;

/**
 * 最小心率
 */
@property(nonatomic,assign)NSUInteger minHeartRate;

/**
 * 最大心率
 */
@property(nonatomic,assign)NSUInteger maxHeartRate;


-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATHeartRateSwitch

@interface ATHeartRateSwitch : ATConfigItem

/**
  * 0x00:关闭心率检测
  * 0x01:开启心率检测
  * 0x02:开启智能心率检测
  */
@property(nonatomic,assign)NSUInteger state;

-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATUserInfo

@interface ATUserInfo : ATConfigItem

/**
 * 身高,单位M 最大值是2.5m,stride=身高*0.4
 */
@property(nonatomic,assign) float height ;

/**
 * 体重,最大值是300kg
 */
@property(nonatomic,assign) float weight ;

/**
 * 用户年龄
 */
@property(nonatomic,assign)  int age;

/**
 * 用户性别
 */
@property(nonatomic,assign) LSUserGender userGender;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATReminderSwitch

/**
 * 提醒开关
 */
@interface ATReminderSwitch : ATConfigItem

/**
 * 提醒类型
 */
@property(nonatomic,assign)ATEventReminderType reminderType;

/**
 * 提醒开关
 * 0x01 = 打开
 * 0x00 = 关闭
 */
@property(nonatomic,assign)NSUInteger state;

-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data configType:(ATConfigType)type;
@end

#pragma mark - ATSleepQuality

/**
 * 睡眠呼吸质量开关
 */
@interface ATSleepQuality : ATConfigItem

/**
 * 提醒开关
 * 0x01 = 打开
 * 0x00 = 关闭
 */
@property(nonatomic,assign)NSUInteger state;
@end


#pragma mark - ATWomenHealth

/**
 * 女性健康
 */
@interface ATWomenHealth : ATConfigItem

/**
 * 经期长度,单位天,范围 3~15
 */
@property(nonatomic,assign) int menstrualLen;

/**
 * 经期周期,单位天,范围 17~60
 */
@property(nonatomic,assign) int menstrualCycle;

/**
 * 最近一次经期开始时间,UTC，单位秒
 */
@property(nonatomic,assign) int lastMenstrualDate;

/**
 * 最近一次经期结束时间,UTC,单位秒
 */
@property(nonatomic,assign) int endMenstrualDate;

/**
 * 女性健康提醒开关
 */
@property(nonatomic,assign) BOOL enable;


/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATMenstrualRemind
/**
 * 女性经期提醒
 */
@interface ATMenstrualRemind : ATConfigItem

/**
 * 提醒开关
 */
@property(nonatomic,assign)BOOL enable;

/**
 * 提醒提前天数
 */
@property(nonatomic,assign) int advanceDays;

/**
 * 提醒时间，格式HH:MM
 */
@property(nonatomic,strong) NSString * _Nullable time;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATPregnancyRemind

/**
 * 女性孕期提醒
 */
@interface ATPregnancyRemind : ATConfigItem

/**
 * 提醒开关
 */
@property(nonatomic,assign)BOOL enable;

/**
 * 提醒提前天数
 */
@property(nonatomic,assign) int advanceDays;

/**
 * 提醒时间，格式HH:MM
 */
@property(nonatomic,strong) NSString * _Nullable time;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end



#pragma mark - LS456 新增

#pragma mark - ATExerciseMinutes

/**
 * 锻炼分钟数目标设置
 */
@interface ATExerciseMinutes : ATConfigItem

/**
 * 锻炼分钟数目标,单位分钟，默认30分钟
 */
@property(nonatomic,assign) int targetMin;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATActiveHours

/**
 * 活跃小时目标设置
 */
@interface ATActiveHours : ATConfigItem

/**
 * 活跃小时目标,单位小时，范围6~12
 */
@property (nonatomic, assign) int targetHour;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATWalkStep


/**
 * 走动提醒步数阈值
 */
@interface ATWalkStep : ATConfigItem

/**
 * 步数，在自然小时内，若达不到设定的步数，则触发走动提醒
 */
@property (nonatomic, assign) int targetStep;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATCustomHeartRate


/**
 * 达到保存条件的心率值
 */
@interface ATCustomHeartRate : ATConfigItem

/**
 * "非运动状态" 并且 "非睡眠状态"下
 *  检测10秒内心率平均值大于或等于n值时保存当前心率值及时间（n默认为100，app可以设置n值）
 */
@property (nonatomic, assign) int heartRate;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end

#pragma mark - LS453 新增

#pragma mark - ATExerciseTarget


/**
 * 运动目标设置信息
 */
@interface ATExerciseTarget : ATConfigItem

/**
 * 运动类型
 */
@property(nonatomic,assign)ATExerciseType exerciseType;

/**
 * 目标类型
 */
@property(nonatomic,assign)ATEncourageType targetType;

/**
 * 目标值
 */
@property(nonatomic,assign)int targetValue;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATExerciseInfo

/**
 * 设备当前选择的运动类型及排序信息
 */
@interface ATExerciseInfo : ATConfigItem

/**
 * 运动类型总数
 */
@property(nonatomic,assign) int count;

/**
 * 运动项,已排序 参考ATExerciseType的定义
 */
@property(nonatomic,strong,nullable) NSArray *exerciseItems;

-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data;

/**
 * 手环8运动类型返回
 */
-(instancetype _Nonnull )initWithData:(NSData *_Nullable)data tag:(NSUInteger)tag;
@end


#pragma mark - ATMenuPage

@interface ATMenuPage : ATConfigItem

/**
 * 页面类型，默认为应用列表
 *
 * 0x00 应用列表
 * 0x01 一级页面
 */
@property(nonatomic,assign)  int pageType;

/**
 * 已排序的应用列表或一级应用列表集合
 *
 * pageType = 0x00 参考ATWatchPage定义
 *
 * pageType = 0x01 参考ATWatchHotkey定义
 */
@property(nullable,nonatomic,strong)  NSArray *pages;

/**
 * 设备支持的应用列表
 */
@property(nullable,nonatomic,strong) NSArray *supportPages;

-(instancetype _Nonnull)initWithData:(NSData * _Nullable )data configType:(ATConfigType)type;
@end

#pragma mark - ATWatchFaceSummary

/**
 * 表盘信息配置概要说明
 */
@interface ATWatchFaceSummary : ATConfigItem

/**
 * 可安装的静态表盘个数
 */
@property(nonatomic,assign) int countOfStatic;

/**
 * 可安装的静态表盘索引号
 */
@property(nonatomic,strong,nullable)NSArray *staticIndex;

/**
 * 可安装的动态表盘个数
 */
@property(nonatomic,assign) int countOfDynamic;

/**
 * 可安装的动态表盘索引号
 */
@property(nonatomic,strong,nullable) NSArray *dynamicIndex;

/**
 * 不可删除的表盘个数
 */
@property(nonatomic,assign) int countOfFixed;

/**
 * 不可删除的表盘索引号
 */
@property(nonatomic,strong,nullable) NSArray *fixedIndex;

/**
 * 当前索引
 */
@property(nonatomic,assign)  int currentIndex;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATPhonePosition

@interface ATPhonePosition : ATConfigItem

/**
 * 手环查找手机开关状态
 */
@property(nonatomic,assign) BOOL enable;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATWatchFaceRemove

/**
 * 表盘删除设置项
 */
@interface ATWatchFaceRemove : ATConfigItem

/**
 * 待删除的表盘项
 */
@property(nonatomic,strong,nullable)NSArray <ATWatchFaceItem *> *removeItems;
@end


#pragma mark - ATSleepPlan

/**
 * 睡眠计划
 * 0x35
 */
@interface ATSleepPlan : ATConfigItem

/**
 * 计划入睡时间，格式HH:MM
 */
@property(nonatomic,strong,nullable) NSString *bedTime;

/**
 * 计划起床时间，格式HH:MM
 */
@property(nonatomic,strong,nullable) NSString *wakeupTime;

/**
 * 计划睡眠时长，min，分钟为单位，10代表10分钟
 */
@property(nonatomic,assign) int sleepTime;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end

#pragma mark - ATBrightnessTime

@interface ATBrightnessTime : ATConfigItem

/**
 * 亮屏时长，单位秒
 *
 */
@property(nonatomic,assign)  int time;

-(instancetype _Nonnull)init;

-(instancetype _Nonnull)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATMessageSwitches

@interface ATMessageSwitches : ATConfigItem

/**
 * 消息提醒设置开关
 */
@property(nonatomic,strong,nullable)  NSArray <ATMessageItem *> *items;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATHeartRateDetection

@interface ATHeartRateDetection : ATConfigItem

/**
 * 心率监测周期（间隔）（分钟）
 * 0 代表实时心率监测模式
 */
@property(nonatomic,assign)  int  duration;

/**
 * 心率区间阈值L0
 */
@property(nonatomic,assign)  int level0;

/**
 * 心率区间阈值L1
 */
@property(nonatomic,assign)  int level1;

/**
 * 心率区间阈值L2
 */
@property(nonatomic,assign)  int level2;

/**
 * 心率区间阈值L3
 */
@property(nonatomic,assign)  int level3;

/**
 * 心率区间阈值L4
 */
@property(nonatomic,assign)  int level4;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end

#pragma mark - ATSleepRemind

/**
 * 入睡提醒
 */
@interface ATSleepRemind : ATConfigItem
/**
 * 提醒开关
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 提醒时间
 */
@property(nonatomic,strong,nullable)  NSString *time;

/**
 * 提醒周期
 */
@property(nonatomic,strong,nullable)  NSArray<NSNumber*> *days;

/**
 * 反向解析，创建对象
 */
-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end


#pragma mark - ATDrinkItem

/**
 * 喝水提醒设置项
 */
@interface ATDrinkItem : ATConfigItem

/**
 * 提醒开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 提醒开始时间
 */
@property(nullable,nonatomic,strong) NSString *startTime;

/**
 * 提醒结束时间
 */
@property(nullable,nonatomic,strong) NSString *endTime;

/**
 * 提醒频率
 */
@property(nonatomic,assign)  int frequency;

/**
 * 提醒重复时间
 */
@property(nullable,nonatomic,strong) NSArray *repeatDay;

/**
 * 勿扰模式设置
 */
@property(nullable,nonatomic,strong) ATDisturbMode *disturbMode;

-(instancetype _Nonnull)initWithData:(NSData * _Nullable)data;
@end



#pragma mark - ATTemperatureState

/**
 * 体温检测开关设置
 */
@interface ATTemperatureState : ATConfigItem

/**
 * 开关状态
 */
@property(nonatomic,assign)  BOOL state;
@end

#pragma mark - ATLanguageInfo

/**
 * 语言信息
 */
@interface ATLanguageInfo : ATConfigItem

/**
 * 语言编码
 */
@property(nonatomic,assign)  ATLanguageCode code;

-(instancetype)initWithData:(NSData *)data;
@end


