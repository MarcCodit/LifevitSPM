//
//  ATWorkingItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/10/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 手表、手环工作记录数据
 */
@interface ATWorkingItem : NSObject

/**
 * 操作类型
 * <p>0x00:自动</p>
 * <p>0x01:UI</p>
 * <p>0x02:按键</p>
 * <p>其他:预留</p>
 */
@property(nonatomic,assign)  int action;

/**
 * 操作时间
 */
@property(nonatomic,assign) long utc;

/**
 * 预留标志位
 */
@property(nonatomic,assign)  int flag;

@end
