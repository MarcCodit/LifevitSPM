//
//  ATHeartRateZoneItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/24.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATHeartRateZoneItem : NSObject

/**
 * 心率下限
 */
@property(nonatomic,assign) unsigned int min;

/**
 * 心率上限
 */
@property(nonatomic,assign) unsigned int max;

@end

