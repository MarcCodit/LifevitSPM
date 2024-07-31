//
//  LSBluetoothManager+Sync.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2019/11/8.
//  Copyright © 2019 sky. All rights reserved.
//

#import "LSBluetoothManager.h"

@class IBGattClients;

@interface LSBluetoothManager (Sync)


@property(nonatomic,assign)NSUInteger syncStatus;

/**
 * 获取设备列表
 */
-(NSArray *)getDevices;

/**
 * Added in version 2.0.0
 * 设置测量设备列表
 */
-(BOOL)setDevices:(NSArray *)list;

/**
 * Added in version 2.0.0
 * 添加单个测量设备
 */
-(BOOL)addDevice:(LSDeviceInfo *)lsDevice;


/**
 * Added in version 2.0.0
 * 以刷新设备列表和自动连接的方式添加测量设备，无需先stopDeviceSync,再刷新设备列表
 */
-(BOOL)addDevice:(LSDeviceInfo *)lsDevice autoConnect:(BOOL)enable;

/**
 * Added in version 2.0.0
 * 根据广播ID删除单个测量设备
 */
-(BOOL)deleteDevice:(NSString *)broadcastId;

/**
 * Added in version 2.0.0
 * 启动测量数据接收服务
 */
-(BOOL)startDeviceSync:(id<LSDeviceDataDelegate>)delegate;

/**
 * Added in version 2.0.0
 * 停止测量数据接收服务
 */
-(BOOL)stopDeviceSync;

/**
 * Added in version 2.0.0
 * 根据设备广播ID查询GattClient
 */
-(IBGattClients *)getDeviceSyncWorker:(NSString *)broadcastId;

@end
