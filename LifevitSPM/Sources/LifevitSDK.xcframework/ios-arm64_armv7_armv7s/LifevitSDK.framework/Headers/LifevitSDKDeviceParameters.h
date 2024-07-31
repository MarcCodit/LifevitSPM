//
//  LifevitSDKDeviceParameters.h
//  LifevitSDK
//
//  Created by Oscar on 10/9/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKAppNotification.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKDeviceParameters : NSObject

@property (nonatomic, assign) BOOL distanceUnitKm;
@property (nonatomic, assign) BOOL hourDisplay24h;
@property (nonatomic, assign) BOOL wristSenseEnabled;
@property (nonatomic, assign) BOOL temperatureUnitCelsius;
@property (nonatomic, assign) BOOL nightMode;
@property (nonatomic, assign) BOOL ANCSEnabled;
@property (nonatomic, strong) LifevitSDKAppNotification* ANCSInformation;
@property (nonatomic, strong) NSNumber* basicHeartRateSetting;
@property (nonatomic, strong) NSNumber* screenBrightness;
@property (nonatomic, strong) NSNumber* dialInterface;
@property (nonatomic, strong) NSNumber* language;


- (LifevitSDKDeviceParameters *) init: (BOOL) distanceUnitKm
                       hourDisplay24h: (BOOL) hourDisplay24h
                    wristSenseEnabled: (BOOL) wristSenseEnabled
               temperatureUnitCelsius: (BOOL) temperatureUnitCelsius
                            nightMode: (BOOL) nightMode
                          ANCSEnabled: (BOOL) ANCSEnabled
                      ANCSInformation: (LifevitSDKAppNotification*) ANCSInformation
                basicHeartRateSetting: (NSNumber*) basicHeartRateSetting
                     screenBrightness: (NSNumber*) screenBrightness
                        dialInterface: (NSNumber*) dialInterface
                             language: (NSNumber*) language;

-(NSString*) print;

@end

NS_ASSUME_NONNULL_END
