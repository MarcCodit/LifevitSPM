//
//  HeartBeatData.h
//  HealthApp
//
//  Created by David Casas on 12/7/17.
//  Copyright © 2017 Daga. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKHeartBeatData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* heartRate;

@end
