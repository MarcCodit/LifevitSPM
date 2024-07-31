//
//  LSBluetoothManager+Pair.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2019/11/8.
//  Copyright © 2019 sky. All rights reserved.
//

#import "LSBluetoothManager.h"



@interface LSBluetoothManager (Pair)

@property(nonatomic,strong)NSMutableDictionary * _Nullable pairingDelegateMap;

/**
 * Added in version 2.0.0
 * 绑定设备
 */
-(BOOL)pairDevice:(LSDeviceInfo *_Nonnull)lsDevice
         delegate:(id<LSDevicePairingDelegate> _Nonnull)pairedDelegate;

/**
 * Added in version 2.0.0
 * 取消设备的配对操作
 */
-(void)cancelDevicePairing:(LSDeviceInfo *_Nonnull)lsDevice;

@end

