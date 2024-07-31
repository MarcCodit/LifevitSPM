//
//  ATPairSetting.h
//  ByteTest
//
//  Created by caichixiang on 2020/3/20.
//  Copyright © 2020 sky. All rights reserved.
//

#import "IBDeviceSetting.h"
#import "LSUserInfo.h"

@interface ATPairSetting : IBDeviceSetting

@end

#pragma mark - ATPairRequestResp

/**
 * 绑定请求回复
 */
@interface ATPairRequestResp : ATPairSetting

/**
 * 请求确认，YES=同意建立绑定关系，NO=拒绝建立绑定关系断开连接
 */
@property(nonatomic,assign)BOOL state;

/**
 * 绑定方式
 * 0x04 = 二维码绑定
 * 0x05 = 手动绑定
 * 0x03 = 随机码绑定
 */
@property(nonatomic,assign)NSUInteger pairMode;
@end



#pragma mark - ATRandomCodeResp
/**
 * A5手环随机数绑定回复:0x7B
 */
@interface ATRandomCodeResp : ATPairSetting
@property(nonatomic,strong)NSString *randomNum;

-(instancetype)initWithRandomNum:(NSString *)num;
@end

#pragma mark - ATBindConfirmResp

@interface ATBindConfirmResp : ATPairSetting
@property(nonatomic,assign)unsigned int status;         //绑定状态，0x00:成功，0x01:失败
@property(nonatomic,assign)long utc;                    //手机当前时间
@property(nonatomic,assign)unsigned int timeZone;       //时区
@property(nonatomic,assign)float height;                //用户身高
@property(nonatomic,assign)float weight;                //用户体重
@property(nonatomic,assign)unsigned int platform;       //平台版本，0x01:iOS，0x02:Android
@property(nonatomic,strong)LSUserInfo *userInfo;        //用户信息
@end


#pragma mark - ATDiconnectReq

@interface ATDisconnectReq : ATPairSetting
@property(nonatomic,assign)unsigned int flag;            //预留，默认为:0x00000000
@property(nonatomic,assign)unsigned int status;          //0x00:手环状态机复位到登录 0x01:手环断开蓝牙连接
@end

#pragma mark - WSRegisterResp

@interface WSRegisterResp : ATPairSetting
@property(nonatomic,strong)NSString *registerKey;         //设备注册信息
@end
