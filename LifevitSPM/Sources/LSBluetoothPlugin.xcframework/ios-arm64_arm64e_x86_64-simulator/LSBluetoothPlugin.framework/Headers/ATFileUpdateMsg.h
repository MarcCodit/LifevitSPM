//
//  ATFileUpdateMsg.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,ATFileState) {
    ATFileStateDownloading = 0x01,
    ATFileStateVerifySuccess = 0x02,
    ATFileStateVerifyFailure = 0x03,
    ATFileStateUpdating = 0x04,
    ATFileStateSuccess = 0x05,
    ATFileStateFailure = 0x06,
    ATFileStateCancel = 0x07,
};

@interface ATFileUpdateMsg : NSObject

/**
 * 文件更新状态
 * 0x01 = 文件下载中
 * 0x02 = 校验成功
 * 0x03 = 校验失败
 * 0x04 = 开始更新
 * 0x05 = 更新成功
 * 0x06 = 更新失败
 * 0x07 = 取消更新
 *
 */
@property(nonatomic,assign)NSUInteger state;

/**
 * 错码码，参考LSErrorCode的定义
 */
@property(nonatomic,assign)NSUInteger errorCode;

/**
 * 文件下载进度
 * 0%~100%
 */
@property(nonatomic,assign)NSUInteger progress;

/**
 * 是否正在下载文件
 */
@property(nonatomic,assign,readonly)BOOL isProgressUpdating;

/**
 * 是否正在更新状态
 */
@property(nonatomic,assign,readonly)BOOL isStateUpdating;

/**
 * 文件类型
 */
@property(nonatomic,assign)NSUInteger fileType;
@end

