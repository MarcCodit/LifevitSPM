//
//  OximeterViewController.m
//  OximeterSDKTest
//
//  Created by Oscar Navas on 7/11/17.
//

#import "OximeterViewController.h"

@interface OximeterViewController ()


@property (weak, nonatomic) IBOutlet UILabel *lblUUID;

@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UILabel *lblSp2;
@property (weak, nonatomic) IBOutlet UILabel *lblPi;
@property (weak, nonatomic) IBOutlet UILabel *lblPul_min;
@property (weak, nonatomic) IBOutlet UILabel *lblRes_min;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;

@end

@implementation OximeterViewController {
    int deviceStatus;    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"Oximeter"];
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].oximeterDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_OXIMETER]){
        deviceStatus = STATUS_CONNECTED;
    } else {
        deviceStatus = STATUS_DISCONNECTED;
    }
    
    [self device:DEVICE_OXIMETER onConnectionChanged:deviceStatus];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {

    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_OXIMETER];
            break;
    }
}

- (IBAction)onConnectByUUID:(id)sender {
    
    NSString* uuid = self.lblUUID.text;
 
    if(uuid.length>0){
        [[LifevitSDKManager sharedInstance] connectByUUID:uuid withType:DEVICE_OXIMETER];
    }
}

- (void) checkUUID{
    NSString* uuid = [[LifevitSDKManager sharedInstance] getDeviceUUID:DEVICE_OXIMETER];
    
    if(uuid){
        self.lblUUID.text = uuid;
    }
}

#pragma mark - Oximeter delegate

- (void)oximeterDeviceOnProgressMeasurement:(LifevitSDKOximeterData*) data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        
        self.lblStatus.text = [NSString stringWithFormat:@"%@ - %d", [dateFormatter stringFromDate:data.date], [data.pleth intValue]];

    });
    
}

- (void)oximeterDeviceOnResult:(LifevitSDKOximeterData*) data{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        
        self.lblStatus.text = [NSString stringWithFormat:@"%@ - %d", [dateFormatter stringFromDate:data.date], [data.pleth intValue]];
        self.lblSp2.text = [NSString stringWithFormat:@"%d", [data.sp2 intValue]];
        self.lblPi.text = [NSString stringWithFormat:@"%d", [data.pi intValue]];
        self.lblPul_min.text = [NSString stringWithFormat:@"%d", [data.lpm intValue]];
        self.lblRes_min.text = [NSString stringWithFormat:@"%d", [data.rpm intValue]];
        
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
            
            //Miramos el uuid del dispositivo
            [self checkUUID];
            
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
