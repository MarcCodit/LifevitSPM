//
//  DeviceScanCell.h
//  LifevitSDKSample
//
//  Created by Oscar on 11/10/18.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DeviceScanCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *lblUUID;
@property (weak, nonatomic) IBOutlet UILabel *lblDistance;

@end

NS_ASSUME_NONNULL_END
