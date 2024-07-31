//
//  ATMeditationItem.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/7/28.
//  Copyright © 2020 sky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ATMeditationItem : NSObject

/**
 * 冥想记录对应的UTC
 */
@property(nonatomic,assign) long utc;

/**
 * 当天累计冥想时长
 */
@property(nonatomic,assign) unsigned int time;
@end
