//
//  PillReminderViewController.h
//  LifevitSDKSample
//
//  Created by Oscar on 06/05/2019.
//  Copyright © 2019 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>
@import LifevitSDK;

NS_ASSUME_NONNULL_BEGIN

@interface PillReminderViewController : UIViewController<LifevitDeviceDelegate, LifevitPillReminderDelegate>

@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UITextView *tvReceivedData;

@property (weak, nonatomic) IBOutlet UIButton *btnSend;
@property (weak, nonatomic) IBOutlet UIButton *btnConnect;


@end

NS_ASSUME_NONNULL_END
