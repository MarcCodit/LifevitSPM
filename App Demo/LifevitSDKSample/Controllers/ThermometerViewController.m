//
//  ViewController.m
//  ThemometerTest
//
//  Created by iNMovens Solutions on 20/11/17.
//  Copyright © 2017 Lifevit. All rights reserved.
//

#import "ThermometerViewController.h"

@interface ThermometerViewController ()


@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblUnit;
@property (weak, nonatomic) IBOutlet UILabel *lblTemperature;
@property (weak, nonatomic) IBOutlet UIButton *btnStart;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;
@property (weak, nonatomic) IBOutlet UIButton *btnCommand;

@end

@implementation ThermometerViewController {
    int deviceStatus;
}

@synthesize btnCommand;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Thermometer"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].thermometerDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_THERMOMETER]){
        deviceStatus = STATUS_CONNECTED;
        [btnCommand setHidden:NO];
    }
    else{
        deviceStatus = STATUS_DISCONNECTED;
        [btnCommand setHidden:YES];
    }
    
    [self device:DEVICE_THERMOMETER onConnectionChanged:deviceStatus];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {
    
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_THERMOMETER withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_THERMOMETER];
            
            break;
    }
}
- (IBAction)onCommandPressed:(id)sender {
    UIAlertController * alert = [UIAlertController
                                 alertControllerWithTitle:@"Please select command"
                                 message:@""
                                 preferredStyle:UIAlertControllerStyleAlert];
    
    //Add Buttons
    
    UIAlertAction* action = [UIAlertAction
                             actionWithTitle:@"Change to celsius"
                             style:UIAlertActionStyleDefault
                             handler:^(UIAlertAction * action) {
                                 //Handle your yes please button action here
                                 [[LifevitSDKManager sharedInstance] sendThermometerCommand:THERMOMETERV2_COMMAND_CELSIUS];
                             }];
    [alert addAction:action];
    action = [UIAlertAction
              actionWithTitle:@"Change to farenheit"
              style:UIAlertActionStyleDefault
              handler:^(UIAlertAction * action) {
                  //Handle your yes please button action here
                  [[LifevitSDKManager sharedInstance] sendThermometerCommand:THERMOMETERV2_COMMAND_FARENHEIT];
              }];
    [alert addAction:action];
    action = [UIAlertAction
              actionWithTitle:@"Get last measurement"
              style:UIAlertActionStyleDefault
              handler:^(UIAlertAction * action) {
                  //Handle your yes please button action here
                  [[LifevitSDKManager sharedInstance] sendThermometerCommand:THERMOMETERV2_COMMAND_LAST_MEASURE];
              }];
    [alert addAction:action];
    action = [UIAlertAction
              actionWithTitle:@"Get version number"
              style:UIAlertActionStyleDefault
              handler:^(UIAlertAction * action) {
                  //Handle your yes please button action here
                  [[LifevitSDKManager sharedInstance] sendThermometerCommand:THERMOMETERV2_COMMAND_VERSION_NUMBER];
              }];
    [alert addAction:action];
    action = [UIAlertAction
              actionWithTitle:@"Shutdown"
              style:UIAlertActionStyleDefault
              handler:^(UIAlertAction * action) {
                  //Handle your yes please button action here
                  [[LifevitSDKManager sharedInstance] sendThermometerCommand:THERMOMETERV2_COMMAND_SHUTDOWN];
              }];
    [alert addAction:action];
    
    action= [UIAlertAction
                               actionWithTitle:@"Close"
                               style:UIAlertActionStyleDefault
                               handler:^(UIAlertAction * action) {
                                   //Handle no, thanks button
                               }];
    
    //Add your buttons to alert controller
    
    [alert addAction:action];
    
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - Thermometer delegate

- (void)thermometerOnResult:(LifevitSDKThermometerData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        
        
        self.lblUnit.text = [NSString stringWithFormat:@"%@", data.unit];
        self.lblTemperature.text = [NSString stringWithFormat:@"%.2f", [data.temperature doubleValue]];
    });
}

- (void)thermometerOnError:(int)errorCode{
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

- (void)thermometerOnSuccessCommand:(LifevitSDKThermometerSuccessData *)data{
    
    dispatch_async(dispatch_get_main_queue(), ^{
    switch ([data.command intValue]){
        case THERMOMETER_SUCCESS_UNIT:
            self.lblTemperature.text = @"Command success: Changed unit";
            break;
        case THERMOMETER_SUCCESS_SHUTDOWN:
            self.lblTemperature.text = @"Command success: Shutdown";
            break;
        case THERMOMETER_SUCCESS_VERSION:
            self.lblTemperature.text = [@"Command success: Version number: " stringByAppendingString:[data.data stringValue]] ;
            break;
            
    }
    });
}


#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    deviceStatus = status;
    dispatch_async(dispatch_get_main_queue(), ^{
        
    self.btnAction.hidden = false;
    self.btnStart.hidden = deviceStatus != STATUS_CONNECTED;
    switch(status){
        case STATUS_CONNECTED:
            [btnCommand setHidden:NO];
            self.lblStatus.text = @"Connected";
            [self.lblStatus setTextColor:[UIColor greenColor]];
            [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
            break;
        case STATUS_DISCONNECTED:
            [btnCommand setHidden:YES];
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
