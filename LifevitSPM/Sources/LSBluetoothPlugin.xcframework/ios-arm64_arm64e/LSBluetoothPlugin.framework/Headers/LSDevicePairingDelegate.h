//
//  LSDevicePairingDelegate.h
//  LsBluetooth-Test
//
//  Created by sky on 14-8-13.
//  Copyright (c) 2014年 com.lifesense.ble. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSDeviceInfo.h"
#import "LSDevicePairMsg.h"


@protocol LSDevicePairingDelegate <NSObject>

/**
 * 设备配对结果
 */
@required
-(void)bleDevice:(LSDeviceInfo *)device didPairStateChanged:(LSPairState)state;

/**
 * 在设备绑定或配对过程中，操作指令更新结果回调
 */
@optional
-(void)bleDevice:(LSDeviceInfo *)lsDevice didPairMessageUpdate:(LSDevicePairMsg *)pairMsg;
@end
