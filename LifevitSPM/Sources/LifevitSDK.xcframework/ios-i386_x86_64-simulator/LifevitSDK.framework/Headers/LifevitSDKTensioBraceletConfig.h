//
//  LifevitSDKTensioBraceletConfig.h
//  LifevitSDK
//
//  Created by iNMovens Solutions on 10/5/18.
//  Copyright © 2018 LifeVit. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum HAND{LEFT, RIGHT} HAND;

@interface LifevitSDKTensioBraceletConfig : NSObject

@property HAND hand;
@property BOOL ambulatoryEnabled;
@end
