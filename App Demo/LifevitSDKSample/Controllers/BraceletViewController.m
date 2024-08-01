//
//  ViewController.m
//  BraceletSDKTest
//
//  Created by David Casas on 5/9/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import "BraceletViewController.h"


@interface BraceletViewController ()
@property (weak, nonatomic) IBOutlet UILabel *lblStatus;
@property (weak, nonatomic) IBOutlet UITextView *txtReceivedData;
@property (weak, nonatomic) IBOutlet UIButton *btnAction;
@property (weak, nonatomic) IBOutlet UIButton *btnSendCommand;
@property (weak, nonatomic) IBOutlet UISegmentedControl *braceletSelector;
@property (strong,nonatomic) NSTimer* timer;
@property (assign,nonatomic) BOOL enableSport;
@property (assign,nonatomic) BOOL enableHealthMeasurementHRV;
@property (assign,nonatomic) BOOL enableHealthMeasurementHeartRate;
@property (assign,nonatomic) BOOL enableHealthMeasurementBloodOxygen;
@end

@implementation BraceletViewController{
    int deviceStatus;
    BOOL showingECG;
}

- (IBAction)testPressed:(id)sender {
}

-(void) viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
    showingECG = false;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setTitle:@"AT250/AT500HR/VITAL"];
    
    showingECG = false;
    
    // Do any additional setup after loading the view, typically from a nib.
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].braceletDelegate = self;
    [LifevitSDKManager sharedInstance].braceletAT250Delegate = self;
    [LifevitSDKManager sharedInstance].braceletVITALDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_BRACELET_AT500HR]){
        deviceStatus = STATUS_CONNECTED;
        [_braceletSelector setSelectedSegmentIndex:1];
        [self device:DEVICE_BRACELET_AT500HR onConnectionChanged:deviceStatus];
    }else if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_BRACELET_AT250]){
        deviceStatus = STATUS_CONNECTED;
        [_braceletSelector setSelectedSegmentIndex:0];
        [self device:DEVICE_BRACELET_AT250 onConnectionChanged:deviceStatus];
    }else if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_BRACELET_VITAL]){
        deviceStatus = STATUS_CONNECTED;
        [_braceletSelector setSelectedSegmentIndex:2];
        [self device:DEVICE_BRACELET_VITAL onConnectionChanged:deviceStatus];
    }
    else{
        deviceStatus = STATUS_DISCONNECTED;
        [self device:DEVICE_BRACELET_AT500HR onConnectionChanged:deviceStatus];
        [self device:DEVICE_BRACELET_AT250 onConnectionChanged:deviceStatus];
        [self device:DEVICE_BRACELET_VITAL onConnectionChanged:deviceStatus];
    }
    
    [self updateButtons];
    
    _enableSport = NO;
    _enableHealthMeasurementHRV = NO;
    _enableHealthMeasurementHeartRate = NO;
    _enableHealthMeasurementBloodOxygen = NO;
    //self.timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(initBraceletChecks) userInfo:nil repeats:YES];
    
}

-(void) updateButtons{
    
    switch(deviceStatus){
        case STATUS_CONNECTED:
            [self.btnSendCommand setHidden:NO];
            self.lblStatus.text = @"Connected";
            [self.lblStatus setTextColor:[UIColor greenColor]];
            [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
            [_braceletSelector setEnabled:false];
            break;
        case STATUS_DISCONNECTED:
            [self.btnSendCommand setHidden:YES];
            self.lblStatus.text = @"Disconnected";
            [self.lblStatus setTextColor:[UIColor redColor]];
            [self.btnAction setTitle:@"Connect" forState:UIControlStateNormal];
            [_braceletSelector setEnabled:true];
            break;
        case STATUS_SCANNING:
            [self.btnSendCommand setHidden:YES];
            self.lblStatus.text = @"Scanning near devices...";
            [self.lblStatus setTextColor:[UIColor blackColor]];
            [self.btnAction setTitle:@"Cancel connection" forState:UIControlStateNormal];
            [_braceletSelector setEnabled:false];
            break;
        case STATUS_CONNECTING:
            [self.btnSendCommand setHidden:YES];
            self.lblStatus.text = @"Connecting";
            [self.lblStatus setTextColor:[UIColor blackColor]];
            [self.btnAction setTitle:@"Disconnect" forState:UIControlStateNormal];
            [_braceletSelector setEnabled:false];
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onActionPressed:(id)sender {
    [self reconnectDevice];
}

- (void) reconnectDevice{
    dispatch_async(dispatch_get_main_queue(), ^{
        int braceletDevice = [self getSelectedBracelet];
        
        switch(self->deviceStatus){
            case STATUS_DISCONNECTED:
                [[LifevitSDKManager sharedInstance] connectDevice:braceletDevice withTimeout:60000];
                
                
                // [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER withTimeout:30];
                // [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_HEART withTimeout:30];
                break;
            case STATUS_CONNECTED:
            case STATUS_SCANNING:
            case STATUS_CONNECTING:
                [[LifevitSDKManager sharedInstance] disconnectDevice:braceletDevice];
                break;
        }
    });
}

- (void)prepareCommandListAT250:(UIAlertController *)alert {
    UIAlertAction* action = [UIAlertAction actionWithTitle:@"Set Datetime"
                                                     style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action)
                             {
                                 [[LifevitSDKManager sharedInstance] configureBraceletAT250Datetime: [NSDate date]];
                             }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set User Information Height: (190) Weight: (90) Gender: (Male/0) Birthday: (24/12/1980) Vibrate: (YES)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  NSString *dateStr = @"1980-12-24";
                  NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
                  [dateFormatter setDateFormat:@"yyyy-MM-dd"];
                  NSDate *date = [dateFormatter dateFromString:dateStr];
                  
                  [[LifevitSDKManager sharedInstance] configureBraceletAT250UserInfo: @190
                                                                          userWeight: @90
                                                                          userGender: @0
                                                                        userBirthday: date
                                                                             vibrate: YES];
              }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Update Firmware"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] updateBraceletAT250Firmware];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Steps Goal: (8000)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] configureBraceletAT250StepsGoal: @8000];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Data from today"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] getBraceletAT250TodayData];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get History Data 3 days ago"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@6];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@5];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@4];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@3];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@2];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@1];
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HistoryData:@0];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get HR Sync Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  
                  //-(void)getBraceletAT250HeartRateValue;
                  //-(void)setBraceletAT250RealtimeHREnabled:(BOOL) enabled;
                  //-(void)setBraceletAT250MonitoringHREnabled:(BOOL) enabled;
                  //-(void)setBraceletAT250MonitoringHRAuto:(BOOL) enabled withTimeRange: (LifevitSDKAT250TimeRange*) range;
                  [[LifevitSDKManager sharedInstance] getBraceletAT250HeartRateSync];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Enable realtime HR"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] setBraceletAT250RealtimeHREnabled:YES];
              }];
    
    [alert addAction:action];
    action = [UIAlertAction actionWithTitle:@"Disable realtime HR"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] setBraceletAT250RealtimeHREnabled:NO];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Enable monitoring HR"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] setBraceletAT250MonitoringHREnabled:YES];
              }];
    
    [alert addAction:action];
    action = [UIAlertAction actionWithTitle:@"Disable monitoring HR"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] setBraceletAT250MonitoringHREnabled:NO];
              }];
    
    [alert addAction:action];
    action = [UIAlertAction actionWithTitle:@"Set monitoring HR time range"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  LifevitSDKAT250TimeRange* range = [LifevitSDKAT250TimeRange new];
                  [[LifevitSDKManager sharedInstance] setBraceletAT250MonitoringHRAuto:YES withTimeRange:range];
              }];
    
    [alert addAction:action];
}


- (void)prepareCommandListVITAL:(UIAlertController *)alert {
    
    UIAlertAction* action = [UIAlertAction actionWithTitle:@"Unlock QR Code"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] showVitalQR:false];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Show QR Code"
                                                     style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action)
                             {
        [[LifevitSDKManager sharedInstance] showVitalQR:true];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Set Time"
                                                     style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action)
                             {
        [[LifevitSDKManager sharedInstance] setBraceletTime:[NSDate date]];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Time"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getBraceletTime];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set User Information"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        LifevitSDKUser* user = [LifevitSDKUser new];
        
        NSString *dateStr = @"1980-12-24";
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd"];
        NSDate *date = [dateFormatter dateFromString:dateStr];
        
        user.birthday = date;
        user.weight = @(84);
        user.height = @(174);
        user.gender = @(GENDER_FEMALE);
        
        [[LifevitSDKManager sharedInstance] setVitalUserInformation: user];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get User Information"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getVitalUserInformation];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Set Device Parameters"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        
        LifevitSDKVitalParams* params = [LifevitSDKVitalParams new];
        params.notifications.facebook = YES;
        params.notifications.call = YES;
        params.notifications.mobileInformation = YES;
        params.notifications.linkedin = YES;
        params.notifications.qq = YES;
        params.notifications.instagram = YES;
        params.notifications.twitter = YES;
        params.notifications.wechat = YES;
        params.notifications.skype = YES;
        params.notifications.telegram = YES;
        params.notifications.vkclient = YES;
        
        params.basicHeartRateSetting = 50;
        params.screenBrightness = 12;
        
        [[LifevitSDKManager sharedInstance] setVitalParameters: params];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Device Parameters"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getVitalParameters];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get MAC Address"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getVitalMACAddress];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Step Goal"
                                                     style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action)
                             {
        [[LifevitSDKManager sharedInstance] setVitalStepsGoal:@(8000)];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Step Goal"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getVitalStepsGoal];
    }];
    [alert addAction:action];
    
    
    
    action = [UIAlertAction actionWithTitle:@"Get Device Battery"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] getBraceletBattery];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get Blood Oxygen Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalData:OXYMETER];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Automatic Blood Oxygen Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalData:OXYMETER periodically:true];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Automatic Blood Oxygen Detection Period"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        LifevitSDKVitalPeriod* period = [LifevitSDKVitalPeriod new];
        
        period.workingMode = TIME_PERIOD;
        period.type = OXYMETER;
        period.intervalTime = 15;
        period.startHour = 8;
        period.startMinute = 30;
        period.endHour = 22;
        period.endMinute=30;
        
        [period setWeekdays:true];
        [period setWeekend:false];
        
          
        [[LifevitSDKManager sharedInstance] setVitalPeriodicConfiguration:period];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Automatic Blood Oxygen Detection Period"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalPeriodicConfiguration:OXYMETER];
        
    }];
    [alert addAction:action];
        
    action = [UIAlertAction actionWithTitle:@"Get Temperature Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        
        [[LifevitSDKManager sharedInstance] getVitalData:TEMPERATURE];
        
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Automatic Temperature Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalData:TEMPERATURE periodically:true];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Heart Rate Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        
        [[LifevitSDKManager sharedInstance] getVitalData:HR];
        
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Automatic Heart Rate Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalData:HR periodically:true];
        
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Set Period Heart Rate Detection"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        LifevitSDKVitalPeriod* period = [LifevitSDKVitalPeriod new];
        
        period.workingMode = TIME_INTERVAL;
        period.type = HR;
        period.intervalTime = 15;
        period.startHour = 8;
        period.startMinute = 30;
        period.endHour = 22;
        period.endMinute=30;
        
        [period setWeekdays:true];
        [period setWeekend:false];
        
          
        [[LifevitSDKManager sharedInstance] setVitalPeriodicConfiguration:period];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Period Heart Rate Detection"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalPeriodicConfiguration:HR];

    }];
    [alert addAction:action];
    
    
    
    
    action = [UIAlertAction actionWithTitle:@"Set Period Temperature Rate Detection"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        LifevitSDKVitalPeriod* period = [LifevitSDKVitalPeriod new];
        
        period.workingMode = TIME_INTERVAL;
        period.type = TEMPERATURE;
        period.intervalTime = 15;
        period.startHour = 8;
        period.startMinute = 30;
        period.endHour = 22;
        period.endMinute=30;
        
        [period setWeekdays:true];
        [period setWeekend:false];
        
          
        [[LifevitSDKManager sharedInstance] setVitalPeriodicConfiguration:period];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Period Temperature Detection"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        [[LifevitSDKManager sharedInstance] getVitalPeriodicConfiguration:TEMPERATURE];

    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get ECG Start Data Uploading"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] startVitalECG];
    }];
    [alert addAction:action];
    
    
    
    action = [UIAlertAction actionWithTitle:@"Get ECG Measurement Status"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalECGStatus];
    }];
    [alert addAction:action];
    

    action = [UIAlertAction actionWithTitle:@"Get ECG Waveform"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalECGWaveform];
    }];
    [alert addAction:action];
 
    
    action = [UIAlertAction actionWithTitle:@"Get HRV Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalData:VITALS];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Realtime step counting ON"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] setVitalRealtimeSteps:true temperature:true];
    }];
    [alert addAction:action];

    action = [UIAlertAction actionWithTitle:@"Set Realtime step counting OFF"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
[[LifevitSDKManager sharedInstance] setVitalRealtimeSteps:false temperature:false];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get total step data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        
[[LifevitSDKManager sharedInstance] getBraceletCurrentSteps];
        
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get detailed step data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        
[[LifevitSDKManager sharedInstance] getVitalData:STEPS];
        
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get detailed sleep data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
[[LifevitSDKManager sharedInstance] getVitalData:SLEEP];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Set activity period"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        LifevitSDKVitalActivityPeriod* period = [LifevitSDKVitalActivityPeriod new];
                
        period.exerciseReminderPeriod = 180;
        period.minimumNumberSteps = 120;
        
        [period setWeekdays:true];
        
        period.startHour = 8;
        period.startMinute = 30;
        period.endHour = 22;
        period.endMinute = 30;
                
        [[LifevitSDKManager sharedInstance] setVitalActivityPeriod:period];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get activity period"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalActivityPeriod];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Start sport mode"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] startVitalSportMode:BREATH levelSelection:MEDIUM_TIME timePeriod:100];
        
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Stop sport mode"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
            [[LifevitSDKManager sharedInstance] stopVitalSportMode];
    }];
    [alert addAction:action];
    
    
    
    action = [UIAlertAction actionWithTitle:@"Start health measurement control (HRV)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] startVitalMeasurement:VITALS];
    }];
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Stop health measurement control (HRV)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] stopVitalMeasurement:VITALS];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Start health measurement control (HEART RATE)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] startVitalMeasurement:HR];
        
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Stop health measurement control (HEART RATE)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] stopVitalMeasurement:HR];
        
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Start health measurement control (BLOOD OXYGEN)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] startVitalMeasurement:OXYMETER];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Stop health measurement control (BLOOD OXYGEN)"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        [[LifevitSDKManager sharedInstance] stopVitalMeasurement:OXYMETER];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Sport Data"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                
        [[LifevitSDKManager sharedInstance] getVitalData:SPORTS];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Weaher"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        LifevitSDKVitalWeather* data = [LifevitSDKVitalWeather new];
        data.location = @"IOS";
        data.status = SUNNY;
        data.temperature = 16;
        data.maxTemperature = 20;
        data.minTemperature = 10;
        data.airQuality = 90;
                
        [[LifevitSDKManager sharedInstance] setVitalWeather:data];
    }];
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Alarms"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
        
        NSMutableArray* alarms = [NSMutableArray new];
        LifevitSDKVitalAlarm* data = [LifevitSDKVitalAlarm new];
        data.type = ALARM;
        data.text = @"Alarm";
        data.enabled= true;
        [data setWeekdays:true];
        data.hour = @(12);
        data.minute = @(0);
        
        [alarms addObject:data];
                
        [[LifevitSDKManager sharedInstance] setVitalAlarms:alarms];
    }];
    [alert addAction:action];
    
}




-(void) prepareCommandList: (UIAlertController*) alert {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        int braceletDevice = [self getSelectedBracelet];
        switch (braceletDevice) {
            case DEVICE_BRACELET_AT250: {
                [self prepareCommandListAT250:alert];
                
            }
                break;
                                
            case DEVICE_BRACELET_VITAL: {
                [self prepareCommandListVITAL:alert];
                
            }
                break;
                
            default: {
                if(![[LifevitSDKManager sharedInstance] isBraceletInActivity]){
                    
                    UIAlertAction* action = [UIAlertAction actionWithTitle:@"Send HOLA"
                                                                     style:UIAlertActionStyleDefault
                                                                   handler:^(UIAlertAction * action)
                                             {
                                                 [[LifevitSDKManager sharedInstance] sendTextToAT500HR:@"HOLA"];
                                             }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Set User Height (190)"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] configureBraceletUserHeight:190];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Set User Weight (90)"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] configureBraceletUserWeight:90];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Set current date"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] configureBraceletDate:[NSDate new]];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure All ACNS"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  NSArray* ancsTypes = [NSArray arrayWithObjects:@(ACNS_CALL),@(ACNS_QQ),@(ACNS_SMS),@(ACNS_LINE),@(ACNS_EMAIL),@(ACNS_SKYPE),@(ACNS_WECHAT),@(ACNS_TWITTER),@(ACNS_FACEBOOK),@(ACNS_WHATSAPP),@(ACNS_INSTAGRAM), nil];
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletACNS:ancsTypes];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure NO ACNS"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  NSArray* ancsTypes = [NSArray new];
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletACNS:ancsTypes];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure NO Hand"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletRiseHand:BRACELET_HAND_NONE];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure Right Hand"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletRiseHand:BRACELET_HAND_RIGHT];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure Left Hand"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] configureBraceletRiseHand:BRACELET_HAND_LEFT];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure Antitheft"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletAntitheft:YES];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure NO Antitheft"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletAntitheft:NO];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure Monitor HeartRate"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletMonitorHeartRate:YES];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure NO Monitor HeartRate"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletMonitorHeartRate:NO];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure FindPhone"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletSettingFindPhone:YES];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure NO FindPhone"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletSettingFindPhone:NO];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Get current Steps"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] getBraceletCurrentSteps];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Get HeartBeat"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] getBraceletHeartBeat];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Sync History"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] synchronizeBraceletHistoryData];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Start Activity"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] sendBraceletStartOrFinishExercise:YES];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Bind bracelet"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] bindBracelet];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Activate bracelet"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] activateBracelet];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure alarm next minute"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  LifevitSDKBraceletAlarm * alarm = [[LifevitSDKBraceletAlarm alloc] init];
                                  alarm.monday = NO;
                                  alarm.tuesday = NO;
                                  alarm.wednesday = YES;
                                  alarm.thursday = NO;
                                  alarm.friday = NO;
                                  alarm.saturday = NO;
                                  alarm.sunday = NO;
                                  
                                  NSDate * date = [NSDate dateWithTimeIntervalSinceNow:1*60];
                                  NSDateFormatter * df = [NSDateFormatter new];
                                  [df setDateFormat:@"HH"];
                                  alarm.hour = @([[df stringFromDate:date] intValue]);
                                  [df setDateFormat:@"mm"];
                                  alarm.minute = @([[df stringFromDate:date] intValue]);
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletAlarm:alarm];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Disable alarm"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  
                                  
                                  [[LifevitSDKManager sharedInstance] disableBraceletAlarm:NO];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Disable sedentary alarm"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  [[LifevitSDKManager sharedInstance] disableBraceletSedentaryAlarm];
                              }];
                    [alert addAction:action];
                    
                    action = [UIAlertAction actionWithTitle:@"Configure sedentary alarm from 9 to 17"
                                                      style:UIAlertActionStyleDefault
                                                    handler:^(UIAlertAction * action)
                              {
                                  LifevitSDKBraceletSedentaryAlarm* alarm = [LifevitSDKBraceletSedentaryAlarm new];
                                  alarm.startHour = @(9);
                                  alarm.startMinute = @(0);
                                  alarm.endHour = @(17);
                                  alarm.endMinute = @(0);
                                  alarm.interval = @(5);
                                  
                                  [[LifevitSDKManager sharedInstance] configureBraceletSedentaryAlarm:alarm];
                              }];
                    [alert addAction:action];
                    
                }else{
                    UIAlertAction* action = [UIAlertAction actionWithTitle:@"Stop Activity"
                                                                     style:UIAlertActionStyleDefault
                                                                   handler:^(UIAlertAction * action)
                                             {
                                                 
                                                 [[LifevitSDKManager sharedInstance] sendBraceletStartOrFinishExercise:NO];
                                             }];
                    [alert addAction:action];
                }
                
                UIAlertAction* version = [UIAlertAction actionWithTitle:@"Get version"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * action)
                                          {
                                              [[LifevitSDKManager sharedInstance] getBraceletVersion];
                                          }];
                
                [alert addAction:version];
                UIAlertAction* battery = [UIAlertAction actionWithTitle:@"Get battery"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * action)
                                          {
                                              [[LifevitSDKManager sharedInstance] getBraceletBattery];
                                          }];
                
                [alert addAction:battery];
                
                
            }
                break;
        }
        
        UIAlertAction* cancel = [UIAlertAction actionWithTitle:@"Cancel"
                                                         style:UIAlertActionStyleCancel
                                                       handler:^(UIAlertAction * action)
                                 {
                                     
                                 }];
        
        [alert addAction:cancel];
    });
}

- (IBAction)onSendCommand:(id)sender {
    UIAlertController * alert=[UIAlertController alertControllerWithTitle:@"Bracelet TEST"
                                                                  message:@"Choose the command you want to send\n(* not working)"
                                                           preferredStyle:UIAlertControllerStyleAlert];
    
    [self prepareCommandList:alert];
    
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        int braceletDevice = [self getSelectedBracelet];
        if(device == braceletDevice){
            dispatch_async(dispatch_get_main_queue(), ^{
                
                self->deviceStatus = status;
                
                [self updateButtons];
            });
        }
        else{
            switch (device) {
                case DEVICE_HEART:
                    [[LifevitSDKManager sharedInstance] startMeasurement];
                    break;
                    
                default:
                    break;
            }
        }
    });
}

- (void)device:(int)device onConnectionError:(int)error{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor redColor]];
        self.lblStatus.text = [@"On result error: " stringByAppendingString:[@(error) stringValue]];
        
    });}


- (void)device:(int)device onSendInformation:(id)data{
    if([data isKindOfClass:[NSString class]]){
        dispatch_async(dispatch_get_main_queue(), ^{
            
            NSString* text = self.txtReceivedData.text;
            
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:data];
            self.txtReceivedData.text = text;
            [self scrollTextViewToBottom:self.txtReceivedData];
        });
    }
}

-(void)scrollTextViewToBottom:(UITextView *)textView {
     if(textView.text.length > 0 ) {
        NSRange bottom = NSMakeRange(textView.text.length -1, 1);
        [textView scrollRangeToVisible:bottom];
     }

}

- (void)device:(int) device onBatteryLevelReceived:(int) battery{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Battery level: %d", battery]];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

#pragma mark - vital delegate

- (void)braceletVitalSOS:(NSString *)device{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        //NSString* text = self.txtReceivedData.text;
        NSString* text = @"";
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"SOS: "];
        text = [text stringByAppendingString:device];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletVitalDevice:(NSString *)device operation:(BraceletVitalOperation)operation{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        //NSString* text = self.txtReceivedData.text;
        NSString* text = @"";
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Operation %d of device %@", operation, device]];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletVitalDevice:(NSString *)device information:(LifevitSDKResponse *)info{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        //NSString* text = self.txtReceivedData.text;
        NSString* text = @"";
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"braceletVitalDevice command %d of device %@", info.command, device]];
        if(info.data){
            if([info.data isKindOfClass:[NSArray class]]){
                NSArray* a = info.data;
                if(a.count>0){
                    text = [text stringByAppendingString:[NSString stringWithFormat:@"Result: %@", a]];
                    
                }
            }
            else{
                text = [text stringByAppendingString:[NSString stringWithFormat:@"Result: %@", info.data]];
            }
        }
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletVitalDevice:(NSString *)device error:(BraceletVitalError)errorCode forCommand:(BraceletVitalCommand)command{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        //NSString* text = self.txtReceivedData.text;
        NSString* text = @"";
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"braceletVitalDevice ERROR %d command %d of device %@", errorCode, command, device]];
       
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

#pragma mark - bracelet delegate

- (void) braceletActivityStarted{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"ACTIVITY STARTED"];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void) braceletActivityFinished{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"ACTIVITY FINISHED"];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletBatteryReceived:(int)battery{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Battery level: %d", battery]];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}


- (void)braceletHeartDataReceived:(LifevitSDKHeartBeatData *)data{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Heart Data Received: %d", [data.heartRate intValue]]];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletParameterSet:(int)parameter{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        
        switch (parameter) {
            case BRACELET_PARAM_ACNS:
                
                text = [text stringByAppendingString:@"ACNS Configured"];
                break;
            case BRACELET_PARAM_DATE:
                
                text = [text stringByAppendingString:@"Date Configured"];
                break;
            case BRACELET_PARAM_HANDS:
                
                text = [text stringByAppendingString:@"Hands Configured"];
                break;
            case BRACELET_PARAM_HEIGHT:
                
                text = [text stringByAppendingString:@"Height Configured"];
                break;
            case BRACELET_PARAM_TARGET:
                
                text = [text stringByAppendingString:@"Target Configured"];
                break;
            case BRACELET_PARAM_WEIGHT:
                
                text = [text stringByAppendingString:@"Weight Configured"];
                break;
            case BRACELET_PARAM_ANTILOST:
                
                text = [text stringByAppendingString:@"Antilost Configured"];
                break;
            case BRACELET_PARAM_HRMONITOR:
                
                text = [text stringByAppendingString:@"HRMonitor Configured"];
                break;
            case BRACELET_PARAM_FIND_PHONE:
                
                text = [text stringByAppendingString:@"Find Phone Configured"];
                break;
            case BRACELET_PARAM_FIND_DEVICE:
                
                text = [text stringByAppendingString:@"Find Device Configured"];
                break;
                
            default:
                break;
        }
        
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletBeepReceived{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"Beep Received"];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletSyncReceived:(LifevitSDKBraceletData *)data{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"Sync Data Received"];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Step records: %lu", (unsigned long)data.stepsData.count]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Sleep records: %lu", (unsigned long)data.sleepData.count]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"HeartRate records: %lu", (unsigned long)data.heartData.count]];
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"First Results Steps:"];
        
        int i = 0;
        while(i<10 && i<data.stepsData.count){
            LifevitSDKStepData* v = [data.stepsData objectAtIndex:i];
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@ Steps: %d", v.date, [v.steps intValue]]];
            i++;
        }
        
        int totalSteps = 0;
        long totalDistance = 0;
        long totalCalories = 0;

        for (LifevitSDKStepData* d in data.stepsData) {
            totalSteps = totalSteps + [d.steps intValue];
            totalDistance = totalDistance + [d.distance longValue];
            totalCalories = totalCalories + [d.calories longValue];
         }
        text = [text stringByAppendingString:[NSString stringWithFormat:@"\n\nTOTAL Steps: %d Distance: %ld Calories: %ld", totalSteps, totalDistance, totalCalories]];
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"First Results Sleep:"];
        
        i = 0;
        while(i<10 && i<data.sleepData.count){
            LifevitSDKSleepData* v = [data.sleepData objectAtIndex:i];
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@ sleep: %d", v.date, [v.sleepDuration intValue]]];
            i++;
        }
        
        long totalDeepSleep = 0;
        long totalLightSleep = 0;
        
        for (LifevitSDKSleepData* d in data.sleepData) {
            if ([d.sleepDeepness intValue] == DEEP_SLEEP){
                totalDeepSleep = totalDeepSleep + [d.sleepDuration longValue];
            } else {
                totalLightSleep = totalLightSleep + [d.sleepDuration longValue];
            }
         }
        text = [text stringByAppendingString:[NSString stringWithFormat:@"\n\nTOTAL Sleep Deep: %ld Light: %ld", totalDeepSleep, totalLightSleep]];
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"First Results HR:"];
        
        i = 0;
        while(i<10 && i<data.heartData.count){
            LifevitSDKHeartBeatData* v = [data.heartData objectAtIndex:i];
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@ HR: %d", v.date, [v.heartRate intValue]]];
            i++;
        }
        self.txtReceivedData.text = text;
        
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}



- (void) onSummaryStepInformation:(LifevitSDKStepSummaryData*) data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"Summary Step Data"];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@", data.date]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Steps: %d", [data.totalSteps intValue]]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Calories: %d", [data.totalCalories intValue]]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Distance: %.2f", [data.totalDistance doubleValue]]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Active time: %.2f", [data.totalActiveTime doubleValue]]];
        text = [text stringByAppendingString:@"\n"];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void) onSummarySleepInformation:(LifevitSDKSleepSummaryData*) data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"Summary Sleep Data"];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@", data.date]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Awakes: %d", [data.awakes intValue]]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Total Light Minutes: %d", [data.totalLightMinutes intValue]]];
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Total Deep Minutes: %.2f", [data.totalDeepMinutes doubleValue]]];
        text = [text stringByAppendingString:@"\n"];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}


- (void)braceletCurrentStepsReceived:(LifevitSDKStepData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"Current Day Received"];
        text = [text stringByAppendingString:@"\n"];
        text = [data print];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void) braceletAT250HRReceived: (int) value{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Heart Data Received: %d", value]];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

-(void)braceletAT250HRSyncReceived:(NSArray *)value{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Heart Data Received packets: %d", value.count]];
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:@"First Results:"];
        
        int i = 0;
        while(i<10 && i<value.count){
            LifevitSDKHeartBeatData* data = [value objectAtIndex:i];
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:[NSString stringWithFormat:@"Date: %@ HR: %d", data.date, [data.heartRate intValue]]];
            i++;
        }
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)operationFinished:(BOOL)success{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSString* text = self.txtReceivedData.text;
        text = [text stringByAppendingString:@"\n"];
        if (!success) {
            text = [text stringByAppendingString:@"Error on the operation requested"];
        } else {
            text = [text stringByAppendingString:@"Operation succesful"];
        }
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletActivityStepsReceived:(int)steps{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:[NSString stringWithFormat:@"Activity Steps: %d", steps]];
        
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
}

- (void)braceletInfoReceived:(NSString *)info{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.txtReceivedData.text;
        
        text = [text stringByAppendingString:@"\n"];
        text = [text stringByAppendingString:info];
        self.txtReceivedData.text = text;
        [self scrollTextViewToBottom:self.txtReceivedData];
    });
    
}


-(void) initLifevitOxy{
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER withTimeout:60000];
}
-(void) initLifevitTensi{
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_HEART withTimeout:60000];
}
-(void) initBraceletChecks{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        [[LifevitSDKManager sharedInstance] connectDevice:[self getSelectedBracelet] withTimeout:15];
    });
}

-(int) getSelectedBracelet{
    
    int braceletDevice = 0;
    
    switch (_braceletSelector.selectedSegmentIndex) {
        case 0:
            braceletDevice = DEVICE_BRACELET_AT250;
            break;
            
        case 1:
            braceletDevice = DEVICE_BRACELET_AT500HR;
            break;
            
        case 2:
            braceletDevice = DEVICE_BRACELET_VITAL;
            break;
        default:
            break;
    }
    
    return braceletDevice;
    
}

@end
