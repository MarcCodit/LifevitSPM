//
//  LSBluetoothManager.h
//  LSDeviceBluetooth-Library
//
//  Created by caichixiang on 2017/3/1.
//  Copyright © 2017年 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSBluetoothManagerProfiles.h"
#import "LSDeviceInfo.h"
#import "LSDevicePairingDelegate.h"
#import "LSDeviceDataDelegate.h"
#import "LSBluetoothStatusDelegate.h"
#import "LSDeviceUpgradingDelegate.h"
#import "LSDeviceFilterInfo.h"
#import "ATSyncSetting.h"
#import "ATFileData.h"
#import "WFTemplate.h"

@class IBaseClass;
@class LSCacheControler;
@class LSDataControler;

FOUNDATION_EXPORT NSString *const  LSDeviceBluetoothFrameworkVersion;

@interface LSBluetoothManager : NSObject

@property(nonatomic,strong)NSMutableArray <NSData *>* kchiingReminderCmds;
@property(nonatomic,assign)CBManagerState currentBluetoothState;
@property(nonatomic,strong)id<LSDeviceDataDelegate> dataDelegate;
@property(nonatomic,strong)dispatch_queue_t syncDispatchQueue;

@property(nonatomic,assign,readonly)BOOL isBluetoothPowerOn;
@property(nonatomic,strong,readonly)NSString *versionName;
@property(nonatomic,assign,readonly)NSInteger currentTimeZone;

@property(nonatomic,strong,readonly)IBaseClass *logger;
@property(nonatomic,assign,readonly)LSManagerState      managerStatus;
@property(nonatomic,strong,readonly)LSCacheControler    *cacheControler;
@property(nonatomic,strong,readonly)LSDataControler     *dataControler;
@property(nonatomic,strong,readonly)NSMutableDictionary *deviceMap;
@property(nonatomic,strong,readonly)NSMutableDictionary *pushRequestMap;

@property(nonatomic,strong,readonly)NSMutableDictionary *gattClientMap;
@property(nonatomic,strong,readonly)NSMutableArray      *scanType;
@property(nonatomic,strong)id<LSBluetoothStatusDelegate> bleStateDelegate;
@property(nonatomic,assign)BOOL clearScanCache;          //是否清空扫描缓存
@property(nonatomic,strong)NSString *logPath;            //log日志路径
@property(nonatomic,assign)NSUInteger iotSessionId;      //ios json文件会话id
@property(nonatomic,strong,readonly)NSMutableDictionary  *iotAddSettings;
@property(nonatomic,strong,readonly)NSMutableDictionary  *iotNameSettings;
@property(nonatomic,strong)NSString *fileKey;            //当前推送的OTA文件消息key
@property(nonatomic,strong)NSURL *filePath;              //当前推送的OTA文件路径

#pragma mark - public methods

/**
 * Added in version 2.0.0
 * 获取实例对象
 */
+(instancetype)defaultManager;

/**
 * Added in version 2.0.0
 * 采用系统默认配置的蓝牙初始化
 */
-(void)initManager:(dispatch_queue_t)dispatchQueue;

/**
 * Added in version 2.0.0
 * 带可选项的系统蓝牙初始化
 */
-(void)initManagerWithDispatch:(dispatch_queue_t)queue
                       options:(nullable NSDictionary<NSString *, id> *)options;

/**
 * Added in version 2.0.0
 * 将调试信息保存到相应的文件目录中
 */
-(void)saveDebugMessage:(BOOL)enable forFileDirectory:(NSString *_Nonnull)filePath;

/**
 * Added in version 2.0.0
 * 打开调试模式
 */
-(void)openDebugMode:(NSString *_Nonnull)permissionKey;

/**
 * Added in version 2.0.0
 * 在文件中记录调试信息
 */
-(void)appendDebugMessage:(NSString *_Nonnull)msg;

/**
 * Added in version 2.0.0
 * 检查手机蓝牙状态
 */
-(void)checkingBluetoothStatus:(id<LSBluetoothStatusDelegate>_Nonnull)bleStatusDelegate;

/**
 * Added in version 2.0.0
 * 根据指定条件搜索设备
 */
-(BOOL)searchDevice:(NSArray *_Nullable)types  results:(SearchResultsBlock _Nonnull )block;

/**
 * Added in version 2.0.0
 * 停止搜索
 */
-(BOOL)stopSearch;

/**
 * Added in version 2.0.0
 * 根据广播ID,检查设备当前的连接状态
 */
-(LSConnectState)checkConnectState:(NSString *_Nonnull)broadcastId;

/**
 * Added in version 2.0.0
 * 清空CBPeripheral对象缓存
 */
-(void)clearPeripheralCache;

/**
 * Added in version 2.0.0
 * 根据不同的工作模式，不同的匹配方式，设置设备过滤信息，filterInfos=nil表示删除已存在的过滤信息或执行无过滤操作
 */
-(BOOL)setDeviceFilterInfo:(NSArray <LSDeviceFilterInfo *>*_Nullable)filterInfos
           forWorkingState:(LSManagerState)state;

/**
 * Added in version 2.0.0
 * Device ID 转 Device SN
 */
-(NSString *_Nullable)toDeviceSn:(NSString *_Nonnull)deviceId;

/**
 * Added in version 2.0.0
 * Device SN 转 Device ID
 */
-(NSString *_Nullable)toDeviceID:(NSString *_Nonnull)deviceSn;

/**
 * Added in version 2.0.0
 * 计算字节流数据CRC32
 */
-(NSData *_Nullable)computeCRC32:(NSData *_Nonnull)srcData;

/**
 * 导出日志文件
 */
-(NSArray *_Nullable)exportLogFiles:(NSString *_Nullable)broadcastId;

/**
 * 解析原始数据
 */
-(ATDeviceData *_Nullable)parseData:(NSData *_Nonnull)data
                                cmd:(NSUInteger)cmd;

/**
 * 根据配置文件XMl及资源文件夹内容（WF）生成表盘文件
 */
-(NSURL *_Nullable)createWatchFaceFile:(WFTemplate *_Nonnull)xml
                           deviceModel:(NSString *_Nonnull)model;

/**
 * 加载表盘资源文件，用于固件模板模拟测试,并返回xml文件所在路径
 */
-(NSURL *_Nullable)loadResourceFiles;

/**
 * 删除文件夹及文件夹下的所有文件
 */
-(BOOL)removeItemAtFolder:(NSURL *_Nonnull)dirPath;

/**
 * 根据背景图片、设备型号生成表盘文件
 */
-(NSURL *_Nullable)packingWatchFaceFile:(NSURL *_Nonnull)imageUrl
                            deviceModel:(NSString *_Nonnull)model;


/**
 * 获取系统已配对、绑定的耳机设备
 */
-(NSArray <LSDeviceInfo *> *_Nullable)checkPairedEarphone;


/**
 * 手环6S睡眠状态数据，合并成完整睡眠报告
 * filterTime:数据过滤时间段设置，单位分钟，如设置720（12*60）表示过滤12点后返回的无效睡眠数据
 */
-(NSArray <ATSleepReportData *>*_Nullable)mergeSleepReport:(NSArray <ATSleepReportItem *>*_Nonnull)items
                                                filterTime:(NSUInteger)time;

/**
 * 获取SDK内部的CBCentralManager
 */
-(CBCentralManager *_Nullable)localCentralManager;
@end
