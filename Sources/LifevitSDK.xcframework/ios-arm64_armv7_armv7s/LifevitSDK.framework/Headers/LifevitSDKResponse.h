//
//  LifevitSDKResponse.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 5/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKResponse : NSObject

@property BraceletVitalCommand command;
@property BraceletVitalDataType type;
@property (strong, nonatomic) id data;

@end

NS_ASSUME_NONNULL_END
