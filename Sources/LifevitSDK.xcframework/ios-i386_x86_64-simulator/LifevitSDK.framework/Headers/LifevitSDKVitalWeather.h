//
//  LifevitSDKVitalWeather.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 5/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface LifevitSDKVitalWeather : NSObject

enum WeatherStatus{
    SUNNY = 0,
    CLEAR_NIGHT = 1,
    FAIR = 2,
    FAIR_NIGHT = 3,
    CLOUDY = 4,
    PARTLY_CLOUDY = 5,
    PARTLY_CLOUDY_NIGHT = 6,
    MOSTLY_CLOUDY = 7,
    MOSTLY_CLOUDY_NIGHT = 8,
    OVERCAST = 9,
    SHOWER = 10,
    THUNDERSHOWER = 11,
    THUNDERSHOWER_HAIL = 12,
    RAIN = 13,
    MODERATE_RAIN = 14,
    HEAVY_RAIN = 15,
    STORM = 16,
    HEAVY_STORM = 17,
    SEVERE_STORM = 18,
    ICE_RAIN = 19,
    SLEET = 20,
    SNOW_FLURRY = 21,
    LIGHT_SNOW = 22,
    MODERATE_SNOW = 23,
    HEAVY_SNOW = 24,
    SNOWSTORM = 25,
    DUST = 26,
    SAND = 27,
    DUSTSTORM = 28,
    SANDSTORM = 29,
    FOGGY = 30,
    HAZE = 31,
    WINDY = 32,
    BLUSTERY = 33,
    HURRICANE = 34,
    TROPICAL_STORM = 35,
    TORNADO = 36,
    COLD = 37,
    HOT = 38
};
@property enum WeatherStatus status;

@property int temperature;
@property int maxTemperature;
@property int minTemperature;
@property int airQuality;
@property (strong, nonatomic) NSString* location;

@end

NS_ASSUME_NONNULL_END
