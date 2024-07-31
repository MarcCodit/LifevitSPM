//
//  LifevitSDKTensioBraceletInterval.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 2/5/18.
//  Copyright © 2018 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum TENSIO_HOUR_MINUTE { O_CLOCK, HALFPAST } TENSIO_HOUR_MINUTE;
typedef enum TENSIO_MINUTE_INTERVAL { HALF_HOUR, HOUR, HOUR_AND_A_HALF, TWO_HOURS, TWO_HOURS_AND_A_HALF, THREE_HOURS, THREE_HOURS_AND_A_HALF, FOUR_HOURS } TENSIO_MINUTE_INTERVAL;

@interface LifevitSDKTensioBraceletInterval : NSObject

@property NSNumber* startHour;
@property TENSIO_HOUR_MINUTE startMinuteInterval;
@property NSNumber* endHour;
@property TENSIO_HOUR_MINUTE endMinuteInterval;
@property TENSIO_MINUTE_INTERVAL ambulatoriInterval;

@end
