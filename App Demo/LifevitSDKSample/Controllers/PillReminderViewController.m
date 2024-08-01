//
//  PillReminderViewController.m
//  LifevitSDKSample
//
//  Created by Oscar on 06/05/2019.
//  Copyright © 2019 Lifevit. All rights reserved.
//

#import "PillReminderViewController.h"

@interface PillReminderViewController ()

@end

@implementation PillReminderViewController{
    int deviceStatus;
    int alarmsRequestCounter;
    int historyRecordsRequestCounter;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    alarmsRequestCounter = 0;
    historyRecordsRequestCounter = 0;
    
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].pillReminderDelegate = self;
    
    if([[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_PILL_REMINDER]){
        deviceStatus = STATUS_CONNECTED;
        [self device:DEVICE_PILL_REMINDER onConnectionChanged:deviceStatus];
    } else {
        deviceStatus = STATUS_DISCONNECTED;
        [self device:DEVICE_PILL_REMINDER onConnectionChanged:deviceStatus];
    }
    
}

- (void) reconnectDevice{
    
    switch(deviceStatus){
        case STATUS_DISCONNECTED:
            [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_PILL_REMINDER withTimeout:60];
            
            
            // [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER withTimeout:30];
            // [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_HEART withTimeout:30];
            break;
        case STATUS_CONNECTED:
        case STATUS_SCANNING:
        case STATUS_CONNECTING:
            [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_PILL_REMINDER];
            break;
    }
}


- (IBAction)onSendPressed:(id)sender {
    UIAlertController * alert=[UIAlertController alertControllerWithTitle:@"Pill Reminder TEST"
                                                                  message:@"Choose the command you want to send"
                                                           preferredStyle:UIAlertControllerStyleAlert];
    
    [self prepareCommandList:alert];
    
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)prepareCommandList:(UIAlertController *)alert {
    
   /* UIAlertAction* action = [UIAlertAction actionWithTitle:@"Set datetime to now"
                                                     style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action)
                             {
                                 [[LifevitSDKManager sharedInstance] prSetDeviceTime];
                             }];
    [alert addAction:action];*/
    
    UIAlertAction* action = [UIAlertAction actionWithTitle:@"Read device datetime"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetDeviceTime];
              }];
    
    [alert addAction:action];
    
   /* action = [UIAlertAction actionWithTitle:@"Set timezone to +0:00UTC"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prSetDeviceTimeZone:0 minute:00];
              }];
    [alert addAction:action];*/
    

    
    action = [UIAlertAction actionWithTitle:@"Get timezone"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetDeviceTimeZone];
              }];
    
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get battery level"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetBatteryLevel];
              }];
    
    [alert addAction:action];

    action = [UIAlertAction actionWithTitle:@"Get Latest Synchronization Time"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetLatestSynchronizationTime];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Successful Synchronization Status"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prSetSuccessfulSynchronizationStatus];
              }];
    
    [alert addAction:action];
    
    
    
    
    action = [UIAlertAction actionWithTitle:@"Clear Schedule Performance History"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prClearSchedulePerformanceHistory];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Get Alarm Schedule"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetAlarmSchedule];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Alarms Schedule 2 minutes from now"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  NSMutableArray* alarms = [NSMutableArray new];
                  
                  /*LifevitSDKPillReminderAlarmData* alarm1 = [LifevitSDKPillReminderAlarmData new];

                  NSString *dateString = @"2015-09-18 10:25:00";
                  NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
                  [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
                  NSDate *dateFromString = [dateFormatter dateFromString:dateString];
                  
                  
                  alarm1.date = dateFromString;
                  alarm1.color = @PILLREMINDER_COLOR_PURPLE;

                  [alarms addObject:alarm1];*/
                  
                  NSDate *now = [NSDate date];
                  
                  NSDate *newAlarm = [now dateByAddingTimeInterval:60*1];
                  
                  LifevitSDKPillReminderAlarmData* alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @PILLREMINDER_COLOR_RED;
                  
                  [alarms addObject:alarm2];
                  
                  newAlarm = [now dateByAddingTimeInterval:60*2];
                  
                  alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @PILLREMINDER_COLOR_BLUE;
                  
                  [alarms addObject:alarm2];
                  
                  newAlarm = [now dateByAddingTimeInterval:60*4];
                  
                  alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @(PILLREMINDER_COLOR_GREEN);
                  
                  [alarms addObject:alarm2];
                  
                  newAlarm = [now dateByAddingTimeInterval:60*10];
                  
                  alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @(PILLREMINDER_COLOR_PURPLE);
                  
                  [alarms addObject:alarm2];
                  
                  newAlarm = [now dateByAddingTimeInterval:60*2];
                  
                  alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @(PILLREMINDER_COLOR_YELLOW);
                  
                  [alarms addObject:alarm2];
                  
                  newAlarm = [now dateByAddingTimeInterval:60*7];
                  
                  alarm2 = [LifevitSDKPillReminderAlarmData new];
                  alarm2.date = newAlarm;
                  alarm2.color = @(PILLREMINDER_COLOR_RED);
                  
                  [alarms addObject:alarm2];
                  
                  [[LifevitSDKManager sharedInstance] prSetAlarmSchedule: alarms];
              }];
    
    [alert addAction:action];
    
    
    action = [UIAlertAction actionWithTitle:@"Get Schedule Performance History"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prGetSchedulePerformanceHistory];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Alarm Duration to 1 minute"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prSetAlarmDuration:1];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Set Alarm Confirmation Time to 5 minutes"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prSetAlarmConfirmationTime: 5];
              }];
    
    [alert addAction:action];
    
    action = [UIAlertAction actionWithTitle:@"Clear Alarm Schedule"
                                      style:UIAlertActionStyleDefault
                                    handler:^(UIAlertAction * action)
              {
                  [[LifevitSDKManager sharedInstance] prClearAlarmSchedule];
              }];
    
    [alert addAction:action];
    
    
    UIAlertAction* cancel = [UIAlertAction actionWithTitle:@"Cancel"
                                                     style:UIAlertActionStyleCancel
                                                   handler:^(UIAlertAction * action)
                             {
                                 
                             }];
    
    [alert addAction:cancel];

}


- (IBAction)onConnectPressed:(id)sender {
        [self reconnectDevice];
}

#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    
    deviceStatus = status;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        switch(status){
            case STATUS_CONNECTED:
                [self.btnSend setHidden:NO];
                self.lblStatus.text = @"Connected";
                [self.lblStatus setTextColor:[UIColor greenColor]];
                [self.btnConnect setTitle:@"Disconnect" forState:UIControlStateNormal];
                break;
            case STATUS_DISCONNECTED:
                [self.btnSend setHidden:YES];
                self.lblStatus.text = @"Disconnected";
                [self.lblStatus setTextColor:[UIColor redColor]];
                [self.btnConnect setTitle:@"Connect" forState:UIControlStateNormal];
                break;
            case STATUS_SCANNING:
                [self.btnSend setHidden:YES];
                self.lblStatus.text = @"Scanning near devices...";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnConnect setTitle:@"Cancel connection" forState:UIControlStateNormal];
                break;
            case STATUS_CONNECTING:
                [self.btnSend setHidden:YES];
                self.lblStatus.text = @"Connecting";
                [self.lblStatus setTextColor:[UIColor blackColor]];
                [self.btnConnect setTitle:@"Disconnect" forState:UIControlStateNormal];
        }
    });
    
}

- (void)device:(int)device onConnectionError:(int)error{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.lblStatus setTextColor:[UIColor redColor]];
        _lblStatus.text = [@"On result error: " stringByAppendingString:[@(error) stringValue]];
        
    });}

- (void)device:(int)device onSendInformation:(id)data{
    if([data isKindOfClass:[NSString class]]){
        dispatch_async(dispatch_get_main_queue(), ^{
            
            NSString* text = self.tvReceivedData.text;
            
            text = [text stringByAppendingString:@"\n"];
            text = [text stringByAppendingString:data];
            self.tvReceivedData.text = text;
            
        });
    }
}


- (void)pillReminderOnResult: (id) info {
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.tvReceivedData.text;
        text = [text stringByAppendingString:@"\n"];
        
        NSString* response = @"";
        
        if ([info isKindOfClass:[LifevitSDKPillReminderMessageData class]]){
            LifevitSDKPillReminderMessageData* message = (LifevitSDKPillReminderMessageData*) info;
            
            switch ([message.request intValue]) {
                    
                case PILLREMINDER_REQUEST_GET_BATTERYLEVEL:
                    response = [NSString stringWithFormat:@"Battery level: %@", message.messageText];
                    break;
                    
                default:
                    response = message.messageText;
                    break;
            }
            
        } else if ([info isKindOfClass:[LifevitSDKPillReminderAlarmListData class]]){
            LifevitSDKPillReminderAlarmListData* data = (LifevitSDKPillReminderAlarmListData*) info;
            
            switch ([data.request intValue]) {
                    
                case PILLREMINDER_REQUEST_GET_ALARMSCHEDULE:{
                    
                    if (self->alarmsRequestCounter == 0) {
                        response = [NSString stringWithFormat:@"Alarm schedule request successful:\n"];
                    }
                    
                    NSDateFormatter* df = [NSDateFormatter new];
                    [df setDateFormat:@"HH:mm:ss dd/MM/yyyy"];
                    
                    if (data.alarmList != nil) {
                        for (LifevitSDKPillReminderAlarmData* alarm in data.alarmList) {
                            
                            response = [NSString stringWithFormat:@"%@%@\n", response, [df stringFromDate:alarm.date]];
                        }
                    } else {
                        self->alarmsRequestCounter = 0;
                    }
                }
                    break;
                    
                    
                case PILLREMINDER_REQUEST_GET_SCHEDULEPERFORMANCEHISTORY:{
                    
                    if (self->historyRecordsRequestCounter == 0) {
                        response = [NSString stringWithFormat:@"Schedule performance history request successful:\n"];
                        text = [text stringByAppendingString:response];
                    }
                    
                    NSDateFormatter* df = [NSDateFormatter new];
                    [df setDateFormat:@"HH:mm:ss dd/MM/yyyy"];
                    
                    if (data.alarmList != nil) {
                        NSMutableArray* records = data.alarmList;
                        
                        for (LifevitSDKPillReminderPerformanceData* record in records) {
                            response = [NSString stringWithFormat:@"%@ - status: %d (%@)\n", [df stringFromDate:record.date], [record.statusTaken intValue], [df stringFromDate:record.dateTaken]];
                            text = [text stringByAppendingString:response];
                        }
                    } else {
                        self->historyRecordsRequestCounter = 0;
                    }
                    
                }
                    
                    break;
                    
                default:
                    break;
            }
            
        }else if ([info isKindOfClass:[LifevitSDKPillReminderPerformanceData class]]){
            
            LifevitSDKPillReminderPerformanceData* record = (LifevitSDKPillReminderPerformanceData*) info;
            
            response = [NSString stringWithFormat:@"Real-time performance received:\n"];
            text = [text stringByAppendingString:response];
            
            NSDateFormatter* df = [NSDateFormatter new];
            [df setDateFormat:@"HH:mm:ss dd/MM/yyyy"];
            
            response = [NSString stringWithFormat:@"%@ - status: %d (%@)\n", [df stringFromDate:record.date], [record.statusTaken intValue], [df stringFromDate:record.dateTaken]];
            
        }else if ([info isKindOfClass:[LifevitSDKPillReminderData class]]){
            
            LifevitSDKPillReminderData* data = (LifevitSDKPillReminderData*) info;
            
            switch ([data.request intValue]) {
                    
                case PILLREMINDER_REQUEST_GET_DEVICETIME:{
                    response = [NSString stringWithFormat:@"Device date: %@", data.date];
                }
                    break;
                    
                case PILLREMINDER_REQUEST_GET_LATESTSYNCHRONIZATIONTIME: {
                    if (data.date) {
                        response = [NSString stringWithFormat:@"Latest synchronization time: %@", data.date];
                    } else {
                        response = [NSString stringWithFormat:@"Device not synchronized"];
                    }
                }
                    break;
                    
                default:
                    
                    break;
            }
        }
        

        if(response){
            text = [text stringByAppendingString:response];
            self.tvReceivedData.text = text;
        }
        
    });
    
}

- (void)pillReminderOnError:(LifevitSDKPillReminderMessageData *)info {
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString* text = self.tvReceivedData.text;
        text = [text stringByAppendingString:@"\n"];
        
        NSString* response = info.messageText;
        
        text = [text stringByAppendingString:response];
        self.tvReceivedData.text = text;
        
    });
}


@end
