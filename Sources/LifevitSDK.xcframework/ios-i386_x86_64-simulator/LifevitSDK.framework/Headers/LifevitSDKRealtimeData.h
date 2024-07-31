//
//  LifevitSDKRealtimeData.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 8/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKStepSummaryData.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKRealtimeData : NSObject

@property LifevitSDKStepSummaryData* stepData;
@property int heartrate;
@property double temperature;

@end

NS_ASSUME_NONNULL_END
