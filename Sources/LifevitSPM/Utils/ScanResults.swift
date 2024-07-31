//
//  ScanResults.swift
//
//
//  Created by Marc on 31/7/24.
//

import UIKit
import LSBluetoothPlugin

class ScanResults{

    //MARK: Properties
    
    var name: String?;
    var manufacturerData: String?;
    var service: String?;
    var rssi:Int;
    var pairedState:Int;
    var broadcastId:String?;
    var deviceType:Int;
    var userNumber:Int;
    var deviceId:String?;
    var deviceSn:String?;
    var protocolType:String?;
    var macAddress:String?;
    var registerState:Int;
    var isPairMode:Bool;

    
    //MARK: Initialization
    
    init?(device: LSDeviceInfo?) {
        //过滤无效广播名
        if(device!.deviceName == nil || device!.rssi == nil){
            return nil;
        }
        // Initialize stored properties.
        self.name = (device!.deviceName != nil ? device!.deviceName!:"nil");
        self.manufacturerData=(device!.manufacturerData != nil ? device!.manufacturerData!:"Manufacturer Data:Undefined");
        self.broadcastId=(device!.broadcastId != nil ? device!.broadcastId!:"nil");//.rssi.intValue as! Int;
        self.pairedState=(device!.isInSystem == true ? 0x01:0x00);
        //parse service uuid
        self.service="Service:Undefined!";
        if(device?.services != nil && (device?.services!.count)! > 0){
            let services:[CBUUID]=device?.services as! [CBUUID];
            var str:String="Service:";
            for item in services{
                str=String.init(format: "%@%@,", str,item.uuidString);
            }
            self.service=str;
        }
        if(device?.isInSystem  == true){
            //reset service label
            self.service="Connected";
        }
        self.rssi=device!.rssi!.intValue;
        self.deviceType=Int(device!.deviceType.rawValue);
        self.userNumber=Int(device!.deviceUserNumber);
        self.deviceId=device!.deviceId;
        self.deviceSn=device!.deviceSn;
        self.macAddress=device!.macAddress;
        self.protocolType=device!.protocolType;
        self.registerState=device!.isRegistered ? 0x01:0x00;
        self.isPairMode = device!.preparePair;
    }
   
    private func mergeService(services:[CBUUID]) -> String?{
        if(services.count > 0){
            var str:String?="Service:";
            for item in services{
                str=String.init(format: "%@%@,", str!,item);
            }
            return str;
        }
        else{
            return "Service:nil";
        }
    }
}
