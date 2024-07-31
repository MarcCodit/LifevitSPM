//
//  TensiometerSDK.h
//  TensiometerSDK
//
//  Created by David Casas on 3/8/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TensiometerSDK.
FOUNDATION_EXPORT double LifevitSDKVersionNumber;

//! Project version string for TensiometerSDK.
FOUNDATION_EXPORT const unsigned char LifevitSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TensiometerSDK/PublicHeader.h>

#import <LifevitSDK/LifevitSDKManager.h>
#import <LifevitSDK/LifevitSDKUser.h>
#import <LifevitSDK/LifevitSDKDevice.h>
#import <LifevitSDK/LifevitSDKConstants.h>
#import <LifevitSDK/LifevitSDKHeartData.h>
#import <LifevitSDK/LifevitSDKHeartBeatData.h>
#import <LifevitSDK/LifevitSDKBraceletData.h>
#import <LifevitSDK/LifevitSDKStepData.h>
#import <LifevitSDK/LifevitSDKDetailedStepData.h>
#import <LifevitSDK/LifevitSDKSleepData.h>
#import <LifevitSDK/LifevitSDKDetailedSleepData.h>
#import <LifevitSDK/LifevitSDKOximeterData.h>
#import <LifevitSDK/LifevitSDKGlucometerData.h>
#import <LifevitSDK/LifevitSDKPillReminderData.h>
#import <LifevitSDK/LifevitSDKPillReminderAlarmData.h>
#import <LifevitSDK/LifevitSDKPillReminderPerformanceData.h>
#import <LifevitSDK/LifevitSDKPillReminderMessageData.h>

#define PACKET_SIZE 20
#define PACKETS_NOTIFICATION_INTERVAL 10

