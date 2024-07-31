//
//  TSafeMutableArray.h
//  LSBluetoothPlugin
//
//  Created by caichixiang on 2021/3/27.
//  Copyright © 2021 sky. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface IBMutableArray : NSMutableArray

/**
 * 从队列中获取第一个元素,且执行删除操作
 */
-(id)dequeue;


/**
 * 向队列中插入一个元素
 */
-(void) enqueue:(id)obj;


-(NSUInteger)count;
@end
