//
//  DeviceConnectionCell.h
//  LifevitSDKSample
//
//  Created by Oscar on 29/10/18.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DeviceConnectionCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *lblDeviceType;
@property (weak, nonatomic) IBOutlet UILabel *lblDeviceStatus;



@end

NS_ASSUME_NONNULL_END
