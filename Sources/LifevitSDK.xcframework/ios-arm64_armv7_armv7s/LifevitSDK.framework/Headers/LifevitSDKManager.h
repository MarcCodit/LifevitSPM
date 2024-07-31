//
//  LifevitSDKManager.h
//  TensiometerSDK
//
//  Created by David Casas on 3/8/17.
//  Copyright © 2017 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LifevitSDKHeartData.h"
#import "LifevitSDKConstants.h"
#import "LifevitSDKStepData.h"
#import "LifevitSDKDetailedStepData.h"
#import "LifevitSDKHeartBeatData.h"
#import "LifevitSDKOximeterData.h"
#import "LifevitSDKBraceletData.h"
#import "LifevitSDKBraceletSedentaryAlarm.h"
#import "LifevitSDKBraceletMonitoringAlarm.h"
#import "LifevitSDKBraceletAlarm.h"
#import "LifevitSDKWeightScaleData.h"
#import "LifevitSDKThermometerData.h"
#import "LifevitSDKThermometerSuccessData.h"
#import "LifevitSDKBabyThermometerData.h"
#import "LifevitSDKTensioBraceletData.h"
#import "LifevitSDKPillReminderMessageData.h"
#import "LifevitSDKPillReminderAlarmData.h"
#import "LifevitSDKPillReminderAlarmListData.h"
#import "LifevitSDKPillReminderPerformanceData.h"
#import "LifevitSDKTensioBraceletInterval.h"
#import "LifevitSDKTensioBraceletConfig.h"
#import "LifevitSDKAT250TimeRange.h"
#import "LifevitSDKAppNotification.h"
#import "LifevitSDKUser.h"
#import "LifevitSDKStepSummaryData.h"
#import "LifevitSDKSleepSummaryData.h"
#import "LifevitSDKVitalECGConstantsData.h"
#import "LifevitSDKVitalECGData.h"
#import "LifevitSDKDeviceParameters.h"
#import "LifevitSDKVitalActivityPeriod.h"
#import "LifevitSDKVitalPeriod.h"
#import "LifevitSDKVitalWeather.h"
#import "LifevitSDKResponse.h"
#import "LifevitSDKVitalParams.h"
#import "LifevitSDKVitalAlarm.h"
#import "LifevitSDKGlucometerData.h"
#import <CoreBluetooth/CoreBluetooth.h>

@protocol LifevitSDKManagerDelegate <NSObject>
@required

-(void) bluetoothPoweredOn:(BOOL) on;

#pragma mark - HeartDevice
@optional
- (void)heartDeviceOnConnectionChanged:(int) status;
- (void)heartDeviceOnConnectionError:(int) error;
- (void)heartDeviceOnProgressMeasurement:(int) pulse;
- (void)heartDeviceOnResult:(LifevitSDKHeartData*) data;
@end

@protocol LifevitDeviceDelegate <NSObject>
@required
- (void)device:(int) device onConnectionChanged:(int) status;
- (void)device:(int) device onConnectionError:(int) error;
- (void)device:(int) device onSendInformation:(id) data;
@optional
- (void)device:(int) device onBatteryLevelReceived:(int) battery;
@end


@protocol LifevitHeartDelegate <NSObject>
@required
- (void)heartDeviceOnProgressMeasurement:(int) pulse;
- (void)heartDeviceOnResult:(LifevitSDKHeartData*) data;
@end


@protocol LifevitWeightScaleDelegate <NSObject>
@required
- (void)weightscaleOnMeasurementResult:(LifevitSDKWeightScaleData*) data;
- (void)weightscaleOnResult:(LifevitSDKWeightScaleData*) data;
@optional
- (void)weightscaleOnTypeDetected:(NSNumber*) type;
@end

@protocol LifevitThermometerDelegate <NSObject>
@required
- (void)thermometerOnResult:(LifevitSDKThermometerData*) data;
- (void)thermometerOnSuccessCommand:(LifevitSDKThermometerSuccessData*) data;
- (void)thermometerOnError:(int) errorCode;
@end

@protocol LifevitBabyThermometerDelegate <NSObject>
@required
- (void)babyThermometerOnResult:(LifevitSDKBabyThermometerData*) data;
@end

@protocol LifevitBraceletDelegate <NSObject>
@required

- (void) braceletBeepReceived;
- (void) braceletActivityStarted;
- (void) braceletActivityFinished;
- (void) braceletBatteryReceived:(int) battery;
- (void) braceletParameterSet:(int) parameter;
- (void) braceletSyncReceived:(LifevitSDKBraceletData*) data;
- (void) braceletActivityStepsReceived:(int) steps;
- (void) braceletCurrentStepsReceived:(LifevitSDKStepData*) data;
- (void) braceletHeartDataReceived:(LifevitSDKHeartBeatData*) data;
- (void) braceletInfoReceived:(NSString*) info;
@end


@protocol LifevitBraceletVITALDelegate <NSObject>
- (void)  braceletVitalSOS:(NSString*) device;

- (void)  braceletVitalDevice:(NSString*) device operation:(BraceletVitalOperation) operation;
- (void)  braceletVitalDevice:(NSString*) device information:(LifevitSDKResponse*) info;
- (void)  braceletVitalDevice:(NSString*) device error:(BraceletVitalError) errorCode forCommand: (BraceletVitalCommand) command;
@required


@optional
- (void) braceletSyncReceived:(LifevitSDKBraceletData*) data;

- (void) onSummaryStepInformation:(LifevitSDKStepSummaryData*) data;
- (void) onSummarySleepInformation:(LifevitSDKSleepSummaryData*) data;
@end


@protocol LifevitBraceletAT250Delegate <NSObject>
@required
- (void) braceletSyncReceived:(LifevitSDKBraceletData*) data;
- (void) braceletCurrentStepsReceived:(LifevitSDKStepData*) data;
- (void) operationFinished:(BOOL) success;
@optional
#pragma mark - Only HR devices
- (void) braceletAT250HRReceived:(int) value;
- (void) braceletAT250HRSyncReceived:(NSArray*) value;
@end

@protocol LifevitOximeterDelegate <NSObject>
@required
- (void)oximeterDeviceOnProgressMeasurement:(LifevitSDKOximeterData*) data;
- (void)oximeterDeviceOnResult:(LifevitSDKOximeterData*) data;
@end

@protocol LifevitGlucometerDelegate <NSObject>
@required
- (void)onGlucometerDeviceResult:(LifevitSDKGlucometerData*) data;
//- (void)onGlucometerDeviceError:(int) errorCode;
@end

@protocol LifevitTensioBraceletDelegate <NSObject>
@required
- (void)tensioBraceletInformation:(id) data;
- (void)tensioBraceletRequestExecuted:(TensioBraceletRequest) request;
- (void)tensioBraceletOnProgressMeasurement:(int) pulse;
- (void)tensioBraceletOnResult:(LifevitSDKTensioBraceletData*) data;
@end

@protocol LifevitSDKDevicesScanDelegate <NSObject>
@required
- (void)allDevicesDetected:(NSMutableDictionary *) devicesList;
@end


@protocol LifevitPillReminderDelegate <NSObject>
@required

- (void)pillReminderOnResult:(id) info;
- (void)pillReminderOnError:(LifevitSDKPillReminderMessageData*) info;
@end


@interface LifevitSDKManager : NSObject<CBPeripheralDelegate>


+ (LifevitSDKManager *)sharedInstance;

@property (weak, nonatomic) id<LifevitSDKManagerDelegate> delegate;
@property (weak, nonatomic) id<LifevitDeviceDelegate> deviceDelegate;
@property (weak, nonatomic) id<LifevitHeartDelegate> heartDelegate;
@property (weak, nonatomic) id<LifevitBraceletDelegate> braceletDelegate;
@property (weak, nonatomic) id<LifevitBraceletAT250Delegate> braceletAT250Delegate;
@property (weak, nonatomic) id<LifevitBraceletVITALDelegate> braceletVITALDelegate;
@property (weak, nonatomic) id<LifevitOximeterDelegate> oximeterDelegate;
@property (weak, nonatomic) id<LifevitWeightScaleDelegate> weightscaleDelegate;
@property (weak, nonatomic) id<LifevitThermometerDelegate> thermometerDelegate;
@property (weak, nonatomic) id<LifevitBabyThermometerDelegate> babyThermometerDelegate;
@property (weak, nonatomic) id<LifevitTensioBraceletDelegate> tensioBraceletDelegate;
@property (weak, nonatomic) id<LifevitSDKDevicesScanDelegate> devicesScanDelegate;
@property (weak, nonatomic) id<LifevitPillReminderDelegate> pillReminderDelegate;
@property (weak, nonatomic) id<LifevitGlucometerDelegate> glucometerDelegate;

- (void) initCentralManagerWithoutBackgroundMode;
- (void) setCentralManagerIdentifiers:(NSArray *) identifiers;
- (void) setPeripheralManagerIdentifiers:(NSArray *) identifiers;

- (BOOL) isBluetoothOn;

- (int) getDeviceStatus:(int)type;
- (BOOL) isDeviceConnected;
- (BOOL) isDeviceConnected: (int) type;
- (void) disconnectDevice;
- (void) disconnectDevice:(int) type;
- (NSString*) getDeviceUUID:(int) type;
- (void) connectByUUID:(NSString*) uuid withType:(int) type;
- (void) connectDevice:(int) timeout;
- (void) connectDevice:(int) type withTimeout:(int) timeout;
- (void) checkBracelet;
- (void) scanAllDevices;
- (void) stopScanForDevices;
- (void) checkBatteryLevel: (int) type;

#pragma mark - Heart Device
- (BOOL) startMeasurement;
- (BOOL) stopMeasurement;
#pragma mark - Weight Device
- (void) setWeightScaleParams:(NSString*) unit withGender:(int) gender Age:(int) age andHeight:(int) cms;

#pragma mark - BraceletAT500HR
- (void) synchronizeBraceletHistoryData;
- (void) getBraceletCurrentSteps;
- (void) getBraceletHeartBeat;
- (BOOL) isBraceletInActivity;

- (void)sendBraceletStartOrFinishExercise:(BOOL)start;
- (void)sendBraceletStartOrFinishAutoSteps:(BOOL)start;

- (void) disableBraceletAlarm: (BOOL) secondaryAlarm;
- (void) disableBraceletSedentaryAlarm;
- (void)configureBraceletSedentaryAlarm:(LifevitSDKBraceletMonitoringAlarm*) alarm;
- (void)configureBraceletAlarm:(LifevitSDKBraceletAlarm*) alarm;
- (void)configureBraceletSettingFindPhone:(BOOL)enabled;
- (void)configureBraceletStepTarget: (int) target;
- (void)configureBraceletAntitheft:(BOOL)enabled;
- (void)configureBraceletMonitorHeartRate:(BOOL)enabled;
- (void)configureBraceletRiseHand:(int)type;
- (void)configureBraceletDate:(NSDate*)date;
- (void)configureBraceletUserHeight:(int)height;
- (void)configureBraceletUserWeight:(int)weight;
- (void)configureBraceletACNS:(NSArray*)types;


- (void)sendBraceletFindDevice;
- (void)bindBracelet;
- (void)activateBracelet;

- (void)getBraceletVersion;
- (void)getBraceletBattery;

- (void)sendTextToAT500HR: (NSString*) text;

#pragma mark - BraceletAT250
- (void)configureBraceletAT250UserInfo: (NSNumber*) userHeight
                            userWeight: (NSNumber*) userWeight
                            userGender: (NSNumber*) userGender
                          userBirthday: (NSDate*) userBirthday
                               vibrate: (BOOL)vibrate;
-(void)configureBraceletAT250StepsGoal: (NSNumber*) stepsGoal;
-(void)configureBraceletAT250Datetime: (NSDate*) date;
-(void)getBraceletAT250TodayData;
-(void)updateBraceletAT250Firmware;
-(void)getBraceletAT250HistoryData:(NSNumber*) daysCount;

#pragma mark - AT250 HR

-(void)getBraceletAT250HeartRateSync;
-(void)setBraceletAT250RealtimeHREnabled:(BOOL) enabled;
-(void)setBraceletAT250MonitoringHREnabled:(BOOL) enabled;
-(void)setBraceletAT250MonitoringHRAuto:(BOOL) enabled withTimeRange: (LifevitSDKAT250TimeRange*) range;

#pragma mark - VITAL

-(BOOL)setVitalStepsGoal:(NSNumber*) steps;
-(BOOL)getVitalStepsGoal;
-(BOOL)getVitalMACAddress;
-(BOOL)setBraceletTime:(NSDate*) date;
-(BOOL)getBraceletTime;
-(BOOL)setVitalUserInformation: (LifevitSDKUser*) user;
-(BOOL)getVitalUserInformation;
-(BOOL)setVitalParameters: (LifevitSDKVitalParams*) parameters;
-(BOOL)getVitalParameters;

-(BOOL)startVitalSportMode:(BraceletVitalSportType) sportMode levelSelection:(BraceletVitalMeditationLevel) levelSelection timePeriod:(int) timePeriod;
-(BOOL)stopVitalSportMode;


-(BOOL)setVitalActivityPeriod: (LifevitSDKVitalActivityPeriod*) period;
-(BOOL)getVitalActivityPeriod;

- (BOOL) setVitalPeriodicConfiguration: (LifevitSDKVitalPeriod*) period;
- (BOOL) getVitalPeriodicConfiguration: (BraceletVitalDataType) type;

- (BOOL) setVitalWeather: (LifevitSDKVitalWeather*) data;

- (BOOL) setVitalAlarms: (NSArray*) alarms;

- (BOOL) getVitalData: (BraceletVitalDataType) type;

- (BOOL) getVitalData: (BraceletVitalDataType) type periodically: (BOOL) periodically;

- (BOOL) startVitalMeasurement: (BraceletVitalDataType) type;
- (BOOL) stopVitalMeasurement: (BraceletVitalDataType) type;

- (BOOL) showVitalQR: (BOOL) show;

- (BOOL) startVitalECG;

- (BOOL) getVitalECGStatus;

- (BOOL) getVitalECGWaveform;

-(BOOL) setVitalRealtimeSteps: (BOOL) stepsEnabled temperature: (BOOL) temperatureEnabled;

#pragma mark - TensioBracelet Device

- (void)setSmartwatchConfigTensioBracelet: (LifevitSDKTensioBraceletConfig*) config;
- (BOOL)isTensioBraceletMeasuring;
- (void)startMeasurementTensioBracelet;
- (void)stopMeasurementTensioBracelet;
- (void)getBloodPressureHistoryTensioBracelet;
- (void)removeBloodPressureHistoryTensioBracelet;
//- (void)getSmartwatchTimeTensioBracelet;
//- (void)getAmbulatoryBloodPressureTimeTensioBracelet;
- (void)getBasicInfoTensioBracelet;
- (void)returnMeasurementTensioBracelet;
//- (void)resetDefaultsTensioBracelet;
- (void)setSmartwatchTimeTensioBracelet;
- (void)setAmbulatoryBloodPressureTimeTensioBracelet: (NSArray*) intervals;

#pragma mark - PillReminder

- (void) prGetDeviceTime;
//- (void) prSetDeviceTime;
//- (void) prSetDeviceTimeZone:(int) hour
//                      minute:(int) minute;
- (void) prGetDeviceTimeZone;

- (void) prGetBatteryLevel;
- (void) prGetLatestSynchronizationTime;

- (void) prSetSuccessfulSynchronizationStatus;
- (void) prClearSchedulePerformanceHistory;
- (void) prGetAlarmSchedule;
- (void) prSetAlarmSchedule: (NSMutableArray*) alarms;

- (void) prGetSchedulePerformanceHistory;
- (void) prSetAlarmDuration:(int) duration;

- (void) prSetAlarmConfirmationTime:(int) confirmationTime;
- (void) prClearAlarmSchedule;

#pragma mark - thermometer

- (void) sendThermometerCommand: (int) command;

@end
