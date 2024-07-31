//
//  LifevitSDKVitalPeriod.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKPeriod.h"
#import "LifevitSDKConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalPeriod : LifevitSDKPeriod
@property BraceletVitalDataType type;
@property BraceletVitalPeriodWorkingMode workingMode;
@property int intervalTime;
@end

NS_ASSUME_NONNULL_END
