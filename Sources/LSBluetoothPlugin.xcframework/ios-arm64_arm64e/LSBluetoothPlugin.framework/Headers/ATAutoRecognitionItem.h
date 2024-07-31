//
//  ATAutoRecognitionItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"

/**
 * 运动模式自动识别
 */
@interface ATAutoRecognitionItem : NSObject

/**
 * 开关
 */
@property(nonatomic,assign) BOOL enable;

/**
 *运动类别
 */
@property(nonatomic,assign) ATExerciseType type;

@end

