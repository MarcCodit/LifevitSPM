//
//  LifevitSDKBraceletData.h
//  TensiometerSDK
//
//  Created by David Casas on 4/9/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKBraceletData : NSObject

@property (strong, nonatomic) NSMutableArray* heartData;
@property (strong, nonatomic) NSMutableArray* stepsData;
@property (strong, nonatomic) NSMutableArray* sleepData;

@end
