//
//  TensioBraceletViewController.m
//  TensioBraceletSDKTest
//
//  Created by Oscar on 12/12/17.
//  Copyright © 2017 Oscar. All rights reserved.
//

#import "TensioBraceletViewController.h"

@interface TensioBraceletViewController ()
@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblSystolic;
@property (weak, nonatomic) IBOutlet UILabel *lblDiastolic;
@property (weak, nonatomic) IBOutlet UILabel *lblPulse;
@property (weak, nonatomic) IBOutlet UILabel *lblSteps;

@property (weak, nonatomic) IBOutlet UIButton *btnAction;
@property (weak, nonatomic) IBOutlet UIButton *btnStart;
@property (weak, nonatomic) IBOutlet UITextView *tvInfo;

@property (weak, nonatomic) IBOutlet UIView *vFunctions1;
@property (weak, nonatomic) IBOutlet UIView *vFunctions2;
@property (weak, nonatomic) IBOutlet UIView *vFunctions3;



@end

@implementation TensioBraceletViewController {
    int deviceStatus;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Tensiometer Bracelet"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].tensioBraceletDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected: DEVICE_TENSIO_BRACELET]){
        
        deviceStatus = STATUS_CONNECTED;
        
    }
    else{
        
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_TENSIO_BRACELET onConnectionChanged:deviceStatus];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)onClearReceivedData:(id)sender {
    _tvInfo.text = @"";
}


- (IBAction)onActionPressed:(id)sender {
    switch(deviceStatus){
        case STATUS_DISCONNECTED :
            [[LifevitSDKManager sharedInstance] connectDevice: DEVICE_TENSIO_BRACELET withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice: DEVICE_TENSIO_BRACELET];
            break;
    }
}


- (IBAction)onStartMeasurement:(id)sender {
    
    if (![[LifevitSDKManager sharedInstance] isTensioBraceletMeasuring]) {
        //[[LifevitSDKManager sharedInstance] returnMeasurementTensioBracelet];
        [[LifevitSDKManager sharedInstance] startMeasurementTensioBracelet];
    } else {
        [[LifevitSDKManager sharedInstance] stopMeasurementTensioBracelet];
    }
}

- (IBAction)onGetBloodPressureHistory:(id)sender {
    [[LifevitSDKManager sharedInstance] getBloodPressureHistoryTensioBracelet];
}

- (IBAction)onRemoveBloodPressureHistory:(id)sender {
    [[LifevitSDKManager sharedInstance] removeBloodPressureHistoryTensioBracelet];
}

/*- (IBAction)onGetSmartwatchTime:(id)sender {
 [[LifevitSDKManager sharedInstance] getSmartwatchTimeTensioBracelet];
 }
 
 
 - (IBAction)onGetAmbulatoryBloodPressure:(id)sender {
 [[LifevitSDKManager sharedInstance] getAmbulatoryBloodPressureTimeTensioBracelet];
 }*/

- (IBAction)onGetBasicInfo:(id)sender {
    [[LifevitSDKManager sharedInstance] getBasicInfoTensioBracelet];
}


- (IBAction)onReturn:(id)sender {
    [[LifevitSDKManager sharedInstance] returnMeasurementTensioBracelet];
}

/*- (IBAction)onResetDefaults:(id)sender {
 [[LifevitSDKManager sharedInstance] resetDefaultsTensioBracelet];
 }*/

- (IBAction)onSetTime:(id)sender {
    [[LifevitSDKManager sharedInstance] setSmartwatchTimeTensioBracelet];
}

- (IBAction)onSetSmartwatchConfig:(id)sender {
    
    LifevitSDKTensioBraceletConfig* config = [LifevitSDKTensioBraceletConfig new];
    config.ambulatoryEnabled = YES;
    config.hand = LEFT;
    
    [[LifevitSDKManager sharedInstance] setSmartwatchConfigTensioBracelet:config];
}

- (IBAction)setAmbulatoryBloodPressureTime:(id)sender {
    
    // NSLog(@"Setting ambulatory blood pressure time from %i:%i to %i:%i with every:%i", hour, minute, hourFinish, minuteFinish, intervalMinutes);
    
    NSMutableArray* intervals = [NSMutableArray new];
    LifevitSDKTensioBraceletInterval* interval = [LifevitSDKTensioBraceletInterval new];
    interval.startHour = @(10);
    interval.startMinuteInterval = O_CLOCK;
    
    interval.endHour = @(13);
    interval.endMinuteInterval = O_CLOCK;
    
    interval.ambulatoriInterval = HALF_HOUR;
    
    [intervals addObject:interval];
    
    interval = [LifevitSDKTensioBraceletInterval new];
    interval.startHour = @(13);
    interval.startMinuteInterval = O_CLOCK;
    
    interval.endHour = @(16);
    interval.endMinuteInterval = O_CLOCK;
    
    interval.ambulatoriInterval = HALF_HOUR;
    
    [intervals addObject:interval];
    
    
    interval = [LifevitSDKTensioBraceletInterval new];
    interval.startHour = @(16);
    interval.startMinuteInterval = O_CLOCK;
    
    interval.endHour = @(19);
    interval.endMinuteInterval = O_CLOCK;
    
    interval.ambulatoriInterval = HALF_HOUR;
    
    [intervals addObject:interval];
    
    [[LifevitSDKManager sharedInstance] setAmbulatoryBloodPressureTimeTensioBracelet:intervals];
    
}



#pragma mark - Device delegate

- (void)device:(int)device onConnectionChanged:(int)status{
    deviceStatus = status;
    dispatch_async(dispatch_get_main_queue(), ^{
        
        switch(status){
            case STATUS_CONNECTED:
                [self.btnStart setHidden:NO];
                [self.vFunctions1 setHidden:NO];
                [self.vFunctions2 setHidden:NO];
                [self.vFunctions3 setHidden:NO];
                self.lblStatus.text = @"Connected";
                [self.lblStatus setTextColor:[UIColor greenColor]];
                [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
                break;
            case STATUS_DISCONNECTED:
                [self.btnStart setHidden:YES];
                [self.vFunctions1 setHidden:YES];
                [self.vFunctions2 setHidden:YES];
                [self.vFunctions3 setHidden:YES];
                self.lblStatus.text = @"Disconnected";
                [self.lblStatus setTextColor:[UIColor redColor]];
                [self.btnAction setTitle:@"Connect" forState:UIControlStateNormal];
                break;
            case STATUS_SCANNING:
                [self.btnStart setHidden:YES];
                [self.vFunctions1 setHidden:YES];
                [self.vFunctions2 setHidden:YES];
                [self.vFunctions3 setHidden:YES];
                self.lblStatus.text = @"Scanning near devices...";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnAction setTitle:@"Cancel connection" forState:UIControlStateNormal];
                break;
            case STATUS_CONNECTING:
                [self.btnStart setHidden:YES];
                [self.vFunctions1 setHidden:YES];
                [self.vFunctions2 setHidden:YES];
                [self.vFunctions3 setHidden:YES];
                self.lblStatus.text = @"Connecting";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
                break;
        }
        
        if ([[LifevitSDKManager sharedInstance] isTensioBraceletMeasuring]) {
            [self.btnStart setTitle:@"Stop Measurement" forState:UIControlStateNormal];
        } else {
            [self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
        }
        
    });
}

- (void)device:(int)device onConnectionError:(int)error{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor redColor]];
        _lblStatus.text = [@"On result error: " stringByAppendingString:[@(error) stringValue]];
        
        [self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
    });
}

- (void)tensioBraceletOnResult:(LifevitSDKTensioBraceletData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        _lblSystolic.text = [data.systolic stringValue];
        _lblDiastolic.text = [data.diastolic stringValue];
        _lblPulse.text = [data.pulse stringValue];
        _lblSteps.text = @"-";
        
        
        [self.btnStart setTitle:@"Start Measurement" forState:UIControlStateNormal];
    });
}

-(void)tensioBraceletInformation:(id)data{
    
    self.tvInfo.text = [NSString stringWithFormat:@"%@\nData Received: %@", self.tvInfo.text,data];
}

- (void)tensioBraceletOnProgressMeasurement:(int)value{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor blackColor]];
        _lblStatus.text = [@"Progress measurement. Value: " stringByAppendingString:[@(value) stringValue]];
        
        [self.btnStart setTitle:@"Stop Measurement" forState:UIControlStateNormal];
        
    });
}

- (void)tensioBraceletRequestExecuted:(TensioBraceletRequest)request{
    
    self.tvInfo.text = [[NSString stringWithFormat:@"%@\nRequest executed Value: ", self.tvInfo.text] stringByAppendingString:[@(request) stringValue]];
}

@end
