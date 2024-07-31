//
//  ATStressTestItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2021/3/31.
//  Copyright © 2021 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * 压力测试项明细
 */
@interface ATStressTestItem : NSObject

/**
 * 测试时间
 */
@property(nonatomic,assign) long utc;


/**
 * 压力值
 */
@property(nonatomic,assign) unsigned int value;

@end
