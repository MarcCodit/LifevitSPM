//
//  IotDevice.h
//  WatchFaceDemo
//
//  Created by caichixiang on 2021/5/31.
//

#import <Foundation/Foundation.h>


/**
 * 路易斯iot控制属性类型
 */
typedef NS_ENUM(NSUInteger,ATIotAttsCategory) {
    ATIotAttsCategorySwitch=0x01,         //开关类型，没有属性设置信息表；
    ATIotAttsCategoryArray=0x02,          //数组列表类型，为一个可设置项的字符串数组，用attSetInfos来表示
    ATIotAttsCategorySet=0x03,            //设置项类型
    ATIotAttsCategoryText=0x04,           //文本类型
};

/**
 * iot设备属性定义
 */
@interface ATIotAtts : NSObject

/**
 * 属性ID
 */
@property(nonatomic,assign) int attId;

/**
 * 属性类型
 */
@property(nonatomic,assign) ATIotAttsCategory attType;

/**
 * 属性描述
 */
@property(nonatomic,strong) NSString*attDesc;

/**
 * 描述字体颜色
 */
@property(nonatomic,assign) int descColor;

/**
 * 属性值
 */
@property(nonatomic,assign) int attVal;

/**
 *  属性值字体颜色
 */
@property(nonatomic,assign) int attValColor;

/**
 * 属性设置项 字符串可选项
 */
@property(nonatomic,strong) NSArray <NSString *>*attSetInfos;

/**
 * 最小值
 */
@property(nonatomic,assign) int attMinVal;

/**
 * 最大值
 */
@property(nonatomic,assign) int attMaxVal;

/**
 * 步进
 */
@property(nonatomic,assign) int attStepVal;

/**
 * 单位
 */
@property(nonatomic,strong) NSString *attUnit;

/**
 * 属性文本信息
 */
@property(nonatomic,strong)NSString *attTextVal;

-(instancetype)initWithAttCategory:(ATIotAttsCategory)type;

-(NSDictionary *)toJsonMap;

/**
 * 根据0x27指令，转相应格式指令
 */
-(NSData *)toControlBytes;
@end


@interface ATIotInfo : NSObject

/**
 * 设备名称
 */
@property(nonatomic,strong) NSString *devName;

/**
 * 设备序号
 */
@property(nonatomic,assign)  int devSerial;

/**
 * 设备类型
 */
@property(nonatomic,assign) int devClass;

/**
 * 设备类型Id
 */
@property(nonatomic,strong)  NSString *devID;

/**
 * 设备图标ID
 */
@property(nonatomic,strong)  NSString *devIconID;

/**
 * 设备属性
 */
@property(nonatomic,strong) NSArray <ATIotAtts *>*devAtts;

/**
 * 设备名称更新标志位
 */
@property(nonatomic,assign) BOOL isUpdateName;

/**
 * 全量更新标志位
 */
@property(nonatomic,assign) BOOL isUpdateFull;

-(NSDictionary *)toJsonMap;
@end
