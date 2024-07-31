# Swift Package Manager for LifevitSDK

## Requirements

- Requires Xcode 15.2 or above
- For Objective C projects add `-ObjC` on `Other Linker Flags` option.



## Installation

> If you've previously used CocoaPods, remove them from the project with `pod deintegrate`.

### Installing from Xcode

Add a package by selecting `File` → `Add Packages…` in Xcode’s menu bar.


---

Search for the LifevitSDK using the repo's URL:
```
https://github.com/lifevit/LifevitSPM.git
```

Next, set the **Dependency Rule** to be `branch` `main`.

Then, select **Add Package**.


## Usage
### For Lifevit Devices
You'll need to import:
`import LifevitSDK`

You have a complete documentation of the library and all its devices in:

[https://developers.lifevit.es/](https://developers.lifevit.es/)


### For Transtek Devices (TMB-2284-B, TMB-2296-BT)

You'll need to import:

```
import LifevitSPM
import LSBluetoothPlugin
```

1- On your ViewController:

```
class MyViewController {

let transtekManager = TranstekManager()
var transtekDevice: LSDeviceInfo? // If you want to save device info
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        transtekManager.delegate = self
    }
}

```

2- You can call this methods to connect and retrieve data:

```
// Main func to connect and receive data:
transtekManager.scanConnectAndRetrieveData()

// More options to connect and receive data
transtekManager.connectAndRetrieveData(withMacAddress: "B8:B7:7D:0E:63:16") // <- Change this fake mac
transtekManager.connectAndRetrieveData(for: transtekDevice)
```


3- You'll receive device data on TranstekDelegate

```
extension MyViewController: TranstekDelegate {
    func onDeviceInfo(deviceInfo: LSDeviceInfo) {
        // Callback with connected device info
        transtekDevice = deviceInfo
    }
    
    func onStatusChanged(state: LSConnectState, description: String) {
        // Callback with live connection state
    }
    
    func onDataReceived(data: LSBloodPressure) {
        // Callback with Data received
    }
}
```

## Questions and Issues

Please provide any feedback via a [GitHub
Issue](https://github.com/lifevit/LifevitSPM/issues).
