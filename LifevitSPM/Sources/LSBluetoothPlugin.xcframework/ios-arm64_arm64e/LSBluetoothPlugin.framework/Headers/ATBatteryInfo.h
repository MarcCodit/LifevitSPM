//
//  ATBatteryInfo.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/29.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ATBatteryInfo : NSObject

/**
 * 原数据包
 */
@property(nullable,nonatomic,strong) NSData *srcData;

/**
 * 设备MAC
 */
@property(nullable,nonatomic,strong) NSString *deviceMac;

/**
 * 标志位
 * 0x00 表示正常工作,
 * 0x01 表示充电中,
 * 0x02 表示上传的是电量百分比
 * -1   表示不支持
 */
@property(nonatomic,assign) unsigned int flag;

/**
 * 电量电压
 */
@property(nonatomic,assign)  float voltage;

/**
 * 电量百分比
 */
@property(nonatomic,assign) unsigned int battery;

/**
 * 是否支持通道状态设置
 */
@property(nonatomic,assign) BOOL stateSetting;

/**
 * A501通道状态
 * 0x0002 表示打开，其他表示关闭
 */
@property(nonatomic,assign) unsigned int stateOfA501;

/**
 * A503通道状态
 * 0x0001 表示打开，其他表示关闭
 */
@property(nonatomic,assign) unsigned int stateOfA503;

/**
 * 充电时间
 * 对应ATChargeRecordData.startUtc 充电记录的开始时间
 */
@property(nonatomic,assign)  long chargingTime;


-(instancetype)initWithData:(NSData *_Nullable)data;


-(NSDictionary *)toString;

@end
