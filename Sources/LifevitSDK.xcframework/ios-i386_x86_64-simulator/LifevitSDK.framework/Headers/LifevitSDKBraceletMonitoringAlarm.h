//
//  LifevitSDKBraceletMonitoringAlarm.h
//  LifevitSDK
//
//  Created by Oscar on 25/09/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKBraceletSedentaryAlarm.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKBraceletMonitoringAlarm : LifevitSDKBraceletSedentaryAlarm

@property BOOL monday;
@property BOOL tuesday;
@property BOOL wednesday;
@property BOOL thursday;
@property BOOL friday;
@property BOOL saturday;
@property BOOL sunday;

@end

NS_ASSUME_NONNULL_END
