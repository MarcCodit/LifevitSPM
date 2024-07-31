//
//  LifevitSDKPeriod.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKPeriod : NSObject

@property BOOL monday;
@property BOOL tuesday;
@property BOOL wednesday;
@property BOOL thursday;
@property BOOL friday;
@property BOOL saturday;
@property BOOL sunday;


@property int startHour;
@property int startMinute;
@property int endHour;
@property int endMinute;

- (void) setWeekdays: (BOOL) enabled;
- (void) setWeekend: (BOOL) enabled;
- (void) setWeek: (BOOL) enabled;

- (BOOL) checkValidDates;

@end

NS_ASSUME_NONNULL_END
