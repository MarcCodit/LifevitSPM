//
//  ECGViewController.h
//  LifevitSDKSample
//
//  Created by Oscar on 7/10/21.
//  Copyright © 2021 Lifevit. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Charts/Charts-Swift.h"
@import LifevitSDK;

NS_ASSUME_NONNULL_BEGIN

@interface ECGViewController : UIViewController /*<IChartAxisValueFormatter>*/

@property (weak, nonatomic) IBOutlet LineChartView *vChart;
@property (weak, nonatomic) IBOutlet UIButton *btnStartStop;

@property (weak, nonatomic) IBOutlet UILabel *lblBPM;
@property (weak, nonatomic) IBOutlet UILabel *lblBPMTitle;

@property (weak, nonatomic) IBOutlet UILabel *lblHRV;
@property (weak, nonatomic) IBOutlet UILabel *lblHRVTitle;

@property (weak, nonatomic) IBOutlet UILabel *lblMMHG;
@property (weak, nonatomic) IBOutlet UILabel *lblMMHGTitle;

@property (weak, nonatomic) IBOutlet UIProgressView *progressBar;
@property (weak, nonatomic) IBOutlet UILabel *lblProgress;

@end

NS_ASSUME_NONNULL_END
