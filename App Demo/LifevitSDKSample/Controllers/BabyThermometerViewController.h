//
//  ViewController.h
//  BabyThermometerTest
//
//  Created by Oscar on 26/3/18.
//

#import <UIKit/UIKit.h>
@import LifevitSDK;

@interface BabyThermometerViewController : UIViewController<LifevitDeviceDelegate, LifevitBabyThermometerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *lblTemperature;
@property (weak, nonatomic) IBOutlet UILabel *lblEnvironmentTemperature;
@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;

@end

