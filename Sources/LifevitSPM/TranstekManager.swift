//
//  TranstekManager.swift
//
//
//  Created by Marc on 31/7/24.
//


import Foundation
import LSBluetoothPlugin

public protocol TranstekDelegate {
    func onStatusChanged(state: LSConnectState, description: String)
    func onDataReceived(data: LSBloodPressure)
}

public class TranstekManager: NSObject {
    
    private let devicesAllowed = ["TMB-2284-B", "TMB-2296-BT"]
    public var delegate: TranstekDelegate?
    
    public init(delegate: TranstekDelegate? = nil) {
        self.delegate = delegate
    }
    
    
    public func scanAndConnect() {
        //scan filter with device type
        let deviceTypes=[LSDeviceType.bloodGlucoseMeter.rawValue,
                         LSDeviceType.bloodPressureMeter.rawValue,
                         LSDeviceType.thermometer.rawValue]
        
        LSBluetoothManager.default()?.searchDevice(deviceTypes, results: { (device) in
            let item : ScanResults? = ScanResults(device: device)
            
            if let name = item?.name, self.devicesAllowed.contains(name) {
                //add target device
                let macAddress = item!.macAddress ?? ""
                let device = LSDeviceInfo()
                device.macAddress = macAddress
                device.broadcastId = macAddress.replacingOccurrences(of: ":", with: "")
                device.deviceType = LSDeviceType(rawValue: UInt(item!.deviceType))!
                device.delayDisconnect = true
                
                
                LSBluetoothManager.default().stopSearch()
                LSBluetoothManager.default()?.addDevice(device)
                LSBluetoothManager.default()?.startDeviceSync(self)
            }
        })
    }
}

extension TranstekManager: LSDeviceDataDelegate {
    public func bleDevice(_ device: LSDeviceInfo!, didConnectStateChanged state: LSConnectState) {
        switch state {
        case .unknown:
            print("")
            
        case .connected:
            print(">> CONNECTED ✅")
            delegate?.onStatusChanged(state: state, description: "CONNECTED")
            
        case .failure:
            print(">> FAILURE ❌")
            delegate?.onStatusChanged(state: state, description: "FAILURE")
            LSBluetoothManager.default().stopSearch()
            LSBluetoothManager.default().stopDeviceSync()
            
        case .disconnect:
            print(">> DISCONNECTED")
            delegate?.onStatusChanged(state: state, description: "DISCONNECTED")
            LSBluetoothManager.default().stopDeviceSync()
            
        case .connecting:
            print(">> CONNECTING...")
            delegate?.onStatusChanged(state: state, description: "CONNECTING...")
            
        case .timeout:
            print(">> TIMEOUT ⚠️")
            delegate?.onStatusChanged(state: state, description: "TIMEOUT")
            LSBluetoothManager.default().stopSearch()
            LSBluetoothManager.default().stopDeviceSync()
            
        case .success:
            print(">> SUCCESS")
            delegate?.onStatusChanged(state: state, description: "SUCCESS")
            LSBluetoothManager.default().stopSearch()
            
        @unknown default:
            print("")
        }
    }
    
    
    public func bleDevice(_ device: LSDeviceInfo!, didDataUpdateForBloodPressureMonitor data: LSBloodPressure!) {
        delegate?.onDataReceived(data: data)
        
        DispatchQueue.main.async {
            
//            print(data.toString())
            
            var results: [String : String] = ["":""]
            
            //source data
            let str = String.init(format: "\nsrcData=%@\n",data.srcData!.hexadecimal)
            print(">> \(str)")

            //log class name
            let className = type(of: data).description()
            print(">> \(className)")
            
            //log class properties
            for (key, value) in data.toString() {
                results.updateValue("\(value)", forKey: "\(key)")
            }
            results.updateValue(data.measureTime ?? "", forKey: "measureTime")
            print(results)
        }
    }
}

extension Data {
    var hexadecimal: String {
        return map { String(format: "%02X", $0) }.joined()
    }
}
