//
//  LSBluetoothManagerProfiles.h
//  LSDeviceBluetooth-Library
//
//  Created by caichixiang on 2017/3/14.
//  Copyright © 2017年 sky. All rights reserved.
//

#ifndef LSBluetoothManagerProfiles_h
#define LSBluetoothManagerProfiles_h

@class LSDeviceInfo;

/**
 * 扫描结果回调代码块
 */
typedef void(^SearchResultsBlock)(LSDeviceInfo *lsDevice);


#pragma mark - LSManagerState 工作状态

/**
 * 管理器当前的工作状态
 */
typedef NS_ENUM(NSUInteger,LSManagerState)
{
    LSManagerStateFree=0,       //空闲
    LSManagerStateScaning=1,    //扫描状态
    LSManagerStatePairing=2,    //设备配对状态
    LSManagerStateSyncing=3,    //设备同步状态
    LSManagerStateUpgrading=4,  //设备升级状态
};

#pragma mark - LSScanMode 扫描模式

/**
 * 扫描模式
 */
typedef NS_ENUM(NSUInteger,LSScanMode)
{
    LSScanModeFree=0,     //空闲
    LSScanModeNormal=1,   //正常的扫描模式
    LSScanModeUpgrade=2,  //升级模式下的扫描
    LSScanModelSync=3,    //数据同步模式下的扫描
};

#pragma mark - LSDeviceType 设备类型

/**
 * 设备类型
 */
typedef NS_ENUM(NSUInteger,LSDeviceType)
{
    LSDeviceTypeUnknown=0,              //设备类型未知
    LSDeviceTypeWeightScale=1,          //01 体重秤
    LSDeviceTypeFatScale = 2,           //02 脂肪秤
    LSDeviceTypeHeightMeter = 3,        //03 身高测量仪
    LSDeviceTypePedometer =4,           //04 手环
    LSDeviceTypeWaistlineMeter=5,       //05 腰围尺
    LSDeviceTypeBloodGlucoseMeter=6,    //06 血糖仪
    LSDeviceTypeThermometer=7,          //07 温度计
    LSDeviceTypeBloodPressureMeter =8,  //08 血压计
    LSDeviceTypeKitchenScale = 9,       //09 厨房秤
    LSDeviceTypePulseOximeter = 10,     //10 血氧仪
    LSDeviceTypeEarphone=0x10,          //0x10,耳机类产品
};

#pragma mark - LSBroadcastType 广播类型

/**
 * 设备广播类型
 */
typedef NS_ENUM(NSUInteger,LSBroadcastType)
{
    LSBroadcastTypeNormal=1,      //设备的正常广播
    LSBroadcastTypePair=2,        //设备配对广播
    LSBroadcastTypeAll=3,         //设备的所有广播
};

#pragma mark - LSConnectionState 连接状态

/**
 * 设备的连接状态
 */
typedef NS_ENUM(NSUInteger,LSConnectState)
{
    LSConnectStateUnknown=0,             //未知
    LSConnectStateConnected=1,           //底层连接成功
    LSConnectStateFailure=2,             //连接失败
    LSConnectStateDisconnect=3,          //连接断开
    LSConnectStateConnecting=4,          //连接中
    LSConnectStateTimeout=5,             //连接超时
    LSConnectStateSuccess=6,             //协议层的连接成功
} ;

#pragma mark - LSPairedState 配对绑定状态

/**
 * 设备配对或绑定状态
 */
typedef NS_ENUM(NSUInteger,LSPairState)
{
    LSPairStateUnknown=0,    //未知
    LSPairStateSuccess=1,    //配对成功
    LSPairStateFailure=2,    //配对失败
};

#pragma mark - LSUpgradeState 设备升级状态

/**
 * 设备升级状态
 * 
 */
typedef NS_ENUM(NSUInteger,LSUpgradeState)
{
    LSUpgradeStateUnknown=0,                     //未知状态
    LSUpgradeStateUpgrading=0x01,                //正在升级
    LSUpgradeStateVerifyFailure=0x03,            //资源校验失败
    LSUpgradeStateSuccess=0x05,                  //升级成功
    LSUpgradeStateFailure=0x06,                  //升级失败
    
    LSUpgradeStateSearch=0x10,                    //扫描正常模式下的设备广播
    LSUpgradeStateSearchUpgradingDevice=0x11,     //扫描升级模式下的设备广播
    LSUpgradeStateConnect=0x12,                   //连接正常模式下的设备
    LSUpgradeStateConnectUpgradingDevice=0x13,    //连接升级模式下的设备
    LSUpgradeStateEnterUpgradeMode=0x14,          //进入升级模式
    LSUpgradeStateResetting=0x15,                 //设备重启中
};

/**
 * 测量单位
 */
typedef NS_ENUM(NSUInteger,LSMeasurementUnit)
{
    LSMeasurementUnitKg=0,      //kg
    LSMeasurementUnitLb=1,      //磅
    LSMeasurementUnitSt=2,      //英石
    LSMeasurementUnitJin=3,     //斤
};


/**
 * 性别类型，1表示男，2表示女
 */
typedef NS_ENUM(NSUInteger,LSUserGender)
{
    LSUserGenderMale=1,
    LSUserGenderFemale=2
};


/**
 * 震动方式
 */
typedef NS_ENUM(NSUInteger, LSVibrationMode)
{
    LSVibrationModeContinued,       //持续震动
    LSVibrationModeInterval,        //间歇震动，震动强度不变
    LSVibrationModeIntervalS2L,     //间歇震动，震动强度由小变大
    LSVibrationModeIntervalL2S,     //间歇震动，震动强度由大变小
    LSVibrationModeIntervalLoop,    //间歇震动，震动强度大小循环
};


/**
 * 消息设置类型
 */
typedef NS_ENUM(NSUInteger,LSDeviceMessageType)
{
   LSDeviceMessageAll=0x00,        //所有消息
   LSDeviceMessageIncomingCall=1,  //来电消息
   LSDeviceMessageDefault=2,       //消息提醒
   LSDeviceMessageDisconnect=3,    //连接断开消息
   LSDeviceMessageSMS=4,           //短信消息
   LSDeviceMessageWechat=5,        //微信消息
   LSDeviceMessageQQ=6,            //QQ消息
   LSDeviceMessageFacebook=0x07,   //Facebook 提醒
   LSDeviceMessageTwitter=0x08,    //Twitter 提醒
   LSDeviceMessageLine=0x09,       //Line 提醒
   LSDeviceMessageGmail=0x0A,      //Gmail 提醒
   LSDeviceMessageKakaoTalk=0x0B,  //Kakao Talk 提醒
   LSDeviceMessageWhatsApp=0x0C,   //Whats App 提醒
   LSDeviceMessageSEWellness=0xFE, //SE Wellness 提醒
   LSDeviceMessageCustom=0xFF,     //自定义消息
};


/**
 * 每周目标
 */
typedef NS_ENUM(NSUInteger, LSWeekTarget)
{
    LSWeekTargetStep,           //每周的目标步数
    LSWeekTargetCalories,       //每周的目标卡路里
    LSWeekTargetDistance,       //每周的目标距离
    LSWeekTargetExerciseAmount  //每周的目标运动量
};

/**
 * 数据重置类型
 */
typedef NS_ENUM(NSUInteger,WSResetType) {
    WSResetTypeAll = 1,                     //删除所有信息
    WSResetTypeUserInfo = 1 << 1,           //删除用户信息
    WSResetTypeSetting = 1 << 2,            //删除设置信息
    WSResetTypeHistoricalData = 1 << 3      //删除历史数据
};


#pragma mark - ErrorCode

/**
 * 错误码
 */
typedef NS_ENUM(NSUInteger,LSErrorCode)
{
    ECodeUnknown=0,
    ECodeParameterInvalid=1,                //接口参数错误
    ECodeUpgradeFileFormatInvalid=2,        //升级文件的格式错误
    ECodeUpgradeFileNameInvalid=3,          //文件名错误
    ECodeWorkingStatusError=5,              //蓝牙SDK工作状态错误
    ECodeDeviceNotConnected=7,              //设备未连接
    ECodeDeviceUnsupported=8,               //当前push信息的类型与设备实际支持的功能不相符
    ECodeUpgradeFileVerifyError=9,          //校验文件出错
    ECodeUpgradeFileDataReceiveError=10,    //数据接收失败
    ECodeLowBattery=11,                     //电量不足
    ECodeCodeVersionInvalid=12,             //代码版本不符合，拒绝升级固件文件
    ECodeUpgradeFileHeaderVerifyError=13,   //固件文件头信息校验失败，拒绝升级固件文件
    ECodeFlashSaveError=14,                 //设备保存数据出错,flash保存失败
    ECodeScanTimeout=15,                    //扫描超时，找不到目标设备
    ECodeConnectionFailed=17,               //连接失败，3次重连连接不上，则返回连接失败
    ECodeConnectionTimeout=21,              //连接错误，若120秒内，出现连接无响应、或发现服务无响应
    ECodeBluetoothUnavailable=23,           // 蓝牙关闭
    ECodeAbnormalDisconnect=24,             //异常断开
    ECodeWriteCharacterFailed=25,           //写特征错误
    ECodeUserCancel=26,                     //用户主动取消

    ECodeRandomCodeVerifyFailure=28,        //随机码验证错误
    ECodeWriteRandomCodeFailure=29,         //写随机码失败
    ECodeWritePairedConfirmFailure=30,      //写配对确认失败
    ECodeWriteDeviceIdFailure=31,           //写设备ID失败
    ECodeNoScanResults=32,                  //没有扫描结果
    
    ECodeFileUpdating=40,                   //文件更新中，拒绝任何设置指令下发
    
    ECodeFileNotFound=41,                   //没有对应的资源文件
    ECodeFileSystemBusy=42,                 //系统繁忙/文件任务传输中
    ECodeFileParameterError=43,             //文件参数错误
    ECodeFileVerifyError=44,                //文件校验失败
    ECodeFileException=45,                  //文件读写错误
    ECodeFileCancel=46,                     //设备端取消发送文件
    ECodeFileExisted=47,                    //资源文件已存在
    
    ECodeDataSyncing=0x80,                  //数据正在同步中

};


#pragma mark - LSBroadcastNameMatchWay

/**
 * 广播名称的匹配方式
 */
typedef NS_ENUM(NSUInteger,LSBroadcastNameMatchWay)
{
    LSBroadcastNameMatchPrefix=1,               //前缀匹配，区分大小写
    LSBroadcastNameMatchPrefixIgnoreCase=2,     //前缀匹配，不区分大小写
    LSBroadcastNameMatchSuffix=3,               //后缀匹配，区分大小写
    LSBroadcastNameMatchSuffixIgnoreCase=4,     //后缀匹配，不区分大小写
    LSBroadcastNameMatchEquals=5,               //直接比较，区分大小写
    LSBroadcastNameMatchEqualsIgnoreCase=6,     //直接比较，不区分大小写
};


#endif /* LSBluetoothManagerProfiles_h */
