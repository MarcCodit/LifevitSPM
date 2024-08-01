//
//  ViewController.m
//  BabyThermometerTest
//
//  Created by Oscar on 26/3/18.
//

#import "BabyThermometerViewController.h"

@interface BabyThermometerViewController ()

@end

@implementation BabyThermometerViewController {
    int deviceStatus;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Baby Thermometer"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].babyThermometerDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_BABYTHERMOMETER]){
        deviceStatus = STATUS_CONNECTED;
    }
    else{
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_BABYTHERMOMETER onConnectionChanged:deviceStatus];
    
}

- (IBAction)onActionPressed:(id)sender {
    
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_BABYTHERMOMETER withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_BABYTHERMOMETER];
            
            break;
    }
}
#pragma mark - BabyThermometer delegate

- (void)babyThermometerOnResult:(LifevitSDKBabyThermometerData *)data {
    dispatch_async(dispatch_get_main_queue(), ^{
        
        self.lblTemperature.text = [NSString stringWithFormat:@"%.2f", [data.temperature doubleValue]];
        self.lblEnvironmentTemperature.text = [NSString stringWithFormat:@"%.2f", [data.environmentTemperature doubleValue]];

    });
}


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
