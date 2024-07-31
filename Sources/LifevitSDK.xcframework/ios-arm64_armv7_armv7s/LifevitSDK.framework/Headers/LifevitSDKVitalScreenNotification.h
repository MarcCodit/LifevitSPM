//
//  LifevitSDKVitalScreenNotification.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 7/11/21.
//  Copyright © 2021 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LifevitSDKVitalScreenNotification : NSObject
enum NotificationType{
        STOP_CALL = 0xff, CALL = 0, INFO = 1, WECHAT = 2, FACEBOOK = 3, INSTAGRAM = 4, SKYPE = 5, TELEGRAM = 6, TWITTER = 7, VKCLIENT = 8, WHATSAPP = 9, QQ = 10, LINKEDIN = 11
};

@property enum NotificationType type;
@property (strong, nonatomic) NSString* text;
@property (strong, nonatomic) NSString* contact;


@end

NS_ASSUME_NONNULL_END
