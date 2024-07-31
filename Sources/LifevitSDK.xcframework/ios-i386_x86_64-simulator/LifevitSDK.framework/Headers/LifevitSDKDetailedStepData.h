//
//  LifevitSDKDetailedStepData.h
//  LifevitSDK
//
//  Created by Oscar on 28/9/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKStepData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKDetailedStepData : LifevitSDKStepData

@property (strong, nonatomic) NSMutableArray* stepsPerMinute;

- (id)initWith:(NSDate*) date
         steps:(NSNumber*) steps
      calories:(NSNumber*) calories
      distance:(NSNumber*) distance
stepsPerMinute:(NSMutableArray*) stepsPerMinute;


@end

NS_ASSUME_NONNULL_END
