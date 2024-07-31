//
//  LifevitSDKECGData.h
//  LifevitSDK
//
//  Created by Oscar on 16/9/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalECGData : NSObject

@property (strong, nonatomic) NSNumber* identifier;
@property (strong, nonatomic) NSDate* date;

@property (strong, nonatomic) NSNumber* hrv;
@property (strong, nonatomic) NSNumber* heartRate;
@property (strong, nonatomic) NSNumber* breathRate;
@property (strong, nonatomic) NSNumber* pr;
@property (strong, nonatomic) NSNumber* qt;
@property (strong, nonatomic) NSNumber* qtc;
@property (strong, nonatomic) NSNumber* trs;

@property (strong, nonatomic) NSMutableArray* ecgData;

- (void) calculateValues;
@end

NS_ASSUME_NONNULL_END
