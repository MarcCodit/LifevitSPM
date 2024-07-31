//
//  LifevitSDKBabyThermometer.h
//  LifevitSDK
//
//  Created by Oscar on 23/3/18.
//  Copyright © 2018 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLEDevice.h"

@interface LifevitSDKBabyThermometer : BLEDevice

@property CBService *rs232Service;
@property CBCharacteristic *readCharacteristic;
@property CBCharacteristic *sendCharacteristic;

- (void) startMeasurement;
+ (BOOL)isNameValid: (NSString*) name;

@end
