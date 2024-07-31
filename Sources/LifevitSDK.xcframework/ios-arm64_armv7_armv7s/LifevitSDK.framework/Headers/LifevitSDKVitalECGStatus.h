//
//  LifevitSDKBraceletECGStatus.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LifevitSDKVitalECGConstantsData.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalECGStatus : NSObject

@property int status;
@property (strong, nonatomic) LifevitSDKVitalECGConstantsData* data;
@end

NS_ASSUME_NONNULL_END
