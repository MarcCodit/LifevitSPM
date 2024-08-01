//
//  ECGViewController.m
//  LifevitSDKSample
//
//  Created by Oscar on 7/10/21.
//  Copyright © 2021 Lifevit. All rights reserved.
//

#import "ECGViewController.h"

@interface ECGViewController ()

@end

@implementation ECGViewController{
    
    NSMutableArray* ecgDataArray;
    NSMutableArray* ecgConstantsArray;
    
    
    NSMutableArray* ecgDataProcessedArray;
    
    NSMutableArray* lastVals;
    
    int minValue;
    int maxValue;
    int maxChartValuesOnScreen;
    //int maxChartValuesOnScreenRealtime;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    ecgDataArray = [NSMutableArray new];
    ecgConstantsArray = [NSMutableArray new];
    
    ecgDataProcessedArray = [NSMutableArray new];
    
    lastVals = [NSMutableArray new];
    
    minValue = -32768;
    maxValue = 32767;
    maxChartValuesOnScreen = 2000;
    [self prepareChart: maxValue minValue:minValue];
}


- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receivedECGPacket:)
                                                 name:NOTIFICATION_ECG_DATA
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receivedECGSavedPacket:)
                                                 name:NOTIFICATION_ECG_SAVED_DATA
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receivedECGConstantsPacket:)
                                                 name:NOTIFICATION_ECG_CONSTANTS
                                               object:nil];
}

-(void) viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}


-(void)receivedECGPacket:(NSNotification *)notification{
    NSDictionary *object = [notification object];
    LifevitSDKVitalECGData* ecgData;
    
    if (object != nil){
        if ([object objectForKey:@"ecgData"] != nil){
            ecgData = [object objectForKey:@"ecgData"];
            [ecgDataArray addObject:ecgData];
            [self updateChartView];
        }
    }
}

-(void)receivedECGSavedPacket:(NSNotification *)notification{
    NSDictionary *object = [notification object];
    LifevitSDKVitalECGData* ecgData;
    
    if (object != nil){
        if ([object objectForKey:@"ecgData"] != nil){
            ecgData = [object objectForKey:@"ecgData"];
            [ecgDataArray addObject:ecgData];
            [self updateChartView];
        }
    }
}


-(void)receivedECGConstantsPacket:(NSNotification *)notification{
    NSDictionary *object = [notification object];
    
    if (object != nil){
        
        LifevitSDKVitalECGConstantsData* ecgConstants = object[@"ecgConstantsData"];
                
        if (ecgConstants != nil){
            [ecgConstantsArray addObject:ecgConstants];
            [self updateConstantsView:ecgConstants];
        }
    }
}


-(void) updateConstantsView: (LifevitSDKVitalECGConstantsData*) ecgConstants{
    if ([ecgConstants.heartRate intValue]>0){
        _lblBPM.text = [NSString stringWithFormat:@"%d", [ecgConstants.heartRate intValue]];
        [_lblBPM setHidden:NO];
        [_lblBPMTitle setHidden:NO];
    } else {
        [_lblBPM setHidden:YES];
        [_lblBPMTitle setHidden:YES];
    }
    
    if ([ecgConstants.hrv intValue]>0){
        _lblHRV.text = [NSString stringWithFormat:@"%d", [ecgConstants.hrv intValue]];
        [_lblHRV setHidden:NO];
        [_lblHRVTitle setHidden:NO];
    } else {
        [_lblHRV setHidden:YES];
        [_lblHRVTitle setHidden:YES];
    }
        
    /*if (([ecgConstants.highBloodPressure intValue]>0) && ([ecgConstants.lowBloodPressure intValue]>0)) {
        _lblMMHG.text = [NSString stringWithFormat:@"%d - %d", [ecgConstants.highBloodPressure intValue],  [ecgConstants.lowBloodPressure intValue]];
        [_lblMMHG setHidden:NO];
        [_lblMMHGTitle setHidden:NO];
    } else {*/
        [_lblMMHG setHidden:YES];
        [_lblMMHGTitle setHidden:YES];
  //  }
}


-(void) prepareChart: (int) maxValue minValue: (int) minValue{
    
    
    _vChart.chartDescription.enabled = NO;
    
    _vChart.dragEnabled = YES;
    [_vChart setScaleEnabled:YES];
    _vChart.drawGridBackgroundEnabled = NO;
    _vChart.pinchZoomEnabled = YES;
    
    _vChart.backgroundColor = UIColor.clearColor;
    
    ChartLegend *l = _vChart.legend;
    l.enabled = NO;
    
    //[self getMaxMinValues];
    
    ChartXAxis *xAxis = _vChart.xAxis;
    xAxis.labelFont = [UIFont systemFontOfSize:9.f];
    xAxis.labelTextColor = UIColor.blackColor;
    xAxis.axisLineColor = UIColor.blackColor;
    xAxis.drawGridLinesEnabled = NO;
    xAxis.drawAxisLineEnabled = YES;
    xAxis.axisMinimum = 0.0;
    xAxis.granularity = 1.0;
    //xAxis.valueFormatter = self;
    xAxis.labelPosition = XAxisLabelPositionBottom;
    xAxis.drawLabelsEnabled = NO;
    
    ChartYAxis *leftAxis = _vChart.leftAxis;
    leftAxis.labelTextColor = UIColor.blackColor;
    leftAxis.axisLineColor = UIColor.blackColor;
    leftAxis.axisMaximum = maxValue;
    leftAxis.axisMinimum = minValue;
    leftAxis.drawGridLinesEnabled = NO;
    leftAxis.drawZeroLineEnabled = NO;
    leftAxis.drawAxisLineEnabled = YES;
    leftAxis.granularity = 0.1;
    leftAxis.labelCount = 6;
    
    ChartYAxis *rightAxis = _vChart.rightAxis;
    rightAxis.enabled = NO;
    
    [_vChart animateWithXAxisDuration:1];
    
}


-(void) updateChartView{
    
    [ecgDataProcessedArray removeAllObjects];
    
    for (int i = 0; i < [ecgDataArray count]; i++)
    {
        LifevitSDKVitalECGData* ecgData = ecgDataArray[i];
        
        NSMutableArray* data = (NSMutableArray*) ecgData.ecgData;
        
        [ecgDataProcessedArray addObjectsFromArray:data];
    }

    
    //NSLog(@"ecgCounter: %d", ecgCounter);
    
    [lastVals removeAllObjects];
    int lastLogsCount = maxChartValuesOnScreen;
    if (ecgDataProcessedArray.count > lastLogsCount) { // check count first to avoid exception
        [lastVals addObjectsFromArray:[[ecgDataProcessedArray subarrayWithRange:NSMakeRange(ecgDataProcessedArray.count - lastLogsCount, lastLogsCount)] mutableCopy]];
    } else {
        [lastVals addObjectsFromArray:ecgDataProcessedArray];
    }
    
    NSLog(@"LASTVALS: %d", [lastVals count]);
    
    
    NSMutableArray *yVals = [[NSMutableArray alloc] init];
    int counter = 0;
    for (int i=0; i<=[lastVals count]-1; i++){
        NSNumber* value = lastVals[i];
        [yVals addObject:[[ChartDataEntry alloc] initWithX:counter y:[value floatValue]]];
        counter ++;
    }
    
    
    LineChartDataSet *set1 = nil;
    
    
    for (int i=0; i<=_vChart.data.dataSetCount -1; i++) {
        [_vChart.data removeDataSetByIndex:i];
    }
    
    [_vChart.data clearValues];
    
    NSMutableArray *dataSets = [[NSMutableArray alloc] init];
    
    if ([yVals count]>0) {
        set1 = [[LineChartDataSet alloc] initWithEntries:yVals label:nil];
        [set1 setMode:LineChartModeHorizontalBezier];
        set1.axisDependency = AxisDependencyLeft;
        [set1 setColor:[UIColor blueColor]];
        [set1 setCircleColor:[UIColor clearColor]];
        
        set1.lineWidth = 2.0;
        set1.circleRadius = 2.0;
        set1.fillAlpha = 65/255.0;
        set1.fillColor = [UIColor colorWithRed:51/255.f green:181/255.f blue:229/255.f alpha:1.f];
        set1.highlightColor = [UIColor colorWithRed:244/255.f green:117/255.f blue:117/255.f alpha:1.f];
        set1.drawCircleHoleEnabled = NO;
        [set1 setDrawValuesEnabled:NO];
        [dataSets addObject:set1];
    }
        
    LineChartData *data = [[LineChartData alloc] initWithDataSets:dataSets];
    [data setValueTextColor: [UIColor blueColor]];
    [data setValueFont:[UIFont systemFontOfSize:9.f]];
    
    _vChart.data = data;

}

/*
-(void) updateChartView{
    NSMutableArray *yVals = [[NSMutableArray alloc] init];
    
    //int ecgCounter = 0;
    int counter = 0;
    
    for (int i = 0; i < [ecgDataArray count]; i++)
    {
        LifevitSDKVitalECGData* ecgData = ecgDataArray[i];
        
        NSMutableData* data = (NSMutableData*) ecgData.ecgData;
        signed char *bytes = (signed char *)[data bytes];
        
        int ecgLength = bytes[[data length]-1];
        //NSLog(@"ECG LENGTH: %d", ecgLength);
        
        
        char tempChar = 0x00;
        for (int i = 0; i < [data length] - 1; i++)
        {
            signed char b = (signed char) bytes[i];
            
            if (i % 2 > 0){
                signed char* valueByte = malloc(2);
                valueByte[0] = b;
                valueByte[1] = tempChar;
                
                NSNumber* value = @((SInt16)[ByteUtils byteArrayToInt:valueByte]);
                
                //NSLog(@"ECG Value: %d", [value intValue]);
                
                [ecgDataProcessedArray addObject:value];
                
                //[yVals addObject:[[ChartDataEntry alloc] initWithX:counter y:[value floatValue]]];
                
                tempChar = 0x00;
                counter ++;
            } else {
                tempChar = b;
            }
        }
        
        //ecgCounter ++;
    }
    
    //NSLog(@"ecgCounter: %d", ecgCounter);
    
    NSMutableArray* lastVals = [NSMutableArray new];
    int lastLogsCount = [_maxChartValuesOnScreen intValue];
    if (ecgDataProcessedArray.count > lastLogsCount) { // check count first to avoid exception
        lastVals = [[ecgDataProcessedArray subarrayWithRange:NSMakeRange(ecgDataProcessedArray.count - lastLogsCount, lastLogsCount)] mutableCopy];
    } else {
        lastVals = ecgDataProcessedArray;
    }
    
   // NSLog(@"%d", [lastVals count]);
    
    
    counter = 0;
    for (int i=0; i<=[lastVals count]-1; i++){
        NSNumber* value = lastVals[i];
        [yVals addObject:[[ChartDataEntry alloc] initWithX:counter y:[value floatValue]]];
        counter ++;
    }
    
    
    LineChartDataSet *set1 = nil;
    
    
    for (int i=0; i<=_vChart.data.dataSetCount -1; i++) {
        [_vChart.data removeDataSetByIndex:i];
    }
    
    [_vChart.data clearValues];
        
        NSMutableArray *dataSets = [[NSMutableArray alloc] init];
        
        if ([yVals count]>0) {
            set1 = [[LineChartDataSet alloc] initWithEntries:yVals label:nil];
            [set1 setMode:LineChartModeHorizontalBezier];
            set1.axisDependency = AxisDependencyLeft;
            [set1 setColor:[UIColor blueColor]];
            [set1 setCircleColor:[UIColor clearColor]];
            
            set1.lineWidth = 2.0;
            set1.circleRadius = 2.0;
            set1.fillAlpha = 65/255.0;
            set1.fillColor = [UIColor colorWithRed:51/255.f green:181/255.f blue:229/255.f alpha:1.f];
            set1.highlightColor = [UIColor colorWithRed:244/255.f green:117/255.f blue:117/255.f alpha:1.f];
            set1.drawCircleHoleEnabled = NO;
            [set1 setDrawValuesEnabled:NO];
            [dataSets addObject:set1];
        }
    
        
    
        
        LineChartData *data = [[LineChartData alloc] initWithDataSets:dataSets];
        [data setValueTextColor: [UIColor blueColor]];
        [data setValueFont:[UIFont systemFontOfSize:9.f]];
        
        _vChart.data = data;
        
}
*/


@end
