//
//  LifevitDevice.h
//  LifevitSDK
//
//  Created by Oscar on 11/10/18.
//  Copyright © 2018 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKDevice : NSObject

@property (nonatomic, strong) NSString* deviceIdentifier;
@property (nonatomic, strong) NSNumber* RSSI;
@property (nonatomic, strong) NSNumber* type;

+ (LifevitSDKDevice *)init:(NSString *) identifier
                      RSSI:(NSNumber*) RSSI;

- (NSNumber*) getDistanceToDevice;
- (int) getPowerValue;

@end

NS_ASSUME_NONNULL_END
