//
//  ShareUtils.swift
//
//
//  Created by Marc on 31/7/24.
//

import Foundation
import UIKit


struct ShareUtils {
    @available(*,unavailable)
    private init(){}
    
    static func clearFile() -> Void {
        let clearPath = String.init(format: "%@/WF", self.logPath());
        do {
            let fileManager = FileManager.default;
            // Check if file exists
            if fileManager.fileExists(atPath:clearPath ) {
                // Delete file
                try fileManager.removeItem(atPath: clearPath)
            } else {
                print("File does not exist \(clearPath)")
            }
        } catch {
            print("An error took place: \(error)")
        }
    }
    
    static func logPath() -> String {
        let docPath = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true)[0] as NSString
        let filePath=docPath.appendingPathComponent("LS-BLE");
        if(!FileManager.default.fileExists(atPath: filePath)){
            FileManager.default.createFile(atPath: filePath, contents: nil, attributes: nil);
        }
        print("logPath:\(filePath)");
        return filePath;
    }
    
    static func firmwareFiles(model:String) -> [FileItem]?{
        let filePath=Bundle.main.resourcePath!;
        var fileItems = [FileItem]();
        do {
            let dirContents = try? FileManager.default.contentsOfDirectory(atPath: filePath) as NSArray;
            //根据设备型号过滤文件
            let otaFiles = (dirContents?.filtered(using: NSPredicate(format: "SELF CONTAINS %@", model)))! as NSArray;
            //文件名后缀匹配
            //(dirContents?.filtered(using: NSPredicate(format: "self ENDSWITH '.lsf'")))! as NSArray;
            for file in otaFiles {
                let item = FileItem(fileName:(file as! String));
                fileItems.append(item);
            }
            return fileItems;//dirContents!.filtered(using: ppdfPredicate()) as NSArray
        }
    }
    
    /**
     * 表盘文件
     */
    static func dialFiles(model:String) -> [FileItem]?{
        let filePath=Bundle.main.resourcePath!;
        var fileItems = [FileItem]();
        do {
            let dirContents = try? FileManager.default.contentsOfDirectory(atPath: filePath) as NSArray;
            //根据设备型号过滤文件
            var files = (dirContents?.filtered(using: NSPredicate(format: "SELF CONTAINS %@", "lzo")))! as NSArray;
            if(files.count > 0){
                files = (files.filtered(using: NSPredicate(format: "SELF CONTAINS %@", "lzo"))) as NSArray;
            }
            //文件名后缀匹配
            //(dirContents?.filtered(using: NSPredicate(format: "self ENDSWITH '.lsf'")))! as NSArray;
            for file in files {
                let item = FileItem(fileName:(file as! String));
                fileItems.append(item);
            }
            return fileItems;//dirContents!.filtered(using: ppdfPredicate()) as NSArray
        }
    }
    
    /**
     * 数据文件
     */
    static func dataFiles(model:String) -> [FileItem]?{
        let filePath=Bundle.main.resourcePath!;
        var fileItems = [FileItem]();
        do {
            //let filterName = String.init(format: "%@R", model);
            let dirContents = try? FileManager.default.contentsOfDirectory(atPath: filePath) as NSArray;
            //根据设备型号过滤文件
            //let otaFiles = (dirContents?.filtered(using: NSPredicate(format: "SELF CONTAINS %@", model)))! as NSArray;
            //文件名后缀匹配
            let otaFiles = (dirContents?.filtered(using: NSPredicate(format: "self ENDSWITH '.ubx'")))! as NSArray;
            for file in otaFiles {
                let item = FileItem(fileName:(file as! String));
                fileItems.append(item);
            }
            return fileItems;//dirContents!.filtered(using: ppdfPredicate()) as NSArray
        }
    }
    
    
    /**
     * 文件分享
     */
    static func shareFile(controller:UIViewController, filePath:String){
        let url = URL.init(fileURLWithPath: filePath);
        if(!url.isFileURL){
            return ;
        }
        let view = UIActivityViewController.init(activityItems: [url], applicationActivities: nil);
        controller.present(view, animated: true, completion: nil);
    }
}
