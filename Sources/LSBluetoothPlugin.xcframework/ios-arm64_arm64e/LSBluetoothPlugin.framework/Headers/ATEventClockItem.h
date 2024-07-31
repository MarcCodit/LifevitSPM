//
//  ATEventClockItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/9/8.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"
#import "ATConfigItem.h"


@interface ATEventClockItem : ATConfigItem

/**
 * 事件提醒序号：1~5
 */
@property(nonatomic,assign)  int index;

/**
 * 事件提醒标题内容
 */
@property(nullable,nonatomic,strong) NSString *title;

/**
 * 事件提醒开关
 */
@property(nonatomic,assign) ATEventClockState state;


/**
 * 提醒时间
 */
@property(nullable,nonatomic,strong) NSString *time;


/**
 * 每周的重复时间
 */
@property(nullable,nonatomic,strong) NSArray <NSNumber *>*repeatDay;

/**
 * 震动方式
 */
@property(nonatomic,assign) ATVibrationMode vibrationMode;


/**
 * 振动等级1，范围0-9
 */
@property(nonatomic,assign)  int vibrationStrength1;


/**
 * 振动等级1，范围0-9。当震动方式为持续震动时，该字段无效
 */
@property(nonatomic,assign)  int vibrationStrength2;


/**
 * 振动持续时间,表示提醒持续总时长，最大值60s
 */
@property(nonatomic,assign)  int vibrationTime;


/**
 * 事件提醒类型，参考ReminderType的定义
 */
@property(nonatomic,assign) ATEventReminderType reminderType;


/**
 * 小睡提醒设置
 */
@property(nullable,nonatomic,strong) ATNapRemind *napRemind;

/**
 * 浅睡唤醒设置
 */
@property(nullable,nonatomic,strong) ATSleepWakeup *wakeupRemind;

/**
 * 重复类型
 */
@property(nonatomic,assign)ATRepeatType repeatType;

/**
 * 提醒时间 UTC,
 */
@property(nonatomic,assign)int clockTime;

-(NSData *)toBytes:(NSUInteger)cmd syncState:(ATClockSyncState)state;

-(NSData *)toCavoProtoBytes;
@end
