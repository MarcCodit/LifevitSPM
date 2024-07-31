//
//  LSBluetoothManager+Push.h
//  LSDeviceBluetooth-Library
//
//  Created by caichixiang on 2017/4/6.
//  Copyright © 2017年 sky. All rights reserved.
//

#import "LSBluetoothManager.h"
#import "LSDevicePairMsg.h"
#import "IBDeviceSetting.h"
#import "IBCoreProfiles.h"
//#import "ATF"


@interface LSBluetoothManager (Push)

/**
 * Added in version 2.0.0
 * 推送设备绑定/配对消息指令
 */
-(void)pushPairSetting:(LSDevicePairMsg *_Nonnull)msg
             forDevice:(LSDeviceInfo *_Nonnull)device
           forResponse:(IBPushRespBlock _Nonnull )resp;


/**
 * Added in version 2.0.0
 * 推送设备设置消息指令
 */
-(void)pushSyncSetting:(IBDeviceSetting *_Nonnull)setting
             forDevice:(LSDeviceInfo *_Nonnull)device
           forResponse:(IBPushRespBlock _Nonnull)resp;


/**
 * 文件更新推送，支持固件文件、表盘相册下载推送
 */
-(void)pushFileSetting:(IBDeviceSetting *_Nonnull)setting
             forDevice:(LSDeviceInfo *_Nonnull)device
           forResponse:(IBPushRespBlock _Nonnull)resp;


/**
 * Added in version 2.0.0
 * 查询设备数据
 */
-(void)queryDeviceData:(IBDeviceSetting *_Nonnull)setting
             forDevice:(LSDeviceInfo *_Nonnull)device
           forResponse:(IBPushRespBlock _Nonnull)resp;


/**
 * Added in version 2.0.0
 * 读取设备电量电压信息
 */
-(BOOL)readDeviceBattery:(NSString *_Nonnull)broadcastId
             forResponse:(IBPushRespBlock _Nonnull)resp;


/**
 * 取消文件消息推送设置，如取消固件升级或取消表盘文件下载
 */
-(void)cancelFileSetting:(IBDeviceSetting *_Nonnull)setting forDevice:(LSDeviceInfo *)device;

@end
