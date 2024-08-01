//
//  ScanViewController.m
//  LifevitSDKSample
//
//  Created by iscariot on 05/10/2018.
//  Copyright © 2018 Lifevit. All rights reserved.
//

#import "ScanViewController.h"
#import "DeviceScanCell.h"
#import "DeviceScanSectionView.h"

@interface ScanViewController () {
    NSMutableDictionary* scannedDevices;
}

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end

@implementation ScanViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    _tableView.dataSource=self;
    _tableView.delegate=self;
    
    //Asociamos el XIB que incrustaremos
    [self.tableView registerClass:DeviceScanCell.class forCellReuseIdentifier:@"DeviceScanCell"];
    [self.tableView registerNib:[UINib nibWithNibName:@"DeviceScanCell" bundle:nil] forCellReuseIdentifier:@"DeviceScanCell"];
    //Quitamos separador
    [self.tableView setSeparatorStyle:UITableViewCellSeparatorStyleNone];
    
    
    //[LifevitSDKManager sharedInstance].deviceDelegate = self;
    [LifevitSDKManager sharedInstance].devicesScanDelegate = self;
    
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [[LifevitSDKManager sharedInstance] stopScanForDevices];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return scannedDevices.allKeys.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{

    NSNumber* sec = scannedDevices.allKeys[section];
    
    NSMutableArray* deviceList = [scannedDevices objectForKey: sec];
    
    if ([deviceList count]>0) {
        return [deviceList count];
    }
    return 0;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return SECTION_HEIGHT;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    DeviceScanSectionView * h = [[DeviceScanSectionView alloc] initWithFrame:CGRectMake(0, 0, self.tableView.frame.size.width, SECTION_HEIGHT)];

    NSNumber* sec = scannedDevices.allKeys[section];
    
    switch ([sec intValue]) {
        case DEVICE_HEART:
            h.lblSection.text = @"Tensiómetro";
            break;
        case DEVICE_OXIMETER:
            h.lblSection.text = @"Oxímetro";
            break;
        case DEVICE_GLUCOMETER:
            h.lblSection.text = @"Glucómetro";
            break;
        case DEVICE_THERMOMETER:
            h.lblSection.text = @"Termómetro";
            break;
        case DEVICE_WEIGHT_SCALE:
            h.lblSection.text = @"Báscula Inteligente";
            break;
        case DEVICE_TENSIO_BRACELET:
            h.lblSection.text = @"Pulsera Tensiómetro";
            break;
        case DEVICE_BRACELET_AT250:
            h.lblSection.text = @"Pulsera AT250";
            break;
        case DEVICE_BRACELET_AT500HR:
            h.lblSection.text = @"Pulsera AT500HR";
            break;
        case DEVICE_BABYTHERMOMETER:
            h.lblSection.text = @"Termómetro Bebé";
            break;
        case DEVICE_BRACELET_AT250_DFU:
            h.lblSection.text = @"Pulsera AT250 DFU";
            break;
        case DEVICE_BRACELET_VITAL:
            h.lblSection.text = @"Pulsera VITAL";
            break;
        default:
            break;
    }

    return h;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return CELL_HEIGHT;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    DeviceScanCell *cell;
    
    NSNumber* sec = scannedDevices.allKeys[indexPath.section];
    
    NSMutableArray* deviceList = [scannedDevices objectForKey: sec];
    
    LifevitSDKDevice* device = [deviceList objectAtIndex:indexPath.row];
    NSString *cellIdentifier = @"DeviceScanCell";
    cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    cell.lblUUID.text = device.deviceIdentifier;
    cell.lblDistance.text = [NSString stringWithFormat:@"%.03fm - (RSSI:%@)",[[device getDistanceToDevice] doubleValue], [device.RSSI stringValue]];
    
    if ([device.RSSI doubleValue] > 0) {
        cell.backgroundColor = UIColor.cyanColor;
        UIFont *currentFont = cell.lblDistance.font;
        UIFont *newFont = [UIFont fontWithName:[NSString stringWithFormat:@"%@-Bold",currentFont.fontName] size:currentFont.pointSize];
        cell.lblDistance.font = newFont;
    } else {
        cell.backgroundColor = UIColor.whiteColor;
    }
    
    return cell;
}



- (IBAction)onScanPressed:(id)sender {
    [[LifevitSDKManager sharedInstance] scanAllDevices];
}

- (IBAction)onStopPressed:(id)sender {
    [[LifevitSDKManager sharedInstance] stopScanForDevices];
}



- (void)allDevicesDetected:(NSMutableDictionary *) devicesList{
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self->scannedDevices = devicesList;
        [self.tableView reloadData];
    });
}


@end
