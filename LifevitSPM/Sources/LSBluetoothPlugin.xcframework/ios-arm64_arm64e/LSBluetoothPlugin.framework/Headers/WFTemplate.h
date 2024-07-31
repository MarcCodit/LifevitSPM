//
//  WFTemplate.h
//  ImageDemo
//
//  Created by caichixiang on 2021/2/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define WF_TEMPLATE @"TemplateWatch"


#define WF_ELEMENT @"Element"

#define WF_ELEMENT_VARIABLES @"VARIABLE"
#define WF_ELEMENT_THUMBNAIL @"THUMBNAIL"
#define WF_ELEMENT_ICON @"icon"
#define WF_ELEMENT_PROGRESS @"Progress"
#define WF_ELEMENT_NUMDIGIT @"Numdigit"
#define WF_ELEMENT_ANALOGCLOCK @"AnalogClock"
#define WF_ELEMENT_DRAWRECT @"Drawrect"
#define WF_ELEMENT_COMB @"Comb"

#define WF_ATTRIBUTE @"Attribute"

#define WF_ATTRIBUTE_RENDER @"Render"
#define WF_ATTRIBUTE_RESDIR @"ResDir"
#define WF_ATTRIBUTE_POS @"Pos"
#define WF_ATTRIBUTE_DATASRC @"DataSrc"
#define WF_ATTRIBUTE_DIGITHOLDER @"DigitHolder"
#define WF_ATTRIBUTE_RESPOSLIST @"ResPosList"
#define WF_ATTRIBUTE_ROTATE @"Rotate"
#define WF_ATTRIBUTE_ALIGN @"Align"
#define WF_ATTRIBUTE_FILTERSRC @"FilterSrc"


#define KEY_ELEMENT_TYPE @"element_type"
#define KEY_ELEMENT_LABEL @"label"
#define KEY_ELEMENT_NAME @"name"
#define KEY_ELEMENT_VERSION @"version"
#define KEY_ELEMENT_DPI @"dpi"


/**
 * 配置项内容
 */
typedef NS_ENUM(NSUInteger,WFConfigType) {
    WFConfigTypeTimeDisplayStyle=0x01,      //日期、时间显示样式
};

/**
 * 表盘内容配置项信息
 */
@interface WFConfigItem : NSObject

/**
 * 配置类型
 */
@property(nonatomic,assign)WFConfigType type;

/**
 * 配置内容，单项样式
 */
@property(nonatomic,assign)int value;

/**
 * 配置内容，多项样式
 */
@property(nonatomic,strong)NSArray <NSString *>*list;
@end


@interface WFTemplate : NSObject

@property(nonatomic,strong)NSString *name;           //名称
@property(nonatomic,strong)NSString *version;        //版本
@property(nonatomic,strong)NSString *dpi;            //像素大小
@property(nonatomic,strong)NSDictionary *configMap;  //自定义参数变量
@property(nonatomic,strong,readonly)NSURL *xmlPath;  //配置文件路径
@property(nonatomic,strong)NSString *deviceModel;     //设备型号
@property(nonatomic,strong,nullable)UIImage *bgImage;  //背景图
@property(nonatomic,strong,nullable)UIImage *preImage; //预览图

/**
 * 根据xml文件路径加载表盘配置文件
 */
-(instancetype)initWithXml:(NSURL *)path;

/**
 * 保存自定义参数，并更新xml表盘配置文件
 */
-(NSURL *)saveConfig:(NSDictionary *)varMap;

/**
 * 替换原资源包的背景图片，并将图片转RGB565以二进制bin文件的格式替换原文件
 */
-(NSURL *)saveBackground:(UIImage *)image ;

/**
 * 替换原资源包的预览图片，并将图片转RGB565以二进制bin文件的格式替换原文件
 */
-(NSURL *)savePreview:(UIImage *)image;

/**
 * 根据配置内容修改配置文件
 */
-(void)saveConfigItem:(NSArray <WFConfigItem *>*)items;
@end
