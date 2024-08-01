//
//  GlucometerViewController.m
//  LifevitSDKSample
//
//  Created by Oscar on 21/3/22.
//  Copyright © 2022 Lifevit. All rights reserved.
//

#import "GlucometerViewController.h"

@interface GlucometerViewController ()

@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblTemperature;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;

@end

@implementation GlucometerViewController {
    int deviceStatus;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Glucometer"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].glucometerDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_GLUCOMETER]){
        deviceStatus = STATUS_CONNECTED;
    } else {
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_GLUCOMETER onConnectionChanged:deviceStatus];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {
    
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_GLUCOMETER withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_GLUCOMETER];
            
            break;
    }
}


#pragma mark - Glucometer delegate

- (void)onGlucometerDeviceResult:(LifevitSDKGlucometerData*) data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.lblTemperature.text = [NSString stringWithFormat:@"%.2f", [data.glucose doubleValue]];
    });
}

/*
- (void)onGlucometerDeviceError:(int) errorCode{
    dispatch_async(dispatch_get_main_queue(), ^{
        switch (errorCode){
            case THERMOMETER_ERROR_BODY_TEMPERATURE_HIGH:
                self.lblTemperature.text = @"ERROR: Body temperature too high";
                break;
            case THERMOMETER_ERROR_BODY_TEMPERATURE_LOW:
                self.lblTemperature.text = @"ERROR: Body temperature too low";
                break;
            case THERMOMETER_ERROR_AMBIENT_TEMPERATURE_HIGH:
                self.lblTemperature.text = @"ERROR: Ambient temperature too high";
                break;
            case THERMOMETER_ERROR_AMBIENT_TEMPERATURE_LOW:
                self.lblTemperature.text = @"ERROR: Ambient temperature too low";
                break;
            case THERMOMETER_ERROR_HARDWARE:
                self.lblTemperature.text = @"ERROR: Hardware error";
                break;
            case THERMOMETER_ERROR_LOW_VOLTAGE:
                self.lblTemperature.text = @"ERROR: Low voltage";
                break;
                default:
                self.lblTemperature.text = @"ERROR: Unknown";
                break;
                
        }
    });
}
*/

#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    deviceStatus = status;
    dispatch_async(dispatch_get_main_queue(), ^{
        
    self.btnAction.hidden = false;
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
