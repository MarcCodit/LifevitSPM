//
//  ATReminderItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/9/24.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"
#import "ATDisturbItem.h"

@interface ATReminderItem : NSObject

/**
 * 提醒索引,1~14
 */
@property(nonatomic,assign)  int index;

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
 * 提醒方式
 * 0x00 = 定时
 * 0x01 = 周期
 */
@property(nonatomic,assign)  int remindMode;

/**
 * 提醒时间，格式HH:MM
 */
@property(nullable,nonatomic,strong) NSString *remindTime;


/**
 * 提醒周期,单位min
 */
@property(nonatomic,assign)  int remindCycle;

/**
 * 振动持续时间,单位秒,最大60秒
 */
@property(nonatomic,assign)  int vibrationTime;

/**
 * 提醒重复时间,参考ATWeekDay的定义
 */
@property(nullable,nonatomic,strong) NSArray *repeatDay;

/**
 * 振动方式
 */
@property(nonatomic,assign) ATVibrationMode vibrationMode;

/**
 * 振动强度1，范围0-9
 */
@property(nonatomic,assign)  int vibrationStrength1;


/**
 * 振动强度2，范围0-9。当震动方式为持续震动时，该字段无效
 */
@property(nonatomic,assign)  int vibrationStrength2;

/**
 * 勿扰模式设置项
 */
@property(nullable,nonatomic,strong) ATDisturbItem *disturb;

/**
 * 转字节流数据
 */
-(NSData *)toBytes;
@end

