//
//  ATAlarmClockItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"

@interface ATAlarmClockItem : NSObject

/**
 * 闹钟开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 闹钟时间
 */
@property(nullable,nonatomic,strong) NSString *time;

/**
 * 提醒重复时间
 */
@property(nullable,nonatomic,strong) NSArray *repeatDay;

/**
 * 振动方式
 */
@property(nonatomic,assign) ATVibrationMode vibrationMode;

/**
 * 振动等级1，范围0-9
 */
@property(nonatomic,assign) unsigned int vibrationStrength1;


/**
 * 振动等级1，范围0-9。当震动方式为持续震动时，该字段无效<
 */
@property(nonatomic,assign) unsigned int vibrationStrength2;


/**
 * 振动持续时间,表示提醒持续总时长，最大值60s
 */
@property(nonatomic,assign) unsigned int vibrationTime;

@end

