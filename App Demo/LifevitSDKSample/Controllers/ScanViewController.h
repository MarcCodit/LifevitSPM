//
//  ScanViewController.h
//  LifevitSDKSample
//
//  Created by iscariot on 05/10/2018.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>
@import LifevitSDK;

NS_ASSUME_NONNULL_BEGIN

@interface ScanViewController : UIViewController<LifevitSDKDevicesScanDelegate, UITableViewDataSource, UITableViewDelegate>

@end

NS_ASSUME_NONNULL_END
