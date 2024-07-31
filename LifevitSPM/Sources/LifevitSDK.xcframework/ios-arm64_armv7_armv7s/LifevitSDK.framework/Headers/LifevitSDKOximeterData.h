//
//  LifevitSDKOximeterData.h
//  LifevitSDK
//
//  Created by Oscar Navas on 7/11/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKOximeterData : NSObject

@property(strong, nonatomic) NSDate *date;
//@property(assign) double datemili;
@property (strong, nonatomic) NSNumber* sp2;
@property (strong, nonatomic) NSNumber* pi;
@property (strong, nonatomic) NSNumber* rpm;
@property (strong, nonatomic) NSNumber* lpm;
@property (strong, nonatomic) NSNumber* pleth;
//@property(assign) int nid;
//@property(assign) BOOL from_server;

-(NSString*) print;

@end
