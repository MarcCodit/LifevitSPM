//
//  LifevitSDKVitalActivityPeriod.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKPeriod.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalActivityPeriod : LifevitSDKPeriod

@property int exerciseReminderPeriod;
@property int minimumNumberSteps;
@property BOOL motionEnabled;

@end

NS_ASSUME_NONNULL_END
