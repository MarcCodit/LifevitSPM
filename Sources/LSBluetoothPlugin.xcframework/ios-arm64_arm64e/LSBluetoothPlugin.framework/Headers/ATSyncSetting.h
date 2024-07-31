//
//  ATSyncSetting.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "IBDeviceSetting.h"
#import "ATSettingProfiles.h"
#import "ATAlarmClockItem.h"
#import "ATAutoRecognitionItem.h"
#import "ATDeviceData.h"
#import "ATWeatherItem.h"
#import "ATSedentaryItem.h"
#import "ATHeartRateZoneItem.h"
#import "LSBluetoothManagerProfiles.h"
#import "ATFileUpdateMsg.h"
#import "ATConfigItem.h"
#import "ATEventClockItem.h"
#import "ATReminderItem.h"
#import "ATConfigItem.h"
#import "ATHeartRateItem.h"
#import "ATFileData.h"
#import "ATIotDevice.h"
#import "ATIotInfo.h"

/**
 * 允许设置的最大闹钟提醒数量
 */
#define MAX_NUMBER_OF_ALARM_CLOCK 6
#define ENCOURAGE_GOAL_OF_M2 0x70
#define ENCOURAGE_GOAL_OF_M5 0xA5
#define ACTIVITY_TRACKER_OF_M5 @"M5"
#define MAX_NUMBER_OF_SEDENTARY 15
#define MAX_PACKET_LEN 109

/**
 * 手表、手环设备功能同步设置
 */
@interface ATSyncSetting : IBDeviceSetting

/**
 * 星期数组转换
 */
-(NSArray *_Nonnull)toWeekDay:(NSUInteger)value;


/**
 * 重复方式转星期
 */
-(NSArray *_Nonnull)toWeekDayWithRepeatType:(NSUInteger)value;

/**
 * 对象信息
 */
-(NSDictionary *_Nullable)toString;
@end


#pragma mark - ATAlarmClockSetting

/**
 * 闹钟设置，不带标题
 */
@interface ATAlarmClockSetting : ATSyncSetting
/**
 * 闹钟提醒功能总开关
 */
@property(nonatomic,assign) BOOL statusOfAll;

/**
 * 闹钟提醒列表
 */
@property(nonatomic,strong)  NSArray<ATAlarmClockItem *> * _Nonnull clockItems;
@end


#pragma mark - ATEventClockSetting

/**
 * 闹钟或事件提醒设置，带标题内容
 */
@interface ATEventClockSetting : ATSyncSetting

/**
 * 闹钟同步状态 更新、或新增、或删除
 */
@property(nonatomic,assign)ATClockSyncState syncState;

/**
 * 闹钟个数
 */
@property(nonatomic,assign)NSUInteger count;

/**
 * 闹钟类型，默认为普通闹钟
 */
@property(nonatomic,assign)ATClockType clockType;

/**
 * 当前返回的闹钟列表数量
 */
@property(nullable,nonatomic,strong) NSArray<ATEventClockItem *> *clocks;

/**
 * 总开关
 */
@property(nonatomic,assign)BOOL stateOfAll;

-(instancetype)init;

-(instancetype)initWithData:(NSData *)data forCmd:(NSUInteger)itemCmd;
@end


#pragma mark - ATExerciseModeSetting

/**
 * 运动模式自动识别设置
 */
@interface ATExerciseModeSetting :  ATSyncSetting

@property(nonatomic,strong)  NSArray<ATAutoRecognitionItem *> * _Nullable autoRecognitionItems;
@end

#pragma mark - ATDialStyleSetting

/**
 * 表盘切换/表盘排序设置
 */
@interface ATDialStyleSetting : ATSyncSetting

/**
 * 当前选择的表盘索引
 * 1~12
 */
@property(nonatomic,assign)NSUInteger dialIndex;

/**
 * 设置可选的表盘顺序与切换列表
 */
@property(nonatomic,strong) NSArray * _Nullable dialStyles;
@end


#pragma mark - ATDistanceFormatSetting

/**
 * 距离单位设置
 */
@interface ATDistanceFormatSetting : ATSyncSetting

/**
 * 距离
 */
@property(nonatomic,assign)ATDistanceFormat distanceFormat;
@end


#pragma mark - ATTimeFormatSetting

/**
 * 时间显示单位设置
 */
@interface ATTimeFormatSetting : ATSyncSetting
/**
 * 时间显示单位
 */
@property(nonatomic,assign)ATTimeFormat timeFormat;
@end


#pragma mark - ATEncourageGoalSetting

/**
 * 手表、手环鼓励目标设置
 */
@interface ATEncourageGoalSetting : ATSyncSetting

/**
 * 鼓励目标提醒设置开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 目标类型
 */
@property(nonatomic,assign) ATEncourageType targetType;


/**
 * 目标值
 * 步数,精确度：1.0，范围1000~30000
 * 卡路里，单位：Kcal,精确度：0.1,范围500~20000
 * 距离，单位：米,精确度：1.0
 * 站立时长,单位:分钟,范围60~24*60
 * 运动时长,单位:分钟,范围2~1440
 */
@property(nonatomic,assign) float targetValue;
@end


#pragma mark - ATExerciseInfoSetting

/**
 * 运动参数设置
 */
@interface ATExerciseInfoSetting : ATSyncSetting

/**
 * 配速，配速是指跑(走)完1km 需要多久时间， 精确到秒，例如256表示4’16’’
 */
@property(nonatomic,assign) short speed;

/**
 * 距离，单位 米（M）
 */
@property(nonatomic,assign)  int distance;
@end


#pragma mark - ATExerciseNotifyConfirm

/**
 * 运动通知确认
 */
@interface ATExerciseNotifyConfirm : ATSyncSetting

/**
 * 运动通知
 */
@property(nonatomic,strong) ATExerciseNotify * _Nullable notify;

/**
 * 手机GPS状态
 */
@property(nonatomic,assign) ATGpsStatus gpsStatus;
@end

#pragma mark - ATExerciseRequest

/**
 * App发起的运动请求申请
 */
@interface ATExerciseRequest : ATSyncSetting

/**
 * 运动模式
 */
@property(nonatomic,assign)  ATExerciseType exerciseType;

/**
 * 运动状态
 * 0x00：开始运动
 * 0x01: 结束运动
 */
@property(nonatomic,assign)  BOOL enable;
@end

#pragma mark - ATUserInfoSetting

/**
 * 手表、手环用户信息更新
 */
@interface ATUserInfoSetting : ATSyncSetting

/**
 * Device's MAC
 */
@property(nullable,nonatomic,strong)NSString *macAddress;

/**
 * Device' ID
 */
@property(nullable,nonatomic,strong)NSString *deviceId;

/**
 * 产品型号，如M5或M2
 */
@property(nullable,nonatomic,strong)NSString *productModel;

/**
 * 身高,单位M
 * 最大值是2.5m,stride=身高*0.4
 */
@property(nonatomic,assign) float height ;

/**
 * 体重,单位kg
 * 最大值是300kg
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

/**
 * 周目标类型
 */
@property(nonatomic,assign) ATEncourageType targetState;

/**
 * 周目标值
 */
@property(nonatomic,assign) float targetValue;

/**
 * 手环切换前步数
 */
@property(nonatomic,assign)  int previousSteps;

/**
 * 是否清空历史数据
 */
@property(nonatomic,assign) BOOL isClearData;

/**
 * 心率检测开关
 */
@property(nonatomic,assign)BOOL heartRateDetect;


-(instancetype)init;

-(instancetype)initWithData:(NSData *_Nullable)data;

@end


#pragma mark - ATWearingStyleSetting

@interface ATWearingStyleSetting : ATSyncSetting
/**
 * 佩戴习惯
 * 0x00=左手
 * 0x01=右手
 */
@property(nonatomic,assign)  int wearStyle;
@end


#pragma mark - ATWeatherInfoSetting

@interface ATWeatherInfoSetting : ATSyncSetting

/**
 * 天气更新时间
 */
@property(nonatomic,assign)  int updateTime;

/**
 * 城市名称
 */
@property(nonatomic,strong) NSString *cityName;

/**
 * 未来的天气预报（包含当天）
 */
@property(nonatomic,strong) NSArray <ATWeatherItem *> * _Nullable weatherItems;
@end


#pragma mark - ATStatusControlSetting

/**
 * 手表、手环工作状态控制
 */
@interface ATStatusControlSetting : ATSyncSetting
/**
 * 标志位
 */
@property(nonatomic,assign)  int flag;

/**
 * 状态控制
 * 0x00 = 重新登录
 * 0x01 = 断开连接
 * 0x02 = 解绑设备
 * 0x03 = 重启
 * 0x04 = 重置
 * 0x05 = 关机
 * 0x06 = 查找设备，设备定位
*/
@property(nonatomic,assign) ATControlState state;
@end


#pragma mark - ATSedentarySetting

/**
 * 久坐提醒设置
 */
@interface ATSedentarySetting : ATSyncSetting

/**
 * 久坐提醒功能控制开关
 */
@property(nonatomic,assign) BOOL statusOfAll;

/**
 * 久坐提醒列表
 */
@property(nullable,nonatomic,strong)  NSArray<ATSedentaryItem *> *sedentaryItems;


-(instancetype)init;

-(instancetype)initWithData:(NSData *_Nullable)data;
@end


#pragma mark - ATScreenPagesSetting

/**
 * 自定义功能页面
 */
@interface ATScreenPagesSetting : ATSyncSetting

/**
 * 页面类型
 * 0x00 = 应用列表排序
 * 0x01 = 一级页面排序
 */
@property(nonatomic,assign)NSUInteger pageType;

/**
 * 功能页面
 */
@property(nonatomic,strong)NSArray<NSNumber *> *pages;
@end


#pragma mark - ATScreenModeSetting

@interface ATScreenModeSetting : ATSyncSetting
/**
 * 屏幕方向
 */
@property(nonatomic,assign)  int screenMode;
@end


#pragma mark - ATMessageReminder

/**
 * 消息提醒设置
 */
@interface ATMessageReminder : ATSyncSetting
/**
 * 消息提醒类型
 */
@property(nonatomic,assign) ATMessageRemindType msgType;

/**
 * 消息提醒设置开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 *  振动延时时间
 */
@property(nonatomic,assign)  int vibrationDelay;

/**
 * 振动方式
 */
@property(nonatomic,assign) ATVibrationMode vibrationMode;

/**
 * 震动时间
 */
@property(nonatomic,assign)  int vibrationTime;

/**
 * 振动等级1，0~9
 */
@property(nonatomic,assign)  int vibrationStrength1;

/**
 * 振动等级2，0~9
 */
@property(nonatomic,assign)  int vibrationStrength2;

-(instancetype)init;

-(instancetype)initWithData:(NSData *)data;
@end


#pragma mark - ATHeartRateZoneSetting

/**
 * 心率区间设置
 */
@interface ATHeartRateZoneSetting : ATSyncSetting

/**
 * 用户年龄
 */
@property(nonatomic,assign)  int userAge;

/**
 * 心率区间设置项
 *
 * <p>LS437 项目心率区间计算方式:</p>
 * <p>MAXHr =(220 - 年龄)= 220 – 20 = 200 </p>
 * <p>静态心率: 小于 L0, L0默认值 = MAXHr * 45 %;</p>
 * <p>热身区间:大于等于 L0，小于 L1，L1 默认值= MAXHr * 50 %;</p>
 * <p>减脂区间:大于等于 L1，小于 L2，L2 默认值= MAXHr * 60 %;</p>
 * <p>耐力区间:大于等于 L2，小于 L3，L3 默认值= MAXHr * 75 %;</p>
 * <p>有氧区间:大于等于 L3，小于 L4，L4 默认值= MAXHr * 85 %;</p>
 * <p>极限区间:大于等于 L4 </p>
 */
@property(nonatomic,strong) NSArray<ATHeartRateZoneItem *> *heartRateZoneItems;

/**
 * 设备型号，影响根据年龄计算心率区间的算法，若App采用自定义的心率区间设置，该字段可不设置
 */
@property(nonatomic,strong) NSString *deviceModel;
@end

#pragma mark - ATHeartRateDetectSetting

/**
 * 心率检测设置
 */
@interface ATHeartRateDetectSetting : ATSyncSetting
/**
 * 心率检测开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 心率检测开始时间，仅适用于旧手环
 */
@property(nonatomic,strong) NSString *startTime;

/**
 * 心率检测结束时间，仅适用于旧手环
 */
@property(nonatomic,strong) NSString *endTime;
@end


#pragma mark - ATHeartRateAlertSetting

/**
 * 心率预警设置
 */
@interface ATHeartRateAlertSetting : ATSyncSetting

/**
 * 心率预警类型：0为日常，1为运动
 */
@property(nonatomic,assign) int type;


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

@end


#pragma mark - ATFileSetting

/**
 * 文件更新设置
 */
@interface ATFileSetting :ATSyncSetting
/**
 * 文件url
 */
@property(nonatomic,strong)NSURL *fileUrl;
@end

#pragma mark - ATBacklightSetting
/**
 * 背光亮度设置
 * 0xF5
 */
@interface ATBacklightSetting : ATSyncSetting

/**
 * 日间亮度
 */
@property(nonatomic,assign)  int daytimeBrightness;

/**
 * 夜间亮度
 */
@property(nonatomic,assign)  int nightBrightness;

/**
 * 夜间亮度开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 夜间亮度起始时间
 */
@property(nonatomic,strong) NSString *startTime;

/**
 * 夜间亮度结束时间
 */
@property(nonatomic,strong) NSString *endTime;
@end


#pragma mark - ATDataQuerySetting
/**
 * 数据查询
 * 0xF0
 */
@interface ATDataQuerySetting : ATSyncSetting
/**
 * 数据查询类型
 */
@property(nonatomic,assign) ATDataQueryCmd queryCmd;

/**
 * 预留标志位
 */
@property(nonatomic,assign)  int flag ;//= 0x00;
@end

#pragma mark - ATDialInfoSetting
/**
 * 云端表盘、相册表盘下载
 * 0xF9
 */
@interface ATDialInfoSetting : ATFileSetting

/**
 * 表盘详情信息
 */
@property(nonatomic,strong) ATDialInfo *info;
@end

#pragma mark - ATDialQuerySetting
/**
 * 云端表盘、相册表盘查询
 * 0xF8
 */
@interface ATDialQuerySetting : ATSyncSetting
/**
 * 表盘索引
 * 1~12
 */
@property(nonatomic,assign)  int index;
@end


#pragma mark - ATDialStatusSetting
/**
 * 云端表盘、相册表盘状态设置
 * 0xFA
 */
@interface ATDialStatusSetting : ATSyncSetting
/**
 * 推送状态
 * 0x01 = 资源已发送
 * 0x02 = 取消当前推送
 */
@property(nonatomic,assign)  int status;
@end



#pragma mark - ATHRDetectCycleSetting

/**
 * 心率检测周期设置
 * 0xF6
 */
@interface ATHRDetectCycleSetting : ATSyncSetting
/**
 * 心率检测开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 检测周期
 * 0x00=检测周期不变，只是切换开关
 *  5=5分钟检测一次
 * 10=10分钟检测一次
 * 20=20分钟检测一次
 * 30=30分钟检测一次
 */
@property(nonatomic,assign)  int detectCycle;
@end


#pragma mark - ATLanguageSetting

/**
 * 语言设置
 */
@interface ATLanguageSetting : ATSyncSetting
/**
 * 设备语言，具体请参考 协议文档的 语言代码表
 */
@property(nonatomic,strong) NSString *language;
@end

#pragma mark - ATMusicInfoSetting

/**
 * 音乐信息设置
 */
@interface ATMusicInfoSetting : ATSyncSetting
/**
 * 播放状态
 * 0x00=不可播放
 * 0x01=未播放
 * 0x02=播放
 * 0x03=暂停
 */
@property(nonatomic,assign)  int playState;

/**
 * 当前音量
 *
 */
@property(nonatomic,assign)  int volumeLevel;

/**
 * 播放时间，单位秒
 * 0~65535s
 */
@property(nonatomic,assign)  int playTime;

/**
 * 歌曲时长，单位秒
 * 0s~65535s
 *
 */
@property(nonatomic,assign)  int songTime;

/**
 * 收藏标志
 * 0x00=未收藏
 * 0x01=已收藏
 */
@property(nonatomic,assign)  int favorite;

/**
 * 歌曲名称
 */
@property(nonatomic,strong)  NSString *songName;


/**
 * 艺术家名称
 */
@property(nonatomic,strong)  NSString *author;


/**
 * 专辑名称
 */
@property(nonatomic,strong)  NSString *albumName;

/**
 * 歌曲名称类型
 * 0x00 字符串
 * 0x01 图片
 */
@property(nonatomic,assign)  int songNameType;

/**
 * 音量最大值
 *
 */
@property(nonatomic,assign)  int maxVolume;
@end

#pragma mark - ATNightModeSetting

/**
 * 夜间模式设置
 */
@interface ATNightModeSetting : ATSyncSetting

/**
 * 夜间模式生效状态
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 自动夜间模式控制开关
 */
@property(nonatomic,assign) BOOL autoState;

/**
 * 自动夜间模式生效开始时间,格式HH:MM
 */
@property(nonatomic,strong)  NSString *startTime;

/**
 * 自动夜间模式生效截止时间,格式HH:MM
 */
@property(nonatomic,strong)  NSString *endTime;
@end

#pragma mark - ATRepeatClockSetting

/**
 * 周期性事件（喝水）提醒参数设定
 * 0xF4
 */
@interface ATRepeatClockSetting : ATSyncSetting

/**
 * 提醒类型<
 */
@property(nonatomic,assign)  ATEventReminderType reminderType;

/**
 * 提醒开关
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 提醒开始时间,格式11:00
 */
@property(nonatomic,strong)  NSString *startTime;

/**
 * 提醒结束时间，格式21:00
 */
@property(nonatomic,strong)  NSString *endTime;

/**
 * 从起始时间开始T分钟后后进行第一次提醒,单位分钟
 */
@property(nonatomic,assign)  int remindCycle;

/**
 * 震动方式
 */
@property(nonatomic,assign)  ATVibrationMode vibrationMode;


/**
 * 振动持续时间,表示提醒持续总时长，最大值60s
 */
@property(nonatomic,assign)  int vibrationTime;

/**
 * 振动等级1，范围0-9
 */
@property(nonatomic,assign)  int vibrationStrength1;


/**
 * 振动等级1，范围0-9。当震动方式为持续震动时，该字段无效
 */
@property(nonatomic,assign)  int vibrationStrength2;
@end

#pragma mark - ATTakePicturesSetting

/**
 * 拍照开关设置
 * 0xB2
 */
@interface ATTakePicturesSetting : ATSyncSetting
/**
 * 拍照开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * UI刷新标志
 */
@property(nonatomic,assign)  int statusOfRefresh;

/**
 * 预留字段
 */
@property(nonatomic,assign)  int reserve;
@end


#pragma mark - ATReadSetting

/**
 * 读取设置
 */
@interface ATReadSetting : ATSyncSetting

@property(nonatomic,strong)NSString *msgKey;

/**
 * 类型
 */
@property(nonatomic,assign) ATReadType type;

/**
 * Characteristic UUID Name
 */
@property(nonatomic,strong) NSString *readName;
@end

#pragma mark - ATCancelSetting

/**
 * 消息设置取消
 */
@interface ATCancelSetting : ATSyncSetting

@end

#pragma mark - ATConfigItemSetting

/**
 * 配置项设置
 * 0xFB
 */
@interface ATConfigItemSetting : ATSyncSetting

/**
 * 单位设置
 */
@property(nullable,nonatomic,strong) NSArray<ATConfigItem*> *items;

/**
 * 配置项数据解析
 */
-(instancetype)initWithData:(NSData *)data forCmd:(ATConfigQueryCmd)cmd;
@end


#pragma mark - ATConfigQuerySetting

/**
 * 配置项查询设置
 */
@interface ATConfigQuerySetting : ATSyncSetting

/**
 * 查询项
 */
@property(nonatomic,assign) ATConfigQueryCmd item;

/**
 * 查询项附加内容
 */
@property(nonatomic,strong) ATSyncSetting *itemSetting;
@end


#pragma mark - ATFlashSetting

@interface ATFlashSetting : ATSyncSetting

@property(nullable,nonatomic,strong) ATFlashData *flash;

-(instancetype)init;

-(instancetype)initWithData:(NSData *)data;
@end

#pragma mark - ATReminderSetting

/**
 * 支持勿扰模式的提醒设置
 * 0xFE
 */
@interface ATReminderSetting : ATSyncSetting

/**
 * 提醒类型
 */
@property(nonatomic,assign) ATEventReminderType type;

/**
 * 提醒总开关
 */
@property(nonatomic,assign) BOOL stateOfAllReminder;

/**
 * 提醒设置项
 */
@property(nonatomic,strong) NSArray<ATReminderItem*> *items;

/**
 * 数据包序列号
 */
@property(nonatomic,assign) int packetSeq;

/**
 * 数据包推送消息Key
 */
@property(nonatomic,strong) NSString *packetKey;
@end


#pragma mark - ATTimeSetting
/**
 * 时间同步设置
 * 0xFB
 */
@interface ATTimeSetting : ATSyncSetting

@property(nonatomic,strong)ATTime *time;
@end


#pragma mark - ATFunctionSetting

/**
 * 设备功能设置
 * 0xAD
 */
@interface ATFunctionSetting : ATSyncSetting

/**
 * 设备功能类型
 */
@property(nonatomic,assign)  ATFunctionType type;

/**
 * 设备功能开关
 */
@property(nonatomic,assign)  BOOL enable;
@end


#pragma mark - ATQuietModeSetting

/**
 * 勿扰模式设置
 * 0xB3
 */
@interface ATQuietModeSetting : ATSyncSetting

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
@property(nonatomic,strong) NSString *startTime;

/**
 * 自动勿扰模式生效的结束始时间段,格式：13:09
 */
@property(nonatomic,strong) NSString *endTime;

/**
 * 在自动勿扰模式下，允许使用或设置禁用的设备功能列表
 */
@property(nonatomic,strong) NSArray<ATFunctionSetting *> *functions;
@end


#pragma mark - ATHeartRateSetting

/**
 * 心率开关设置0x30
 */
@interface ATHeartRateSetting : ATSyncSetting

/**
 * 总开关
 */
@property(nonatomic,assign) BOOL stateOfAll;

/**
 * 心率检测开关设置项
 */
@property(nonatomic,strong) NSArray<ATHeartRateItem *> *items;
@end


#pragma mark - ATMusicControlSetting

/**
 * 音乐播放器控制开关
 */
@interface ATMusicControlSetting : ATSyncSetting

/**
 * 控制开关
 */
@property(nonatomic,assign)BOOL enable;
@end


#pragma mark - ATMessageSetting

/**
 * 消息提醒控制开关设置
 */
@interface ATMessageSetting : ATSyncSetting

/**
 * 消息设置项
 */
@property(nonatomic,strong)NSArray <ATMessageItem *> *items;
@end


#pragma mark - ATImageMessage

/**
 * 图片消息
 */
@interface ATImageMessage : ATSyncSetting

/**
 * 应用id
 */
@property(nonatomic,assign) ATAppCategory appId;

/**
 * 图片消息类型
 * 0x01:Incoming Call (来电)
 * 0x02:NewMessage (消息)
 * 0x03:城市名称 (天气界面用)
 * 0x04:音乐信息
 * 0x05:iOT设备信息
 */
@property(nonatomic,assign)  int imageType;

/**
 * 图片字节流
 */
@property(nonatomic,strong)NSData * _Nullable imageBytes;


/**
 * 图片的横向像素
 */
@property(nonatomic,assign)  int horizontalPx;

/**
 * 图片的纵向像素
 */
@property(nonatomic,assign)  int verticalPx;

/**
 * 图片颜色类型
 * 0x01：单色(黑白)
 */
@property(nonatomic,assign)  int color;

/**
 * 压缩算法
 * 0: 不需解压
 * 1: 单色通用压缩算法 V1.0
 * 2: 其他算法
 */
@property(nonatomic,assign)  int algorithm;

/**
 * 消息时间
 * 格式12:23
 */
@property(nonatomic,strong) NSString * _Nullable time;


/**
 * IOT 设备状态消息
 */
@property(nonatomic,strong) ATIotDevice * _Nullable iotDevice;

/**
 * 图片对象
 */
@property(nonatomic,strong)UIImage * _Nullable image;

/**
 * 图片内容，文本格式
 */
@property(nonatomic,strong)NSString * _Nullable text;


-(NSData *_Nullable)formatImageSummary;


-(NSData *_Nullable)formatImageContent;
@end

#pragma mark - ATFileRespSetting

//文件传输协议，响应设置
@interface ATFileRespSetting : ATFileSetting

/**
 * 响应数据
 */
@property(nonatomic,strong) ATFileData * _Nullable fileMsg;

/**
 * iot设备mac
 */
@property(nonatomic,strong) NSString *iotMac;
@end


#pragma mark - ATIotDeviceSetting

/**
 * iOT 设备信息推送
 */
@interface ATIotDeviceSetting : ATSyncSetting

/**
 * 响应状态
 * 0x00 = 响应同步请求
 * 0x01 = App更新请求
 */
@property(nonatomic,assign)NSUInteger respState;

/**
 * 同步状态
 */
@property(nonatomic,assign,readonly)ATIotSyncState syncState;

/**
 * 默认初始化
 */
-(instancetype _Nonnull)init;

/**
 * 根据iot设备及同步状态,初始化设置信息,支持增量或全量状态设置
 */
-(instancetype _Nonnull)initWithDevice:(ATIotDevice *_Nonnull)iotDevice syncState:(ATIotSyncState)state;
@end


#pragma mark - ATIotControlSetting

/**
 * iOT设备控制设置
 */
@interface ATIotControlSetting : ATSyncSetting

//iot设备,支持增量或全量状态设置
@property(nonatomic,strong)ATIotDevice * _Nonnull iotDevice;
@end

#pragma mark - ATGpsInfoSetting

/**
 * GPS信息推送设置
 */
@interface ATGpsInfoSetting : ATSyncSetting

/**
 * 经度，保留小数点后6位小数，value * 1000000
 */
@property(nonatomic,assign)  int longitude;

/**
 * 纬度，保留小数点后6位小数，value * 1000000
 */
@property(nonatomic,assign)  int latitude;

/**
 * 海拔 单位CM
 */
@property(nonatomic,assign)  int altitude;

/**
 * 位置精度 单位CM
 */
@property(nonatomic,assign) int position;

/**
 * “是否在国内”的标志（目的：固件判断采用gps+北斗, 还是gps+glonass的组合）
 * 0x00=表示国内 采用gps+北斗
 * 0x01=表示非国内 gps+glonass
 */
@property(nonatomic,assign)  int flag;
@end


/**
 * 表盘删除功能接口
 */
@interface ATDialRemoveSetting : ATSyncSetting

/**
 * 删除的表盘索引
 */
@property(nonatomic,assign)  int index;

/**
 * 表盘类型
 */
@property(nonatomic,assign)  int typeOfWatchFace;

/**
 * 表盘ID
 */
@property(nonatomic,strong)  NSString * _Nonnull dialId;
@end

/**
 * 天王星运动类型增加/删除/替换 设置
 * 450R0
 */
@interface ATExerciseSetting : ATSyncSetting

/**
  * 运动类型
  * 保留2 种运动不可删减（室内跑步/户外跑步）
  * 当前最多显示15种运动类型
  *
  * APP根据用户自定义的显示页面顺序设置，把自定义（增加/删除/顺序调整）的运动类型信息发送到手环。
  * 手环按照设定的运动类型顺序和种类显示运动界面。
  * 运动类型的定义参考 ATExerciseType
  */
@property(nonatomic,strong)  NSArray * _Nonnull exerciseTypes;
@end

/**
 * 健康提醒设置
 */
@interface ATHealthSetting : ATSyncSetting

/**
 * 提醒设置项，支持同时设置或单项设置
 * 如ATWomenHealth(女性健康提醒)、 ATMenstrualRemind(经期提醒)、 ATPregnancyRemind(孕期提醒)
 */
@property(nonatomic,strong) NSArray <ATConfigItem *> * _Nonnull items;
@end


#pragma mark - ATIotConfigSetting

/**
 * iOT控制协议接口,路易斯协议
 */
@interface ATIotConfigSetting : ATSyncSetting

/**
 * iot设备图标文件列表
 */
@property(nonatomic,strong,readonly)NSMutableArray *iconUrls;

/**
 * iot设备信息
 */
@property(nonatomic,strong,readonly)ATIotInfo *iotInfo;

/**
 * iot控制同步状态
 */
@property(nonatomic,assign)ATIotSyncState syncState;

/**
 * 对象实例化,单个设置
 */
-(instancetype)initWithConfig:(ATIotConfig *)config syncState:(ATIotSyncState)state;

/**
 * 对象实例化,多个设备同时设置
 */
-(instancetype)initWithArray:(NSArray <ATIotConfig *>*)items syncState:(ATIotSyncState)state;
@end


#pragma mark - ATGpsControlSetting

/**
 * GPS状态控制设置指令
 */
@interface ATGpsControlSetting : ATSyncSetting

/**
 * Gps状态
 */
@property(nonatomic,assign)BOOL enable;
@end

#pragma mark - ATMoodRemindSetting

/**
 * 心情提醒设置
 */
@interface ATMoodRemindSetting : ATSyncSetting

/**
 * Status of Mood record reminder
 */
@property(nonatomic,assign) BOOL enable;

/**
 * Start time of Mood record reminder,format HH:MM
 */
@property(nonatomic,strong) NSString *startTime;

/**
 * End time of Mood record reminder,format HH:MM
 */
@property(nonatomic,strong) NSString *endTime;

/**
 * Vibration time of reminder
 * unit:seconds
 * */
@property(nonatomic,assign) int vibrationTime;

/**
 * Vibration interval of reminder
 * unit:minute
 * */
@property(nonatomic,assign) int interval;
@end


#pragma mark - ATMoodNameSetting

/**
 * 心情手环蓝牙名称设置
 */
@interface ATMoodNameSetting : ATSyncSetting

/**
 * 蓝牙名称
 * Max length is 21 bytes
 */
@property(nonatomic,strong) NSString *devName;
@end


#pragma mark - ATDataSycResetSetting

/**
 * 乐心手环6S数据同步重置指令
 * 设置后可以重复拉取设备端已同步过的历史数据
 */
@interface ATDataSyncResetSetting : ATSyncSetting

@property(nonatomic,assign) BOOL enable;

@end
