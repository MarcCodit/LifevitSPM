//
//  LifevitSDKThermometerData.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 20/11/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKThermometerData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* mode;
@property (strong, nonatomic) NSNumber* temperature;
@property (strong, nonatomic) NSString* unit;
@end
