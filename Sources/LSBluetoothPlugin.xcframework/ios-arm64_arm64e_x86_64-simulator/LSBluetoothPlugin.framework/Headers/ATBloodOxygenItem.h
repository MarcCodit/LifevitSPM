//
//  ATBloodOxygenItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATBloodOxygenItem : NSObject

/**
 * UTC
 */
@property(nonatomic,assign) long utc;

/**
 * 血氧数据
 */
@property(nonatomic,assign) unsigned int bloodOxygen;

/**
 * 心率数据
 */
@property(nonatomic,assign) unsigned int heartRate;

/**
 * 血氧数据类型
 *
 * 0x00 = 普通血氧数据
 * 0x01 = 异常血氧数据
 */
@property(nonatomic,assign) unsigned int type;

/**
 * 最高血氧饱和度
 */
@property(nonatomic,assign) int maxSpo2;

/**
 * 最低血氧饱和度
 */
@property(nonatomic,assign) int minSpo2;
@end
