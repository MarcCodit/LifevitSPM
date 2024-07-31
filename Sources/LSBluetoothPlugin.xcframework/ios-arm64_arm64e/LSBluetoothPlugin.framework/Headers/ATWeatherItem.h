//
//  ATWeatherItem.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/24.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATSettingProfiles.h"

@interface ATWeatherItem : NSObject

/**
 * Weather state
 */
@property(nonatomic,assign) ATWeatherType weatherState;

/**
 * 最高温度，单位：℃
 */
@property(nonatomic,assign)  int temperature1;

/**
 * 最低温度，单位：℃
 */
@property(nonatomic,assign)  int temperature2;

/**
 * 空气质量 AQI
 */
@property(nonatomic,assign)  int aqi;

/**
 * 当前温度，单位：℃
 */
@property(nonatomic,assign)  int temperature;

/**
 * 风速 单位：m/s
 */
@property(nonatomic,assign)  int windSpeed;

/**
 * 相对湿度
 */
@property(nonatomic,assign)  int rh;

/**
 * UV指数
 */
@property(nonatomic,assign)  int uv;

/**
 * 日出时间，格式 HH:MM
 */
@property(nonatomic,strong) NSString *sunriseTime;

/**
 * 日落时间，格式 HH:MM
 */
@property(nonatomic,strong) NSString *sunsetTime;
@end

