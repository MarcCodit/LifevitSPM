//
//  LifevitSDKSleepSummaryData.h
//  LifevitSDK
//
//  Created by Oscar on 14/10/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKSleepSummaryData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* awakes;
@property (strong, nonatomic) NSNumber* totalLightMinutes;
@property (strong, nonatomic) NSNumber* totalDeepMinutes;

@end

NS_ASSUME_NONNULL_END
