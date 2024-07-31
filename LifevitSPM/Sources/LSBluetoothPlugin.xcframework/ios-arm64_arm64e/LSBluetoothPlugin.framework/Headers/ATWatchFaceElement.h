//
//  ATWatchFaceElement.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2021/6/4.
//  Copyright © 2021 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 表盘元素可配置项类型
 */
typedef NS_ENUM(NSUInteger,WFElementType) {
    WFElementTypeHiddenInfo=0x00,           //隐藏/显示信息
    WFElementTypeColorInfo=0x01,            //颜色信息
    WFElementTypeSpaceInfo=0x02,            //位置信息
    WFElementTypeConfigInfo=0x03,           //配置信息
};


/**
 * 表盘元素可配置项
 */
typedef NS_ENUM(NSUInteger,WFElementOptions) {
    WFElementOptionsDate=0x01,              //日期
    WFElementOptionsTime=0x02,              //时间
    WFElementOptionsPower=0x03,             //电量
    WFElementOptionsHeartRate=0x04,         //心率
    WFElementOptionsExerciseTime=0x05,      //运动时间
    WFElementOptionsActiveTime=0x06,        //活跃小时
    WFElementOptionsStep=0x07,              //步数
    WFElementOptionsWeather=0x08,           //天气
    WFElementOptionsBluetooth=0x09,         //蓝牙
};

/**
 * 多功能表盘配置类型
 */
typedef NS_ENUM(NSUInteger,ATWatchFaceConfig){
    ATWatchFaceConfigUnknown=0x00,          //未知类型
    ATWatchFaceConfigRealtimeData=0x01,     //实时数据
    ATWatchFaceConfigDataChart=0x02,        //数据图表
    ATWatchFaceConfigApplication=0x03,      //应用功能
};

/**
 * 多功能表盘实时数据类型
 */
typedef NS_ENUM(NSUInteger,ATRealtimeDataType) {
    ATRealtimeDataTypeUnknown=0x00,              //未知
    ATRealtimeDataTypeTodayOverview=0x01,        //今日活动
    ATRealtimeDataTypeStep=0x02,                 //步数
    ATRealtimeDataTypeCalories=0x03,             //卡路里
    ATRealtimeDataTypeStandingTime=0x04,         //站立时长
    ATRealtimeDataTypeExerciseTime=0x05,         //运动时长
    ATRealtimeDataTypeBattery=0x06,              //电量
    ATRealtimeDataTypeWeather=0x07,              //天气
    ATRealtimeDataTypeDate=0x08,                 //日期
};

/**
 * 多功能表盘数据图表类型
 */
typedef NS_ENUM(NSUInteger,ATDataChart) {
    ATDataChartUnknown=0x00,              //未知
    ATDataChartStep=0x01,                 //步数图表
    ATDataChartCalories=0x02,             //卡路里图表
    ATDataChartStandingTime=0x03,         //站立时长图表
    ATDataChartExerciseTime=0x04,         //运动时长图表
    ATDataChartWeather=0x05,              //天气图表
    ATDataChartHeartRate=0x06,            //心率图表
    ATDataChartSleep=0x07,                //睡眠图表
    ATDataChartMusic=0x08,                //音乐控制图表
    ATDataChartMessage=0x09,              //消息图表
    ATDataChartActivity=0x0A,             //今日活动

};


/**
 * 多功能表盘配置项
 */
@interface ATWatchFaceItem : NSObject

/**
 * 表盘索引
 */
@property(nonatomic,assign)NSUInteger index;

/**
 * 表盘类型
 *
 * 0x00 = 云端表盘
 * 0x01 = 相册表盘
 * 0x02 = 本地表盘
 * 0x03 = 多功能表盘
 */
@property(nonatomic,assign)NSUInteger typeOfWatchFace;

/**
 * 配置类型
 */
@property(nonatomic,assign) ATWatchFaceConfig config;

/**
 * 配置内容，其值参考配置类型的定义
 * 当config = ATWatchFaceConfigDataChart 时，value 的定义参考 ATDataChart
 * 当config = ATWatchFaceConfigApplication 时，value 的定义参考 ATWatchPage
 */
@property(nonatomic,assign) int value;

/**
 * 多功能表盘配置内容指令格式
 */
-(NSData *)toBytes;
@end


/**
 * 1F1表盘元素
 */
@interface ATWatchFaceElement : NSObject

/**
 * 配置类型
 */
@property(nonatomic,assign) WFElementType dataType;

/**
 * 根据配置类型，设置配置内容
 */
@property(nonatomic,assign) int dataValue;

/**
 * 表盘显示项,参考ATDisplayItem的设置
 */
@property(nonatomic,strong) NSArray *items;

@end

