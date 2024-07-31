//
//  ATSedentaryItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/24.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"
#import "ATConfigItem.h"

@interface ATSedentaryItem : ATConfigItem

/**
 * 索引序号
 */
@property(nonatomic,assign)NSUInteger index;

/**
 * 久坐提醒开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 * 久坐提醒开始时间
 */
@property(nullable,nonatomic,strong) NSString *startTime;

/**
 * 久坐提醒结束时间
 */
@property(nullable,nonatomic,strong) NSString *endTime;

/**
 * 久坐时间，多久不动就提醒(单位：min)
 */
@property(nonatomic,assign)  int sedentaryTime;

/**
 * 振动持续时间（单位：seconds）
 */
@property(nonatomic,assign)  int vibrationTime;

/**
 * 提醒重复时间
 */
@property(nullable,nonatomic,strong) NSArray *repeatDay;

/**
 * 振动方式
 */
@property(nonatomic,assign)  ATVibrationMode vibrationMode;

/**
 * 振动等级1，范围0-9
 */
@property(nonatomic,assign)  int vibrationStrength1;

/**
 * 振动等级1，范围0-9。当震动方式为持续震动时，该字段无效
 */
@property(nonatomic,assign)  int vibrationStrength2;


/**
 * 勿扰模式设置
 */
@property(nullable,nonatomic,strong) ATDisturbMode *disturbMode;


-(instancetype)initWithData:(NSData *)data;
@end
