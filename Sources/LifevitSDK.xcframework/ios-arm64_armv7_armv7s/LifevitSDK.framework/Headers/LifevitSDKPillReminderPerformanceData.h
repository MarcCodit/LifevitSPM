//
//  LifevitSDKPillReminderPerformanceData.h
//  LifevitSDK
//
//  Created by Oscar on 27/05/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <LifevitSDK/LifevitSDK.h>
#import "LifevitSDKPillReminderAlarmData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKPillReminderPerformanceData : LifevitSDKPillReminderAlarmData

@property(strong, nonatomic) NSDate *dateTaken;
@property(strong, nonatomic) NSNumber *statusTaken;

@end

NS_ASSUME_NONNULL_END
