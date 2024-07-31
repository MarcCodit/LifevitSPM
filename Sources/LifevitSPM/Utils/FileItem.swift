//
//  FileItem.swift
//
//
//  Created by Marc on 31/7/24.
//

import Foundation

class FileItem {
    
    var name:String = "";
    var path:String = "";
    var firmwareVersion:String = "";
    var fileType : String = ".lsf";
    
    init(fileName:String) {
        self.name=fileName;
        self.firmwareVersion = fileName;
        let subStrs: [Substring] = fileName.split(separator: "_");
        //to string
        let _: [String] = subStrs.compactMap {
            (item) -> String in
            if(item.contains("T") && item.contains(".lsf")){
                //截取以T开始的固件版本
                let str:String=String.init(item);
                let startIndex=str.firstIndex(of: "T");
                let endIndex=str.index(startIndex!, offsetBy: 4);
                let range=startIndex!..<endIndex;
                self.firmwareVersion=String.init(str[range]);
                return self.firmwareVersion;
            }
            else if(item.contains("X") && item.contains(".lsf")){
                //截取以X开始的固件版本
                let str:String=String.init(item);
                let startIndex=str.firstIndex(of: "X");
                let endIndex=str.index(startIndex!, offsetBy: 4);
                let range=startIndex!..<endIndex;
                self.firmwareVersion=String.init(str[range]);
                return self.firmwareVersion;
            }
            return self.firmwareVersion;
        }
        self.path=Bundle.main.path(forAuxiliaryExecutable: self.name)!;
    }
    
    init(fileName:String,filePath:String) {
        self.name=fileName;
        self.firmwareVersion = fileName;
        self.path = filePath;
    }
}
