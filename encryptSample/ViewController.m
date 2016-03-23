//
//  ViewController.m
//  encryptSample
//
//  Created by 石橋 弦樹 on 2016/03/22.
//  Copyright © 2016年 石橋 弦樹. All rights reserved.
//

#import "ViewController.h"
#import <CommonCrypto/CommonCrypto.h>
#import <Ltv.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
}

- (IBAction)ltvButtonDidPushed:(id)sender {
    
    // midを暗号化
    NSString *mid = @"test123";
    NSString *midEncrypted = [self encryptWithString:mid];
    NSLog(@"%@", midEncrypted); // 出力された結果が「ttgiVU1WuN6+mR7+RcCY1w==」になることを確認
    
    // ltvのパラメータとして暗号化したmidを送信
    AppAdForceLtv *ltv = [[AppAdForceLtv alloc] init];
    [ltv addParameter:@"mid" :[midEncrypted stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet alphanumericCharacterSet]]];
    [ltv sendLtv:7724];
}

/**
 *  暗号化
 *  AES128/CBCモードで暗号化を行い、暗号化後Base64で変換した文字列を返す
 *
 *  @param string 暗号化する文字列
 *  @return 暗号化された文字列
 */
- (NSString *)encryptWithString:(NSString *)string {
    NSData *data = [string dataUsingEncoding:NSUTF8StringEncoding];
    
    // 暗号化用パラメータ
    NSString *key = @"6$J3&prVgGU8%~q1";
    NSString *iv = @"PLeU#-!T28d-91fg";
    
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
        NSData *dataEncrypted = [NSData dataWithBytesNoCopy:buffer length:numBytesEncrypted];
        return [dataEncrypted base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
    }
    
    free(buffer);
    return nil;
}
@end
