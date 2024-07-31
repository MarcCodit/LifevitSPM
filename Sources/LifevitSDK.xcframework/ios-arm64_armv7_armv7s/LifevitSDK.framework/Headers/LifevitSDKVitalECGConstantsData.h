//
//  LifevitSDKECGConstantsData.h
//  LifevitSDK
//
//  Created by Oscar on 17/9/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalECGConstantsData : NSObject

@property (strong, nonatomic) NSDate* date;
@property (strong, nonatomic) NSNumber* identifier;

@property (strong, nonatomic) NSNumber* hrv;
@property (strong, nonatomic) NSNumber* heartRate;
//@property (strong, nonatomic) NSNumber* mood;
@property (strong, nonatomic) NSNumber* breathingRate;


@end

NS_ASSUME_NONNULL_END
