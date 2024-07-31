//
//  LifevitSDKBraceletVitalsData.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalHRVData : NSObject

@property (strong, nonatomic) NSDate* date;
@property int hrv;
@property int vascularAging;
@property int heartRate;
@property int fatigue;
@property int systolic;
@property int diastolic;
@end

NS_ASSUME_NONNULL_END
