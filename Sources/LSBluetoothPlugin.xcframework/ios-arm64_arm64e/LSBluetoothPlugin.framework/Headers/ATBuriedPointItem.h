//
//  ATBuriedPointItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATBuriedPointItem : NSObject

/**
  * 事件发生的UTC
  */
 @property(nonatomic,assign) long utc;

 /**
  * 菜单界面编码
  */
 @property(nonatomic,assign) unsigned int menuCode;

 /**
  * 事件编码
  */
 @property(nonatomic,assign) unsigned int eventCode;

/**
 * 事件统计次数
 */
@property(nonatomic,assign) unsigned int count;

/**
 * 统计开始时间
 */
@property(nonatomic,assign) unsigned long startUtc;

/**
 * 统计结束时间
 */
@property(nonatomic,assign)  long endUtc;

@end
