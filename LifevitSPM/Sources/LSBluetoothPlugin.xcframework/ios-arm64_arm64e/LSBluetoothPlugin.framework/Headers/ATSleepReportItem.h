//
//  ATSleepReportItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * 睡眠记录明细项
 */
@interface ATSleepReportItem : NSObject

/**
 * 睡眠深度状态
 * 0x01=清醒
 * 0x02=浅睡
 * 0x03=深睡
 * 0x04=眼动
 */
@property(nonatomic,assign) unsigned int state;

/**
 * 开始时间
 */
@property(nonatomic,assign) long startTime;

/**
 * 结束时间
 */
@property(nonatomic,assign) long endTime;

/**
 * 持续时间
 */
@property(nonatomic,assign) unsigned int duration;

/**
 * 睡眠数据所属日期
 */
@property(nonatomic,assign) long datekey;

/**
 * 对象信息
 */
-(NSString *)toString;
@end

