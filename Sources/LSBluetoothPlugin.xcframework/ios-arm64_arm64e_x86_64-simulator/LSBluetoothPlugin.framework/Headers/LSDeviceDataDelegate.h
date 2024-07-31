//
//  LSDeviceDataDelegate.h
//  LSDeviceBluetooth-Library
//
//  Created by caichixiang on 2017/2/28.
//  Copyright © 2017年 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceInfo.h"
#import "ATDeviceData.h"
#import "ATFileData.h"
#import "LSDeviceData.h"
#import "AWDeviceData.h"

@protocol LSDeviceDataDelegate <NSObject>

/**
 * 连接状态改变
 */
@required
-(void)bleDevice:(LSDeviceInfo *)device didConnectStateChanged:(LSConnectState)state;

/**
 * 设备版本信息更新
 */
@optional
-(void)bleDeviceDidInformationUpdate:(LSDeviceInfo *)device;

/**
 * 手环/手表 数据更新
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForActivityTracker:(ATDeviceData *)obj;

/**
 * 文件数据更新
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForFile:(ATFileData *)fileData;

/**
 * 体重数据更新
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForScale:(LSScaleWeight *)weight;


/**
 * 血压数据更新
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForBloodPressureMonitor:(LSBloodPressure *)data;

/**
 * 绑定信息更新
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForPairMsg:(LSDevicePairMsg *)msg;

/**
 * 设备在测量过程或出现错误时，上报的消息通知数据
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForNotification:(LSDeviceData *)obj;

/**
 * 血糖仪测量数据更新回调通知
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForBloodGlucose:(BGDataSummary *)data;


/**
 * 音频耳机数据更新回调通知
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForHeadset:(AWDeviceData *)data;


/**
 * 血氧仪测量数据更新回调通知
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForPulseOximeter:(LSDeviceData *)data;


/**
 * 体温计测量数据更新回调通知
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)device didDataUpdateForThermometer:(LSDeviceData *)data;
@end
