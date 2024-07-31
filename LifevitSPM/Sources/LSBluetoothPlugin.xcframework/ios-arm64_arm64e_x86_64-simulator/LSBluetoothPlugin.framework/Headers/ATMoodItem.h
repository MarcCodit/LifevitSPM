//
//  ATMoodItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2022/1/25.
//  Copyright © 2022 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * 心情数据记录项
 */
@interface ATMoodItem : NSObject

/**
 * Record time
 */
@property(nonatomic,assign)int  utc;

/**
 * Mood value
 */
@property(nonatomic,assign)int  value;


/**
 * Mood Duration Time
 */
@property(nonatomic,assign) int durationTime;
@end


