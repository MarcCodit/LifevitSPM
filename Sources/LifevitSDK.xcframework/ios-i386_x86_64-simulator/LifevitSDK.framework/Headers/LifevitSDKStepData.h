//
//  StepData.h
//  HealthApp
//
//  Created by iNMovens Solutions on 16/2/16.
//  Copyright © 2016 Daga. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKConstants.h"

@interface LifevitSDKStepData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* steps;
@property (strong, nonatomic) NSNumber* calories;
@property (strong, nonatomic) NSNumber* distance;
@property (strong, nonatomic) NSNumber* hr;
@property (strong, nonatomic) NSNumber* activeTime;

-(NSString*) print;

@end
