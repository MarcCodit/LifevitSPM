//
//  IByteUtils.h
//  TestApp
//
//  Created by caichixiang on 2020/3/9.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ICByteUtils : NSObject

/**
 * 将16进制字符串转NSData格式
 */
+(NSData *)formatHexStringWithData:(NSString *)string;

/**
 * NSData 转 16进制String
 */
+(NSString *)toString:(NSData *)data;

/**
 * short to SFloat
 */
+(float)shortToSFloat:(unsigned short)value;

/**
 * float to int
 */
+(int)floatToInt:(float)value;

/**
 * int to float
 */
+(float)intToFloat:(unsigned int)value;

/**
 * 截取小时
 */
+(NSUInteger)captureHour:(NSString *)str;

/**
 * 截取分钟
 */
+(NSUInteger)captureMinute:(NSString *)str;

/**
 * 统计重复星期设置
 */
+(NSUInteger)countRemindRepeatDay:(NSArray <NSNumber *>*)repeatDay;

/**
 * 将float字段转NSData
 */
+(NSData *)float2DataWithBig:(float)value decimalPlaces:(NSUInteger)places;

/**
 * 计算开始时间到结束时间的时间差
 */
+(NSUInteger)getMaxTimeValue:(NSString *)startTme endTime:(NSString *)endTime;

/**
 * 根据固定长度，切割成数组
 */
+(NSArray *)formatToArray:(NSData *)srcData length:(NSUInteger)len;


/**
 * 格式化macAddress
 */
+(NSString *)formatMacAddress:(NSString *)dataStr;

/**
 * 将CBUUID转换成uint16_t;
 */
+(uint16_t)toUint16_t:(NSData* )uuidData;

/**
 * 将NSData按字节为单位，反序输出
 */
+(NSData *)formatDataWithReverseOrder:(NSData *)sourceData;

/**
 * 将NSData转换成utf-8编码的字符串形式;
 */
+(NSString *)formatDataWithUTF8StringEncoding:(NSData *)sourceData;

/**
 * 将字符串转换成uint32_t;
 */
+(uint32_t)formatHexStringWithUint32_t:(NSString*)subString;

/**
 * 16进制字符串转long
 */
+(unsigned long long)hexString2Long:(NSString *)hexStr;

/**
 * 计算对从序号为1～4的数据逐字节相加，结果作为整个数据的校验数据。
 */
+(int)checkSumBytes:(NSData *)data;

/**
 * 判断该数值对应的bit位是否为1
 */
+(BOOL)isBitSet:(int)value bitOffset:(int)offset;

/**
 * 忽略大小的字符串比较
 */
+(BOOL)stringCompare:(NSString *)dst expect:(NSString *)expStr;

/**
 * 字符串格式的时间转UTC
 * 参数格式 yyyyMMdd HH:mm:ss
 */
+(NSUInteger)dateWithTimeString:(NSString *)time;

/**
 * 按固定长度格式化字符串
 */
+(NSData *)dataFormat:(NSData *)strBytes fixedSize:(NSUInteger)len;

/**
 *根据长度截取字符串
 */
+(NSString *)subStr:(NSString *)src len:(NSUInteger)len;


+(NSArray *)toWeekDay:(NSUInteger)value;
@end
