//
//  LifevitSDKGlucometerData.h
//  LifevitSDK
//
//  Created by Oscar on 21/3/22.
//  Copyright © 2022 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKGlucometerData : NSObject

@property(strong, nonatomic) NSDate *date;
@property (strong, nonatomic) NSNumber* glucose;

-(NSString*) print;

@end

NS_ASSUME_NONNULL_END
