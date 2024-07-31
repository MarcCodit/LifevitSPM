//
//  ATDisturbItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/9/24.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ATDisturbItem : NSObject

/**
 * 勿扰模式开关
 */
@property(nonatomic,assign) BOOL enable;


/**
 * 勿扰模式开始时间,格式 HH:MM
 */
@property(nullable,nonatomic,strong) NSString *startTime;

/**
 * 勿扰模式结束时间,格式 HH:MM
 */
@property(nullable,nonatomic,strong) NSString *endTime;

@end
