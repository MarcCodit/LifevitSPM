//
//  ATDeviceData.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/10.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATStepItem.h"
#import "ATExerciseStatus.h"
#import "ATSettingProfiles.h"
#import "ATLogItem.h"
#import "ATBuriedPointItem.h"
#import "ATMeditationItem.h"
#import "ATBloodOxygenItem.h"
#import "ATSleepReportItem.h"
#import "ATSensorItem.h"
#import "ATBatteryInfo.h"
#import "ATIotDevice.h"
#import "ATWorkingItem.h"
#import "ATGpsExerciseItem.h"
#import "ATStressTestItem.h"
#import "ATTargetItem.h"
#import "ATHeartRateItem.h"
#import "ATWatchFaceElement.h"
#import "ATMoodItem.h"
#import "ATCavoProfiles.h"
#import "NSObject+Json.h"

@class ATSyncSetting;

/**
 * 手环/手表 测量数据基类
 * Activity Tracker Device's Data
 */
@interface ATDeviceData : NSObject

/**
 * 原始数据帧
 */
@property(nullable,nonatomic,strong)NSData *srcData;

/**
 * 版本号
 */
@property(nonatomic,assign)NSUInteger version;

/**
 * 数据包命令字
 */
@property(nonatomic,assign)NSUInteger cmd;

/**
 * 命令字数据内容
 */
@property(nullable,nonatomic,strong)NSData *cmdData;

/**
 * 设备广播ID
 */
@property(nullable,nonatomic,strong)NSString *broadcastId;

/**
 * 测量时间，格式 yyyy-MM-dd HH:mm:ss
 */
@property(nullable,nonatomic,strong)NSString *measureTime;

/**
 * 设备ID
 */
@property(nullable,nonatomic,strong)NSString *deviceId;

/**
 * 设备SN
 */
@property(nullable,nonatomic,strong)NSString *deviceSN;

/**
 * 数据类型
 */
@property(nonatomic,assign)NSUInteger dataType;


/**
 * 设备型号
 */
@property(nullable,nonatomic,strong)NSString *deviceModel;


/**
 * 对象初始化
 */
-(instancetype)initWithData:(NSData *)data;

/**
 * 解析命令字数据包内容，由子类重写
 */
-(void)decoding;


/**
 * UTC转字符串时间格式
 */
-(NSString *)utcToString:(long)utc;

/**
 * 对象信息
 */
-(NSDictionary *)toString;

@end

#pragma mark - ATDeviceInfo

/**
 * 设备信息详情
 * 0x50
 */
@interface ATDeviceInfo : ATDeviceData

/**
 * 设备MAC
 */
@property(nullable,nonatomic,strong)NSString *deviceMac;

/**
 * 设备型号
 */
@property(nullable,nonatomic,strong)NSString *model;

/**
 * 设备固件版本
 */
@property(nullable,nonatomic,strong)NSString *firmwareVersion;

/**
 * 设备硬件版本
 */
@property(nullable,nonatomic,strong)NSString *hardwareVersion;

/**
 * 设备当前时区
 */
@property(nonatomic,assign)unsigned int timezone;

/**
 * 标志位
 */
@property(nonatomic,assign)unsigned int flag;

/**
 * 心率检测状态
 * true=心率检测打开
 * false=心率检测关闭
 */
@property(nonatomic,assign)BOOL statusOfHeartRate;

/**
 * 心率检测关闭状态下的开始时间
 */
@property(nullable,nonatomic,strong)NSString *startTimeOfHRDisable;

/**
 * 心率检测关闭状态下的结束时间
 */
@property(nullable,nonatomic,strong)NSString *endTimeOfHRDisable;

/**
 * 待上传的数据记录条数
 */
@property(nonatomic,assign)unsigned int remainDataCount;

/**
 * 绑定状态
 * true=0x03,设备已绑定
 * false=0x04,设备未绑定
 */
@property(nonatomic,assign)BOOL stateOfBond;

/**
 * 自定义的版本信息
 */
@property(nullable,nonatomic,strong)NSString *customVersion;
@end


#pragma mark - ATStepSummary

/**
 * 手表、手环步数记录
 * 0X51,0X57
 */
@interface ATStepSummary : ATDeviceData

/**
 * 类型
 * 0x01:每天测量数据
 */
@property(nonatomic,assign)unsigned int type;

/**
 * 当前上传的数据记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * 可选项标志位
 *
 * Bit0:是否存在静息心率
 * 其他:预留
 */
@property(nonatomic,assign)unsigned int flag;

/**
 * 步数记录
 */
@property(nullable,nonatomic,strong)NSArray <ATStepItem *>* steps;


/**
 * 站立时长,单位小时
 */
@property(nonatomic,assign)int standTime;

/**
 * 步数记录类型
 */
@property(nonatomic,assign)ATStepType stepType;
@end

#pragma mark - ATTemperatureData


/**
 * 体温数据
 */
@interface ATTemperatureData : ATDeviceData

/**
 * UTC偏移量,单位秒
 */
@property(nonatomic,assign) int offset;

/**
 * 剩余数据记录数
 */
@property(nonatomic,assign) int remainCount;

/**
 * 当前上传的数据记录条数
 */
@property(nonatomic,assign) int dataSize;

/**
 * UTC
 */
@property(nonatomic,assign) long utc;

/**
 * 心率值
 */
@property(nonatomic,assign) int hrValue;

/**
 * 测量时间偏移量
 */
@property(nonatomic,assign) int timeOffset;

/**
 * 当前温度值
 */
@property(nonatomic,assign) float value;

/**
 * 数据项测量时间 偏移量
 */
@property(nonatomic,assign) int itemOffset;

/**
 * 动态监测状态
 */
@property(nonatomic,strong) NSArray <NSNumber *> * _Nullable animationStatus;

/**
 * 补偿状态
 */
@property(nonatomic,strong) NSArray <NSNumber *> * _Nullable adjustStatus;

/**
 * 佩戴状态,列表
 */
@property(nonatomic,strong) NSArray <NSNumber *> * _Nullable wearStatus;

/**
 * 体温数据列表
 */
@property(nonatomic,strong) NSArray <NSNumber *> * _Nullable items;
@end



#pragma mark - ATHeartRate

/**
 * 心率数据
 * 0x53
 */
@interface ATHeartRate : ATDeviceData

/**
 * 心率数据类型
 * 0x00:普通心率
 * 0x01:运动心率
 * 0x02:睡眠状态心率
 * 0x03:区间心率
 * 0x04:历史心率(可替换 0x53)
 * 0x05:跑步心率(可替换 0x73)
 * 0xFF:其它状态
 */
@property(nonatomic,assign) unsigned int type;

/**
 * UTC
 */
@property(nonatomic,assign) long utc;

/**
 * UTC偏移量,单位秒
 */
@property(nonatomic,assign) unsigned int offset;

/**
 * 剩余数据记录数
 */
@property(nonatomic,assign) unsigned int remainCount;

/**
 * 当前上传的数据记录条数
 */
@property(nonatomic,assign) unsigned int dataSize;

/**
 * 心率数据集合，每5分钟一个点，集合中每个值之间的itemUtc=utc+index*offset
 */
@property(nullable,nonatomic,strong) NSArray <NSNumber *> *heartRates;

/**
 * 是否是实时的心率数据
 */
@property(nonatomic,assign) BOOL isRealtimeData;


/**
 * 标志位
 */
@property(nonatomic,assign) int flags;

/**
 * 点测心率数据
 */
@property(nullable,nonatomic,strong)NSArray <ATHeartRateItem *>*items;


/**
 * 测温数据列表
 */
//@property(nullable,nonatomic,strong) NSArray <ATTemperatureData *> *temperatures;
@end



#pragma mark - ATSleepData

/**
 * 睡眠数据
 * 0x52
 */
@interface ATSleepData : ATDeviceData

/**
 * UTC
 */
@property(nonatomic,assign)long utc;

/**
 * UTC偏移量,单位秒
 */
@property(nonatomic,assign)unsigned int offset;

/**
 * 剩余数据记录
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 当前上传的数据记录
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * 睡眠数据集合，每5分钟一个点，集合中每个值之间的itemUtc=utc+index*offset
 */
@property(nullable,nonatomic,strong)NSArray <NSNumber *> *sleepStatus;
@end

#pragma mark - ATExerciseData

/**
 * 运动报告数据
 * 0xE2
 */
@interface ATExerciseData : ATDeviceData

/**
 * 运动类别
 */
@property(nonatomic,assign) ATExerciseType category;

/**
 * 运动模式
 * 0x00:手动进入
 * 0x01:自动识别
 * 0x02:轨迹跑有通知到 APP
 * 0x03:轨迹跑没有通知到 APP
 */
@property(nonatomic,assign) unsigned int mode;

/**
 * 标志位
 */
@property(nonatomic,assign) unsigned int flag;

/**
 * 暂停次数
 */
@property(nonatomic,assign) unsigned int pausesCount;

/**
 * 开始时间
 */
@property(nonatomic,assign)  long startUtc;

/**
 * 结束时间
 */
@property(nonatomic,assign)  long stopUtc;

/**
 * 运动时长,单位秒
 */
@property(nonatomic,assign)  unsigned int time;

/**
 * 运动过程中产生的总步数
 */
@property(nonatomic,assign)  unsigned int step;

/**
 * 运动过程中消耗的总卡路里，单位: 0.1Kcal
 */
@property(nonatomic,assign)  float calories;

/**
 * 最大心率
 */
@property(nonatomic,assign)  unsigned int maxHeartRate;

/**
 * 平均心率
 */
@property(nonatomic,assign)  unsigned int avgHeartRate;

/**
 * 最大速度 单位 0.01Km/h
 */
@property(nonatomic,assign)  float maxSpeed;

/**
 * 平均速度 单位 0.01Km/h
 */
@property(nonatomic,assign)  float avgSpeed;

/**
 * 距离 单位:米
 */
@property(nonatomic,assign) unsigned  int distance;

/**
 * 最大步频
 */
@property(nonatomic,assign) unsigned int maxStepFrequency;

/**
 * 平均步频
 */
@property(nonatomic,assign) unsigned int avgStepFrequency;

/**
 * 游泳圈数,该字段仅在游泳模式下有效
 */
@property(nonatomic,assign) unsigned int numOfSwimming;

/**
 * 运动过程状态列表
 */
@property(nullable,nonatomic,strong)  NSArray <ATExerciseStatus *>*exerciseStatus;

/**
 * 平均步幅
 */
@property(nonatomic,assign) unsigned int avgStride;

/**
 * 游泳距离
 */
@property(nonatomic,assign) int swimDistance;

/**
 * 主泳姿
 */
@property(nonatomic,assign) int mainStroke;

/**
 * 平均Swolf
 */
@property(nonatomic,assign) int avgSwolf;

/**
 * 划水次数
 */
@property(nonatomic,assign) int strokeTimes;

/**
 * 最高步频心率
 */
@property(nonatomic,assign) int maxStepHeartRate;


/**
 * 心率区间时间占比，单位百分比
 * 区间1 ~~ 区间5
 */
@property(nullable,nonatomic,strong) NSArray *heartRateZoneTimeRatio;

/**
 * 最高冲刺速度,单位Km/h
 */
@property(nonatomic,assign) float sprintSpeed;

/**
 * 运动目标达成项
 */
@property(nullable,nonatomic,strong) NSArray <ATTargetItem *>*targetItems;

/**
 * 心率区间数据类型，0为分钟数，1为百分比
 */
@property(nonatomic,assign) int heartRateZoneMode;

/**
 * 平均配速，单位 km/h 456 新增
 */
@property(nonatomic,assign) int avgPace;
@end

#pragma mark - ATExerciseCalories

/**
 * 运动卡路里数据
 * 0xE6
 */
@interface ATExerciseCalories : ATDeviceData

/**
 * 运动类别
 */
@property(nonatomic,assign)  ATExerciseType category;

/**
 * 运动模式，手动或自动识别
 */
@property(nonatomic,assign) unsigned  int mode;

/**
 * 开始时间UTC
 */
@property(nonatomic,assign)  long utc;

/**
 * utc偏移量,单位秒
 */
@property(nonatomic,assign) unsigned int offset;

/**
 * 剩余数据记录条数
 */
@property(nonatomic,assign) unsigned int remainCount;

/**
 * 当前上传数据记录条数
 */
@property(nonatomic,assign) unsigned int dataSize;

/**
 * 运动卡路里数据集合，每1分钟一个点，对应每个点的itemUtc=utc+index*offset
 */
@property(nullable,nonatomic,strong)  NSArray<NSNumber *> *calories;
@end

#pragma mark - ATExerciseHeartRate

/**
 * 运动心率数据
 */
@interface ATExerciseHeartRate : ATHeartRate

/**
 * 运动类别
 */
@property(nonatomic,assign)ATExerciseType category;

/**
 * 运动模式，手动或自动识别
 */
@property(nonatomic,assign) unsigned int mode;
@end

#pragma mark - ATExerciseNotify

/**
 * 运动状态通知
 */
@interface ATExerciseNotify : ATDeviceData

/**
 * 标志位,功能检测
 * 0x01=GPS 状态检测
 * 0x02=运动 状态检测
 */
@property(nonatomic,assign) unsigned int flag;

/**
 * 状态
 *
 * <p>if flag=0x01,status的字段按以下解析</p>
 *
 * <p>0x00=开始(通知 app 手表已开始运动， app 需开启 GPS)</p>
 * <p>0x01=开启 GPS</p>
 * <p>0x02=运动开始(通知 app 手表已开启运动)</p>
 * <p>0x03=关闭 GPS</p>
 *
 *
 * <p>if flag=0x02,status的字段按以下解析</p>
 *
 * <p>0x01=结束</p>
 * <p>0x03=暂停</p>
 * <p>0x04=重启</p>
 */
@property(nonatomic,assign) unsigned int status;

/**
 * 运动类别
 */
@property(nonatomic,assign) ATExerciseType category;
@end


#pragma mark - ATExerciseSpeed

/**
 * 运动配速数据
 */
@interface ATExerciseSpeed : ATDeviceData

/**
 * 运动类别
 */
@property(nonatomic,assign)  ATExerciseType category;

/**
 * 运动模式，手动或自动识别
 */
@property(nonatomic,assign) unsigned int mode;

/**
 * 开始时间UTC
 */
@property(nonatomic,assign) long utc;

/**
 * UTC偏移量，单位秒
 */
@property(nonatomic,assign) unsigned int offset;

/**
 * 剩余数据记录条数
 */
@property(nonatomic,assign) unsigned int remainCount;

/**
 * 当前上传数据记录条数
 */
@property(nonatomic,assign) unsigned int dataSize;

/**
 * 运动配速数据集合
 * 配速是指跑(走)完1km 需要多久时间， 精确到秒，例如256表示4’16’’
 */
@property(nullable,nonatomic,strong) NSArray <NSNumber *> *speeds;
@end

#pragma mark - ATRandomCodeReq
/**
 * A5手环随机数绑定请求:0x7B
 */
@interface ATRandomCodeReq : ATDeviceData
@property(nullable,nonatomic,strong,readonly)NSString *randomNum;

/**
 * 随机数校验
 */
-(BOOL)verifyRandomNum:(NSString *)value;
@end

#pragma mark - ATBindConfirmReq
/**
* A5手环随机数绑定请求:0xE3
*/
@interface ATBindConfirmReq : ATDeviceData

/**
 * 绑定确认状态
 */
@property(nonatomic,assign) unsigned int status;
@end


#pragma mark - ATLoginInfo

@interface ATLoginInfo : ATDeviceData

/**
 * MD5
 */
@property(nullable,nonatomic,strong)NSString *md5;

/**
 * 设备绑定状态
 * 0x03=表示已绑定，
 * 0x04=表示未绑定
*/
@property(nonatomic,assign)NSUInteger stateOfBond;
@end


#pragma mark - ATSensorData

@interface ATSensorData : ATDeviceData

/**
 * G-Sensor 数据大小
 */
@property(nonatomic,assign) unsigned int gSensorSize;

/**
 * 心率数据大小
 */
@property(nonatomic,assign) unsigned int heartRateSize;

/**
 * 步数数据大小
 */
@property(nonatomic,assign) unsigned int stepSize;

/**
 * 当前数据包 第一笔测量 数据 UTC
 */
@property(nonatomic,assign) unsigned int utc;

/**
 * UTC 偏移量 (单位:s)
 * 后续数据偏移当前数据包的前一笔测量数据 UTC 的时间间隔
 */
@property(nonatomic,assign) unsigned int offset;

/**
 * 剩余条数
 */
@property(nonatomic,assign) unsigned int remainCount;

/**
 * 当前上传的数据大小
 */
@property(nonatomic,assign) unsigned int dataSize;

/**
 * 数据集合
 */
@property(nullable,nonatomic,strong) NSArray <ATSensorItem *> *sensorItems;
@end


#pragma mark - ATLogData

@interface ATLogData : ATDeviceData
/**
 * 标志位
 */
@property(nonatomic,assign) unsigned int flag;

/**
 * log 日志项信息
 */
@property(nullable,nonatomic,strong) NSArray <ATLogItem *> *logs;
@end

#pragma mark - ATControlData

@interface ATControlData : ATDeviceData
/**
 * 控制指令数据
 */
@property(nonatomic,assign) ATControlCmd controlCmd;

/**
 * 音量范围 0% ~100%
 */
@property(nonatomic,assign) unsigned int volume;
@end

#pragma mark - ATBuriedPointData

@interface ATBuriedPointData : ATDeviceData

/**
 * 剩余数据记录数
 * 本地待上传埋点记录总条数
 */
@property(nonatomic,assign) unsigned int remainCount;

/**
 * 本包记录偏移
 */
@property(nonatomic,assign) unsigned int dataOffset;

/**
 * 当前上传的数据记录条数
 */
@property(nonatomic,assign) unsigned int dataSize;

/**
 * 埋点数据项
 */
@property(nullable,nonatomic,strong) NSArray <ATBuriedPointItem *> *items;
@end

#pragma mark - ATMeditationData

@interface ATMeditationData : ATDeviceData

/**
 * 剩余数据记录数
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 本包记偏移
 * 本次上传记录在待上传记录中的偏移条数
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 本次上传记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * 冥想数据集合
 */
@property(nullable,nonatomic,strong) NSArray<ATMeditationItem *> *meditations;
@end

#pragma mark - ATBloodOxygenData

@interface ATBloodOxygenData : ATDeviceData
/**
 * 剩余数据记录数
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 本包记偏移
 * 本次上传记录在待上传记录中的偏移条数
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 本次上传记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * utc偏移量
 */
@property(nonatomic,assign)unsigned int utcOffset;

/**
 * 数据集合
 */
@property(nullable,nonatomic,strong) NSArray<ATBloodOxygenItem*> *bloodOxygens;

@end

#pragma mark - ATSleepReportData

@interface ATSleepReportData : ATDeviceData
/**
 * 入睡时间 UTC
 */
@property(nonatomic,assign) long bedTime;


/**
 * 起床时间 UTC
 */
@property(nonatomic,assign) long getupTime;


/**
 * 累计清醒时间，单位分钟
 */
@property(nonatomic,assign)unsigned int awakeTime;

/**
 * 累计清醒次数
 */
@property(nonatomic,assign)unsigned int awakeCount;

/**
 * 眼动次数
 */
@property(nonatomic,assign)unsigned int remDuration;

/**
 * 累计浅睡时间，单位分钟
 */
@property(nonatomic,assign)unsigned int lightSleepDuration;

/**
 * 累计深睡时间，单位分钟
 */
@property(nonatomic,assign)unsigned int deepSleepDuration;


/**
 * 睡眠特征
 * T_NONE = 0,  No sleep.
 * T_TEMP = 1, Temporal sleep.
 * T_COMP = 2, Complete sleep.
 */
@property(nonatomic,assign)unsigned int sleepType;

/**
 * 待上传睡眠报告个数
 * 本地存储几个睡眠报告
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 睡眠报告偏移
 * 本数据是属于第个睡眠报告
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 保留字段
 */
@property(nonatomic,assign)unsigned int reserved;

/**
 * 本次睡眠结构总数
 * 本次睡眠报告中的明细结构体个数
 */
@property(nonatomic,assign)unsigned int totalNumberOfSleepItem;

/**
 * 明细睡眠结构偏移
 * 本次传输的结构体在本次睡眠报告明细结构体数组中的偏移
 */
@property(nonatomic,assign)unsigned int offsetOfSleepItem;

/**
 * 本包传输结构个数
 * 本包包含睡眠明细结构个数
 */
@property(nonatomic,assign)unsigned int countOfSleepItem;

/**
 * 本次睡眠呼吸质量，默认-1
 */
@property(nonatomic,assign) int respiratoryQuality;

/**
 * 本次睡眠质量,默认-1
 */
@property(nonatomic,assign) int sleepQuality;

/**
 * 本次睡眠呼吸质量等级，默认-1
 */
@property(nonatomic,assign) int level;

/**
 * 睡眠状态列表
 */
@property(nullable,nonatomic,strong) NSArray<ATSleepReportItem *> *reportItems;

/**
 * 睡眠日期UTC
 */
@property(nonatomic,assign)long dateUtc;

@end

#pragma mark - ATRestingHeartRate

@interface ATRestingHeartRate : ATDeviceData
/**
 * 剩余数据记录数
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 本包记偏移
 * 本次上传记录在待上传记录中的偏移条数
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 本次上传记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * 静息心率数据集合
 */
@property(nullable,nonatomic,strong) NSArray<ATBloodOxygenItem*> *heartRates;
@end

#pragma mark - ATStepRecordData

@interface ATStepRecordData : ATDeviceData
/**
 * UTC
 */
@property(nonatomic,assign) long utc;

/**
 * 采集频率，单位分钟
 * 15，表示计步采集频度为15分钟一笔数据
 */
@property(nonatomic,assign)unsigned int frequency;

/**
 * 剩余数据记录数
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 本包记偏移
 * 本次上传记录在待上传记录中的偏移条数
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 本次上传记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;

/**
 * 步数记录
 */
@property(nullable,nonatomic,strong) NSArray<NSNumber *> *steps;
@end

#pragma mark - ATChargeRecordData

@interface ATChargeRecordData : ATDeviceData
/**
 * 充电时刻UTC
 */
@property(nonatomic,assign)  long startUtc;

/**
 * 开始充电时刻的电量
 */
@property(nonatomic,assign)unsigned  int oldBattery;

/**
 * 停止充电时刻UTC
 */
@property(nonatomic,assign) long endUtc;

/**
 * 停止充电时刻的电量
 */
@property(nonatomic,assign)unsigned  int currentBattery;
@end

#pragma mark - ATUploadDoneNotify

@interface ATUploadDoneNotify : ATDeviceData
/**
 * 数据查询类型
 */
@property(nonatomic,assign)  ATDataQueryCmd dataType;

/**
 * 预留字段
 */
@property(nonatomic,assign)unsigned  int reserved;
@end


#pragma mark - ATBacklightData

@interface ATBacklightData : ATDeviceData
/**
 * 日间亮度
 */
@property(nonatomic,assign) unsigned int daytimeBrightness;

/**
 * 夜间亮度
 */
@property(nonatomic,assign) unsigned int nightBrightness;

/**
 * 夜间亮度开关
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 夜间亮度起始时间
 */
@property(nullable,nonatomic,strong)  NSString *startTime;

/**
 * 夜间亮度结束时间
 */
@property(nullable,nonatomic,strong)  NSString *endTime;
@end

#pragma mark - ATPairConfirmRequest

@interface ATPairConfirmRequest : ATDeviceData

@end

#pragma mark - ATDialStyleData

@interface ATDialStyleData : ATDeviceData
/**
 * 当前选择的表盘索引
 */
@property(nonatomic,assign) unsigned  int index;

/**
 * 表盘个数
 */
@property(nonatomic,assign) unsigned  int len;

/**
 * 表盘数组
 */
@property(nullable,nonatomic,strong)   NSArray<NSNumber *> *dialStyles;
@end

#pragma mark - ATDialInfo

@interface ATDialInfo : ATDeviceData
/**
 * 当前的表盘索引
 * 
 * 天王星说明：
 *1、表盘索引号的范围支持3~7，如果下发1~2会返回失败。
 *2、其中3号用于下载动态表盘，4到7号用于下载静态表盘。1到2号是本地内置表盘不能变更。
 *
 *2、推送指令下发的表盘类型如果是255，则表示这个是删除指令，删除指定索引号的表盘。
 *3、推送的静态表盘和动态表盘都用表盘类型0（在线表盘）来表示。
 *4、相册表盘作为老接口保留，表示原有的直接拼接图片文件下发的相册表盘，以兼容老功能。
 *5、内置于固件不能替换的表盘为本地表盘。

 */
@property(nonatomic,assign)int index;

/**
 * 表盘ID
 */
@property(nullable,nonatomic,strong) NSString *dialId;

/**
 * 表盘类型
 * 0x00=在线表盘
 * 0x01=相册表盘
 * 0x02=本地表盘
 * 0x03=多功能表盘
 * 255：无表盘
 */
@property(nonatomic,assign)int type;

/**
 * 表盘名称
 */
@property(nullable,nonatomic,strong) NSString *name;

/**
 * 背景图名称
 */
@property(nullable,nonatomic,strong) NSString *backgroundName;

/**
 * 样式ID
 */
@property(nonatomic,assign)int styleId;

/**
 * 是否是预制表盘
 */
@property(nonatomic,assign)BOOL isPresetDial;

/**
 * 颜色Id
 */
@property(nonatomic,assign) int colorId;

/**
 * 多功能表盘配置项
 */
@property(nonatomic,strong) NSArray <ATWatchFaceItem *> *configItems;
@end

#pragma mark - ATDialSyncStatusData

@interface ATDialSyncStatusData : ATDeviceData
/**
 * 同步状态
 */
@property(nonatomic,assign) ATDialSyncStatus status;
@end


#pragma mark - ATDialInfoResp

@interface ATDialInfoResp : ATDeviceData
/**
 * 响应状态
 * 0x00 = 接收出错
 * 0x01 = 接收成功
 */
@property(nonatomic,assign)unsigned int respStatus;
@end

#pragma mark - ATIotDeviceInfo

@interface ATIotDeviceInfo : ATDeviceData

/**
 * IOT 设备总数
 */
@property(nonatomic,assign)unsigned int count;

/**
 * IOT 设备列表
 */
@property(nullable,nonatomic,strong) NSArray *iotDevices;
@end


#pragma mark - ATFlashData

@interface ATFlashData : ATDeviceData

/**
 * Flash 数据类型
 *
 * 0x00:读取蓝牙芯片 flash 信息
 * 0x01:读取外挂 flash 芯片信息
 * 0x02:读取外挂 MCU 中 flash 信息
 */
@property(nonatomic,assign)unsigned int type;

/**
 * 起始地址
 */
@property(nonatomic,assign)unsigned int startAddress;

/**
 * 结束地址
 */
@property(nonatomic,assign)unsigned int endAddress;

/**
 * flash 数据内容
 */
@property(nullable,nonatomic,strong) NSData *content;
@end

#pragma mark - ATExerciseStep

/**
 * 运动步频数据
 */
@interface ATExerciseStep : ATDeviceData

/**
 * 运动类别
 */
@property(nonatomic,assign) ATExerciseType category;

/**
 * 运动模式，手动或自动识别
 */
@property(nonatomic,assign)unsigned int mode;

/**
 * 开始时间UTC
 */
@property(nonatomic,assign)unsigned long utc;

/**
 * utc偏移量,单位秒
 */
@property(nonatomic,assign)unsigned int offset;

/**
 * 剩余数据记录条数
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 当前上传数据记录条数
 */
@property(nonatomic,assign)unsigned int dataSize;


/**
 * 运动步频步数集合，每1分钟一个点，对应每个点的itemUtc=utc+index*offset
 */
@property(nullable,nonatomic,strong) NSArray*steps;
@end


#pragma mark - ATBuriedPointSummary

/**
 * 埋点统计数据
 * 0x11
 */
@interface ATBuriedPointSummary : ATDeviceData

/**
 * 统计类型
 */
@property(nonatomic,assign)NSUInteger type;

/**
 * 统计数据项
 */
@property(nullable,nonatomic,strong)NSArray *items;
@end

#pragma mark - ATConfigItemData

/**
 * 配置项数据
 * 0x67
 */
@interface ATConfigItemData : ATDeviceData

/**
 * 配置项类型
 */
@property(nonatomic,assign) ATConfigQueryCmd item;

/**
 * 配置项设置内容
 */
@property(nullable,nonatomic,strong) ATSyncSetting *setting;
@end


/**
 * 异常数据
 */
@interface ATExceptionData : ATDeviceData
@property(nullable,nonatomic,strong)NSException *exception;
@end


#pragma mark - ATWorkStateData

@interface ATWorkStateData : ATDeviceData

/**
 * 上报类型
 *
 * 0x00:工作状态
 * 0x01:工作记录
 * 其他:预留
 */
@property(nonatomic,assign)unsigned int type;

/**
 * 工作状态
 *
 * 0x01:重置
 * 0x02:重启
 * 0x03:关机
 *
 * 其他:预留
 */
@property(nonatomic,assign)unsigned int state;

/**
 * 工作记录
 */
@property(nullable,nonatomic,strong) NSArray<ATWorkingItem*> *items;

-(NSData *_Nonnull)formatRespPacket:(BOOL)state;
@end


#pragma mark - ATIotSyncReq

/**
 * iOT 设备状态同步请求
 */
@interface ATIotSyncReq : ATDeviceData

/**
 * 数据包序号，App回复的时候，必须使用与请求时上传的包序号保持一致
 */
@property(nonatomic,assign) NSUInteger seralNumber;

/**
 * 请求类型
 * 0x00:所有设备
 * 0x01:继续同步剩余设备信息
 * 0x02:同步指定设备
 */
@property(nonatomic,assign,readonly)unsigned int reqType;

/**
 * 设备标识,对应iOT设备Id
 */
@property(nonatomic,strong)NSString * _Nullable iotMac;
@end


#pragma mark - ATIotControlReq

/**
 * iOT 设备状态控制请求
 */
@interface ATIotControlReq : ATDeviceData

/**
 * 设备索引,对应iOT设备Id
 */
@property(nonatomic,strong)NSString * _Nullable iotMac;

/**
 * iOT 设备类别
 */
@property(nonatomic,assign)ATIotCategory iotType;

/**
 * iOT设备信息
 */
@property(nonatomic,strong) ATIotDevice * _Nullable iotDevice;

/**
 * 响应状态码
 * stateCode = 0x01 成功
 * stateCode = 0x00 失败
 */
@property(nonatomic,assign)int stateCode;

/**
 * 操作请求类型
 */
@property(nonatomic,assign)int requestType;

/**
 * 标志位
 */
@property(nonatomic,assign)int flag;

/**
 * iot设备类型
 */
@property(nonatomic,assign)int typeInt;

/**
 * iot设备列表
 */
@property(nullable,nonatomic,strong)ATIotSummary *iotSummary;
@end


#pragma mark - ATGpsExerciseData

/**
 * GPS 运动数据
 */
@interface ATGpsExerciseData : ATDeviceData

/**
 * 运动数据项
 */
@property(nonatomic,strong) NSArray <ATGpsExerciseItem *>* _Nullable items;

/**
 * GPS 文件数据解析
 */
-(instancetype _Nonnull )initWithData:(NSData *_Nonnull)data;
@end


#pragma mark - ATStressTestReport

/**
 * 压力测试报告
 */
@interface ATStressTestReport : ATDeviceData

/**
 * 标志位
 */
@property(nonatomic,assign)unsigned int flag;

/**
 * 待上传记录数
 * 本地待上传记录总条数，
 */
@property(nonatomic,assign)unsigned int remainCount;

/**
 * 本包记录偏移
 * 本次上传记录在待上传记录中的偏移条数，
 */
@property(nonatomic,assign)unsigned int dataOffset;

/**
 * 本包传输结构个数
 * 本包包含压力测试项明细结构个数
 */
@property(nonatomic,assign)unsigned int countOfItem;

/**
 * 压力测试明细列表
 */
@property(nullable,nonatomic,strong) NSArray<ATStressTestItem *> *items;
@end


#pragma mark - ATStandTimeSummary

/**
 * 站立时长报告
 */
@interface ATStandTimeSummary : ATDeviceData

/**
 * 数据标志位
 */
@property(nonatomic,assign)NSUInteger flag;

/**
 * 站立时长报告总数
 */
@property(nonatomic,assign)NSUInteger count;

/**
 * 站立时长记录项
 */
@property(nonatomic,strong)NSArray <ATStandTimeItem *> *items;
@end


#pragma mark - ATMoodBattery
/**
 * 心情手环电量信息
 */
@interface ATMoodBattery : ATDeviceData

/**
 * Record time
 */
@property(nonatomic,assign) long utc;

/**
 * Battery value
 */
@property(nonatomic,assign) int value;

@end

#pragma mark - ATMoodSummary

/**
 * 心情数据概要信息
 */
@interface ATMoodSummary : ATDeviceData

/**
 * Number of remaining records
 */
@property(nonatomic,assign)NSUInteger remainCount;

/**
 * Total number of records
 */
@property(nonatomic,assign)NSUInteger count;

/**
 * Length of Mood Record Item
 */
@property(nonatomic,assign)NSUInteger length;

/**
 * Mood Record list
 */
@property(nonatomic,strong,nullable)NSArray<ATMoodItem *> *items;

/**
  * Low battery recording
  */
@property(nonatomic,strong,nullable)NSArray<ATMoodBattery *> *batteries;
@end


/**
 * System  Error message
 */
@interface ATSystemErrors : ATDeviceData

@property(nonatomic,strong)NSError * _Nullable error;
@end



/**
 * 乐心手环6S 历史数据汇总信息
 */
@interface ATCavoHistorySummary : ATDeviceData

/**
 * 历史记录条数
 */
@property(nonatomic,assign) int history;

/**
 * 记录详情
 */
@property(nonatomic,strong) NSArray <ATCavoHistoryItem *> * _Nullable items;

/**
 * 历史数据同步完成标志位
 */
@property(nonatomic,assign)BOOL syncEnd;

/**
 * 历史数据检测
 */
-(BOOL)checkHistory;

/**
 * 判断数据是否重复
 */
-(BOOL)checkSummary:(NSData *_Nonnull)data;
@end


/**
 * 乐心手环6S 心率数据汇总信息
 */
@interface ATHeartRateSummary : ATDeviceData

/**
 * 心率数据列表
 */
@property(nonatomic,strong) NSArray <ATHeartRate *> * _Nullable heartRates;

/**
 * 体温数据列表
 */
@property(nonatomic,strong) NSArray <ATTemperatureData *> * _Nullable temperatures;

@end


/**
 * 乐心手环6S 运动数据汇总信息
 */
@interface ATExerciseSummary : ATDeviceData

/**
 * 运动数据列表
 */
@property(nonatomic,strong) NSArray <ATExerciseData *> * _Nullable items;
@end
