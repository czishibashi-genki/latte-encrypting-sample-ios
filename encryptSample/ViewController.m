//
//  ViewController.m
//  encryptSample
//
//  Created by 石橋 弦樹 on 2016/03/22.
//  Copyright © 2016年 石橋 弦樹. All rights reserved.
//

#import "ViewController.h"
#import <CommonCrypto/CommonCrypto.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString *string = @"test123";
    NSData *data = [string dataUsingEncoding:NSUTF8StringEncoding];
    
    NSString *key = @"6$J3&prVgGU8%~q1";
    NSString *iv = @"PLeU#-!T28d-91fg";
    
    // 暗号化
    NSData *dataEncrypted = [self encryptWithData:data key:key iv:iv];
    NSString *stringEncrypted = [dataEncrypted base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
    NSLog(@"%@", stringEncrypted); //ttgiVU1WuN6+mR7+RcCY1w==
}


- (NSData *)encryptWithData:(NSData *)data key:(NSString *)key iv:(NSString *)iv {
    // key
    char keyPtr[kCCKeySizeAES128+1];
    bzero(keyPtr, sizeof(keyPtr));
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    
    // iv
    char ivPtr[kCCBlockSizeAES128 + 1];
    bzero(ivPtr, sizeof(ivPtr));
    [iv getCString:ivPtr maxLength:sizeof(ivPtr) encoding:NSUTF8StringEncoding];
    
    size_t bufferSize = [data length] + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);
    
    size_t numBytesEncrypted = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt, kCCAlgorithmAES128, kCCOptionPKCS7Padding,
                                          keyPtr, kCCKeySizeAES128,
                                          ivPtr,
                                          [data bytes], [data length],
                                          buffer, bufferSize,
                                          &numBytesEncrypted);
    if (cryptStatus == kCCSuccess) {
        return [NSData dataWithBytesNoCopy:buffer length:numBytesEncrypted];
    }
    
    free(buffer);
    return nil;
}
@end
