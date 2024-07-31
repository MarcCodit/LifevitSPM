//
//  ByteUtils.h
//  HealthApp
//
//  Created by iNMovens Solutions on 16/2/16.
//  Copyright © 2016 Daga. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ByteUtils : NSObject
+ (NSString *)byteArrayToMAC:(char[]) bytes;
+ (NSNumber *)binaryToDecimal:(NSString *) binaryString;
+ (NSNumber *)binaryToDecimal:(NSString *) binaryString from:(int) from len:(int) len;
+ (NSString *)hexTtoBinary:(NSString *) string;
+ (NSString *) checksum:(NSData *) data;
+ (Byte) checksum:(NSData *) data start:(int) start;
+ (int) bytesToInt:(char[]) bytes;
+ (int16_t) bytesToInt16:(char[]) bytes;
+ (int) bytesToIntLittleIndian:(char[]) bytes;
+ (char*) intToBytes:(int) decimal;
+ (char*) intToBytesLittleIndian:(int) decimal;
+ (int) charToInt:(char) byte;
+ (NSString *)stringFromHexString:(NSString *)hexString;
+ (NSString *)substringBinary:(NSString *)binary range:(NSRange) range;
+ (NSString *)decToBinary:(NSUInteger)decInt total:(int) total;
+ (NSString *)decimalToBinary:(int) decimal total:(int) total;
+ (NSString *) binaryToHex:(NSString *)bin;

+ (NSData *) dataFromArrayHex:(NSArray *) array;
+ (NSData *)_scanHexString:(NSString *)string;
+ (NSString *)decimalToHex:(int) decimal;

+ (NSArray *) nsdataToHex:(NSData *)data;

+ (int) decToBCD:(int) dec;
+ (int) bcdToDec:(int) bcd;
+ (NSString*) byteArrayToString:(char[]) bytes length: (int) length;
+ (int) byteArrayToInt:(char[]) bytes;
+ (int) byteArrayToIntSigned:(signed char[]) bytes;
+ (void)splitThreadOfBytes: (NSMutableData *) dataArray
                 commandId: (int) commandId
                   counter: (int) counter
            receivedBlocks: (int) receivedBlocks
            check50Records: (int) check50Records
             returnHandler: (void (^)(NSMutableArray*,int))handler;



+(double) convertIEEE754ToFloat:(signed char[]) bytes;
+(char*) convertIEEE754FloatToBytes:(float) f;
+(char*) prepareByteArray: (int) count;

@end
