//
//  ATGpsExerciseItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2021/2/1.
//  Copyright © 2021 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * GPS 运动项数据
 */
@interface ATGpsExerciseItem : NSObject

/**
 * 纬度
 */
@property(nonatomic,assign)  double latitude;

/**
 * 经度
 */
@property(nonatomic,assign)  double longitude;

/**
 * UTC
 */
@property(nonatomic,assign)  unsigned int utc;

/**
 * 运动ID
 */
@property(nonatomic,assign)  unsigned int exerciseId;

/**
 * 实时速度(Km/h)
 */
@property(nonatomic,assign)  double speed;

/**
 * 每公里标志
 */
@property(nonatomic,assign)  unsigned int flag ;

/**
 * 预留字节
 */
@property(nonatomic,strong)  NSData*unused;

/**
 * 对象信息
 */
-(NSDictionary *)toString;
@end
