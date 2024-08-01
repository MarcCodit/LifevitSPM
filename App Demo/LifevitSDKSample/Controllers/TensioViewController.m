//
//  ViewController.m
//  SDKTest
//
//  Created by David Casas on 3/8/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import "TensioViewController.h"

@interface TensioViewController ()
@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblSystolic;
@property (weak, nonatomic) IBOutlet UILabel *lblDiastolic;
@property (weak, nonatomic) IBOutlet UILabel *lblPulse;
@property (weak, nonatomic) IBOutlet UILabel *lblUUID;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;
@property (weak, nonatomic) IBOutlet UIButton *btnStart;

@end

@implementation TensioViewController{
    int deviceStatus;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Tensiometer"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].heartDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected: DEVICE_HEART]){
        
        deviceStatus = STATUS_CONNECTED;
       
    }
    else{
        
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_HEART onConnectionChanged:deviceStatus];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice: DEVICE_HEART withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice: DEVICE_HEART];
            break;
    }
}


- (IBAction)onConnectByUUID:(id)sender {
    
    NSString* uuid = self.lblUUID.text;
    
    if(uuid.length>0){
        [[LifevitSDKManager sharedInstance] connectByUUID:uuid withType:DEVICE_HEART];
    }
}

- (void) checkUUID{
    NSString* uuid = [[LifevitSDKManager sharedInstance] getDeviceUUID:DEVICE_HEART];
    
    if(uuid){
        self.lblUUID.text = uuid;
    }
}


- (IBAction)onStartMeasurement:(id)sender {
    //if ([self.btnStart.titleLabel.text isEqualToString:@"Start Measurement"]){
        [[LifevitSDKManager sharedInstance] startMeasurement];
    //} else {
    //    [[LifevitSDKManager sharedInstance] stopMeasurement];
    //}
}

#pragma mark - Device delegate

- (void)device:(int)device onConnectionChanged:(int)status{
    deviceStatus = status;
    dispatch_async(dispatch_get_main_queue(), ^{
        
        switch(status){
            case STATUS_CONNECTED:
                [self.btnStart setHidden:NO];
                self.lblStatus.text = @"Connected";
                [self.lblStatus setTextColor:[UIColor greenColor]];
                [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
                [self checkUUID];
                
                break;
            case STATUS_DISCONNECTED:
                [self.btnStart setHidden:YES];
                self.lblStatus.text = @"Disconnected";
                [self.lblStatus setTextColor:[UIColor redColor]];
                [self.btnAction setTitle:@"Connect" forState:UIControlStateNormal];
                break;
            case STATUS_SCANNING:
                [self.btnStart setHidden:YES];
                self.lblStatus.text = @"Scanning near devices...";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnAction setTitle:@"Cancel connection" forState:UIControlStateNormal];
                break;
            case STATUS_CONNECTING:
                [self.btnStart setHidden:YES];
                self.lblStatus.text = @"Connecting";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
        }
        
        //[self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
    });
}

- (void)device:(int)device onConnectionError:(int)error{
    dispatch_async(dispatch_get_main_queue(), ^{
    [self.lblStatus setTextColor:[UIColor redColor]];
    _lblStatus.text = [@"On result error: " stringByAppendingString:[@(error) stringValue]];
    });
}

- (void)device:(int)device onBatteryLevelReceived:(int)battery{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor redColor]];
        _lblStatus.text = [@"Battery Level: " stringByAppendingString:[@(battery) stringValue]];
        //[self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
    });
}

- (void)heartDeviceOnResult:(LifevitSDKHeartData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        switch ([data.errorCode intValue]) {
            case CODE_OK:
                _lblSystolic.text = [data.systolic stringValue];
                _lblDiastolic.text = [data.diastolic stringValue];
                _lblPulse.text = [data.pulse stringValue];
                self.lblStatus.text = @"Connected";
                [self.lblStatus setTextColor:[UIColor greenColor]];
                break;
                
            default:
                if([data.errorCode intValue] != CODE_LOW_BATTERY){
                    [self.lblStatus setTextColor:[UIColor redColor]];
                    _lblStatus.text = [@"On result error: " stringByAppendingString:[data.errorCode stringValue]];
                }
                break;
        }
        
        //[self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
    });
    
    
    [[LifevitSDKManager sharedInstance] checkBatteryLevel:DEVICE_HEART];
}

- (void)heartDeviceOnProgressMeasurement:(int)pulse{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor blackColor]];
        //[self.btnStart setTitle:@"Stop Measurement" forState:UIControlStateNormal];
        
        _lblStatus.text = [@"Progress measurement. Pulse: " stringByAppendingString:[@(pulse) stringValue]];
    });
}



@end
