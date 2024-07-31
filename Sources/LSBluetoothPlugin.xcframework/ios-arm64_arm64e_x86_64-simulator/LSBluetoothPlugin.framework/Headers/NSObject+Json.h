//
//  NSObject+Json.h
//  LSBluetoothPlugin
//
//  Created by sky.cai on 2023/9/1.
//  Copyright © 2023 sky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


@interface NSObject (Json)

- (NSDictionary *)toJson;

@end
