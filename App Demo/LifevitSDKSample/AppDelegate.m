//
//  AppDelegate.m
//  LifevitSDKSample
//
//  Created by iNMovens Solutions on 11/5/18.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import "AppDelegate.h"

@import LifevitSDK;

@interface AppDelegate () <UISplitViewControllerDelegate>

@end

@implementation AppDelegate{
    NSTimer* timerConnection;
    BOOL executingTimer;
    UIBackgroundTaskIdentifier bgTask;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    
    NSArray* identifiers = [launchOptions objectForKey:UIApplicationLaunchOptionsBluetoothCentralsKey];
    
    //[[LifevitSDKManager sharedInstance] setCentralManagerIdentifiers:identifiers];
    [[LifevitSDKManager sharedInstance] initCentralManagerWithoutBackgroundMode];
    
    [application setMinimumBackgroundFetchInterval:10];
    
    [LifevitSDKManager sharedInstance].delegate = self;
    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].oximeterDelegate = self;
    [LifevitSDKManager sharedInstance].weightscaleDelegate = self;
    
    // New for iOS 8 - Register the notifications
    UIUserNotificationType types = UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert;
    UIUserNotificationSettings *mySettings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
    [[UIApplication sharedApplication] registerUserNotificationSettings:mySettings];
    
    return YES;
}

- (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler{
    
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    if (notification)
    {
        notification.alertBody = @"Alert!";
        notification.soundName = UILocalNotificationDefaultSoundName;
       
        notification.alertBody = @"BACK GROUND FETCH";
        [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
    }
    
    NSLog(@"BACK GROUND FETCH");
    NSString* uuidOximeter = @"8F126858-153D-CDAE-0AAE-2C376D536572";
    NSString* uuidWeightScale = @"CCB2F774-9637-14C8-501E-B1397321AF33";
    if(![[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_OXIMETER]){
        [[LifevitSDKManager sharedInstance] connectByUUID:uuidOximeter withType:DEVICE_OXIMETER];
    }
    
    if(![[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_WEIGHT_SCALE]){
        [[LifevitSDKManager sharedInstance] connectByUUID:uuidWeightScale withType:DEVICE_WEIGHT_SCALE];
    }
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        completionHandler(UIBackgroundFetchResultNewData);
    });
}

- (void) periodicConnect {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        if (!self->executingTimer) {
            self->executingTimer = true;
            NSLog(@"Timer execution to connect devices by UUID");
            NSString* uuidOximeter = @"8F126858-153D-CDAE-0AAE-2C376D536572";
            NSString* uuidWeightScale = @"CCB2F774-9637-14C8-501E-B1397321AF33";
            
            if(![[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_OXIMETER]){
            [[LifevitSDKManager sharedInstance] connectByUUID:uuidOximeter withType:DEVICE_OXIMETER];
            }
            
            if(![[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_WEIGHT_SCALE]){
            [[LifevitSDKManager sharedInstance] connectByUUID:uuidWeightScale withType:DEVICE_WEIGHT_SCALE];
            }
            self->executingTimer = false;
        }
    });
}

- (void) startTimer {
    executingTimer = false;
    NSLog(@"Starting timer");
    if (!timerConnection) {
        timerConnection = [NSTimer scheduledTimerWithTimeInterval:15
                                                              target:self
                                                            selector:@selector(periodicConnect)
                                                            userInfo:nil
                                                             repeats:YES];
    }
}

- (void) stopTimer
{
    NSLog(@"Stoping timer");
    if (timerConnection) {
        [timerConnection invalidate];
        timerConnection = nil;
    }
}





- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    
   
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    
    //[self restartTimerTask: application];
    
    
}

- (void) restartTimerTask:(UIApplication *)application {
    bgTask = [application beginBackgroundTaskWithName:@"MyTask" expirationHandler:^{
        // Clean up any unfinished task business by marking where you
        // stopped or ending the task outright.
        
        [application endBackgroundTask:self->bgTask];
        self->bgTask = UIBackgroundTaskInvalid;
        
        //[self restartTimerTask: application];
    }];
    
    // Start the long-running task and return immediately.
    //dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
    
    [self stopTimer];
    // Do the work associated with the task, preferably in chunks.
    [self startTimer];
    
    //[application endBackgroundTask:self->bgTask];
    //self->bgTask = UIBackgroundTaskInvalid;
    //});
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - Oximeter delegate

- (void)oximeterDeviceOnProgressMeasurement:(LifevitSDKOximeterData*) data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        
        NSLog(@"%@", [NSString stringWithFormat:@"AppDelegate TEST: %@ - %d", [dateFormatter stringFromDate:data.date], [data.pleth intValue]]);
        
    });
    
}

- (void)oximeterDeviceOnResult:(LifevitSDKOximeterData*) data{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        
        NSLog(@"%@", [NSString stringWithFormat:@"AppDelegate TEST: %@ - %d", [dateFormatter stringFromDate:data.date], [data.pleth intValue]]);
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        if (notification)
        {
            notification.alertBody = @"Alert!";
            notification.soundName = UILocalNotificationDefaultSoundName;
            
            notification.alertBody = [NSString stringWithFormat:@"AppDelegate TEST: %@ - %d", [dateFormatter stringFromDate:data.date], [data.pleth intValue]];
            [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
        }
        
    });
}

#pragma mark - Weight delegate

-(void)weightscaleOnMeasurementResult:(LifevitSDKWeightScaleData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSLog(@"%@",  data.weight? [NSString stringWithFormat:@"AppDelegate TEST: %.2f%@ (temp)", [data.weight doubleValue], data.unit]: @"-");
        
    });
}

-(void)weightscaleOnResult:(LifevitSDKWeightScaleData *)data{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSLog(@"%@",  data.weight? [NSString stringWithFormat:@"AppDelegate TEST: %.2f%@", [data.weight doubleValue], data.unit]: @"-");
        
    });
}


#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        switch(status){
            case STATUS_CONNECTED:
                NSLog(@"STATUS_CONNECTED");
                
                break;
            case STATUS_DISCONNECTED:
                NSLog(@"STATUS_DISCONNECTED");
                break;
            case STATUS_SCANNING:
                NSLog(@"STATUS_SCANNING");
                break;
            case STATUS_CONNECTING:
                NSLog(@"STATUS_CONNECTING");
        }
    });
}


- (void)device:(int)device onConnectionError:(int)error{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"%@", [@"On result error: " stringByAppendingString:[@(error) stringValue]]);
    });
}

#pragma mark - Manager delegate

- (void)bluetoothPoweredOn:(BOOL)on{
    if(on){
         if(![[LifevitSDKManager sharedInstance] isDeviceConnected:DEVICE_OXIMETER]){
                   [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER];
         }
    }
}

@end
