//
//  LifevitSDKVitalAlarm.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKBraceletAlarm.h"
#import "LifevitSDKConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalAlarm : LifevitSDKBraceletAlarm


@property BOOL enabled;
@property BraceletVitalAlarmType type;

@property (strong, nonatomic) NSString* text;
@end

NS_ASSUME_NONNULL_END
