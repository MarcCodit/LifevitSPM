//
//  SleepData.h	
//  HealthApp
//
//  Created by iNMovens Solutions on 16/2/16.
//  Copyright © 2016 Daga. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKSleepData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* sleepDuration;
@property (strong, nonatomic) NSNumber* sleepDeepness;

@end
