//
//  LifevitSDKNotifications.h
//  LifevitSDK
//
//  Created by Oscar on 26/09/2019.
//  Copyright © 2019 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKAppNotification : NSObject

@property BOOL sms;
@property BOOL email;
@property BOOL wechat;
@property BOOL qq;
@property BOOL weibo;
@property BOOL facebook;
@property BOOL twitter;
@property BOOL whatsApp;
@property BOOL messenger;
@property BOOL instagram;
@property BOOL linkedIn;
@property BOOL calendar;
@property BOOL skype;
@property BOOL alarm;
@property BOOL pokeman;
@property BOOL call; //NOT AVAILABLE ON AT2019
@property BOOL vKontakte;
@property BOOL line;
@property BOOL viber;
@property BOOL kakaotalk;
@property BOOL gmail;
@property BOOL outlook;
@property BOOL snapchat;
@property BOOL telegram;

@end

NS_ASSUME_NONNULL_END
