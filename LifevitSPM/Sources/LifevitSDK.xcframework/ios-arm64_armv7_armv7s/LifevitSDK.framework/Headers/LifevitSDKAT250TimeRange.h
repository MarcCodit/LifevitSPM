//
//  LifevitSDKAT250TimeRange.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 9/2/18.
//  Copyright © 2018 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LifevitSDKAT250TimeRange : NSObject

@property int startHour;
@property  int startMinute;
@property  int endHour;
@property  int endMinute;
@property  BOOL monday;
@property  BOOL tuesday;
@property  BOOL wednesday;
@property  BOOL thursday;
@property  BOOL friday;
@property  BOOL saturday;
@property  BOOL sunday;

- (void) setOnlyWeekDays;
- (void) setOnlyWeekend;
@end
