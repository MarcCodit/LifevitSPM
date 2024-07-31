//
//  ATStepItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/11.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>



/**
 * 手表/手环 步数记录数据
 */
@interface ATStepItem : NSObject

/**
 * 命令字
 */
@property(nonatomic,assign) unsigned int cmd;

/**
 * 步数
 */
@property(nonatomic,assign) unsigned int step;

/**
 * UTC
 */
@property(nonatomic,assign)  long utc;

/**
 * 运动量
 */
@property(nonatomic,assign)  float exerciseAmount;

/**
 * 卡路里
 */
@property(nonatomic,assign)  float calories;

/**
 * 运动时间
 */
@property(nonatomic,assign)  unsigned int exerciseTime;

/**
 * 距离
 */
@property(nonatomic,assign)  unsigned int distance;

/**
 * 状态
 */
@property(nonatomic,assign)  unsigned int status;

/**
 * 睡眠状态，旧手环
 */
@property(nonatomic,assign)  unsigned int sleepStatus;

/**
 * 抖动等级，旧手环
 */
@property(nonatomic,assign)  unsigned int intensityLevel;

/**
 * 电压
 */
@property(nonatomic,assign)  float batteryVoltage;

/**
 * 测量时间，对应UTC的字符串格式
 */
@property(nullable,nonatomic,strong)  NSString* measureTime;

/**
 * 静息心率
 */
@property(nonatomic,assign) unsigned int restingHeartRate;

/**
 * 扩展数据标志位
 */
@property(nonatomic,assign) int flag;

/**
 * 站立时长
 * 默认值为-1，表示该设备不支持
 */
@property(nonatomic,assign) int standTime;

/**
 * UTC偏移量 乐心手环6S手环
 */
@property(nonatomic,assign)  int offset;

/**
 * 乐心手环6S手环 步数计算模式
 */
@property(nonatomic,assign)  int mode;

@end



/**
 * 站立时长记录
 */
@interface ATStandTimeItem : NSObject

/**
 * UTC
 */
@property(nonatomic,assign)  long utc;

/**
 * 总站立时长，单位小时
 */
@property(nonatomic,assign) NSUInteger time;


/**
 * 站立时长每小时分布描述，0~23 小时
 * 如1，2，5 表示当天的1、2、5小时存在站立时长，其他时间不存在站立
 */
@property(nonatomic,strong,nullable) NSArray <NSNumber *>*items;

-(instancetype _Nonnull)initWithUtc:(long)utc value:(NSUInteger)value;
@end
