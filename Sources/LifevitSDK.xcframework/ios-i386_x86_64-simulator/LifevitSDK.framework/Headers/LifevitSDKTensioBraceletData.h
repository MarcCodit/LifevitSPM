//
//  LifevitSDKTensioBraceletData.h
//  TensiometerSDK
//
//  Created by David Casas on 3/8/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKTensioBraceletData : NSObject

@property (strong, nonatomic) NSDate* date;
//@property (strong, nonatomic) NSNumber* errorCode;
@property (strong, nonatomic) NSNumber* systolic;
@property (strong, nonatomic) NSNumber* diastolic;
@property (strong, nonatomic) NSNumber* pulse;
@property (strong, nonatomic) NSNumber* irregular;
@end
