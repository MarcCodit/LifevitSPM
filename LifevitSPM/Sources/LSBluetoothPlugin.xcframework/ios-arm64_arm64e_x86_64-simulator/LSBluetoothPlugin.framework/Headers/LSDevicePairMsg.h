//
//  LSPairCommand.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2019/11/14.
//  Copyright © 2019 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSUserInfo.h"


typedef NS_ENUM(NSUInteger,LSPairCommand)
{
    LSPairCommandUnknown=0x00,              //未知状态
    LSPairCommandPairState=0x01,            //设备绑定状态
    LSPairCommandRandomCode=0x02,           //随机码输入提示
    LSPairCommandPairConfirm=0x03,          //绑定确认
    LSPairCommandRegister=0x04,             //设备ID注册提示，A6 Scale
    LSPairCommandDeviceUser=0x05,           //用户绑定提示
    LSPairCommandPairRequest=0x06,          //绑定请求，返回设备登录指令
    LSPairCommandPressDown = 0x07,          //提示按压MIO按键
    
    LSPairCommandUserConfirm = 0x10,        //用户绑定确认

};

@interface LSDevicePairMsg : NSObject

/**
 * 绑定指令
 */
@property(nonatomic,assign)LSPairCommand cmd;

/**
 * 绑定状态
 */
@property(nonatomic,assign)BOOL state;

/**
 * 绑定的消息内容
 */
@property(nullable,nonatomic,strong)id data;

/**
 * 绑定方式
 * 0x03 = 随机码绑定
 * 0x04 = 二维码绑定
 * 0x05 = 手动绑定
 */
@property(nonatomic,assign)NSUInteger pairMode;

/**
 * 是否清除绑定过程中的连接缓存
 */
@property(nonatomic,assign)BOOL isClearCache;
@end


/**
 * 设备用户资料信息
 */
@interface LSDeviceUserProfiles : NSObject

@property(nonnull,nonatomic,strong)NSArray <LSUserInfo *>*users;
@end
