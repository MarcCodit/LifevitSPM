//
//  ATFileData.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2020/12/4.
//  Copyright © 2020 sky. All rights reserved.
//

#import "ATDeviceData.h"
#import "ATSettingProfiles.h"

@interface ATFileData : ATDeviceData

/**
 * 文件传输指令
 */
@property(nonatomic,assign)  ATFileCmd fileCmd;

/**
 * 会话Id
 */
@property(nonatomic,assign) unsigned int sessionId;

/**
 * 文件状态
 */
@property(nonatomic,assign)  ATFileRespState state;

/**
 * 根据指令格式封装数据包
 */
-(NSData *_Nonnull)toBytes;

-(instancetype _Nonnull )initWithFileCmd:(ATFileCmd)cmd;
@end

/**
 * 文件列表
 * 获取文件列表（Dev发起:0x20  App发起:0x40）
 */
@interface ATFileList : ATFileData

/**
 * 文件类型
 */
@property(nonatomic,assign) ATFileCategory type;

/**
 * 文件总数
 */
@property(nonatomic,assign)unsigned int count;

/**
 * 文件名列表
 */
@property(nullable,nonatomic,strong) NSArray<NSString *>*fileNames;
@end


/**
 * 文件详情信息
 * 获取文件（Dev发起:0x21  App发起:0x41）
 */
@interface ATFileDetails : ATFileData
/**
 * 文件类型
 */
@property(nonatomic,assign) ATFileCategory type;

/**
 * 文件名
 */
@property(nonatomic,strong) NSString * _Nullable fileName;

/**
 * 文件URL
 */
@property(nonatomic,strong) NSURL * _Nullable fileUrl;
@end

/**
 * 文件概要信息
 * 推送文件/传输文件开始（Dev发起:0x22  App发起:0x42）
 */
@interface ATFileSummary : ATFileData

/**
 * 文件类型
 */
@property(nonatomic,assign) ATFileCategory type;

/**
 * 文件是否唯一标识
 */
@property(nonatomic,assign) unsigned int uniqueId;

/**
 * 每帧最大长度，Max:1023
 */
@property(nonatomic,assign) unsigned int mtu;

/**
 * 多少帧确认一次，Max:15
 */
@property(nonatomic,assign) unsigned int maxFrames;

/**
 * 标识数据的CRC32
 */
@property(nonatomic,assign) unsigned int crc;

/**
 * 文件大小
 */
@property(nonatomic,assign) unsigned int fileSize;

/**
 * 文件名称
 */
@property(nonatomic,strong) NSString * _Nonnull fileName;

/**
 * 具有唯一标识时才有效，用于断点续传。
 * 下个数据块的偏移量，若需求的所有数据完全接收完成；
 * 可使用0xFFFFFFFF促使发送方发送“文件校验通知”指令，以提前完成文件传输过程
 */
@property(nonatomic,assign) unsigned int fileOffset;

/**
 * 文件路径
 */
@property(nonatomic,strong)NSURL * _Nonnull fileUrl;


-(instancetype _Nonnull )initWithFileUrl:(NSURL *_Nonnull)url;
@end

/**
 * 文件块确认信息
 * 文件传输确认包（Dev发起:0x23  App发起:0x43）
 */
@interface ATFileConfirm : ATFileData

/**
 * 数据块CRC32
 */
@property(nonatomic,assign) unsigned int blockCrc;

/**
 * 数据块大小
 */
@property(nonatomic,assign) unsigned int blockSize;

/**
 * 数据块的偏移量
 */
@property(nonatomic,assign) unsigned int fileOffset;
@end

/**
 * 文件取消
 * 停止文件传输（Dev发起:0x24  App发起:0x44）
 */
@interface ATFileCancel : ATFileData

/**
 * 取消原因
 */
@property(nonatomic,assign)unsigned int reason;
@end

/**
 * 文件完成通知
 * 文件传输完成通知（Dev发起:0x25  App发起:0x45）
 */
@interface ATFileCompleted : ATFileData

/**
 * 文件大小
 */
@property(nonatomic,assign) unsigned int fileSize;

/**
 * 文件CRC
 */
@property(nonatomic,assign) unsigned int fileCrc;

/**
 * 文件保存路径
 */
@property(nonatomic,strong) NSString * _Nullable filePath;
@end


/**
 * 文件同步进度
 */
@interface ATFileProgress : ATFileData

@property(nonatomic,assign)unsigned int progress;
@end
