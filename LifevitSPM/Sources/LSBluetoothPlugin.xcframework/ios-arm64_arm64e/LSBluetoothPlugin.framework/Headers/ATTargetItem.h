//
//  ATTargetItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/9/27.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"

@interface ATTargetItem : NSObject

/**
 * 目标实现状态
 */
@property(nonatomic,assign)BOOL state;

/**
 * 目标类型
 */
@property(nonatomic,assign) ATEncourageType type;


/**
 * 目标值
 *
 * 步数，类型 int
 * 距离，单位:米
 * 卡路里, 单位:0.1Kcal
 * 运动时长，单位:分钟
 */
@property(nonatomic,assign)  int value;


-(instancetype)initWithData:(NSData *)srcData;
@end

