//
//  TranstekTensiometreViewController.swift
//  LifevitSDKSample
//
//  Created by Marc on 31/7/24.
//  Copyright © 2024 Lifevit. All rights reserved.
//

import UIKit
import LifevitSPM
import LSBluetoothPlugin

class TranstekTensiometreViewController: UIViewController {
    
    @IBOutlet weak var lblStatus: UILabel!
    @IBOutlet weak var lblDiastolic: UILabel!
    @IBOutlet weak var lblSystolic: UILabel!
    @IBOutlet weak var lblPulse: UILabel!
    @IBOutlet weak var lblUUID: UILabel!
    
    let transtekManager = TranstekManager()
    var transtekDevice: LSDeviceInfo?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        transtekManager.delegate = self
    }
    
    
    @IBAction func onConnect(_ sender: UIButton) {
        transtekManager.scanConnectAndRetrieveData()
    }
    
    @IBAction func onStartMeasurement(_ sender: UIButton) {
        guard let device = transtekDevice else { return }
        
        transtekManager.connectAndRetrieveData(for: device)
    }
    
    
    @IBAction func onConnectByMac(_ sender: UIButton) {
        guard let macAddress = transtekDevice?.macAddress, !macAddress.isEmpty else { return }

        transtekManager.connectAndRetrieveData(withMacAddress: macAddress)
    }
}

extension TranstekTensiometreViewController: TranstekDelegate {
    func onDeviceInfo(deviceInfo: LSDeviceInfo) {
        transtekDevice = deviceInfo
        DispatchQueue.main.async {
            self.lblUUID.text = deviceInfo.macAddress ?? ""
        }
    }
    
    func onStatusChanged(state: LSConnectState, description: String) {
        DispatchQueue.main.async {
            self.lblStatus.text = description
        }
    }
    
    func onDataReceived(data: LSBloodPressure) {
        DispatchQueue.main.async {
            self.lblSystolic.text = "\(data.systolic)"
            self.lblDiastolic.text = "\(data.diastolic)"
            self.lblPulse.text = "\(data.pluseRate)"
        }
    }
}
