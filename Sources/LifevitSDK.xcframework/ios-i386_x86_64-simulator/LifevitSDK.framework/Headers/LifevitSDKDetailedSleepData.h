//
//  LifevitSDKDetailedSleepData.h
//  LifevitSDK
//
//  Created by Oscar on 29/9/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKSleepData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKDetailedSleepData : LifevitSDKSleepData

@property (strong, nonatomic) NSMutableArray* sleepPer5Minutes;

- (id)initWith:(NSDate*) date
 sleepDuration:(NSNumber*) sleepDuration
 sleepDeepness:(NSNumber*) sleepDeepness
sleepPer5Minutes:(NSMutableArray*) sleepPer5Minutes;


@end

NS_ASSUME_NONNULL_END
