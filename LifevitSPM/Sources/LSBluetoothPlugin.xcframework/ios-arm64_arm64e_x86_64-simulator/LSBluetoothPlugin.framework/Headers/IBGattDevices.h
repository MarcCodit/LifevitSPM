//
//  IBGattDevice.h
//  LSBluetoothPlugin-Demo
//
//  Created by caichixiang on 2019/11/6.
//  Copyright © 2019 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CBPeripheral.h>


@interface IBGattDevices : NSObject

@property(nullable,nonatomic,strong)NSString *deviceKey;            //设备唯一标识
@property(nullable,nonatomic,strong)NSString *deviceName;           //设备名称
@property(nullable,nonatomic,strong)NSString *modelNumber;          //设备型号
@property(nullable,nonatomic,strong)NSString *softwareVersion;      //软件版本
@property(nullable,nonatomic,strong)NSString *hardwareVersion;      //硬件版本
@property(nullable,nonatomic,strong)NSString *firmwareVersion;      //固件版本
@property(nullable,nonatomic,strong)NSString *serialNumber;         //产品序列号，SN
@property(nullable,nonatomic,strong)NSString *manufactureName;      //制造商
@property(nullable,nonatomic,strong)NSString *systemId;             //自定义ID
@property(nullable,nonatomic,strong)NSString *manufacturerData;     //制造商自定义广播信息

@property(nullable,nonatomic, strong) NSString *deviceId;           //设备ID
@property(nullable,nonatomic, strong) NSString *deviceSn;           //设备SN

@property(nullable,nonatomic,strong)NSString *fileKey;              //OTA文件消息key
@property(nullable,nonatomic,strong)NSURL *filePath;                //OTA文件路径
@property(nonatomic,assign)NSUInteger fileState;                    //OTA文件处理状态

@property(nullable,nonatomic,strong)NSArray *testData;              //测试数据
@property(nullable,nonatomic,strong)CBPeripheral *peripheral;       //当前扫描的CBPeripheral
@property(nullable,nonatomic,strong)NSDictionary *advMap;           //AdvertisementData

/**
 * 连接模式
 */
@property(nonatomic,assign)NSUInteger connectMode;

/**
 * 登录超时时间，单位秒，默认5秒（最小值）
 */
@property(nonatomic, assign) NSUInteger loginTimeout;

/**
 * 断开后的重连间隔，单位秒，默认3秒，最小值1秒
 */
@property(nonatomic, assign) NSUInteger reonnectInterval;

-(instancetype)initWithKey:(NSString *)key;

@end

