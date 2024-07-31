//
//  ATExerciseStatus.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/18.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATExerciseStatus : NSObject
/**
 * 状态类型
 * 0x00:暂停
 * 0x01:开始
 */
@property(nonatomic,assign)unsigned int type;

/**
 * 状态对应UTC时间
 */
@property(nonatomic,assign)long utc;
@end

