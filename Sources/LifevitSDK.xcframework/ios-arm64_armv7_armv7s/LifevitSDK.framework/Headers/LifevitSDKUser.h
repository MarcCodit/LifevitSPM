//
//  LifevitSDKUser.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 11/09/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKUser : NSObject

@property (nonatomic, strong) NSDate* birthday;
@property (nonatomic, strong) NSNumber* height;
@property (nonatomic, strong) NSNumber* weight;
@property (nonatomic, strong) NSNumber* gender;
@end

NS_ASSUME_NONNULL_END
