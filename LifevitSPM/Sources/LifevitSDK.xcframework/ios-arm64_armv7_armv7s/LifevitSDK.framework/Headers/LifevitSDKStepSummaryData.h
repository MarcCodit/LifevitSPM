//
//  LifevitSDKStepSummaryData.h
//  LifevitSDK
//
//  Created by Oscar on 14/10/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKStepSummaryData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* totalSteps;
@property (strong, nonatomic) NSNumber* totalCalories;
@property (strong, nonatomic) NSNumber* totalDistance;
@property (strong, nonatomic) NSNumber* totalActiveTime;
@property (strong, nonatomic) NSNumber* totalExerciseTime;

@end

NS_ASSUME_NONNULL_END
