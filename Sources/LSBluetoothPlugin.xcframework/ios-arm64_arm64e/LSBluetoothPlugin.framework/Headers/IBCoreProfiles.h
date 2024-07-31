//
//  IBCoreProfiles.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2019/9/27.
//  Copyright © 2019 sky. All rights reserved.
//

#ifndef IBCoreProfiles_h
#define IBCoreProfiles_h

/**
 * Push指令设置结果回调代码块
 */
typedef void(^IBPushRespBlock)(BOOL status,NSUInteger error,id data);


/**
 * 错误码
 */
typedef NS_ENUM(NSUInteger,IBErrorCode) {
    IBECodeUnknown=0x00,
    IBECodeDeviceNotConnected=0x07,
    IBECodeDeviceUnsupported=0x08,
};


/**
 * 设备连接模式
 */
typedef NS_ENUM(NSUInteger,IBConnectMode)
{
    IBConnectModeSync=0,        //数据同步连接模式
    IBConnectModePair=1,        //设备绑定、配对连接模式
    IBConnectModeUpgrade=2,     //固件升级连接模式
    IBConnectModeRead=3,        //读取设备MAC或设备信息
    IBConnectModePairToSync=4,  //配对转同步
};

/**
 * 设备连接状态
 */
typedef NS_ENUM(NSUInteger,IBConnectState)
{
    IBConnectStateUnknown=0,             //未知
    IBConnectStateConnected=1,           //底层连接成功
    IBConnectStateConnectFailure=2,      //连接失败
    IBConnectStateDisconnect=3,          //连接断开
    IBConnectStateConnecting=4,          //连接中
    IBConnectStateConnectionTimeout=5,   //连接超时
    IBConnectStateConnectSuccess=6,      //协议层的连接成功
} ;

/**
 * Gatt Message Filter Type
 */
typedef NS_ENUM(NSUInteger,IBGattFilter){
    IBGattFilterService=0x00,           //根据Service UUID 过滤
    IBGattFilterCharacteristic=0x01,    //根据Characteristic UUID 过滤
};


/**
 * Gatt Message Action
 */
typedef NS_ENUM(NSUInteger,IBGattAction){

    IBGattActionUnknown=0x00,       //未知状态
    IBGattActionEnable=0x01,        //使能通道
    IBGattActionEnableDone=0x02,    //通道使能完成
    IBGattActionDisable=0x03,       //关闭通道
    IBGattActionDisableDone=0x04,   //通道关闭完成
    IBGattActionRead=0x05,          //读取特征通道
    IBGattActionReadDone=0x06,      //读取特征通道完成
    IBGattActionWrite=0x07,         //写特征通道
    IBGattActionNotify=0x08,        //特征通道Enable or Disable
} ;


/**
 * 应用消息推送类别
 */
typedef NS_ENUM(NSUInteger,IBMsgPushCategory) {
    
    IBMsgPushCategoryUnknown=0x00,
    IBMsgPushCategoryRead=0x01,             //Characteristic 读取操作消息
    IBMsgPushCategoryWrite=0x02,            //Characteristic 写入操作消息
    IBMsgPushCategoryEnable=0x03,           //Characteristic 打开操作消息
    IBMsgPushCategoryDisable=0x04,          //Characteristic 关闭操作消息
    IBMsgPushCategoryOta=0x05,              //OTA 消息通知
    IBMsgPushCategoryCancel = 0x06,         //取消
    IBMsgAppStateChanged = 0x07,            //应用状态改变,需检测通道是否被关闭
};


/**
 * 应用前后台状态
 */
typedef NS_ENUM(NSUInteger,IBAppState) {
    IBAppStateForeground,   //前台
    IBAppStateBackground    //后台
};

#endif /* IBCoreProfiles_h */
