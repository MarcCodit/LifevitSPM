//
//  LifevitSDKSportData.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 8/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKStepData.h"


NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKSportData : LifevitSDKStepData

@property (strong, nonatomic) NSNumber* exerciseTime;
@property BraceletVitalSportType sportType;

@end

NS_ASSUME_NONNULL_END
