//
//  LSNotificationMsg.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2019/11/13.
//  Copyright © 2019 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LSDeviceInfo.h"
#import "LSBluetoothManagerProfiles.h"

FOUNDATION_EXPORT NSString *const PairDidStateUpdateNotification;
FOUNDATION_EXPORT NSString *const PairDidDataUpdateNotification;

FOUNDATION_EXPORT NSString *const SyncDidStateUpdateNotification;
FOUNDATION_EXPORT NSString *const SyncDidDataUpdateNotification;

FOUNDATION_EXPORT NSString *const OtaDidStateUpdateNotification;
FOUNDATION_EXPORT NSString *const OtaDidDataUpdateNotification;


@interface LSNotificationMsg : NSObject

@property(nonatomic,strong,readonly)NSString *notificationName;

@property(nonatomic,strong)id obj;
@property(nonatomic,strong)LSDeviceInfo *device;
@property(nonatomic,strong)CBPeripheral *peripheral;
@property(nonatomic,assign)LSConnectState state;
@property(nonatomic,assign)NSUInteger mode;
@property(nonatomic,assign)NSUInteger errorCode;
@property(nonatomic,assign)BOOL pushStatus;

/**
 * 根据通知名称，创建通知消息对象
 */
-(instancetype)initWithName:(NSString *)name;


@end

