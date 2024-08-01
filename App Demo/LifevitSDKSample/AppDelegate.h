//
//  AppDelegate.h
//  LifevitSDKSample
//
//  Created by iNMovens Solutions on 11/5/18.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>
@import LifevitSDK;

@interface AppDelegate : UIResponder <UIApplicationDelegate, LifevitDeviceDelegate, LifevitOximeterDelegate, LifevitWeightScaleDelegate, LifevitSDKManagerDelegate>

@property (strong, nonatomic) UIWindow *window;


@end

