//
//  LifevitSDKVitalParams.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKVitalNotification.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalParams : NSObject

enum Language {
    CHINESE = 0, ENGLISH = 1, SPANISH = 2
};



    @property BOOL distanceUnitKm;
@property BOOL hourDisplay24h;
@property BOOL wristSenseEnabled;
@property BOOL temperatureUnitCelsius;
@property BOOL nightMode;
@property BOOL ANCSEnabled;
@property int basicHeartRateSetting;
@property int screenBrightness;
@property int dialInterface;
   @property enum Language language;
@property int hand;

@property (strong, nonatomic) LifevitSDKVitalNotification* notifications;


@end

NS_ASSUME_NONNULL_END
