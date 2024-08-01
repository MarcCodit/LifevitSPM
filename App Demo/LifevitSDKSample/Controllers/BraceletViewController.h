//
//  ViewController.h
//  BraceletSDKTest
//
//  Created by David Casas on 5/9/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <UIKit/UIKit.h>

@import LifevitSDK;

@interface BraceletViewController : UIViewController<LifevitDeviceDelegate, LifevitBraceletDelegate, LifevitBraceletAT250Delegate, LifevitBraceletVITALDelegate>


@end

