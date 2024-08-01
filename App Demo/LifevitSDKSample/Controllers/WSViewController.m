//
//  ViewController.m
//  WeightScaleTest
//
//  Created by iNMovens Solutions on 20/11/17.
//  Copyright © 2017 Lifevit. All rights reserved.
//

#import "WSViewController.h"

@interface WSViewController ()

@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblWeight;
@property (weak, nonatomic) IBOutlet UILabel *lblIMC;
@property (weak, nonatomic) IBOutlet UILabel *lblFat;
@property (weak, nonatomic) IBOutlet UILabel *lblMuscle;
@property (weak, nonatomic) IBOutlet UILabel *lblBone;
@property (weak, nonatomic) IBOutlet UILabel *lblBMR;
@property (weak, nonatomic) IBOutlet UILabel *lblWater;
@property (weak, nonatomic) IBOutlet UILabel *lblVisceral;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;
@property (weak, nonatomic) IBOutlet UILabel *lblProtein;
@property (weak, nonatomic) IBOutlet UILabel *lblBodyAge;
@property (weak, nonatomic) IBOutlet UILabel *lblIdealWeight;
@property (weak, nonatomic) IBOutlet UILabel *lblObesity;
@property (weak, nonatomic) IBOutlet UILabel *lblBia;

@end

@implementation WSViewController {
    int deviceStatus;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Weight Scale"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].weightscaleDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_WEIGHT_SCALE]){
        deviceStatus = STATUS_CONNECTED;
    }
    else{
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_WEIGHT_SCALE onConnectionChanged:deviceStatus];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {
    
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
        [[LifevitSDKManager sharedInstance] setWeightScaleParams:@"kg" withGender:GENDER_MALE Age:40 andHeight:184];
        //[[LifevitSDKManager sharedInstance] setWeightScaleParams:@"kg" withGender:GENDER_FEMALE Age:35 andHeight:190];
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_WEIGHT_SCALE withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_WEIGHT_SCALE];
            break;
    }
}

#pragma mark - Weight delegate

- (void)weightscaleOnTypeDetected:(NSNumber *)type{
    NSLog(@"Weight scale type: %d", [type intValue]);
}

-(void)weightscaleOnMeasurementResult:(LifevitSDKWeightScaleData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.lblWeight.text = data.weight? [NSString stringWithFormat:@"%.2f%@ (temp)", [data.weight doubleValue], data.unit]: @"-";
        self.lblIMC.text = data.imc? [NSString stringWithFormat:@"%.2f (temp)", [data.imc doubleValue]]: @"-";
        self.lblWater.text = data.waterRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.waterPercentage doubleValue], [data.waterRawValue doubleValue]]: @"-";
        self.lblFat.text = data.fatRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.fatPercentage doubleValue], [data.fatRawValue doubleValue]]: @"-";
        self.lblBMR.text = data.bmr? [NSString stringWithFormat:@"%.2f kCal", [data.bmr doubleValue]]: @"-";
        self.lblVisceral.text = data.visceralRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.visceralPercentage doubleValue], [data.visceralRawValue doubleValue]]: @"-";
        self.lblMuscle.text = data.muscleRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.musclePercentage doubleValue], [data.muscleRawValue doubleValue]]: @"-";
        self.lblBone.text = data.boneRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.bonePercentage doubleValue], [data.boneRawValue doubleValue]]: @"-";
        self.lblProtein.text = data.proteinPercentage? [NSString stringWithFormat:@"%.2f %%", [data.proteinPercentage doubleValue]]: @"-";
        self.lblObesity.text = data.obesityPercentage? [NSString stringWithFormat:@"%.2f %%", [data.obesityPercentage doubleValue]]: @"-";
        self.lblBodyAge.text = data.bodyAge? [NSString stringWithFormat:@"%.2f", [data.bodyAge doubleValue]]: @"-";
        self.lblIdealWeight.text = data.idealWeight? [NSString stringWithFormat:@"%.2f kg", [data.idealWeight doubleValue]]: @"-";
        self.lblBia.text = data.bia? [NSString stringWithFormat:@"%.2f", [data.bia doubleValue]]: @"-";
        
    });
}

-(void)weightscaleOnResult:(LifevitSDKWeightScaleData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.lblWeight.text = data.weight? [NSString stringWithFormat:@"%.2f%@", [data.weight doubleValue], data.unit]: @"-";
        self.lblIMC.text = data.imc? [NSString stringWithFormat:@"%.2f", [data.imc doubleValue]]: @"-";
        self.lblWater.text = data.waterRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.waterPercentage doubleValue], [data.waterRawValue doubleValue]]: @"-";
        self.lblFat.text = data.fatRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.fatPercentage doubleValue], [data.fatRawValue doubleValue]]: @"-";
        self.lblBMR.text = data.bmr? [NSString stringWithFormat:@"%.2f kCal", [data.bmr doubleValue]]: @"-";
        self.lblVisceral.text = data.visceralRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.visceralPercentage doubleValue], [data.visceralRawValue doubleValue]]: @"-";
        self.lblMuscle.text = data.muscleRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.musclePercentage doubleValue], [data.muscleRawValue doubleValue]]: @"-";
        self.lblBone.text = data.boneRawValue? [NSString stringWithFormat:@"%.2f %% - %.2f kg", [data.bonePercentage doubleValue], [data.boneRawValue doubleValue]]: @"-";
        self.lblProtein.text = data.proteinPercentage? [NSString stringWithFormat:@"%.2f %%", [data.proteinPercentage doubleValue]]: @"-";
        self.lblObesity.text = data.obesityPercentage? [NSString stringWithFormat:@"%.2f %%", [data.obesityPercentage doubleValue]]: @"-";
        self.lblBodyAge.text = data.bodyAge? [NSString stringWithFormat:@"%.2f", [data.bodyAge doubleValue]]: @"-";
        self.lblIdealWeight.text = data.idealWeight? [NSString stringWithFormat:@"%.2f kg", [data.idealWeight doubleValue]]: @"-";
        self.lblBia.text = data.bia? [NSString stringWithFormat:@"%.2f", [data.bia doubleValue]]: @"-";
        
    });
}

#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    
    dispatch_async(dispatch_get_main_queue(), ^{
    deviceStatus = status;
    switch(status){
        case STATUS_CONNECTED:
            self.lblStatus.text = @"Connected";
            [self.lblStatus setTextColor:[UIColor greenColor]];
            [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
            break;
        case STATUS_DISCONNECTED:
            self.lblStatus.text = @"Disconnected";
            [self.lblStatus setTextColor:[UIColor redColor]];
            [self.btnAction setTitle:@"Connect" forState:UIControlStateNormal];
            break;
        case STATUS_SCANNING:
            self.lblStatus.text = @"Scanning near devices...";
            [self.lblStatus setTextColor:[UIColor blackColor]];
            [self.btnAction setTitle:@"Cancel connection" forState:UIControlStateNormal];
            break;
        case STATUS_CONNECTING:
            self.lblStatus.text = @"Connecting";
            [self.lblStatus setTextColor:[UIColor blackColor]];
            [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
    }
    });
}


- (void)device:(int)device onConnectionError:(int)error{
    
    dispatch_async(dispatch_get_main_queue(), ^{
    [self.lblStatus setTextColor:[UIColor redColor]];
    _lblStatus.text = [@"On result error: " stringByAppendingString:[@(error) stringValue]];
        
    });
}


@end
