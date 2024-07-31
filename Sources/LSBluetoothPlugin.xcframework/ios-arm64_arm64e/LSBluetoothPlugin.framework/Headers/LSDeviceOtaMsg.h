//
//  LSDeviceOtaMsg.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2020/5/19.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSBluetoothManagerProfiles.h"

@interface LSDeviceOtaMsg : NSObject

@property(nonatomic,assign)LSUpgradeState status;           //升级状态
@property(nonatomic,assign)LSErrorCode errorCode;           //错误码
@property(nullable,nonatomic,strong)NSData *srcData;                 //原数据包
@property(nonatomic,assign)NSUInteger upgradeProgress;      //升级进度
@end

