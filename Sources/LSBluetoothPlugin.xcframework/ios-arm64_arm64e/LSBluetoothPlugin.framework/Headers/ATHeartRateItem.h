//
//  ATHeartRateItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/9/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ATHeartRateItem : NSObject

/**
 * 序号
 */
@property(nonatomic,assign)  int index;

/**
 * 心率类型
 * 0x00:常规状态(非运动且非睡 眠状态)心率
 * 0x01:运动状态心率
 * 0x02:睡眠状态心率
 * 0x03:区间心率
 */
@property(nonatomic,assign)  int type;

/**
 * 开关
 */
@property(nonatomic,assign)  BOOL enable;

/**
 * 单值因子,表示产生一个心率值的时间周期
 *
 * <p>比例因子为5.比如下发值为2，表示每2*5=10S 产生一个 心率值</p>
 */
@property(nonatomic,assign)  int factor;

/**
 * 监测上限最大值
 *
 * <p>考虑到值溢出问题，设置值需 增加正偏差值50才是正在的心 率上限。比如下发值250，那实 际监测的上限为300</p>
 */
@property(nonatomic,assign)  int maxValue;

/**
 * 监测下限最大值
 *
 * <p>考虑到值溢出问题，设置值需 增加正偏差值50才是正在的心 率上限。比如下发值250，那实 际监测的上限为300</p>
 */
@property(nonatomic,assign)  int minValue;


/**
 * 点测心率测量时间UTC
 */
@property(nonatomic,assign) long utc;

/**
 * 点测心率数据
 */
@property(nonatomic,assign) int value;

-(NSData *)toBytes;
@end

