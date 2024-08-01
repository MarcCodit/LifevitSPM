//
//  ConnectAllViewController.m
//  LifevitSDKSample
//
//  Created by Oscar on 29/10/18.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import "ConnectAllViewController.h"
#import "DeviceConnectionCell.h"

@interface ConnectAllViewController (){
}

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end

@implementation ConnectAllViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    _tableView.dataSource=self;
    _tableView.delegate=self;

    [LifevitSDKManager sharedInstance].deviceDelegate = self;
    
    //Asociamos el XIB que incrustaremos
    [self.tableView registerClass:DeviceConnectionCell.class forCellReuseIdentifier:@"DeviceConnectionCell"];
    [self.tableView registerNib:[UINib nibWithNibName:@"DeviceConnectionCell" bundle:nil] forCellReuseIdentifier:@"DeviceConnectionCell"];

    //Quitamos separador
    [self.tableView setSeparatorStyle:UITableViewCellSeparatorStyleNone];
    
    
    [self.tableView reloadData];
}


- (IBAction)onConnectAll:(id)sender {
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_HEART withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_OXIMETER withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_GLUCOMETER withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_THERMOMETER withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_WEIGHT_SCALE withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_TENSIO_BRACELET withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_BRACELET_AT250 withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_BRACELET_VITAL withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_BRACELET_AT500HR withTimeout:30];
    [[LifevitSDKManager sharedInstance] connectDevice:DEVICE_BABYTHERMOMETER withTimeout:30];

}

- (IBAction)onStopAll:(id)sender {
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_HEART];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_OXIMETER];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_GLUCOMETER];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_THERMOMETER];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_WEIGHT_SCALE];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_TENSIO_BRACELET];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_BRACELET_AT250];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_BRACELET_VITAL];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_BRACELET_AT500HR];
    [[LifevitSDKManager sharedInstance] disconnectDevice:DEVICE_BABYTHERMOMETER];
    
    
    [self.tableView reloadData];
}



- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 8;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return CONNECTION_CELL_HEIGHT;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    NSString *cellIdentifier = @"DeviceConnectionCell";
    DeviceConnectionCell* cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];

    switch (indexPath.row) {
        case DEVICE_HEART:
            cell.lblDeviceType.text = @"Tensiómetro";
            break;
        case DEVICE_OXIMETER:
            cell.lblDeviceType.text = @"Oxímetro";
            break;
        case DEVICE_THERMOMETER:
            cell.lblDeviceType.text = @"Termómetro";
            break;
        case DEVICE_WEIGHT_SCALE:
            cell.lblDeviceType.text = @"Báscula Inteligente";
            break;
        case DEVICE_TENSIO_BRACELET:
            cell.lblDeviceType.text = @"Pulsera Tensiómetro";
            break;
        case DEVICE_BRACELET_AT250:
            cell.lblDeviceType.text = @"Pulsera AT250";
            break;
        case DEVICE_BRACELET_AT500HR:
            cell.lblDeviceType.text = @"Pulsera AT500HR";
            break;
        case DEVICE_BABYTHERMOMETER:
            cell.lblDeviceType.text = @"Termómetro Bebé";
            break;
        case DEVICE_BRACELET_VITAL:
            cell.lblDeviceType.text = @"Pulsera VITAL";
            break;
        case DEVICE_GLUCOMETER:
            cell.lblDeviceType.text = @"Glucómetro";
            break;
        default:
            break;
    }

    int status = [[LifevitSDKManager sharedInstance] getDeviceStatus:(int)indexPath.row];
    
    switch(status){
        case STATUS_CONNECTED:
            cell.lblDeviceStatus.text = @"Connected";
            [cell.lblDeviceStatus setTextColor:[UIColor greenColor]];
            break;
        case STATUS_DISCONNECTED:
            cell.lblDeviceStatus.text = @"Disconnected";
            [cell.lblDeviceStatus setTextColor:[UIColor redColor]];
            break;
        case STATUS_SCANNING:
            cell.lblDeviceStatus.text = @"Scanning";
            [cell.lblDeviceStatus setTextColor:[UIColor blueColor]];
            break;
        case STATUS_CONNECTING:
            cell.lblDeviceStatus.text = @"Connecting";
            [cell.lblDeviceStatus setTextColor:[UIColor blackColor]];
    }
    
    
    return cell;
}


#pragma mark - Device delegate

-(void)device:(int)device onConnectionChanged:(int)status{
    
    //[deviceTable setObject:@(status) forKey:@(device)];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.tableView reloadData];
    });
}


@end
