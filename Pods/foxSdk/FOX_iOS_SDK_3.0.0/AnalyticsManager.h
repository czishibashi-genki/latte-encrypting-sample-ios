//
//  AnalyticsManager.h
//  Force Operation X
//
//  Copyright 2014 CyberZ, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface ForceAnalyticsManager : NSObject

/*
 * Json形式の個別情報をセットします。
 * HelpApp連携など全ての通信にパラメーターを設定したい時に使用します。
 * ユーザーのセキュリティ情報を設定しないように注意。
 */
+ (void) setUserInfo:(NSDictionary*) userInfo;

/*
 * セットされたパラメーターをJson形式として取得する。
 */
+ (NSDictionary*) getUserInfo;

/*
 * セッション開始・終了
 */
+ (void)sendStartSession;
+ (void)sendEndSession;

/*
 * イベントトラッキング
 *    アプリ内の特定のイベントの実行回数や利用されたアイテム数などを集計できます。
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param value     値
 *
 *    実行例：
 *        [ForceAnalyticsManager sendEvent:@"チュートリアル完了" action:nil label:nil value:1];
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
            value:(NSUInteger)value;

/*
 * イベントトラッキング
 *    アプリ内の特定のイベントの実行回数や利用されたアイテム数などを集計できます。
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param value     値
 * @param evntInfo  Json形式の任意のイベント情報
 *
 *    実行例：
 *        [ForceAnalyticsManager sendEvent:@"進行イベント" action:@"街到着" label:@"最初の街" value:1 eventInfo: @{@"歩数":@55}];
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
            value:(NSUInteger)value
        eventInfo:(NSDictionary*) eventInfo;

/*
 * アプリ内課金購入イベント
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param transaction     IPAのトランザクション
 * @param product  IPAのアイテム情報
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
      transaction:(SKPaymentTransaction*)transaction
          product:(SKProduct*)product;

/*
 * アプリ内課金購入イベント
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param transaction     IPAのトランザクション
 * @param product  IPAのアイテム情報
 * @param evntInfo  Json形式の任意のイベント情報
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
      transaction:(SKPaymentTransaction*)transaction
          product:(SKProduct*)product
        eventInfo:(NSDictionary*) eventInfo;

/*
 * 課金イベント
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param orderId   オーダーID
 * @param sku       SKU
 * @param itemName  アイテム名
 * @param price     値段
 * @param quantity  個数
 * @param currency  通貨
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
          orderID:(NSString*)orderID
              sku:(NSString*)sku
         itemName:(NSString*)itemName
            price:(double)price
         quantity:(NSUInteger)quantity
         currency:(NSString*)currency;

/*
 * 課金イベント
 * @param eventName イベント名
 * @param action    アクション
 * @param label     ラベル
 * @param orderId   オーダーID
 * @param sku       SKU
 * @param itemName  アイテム名
 * @param price     値段
 * @param quantity  個数
 * @param currency  通貨
 * @param evntInfo  Json形式の任意のイベント情報
 */
+ (void)sendEvent:(NSString*)eventName
           action:(NSString*)action
            label:(NSString*)label
          orderID:(NSString*)orderID
              sku:(NSString*)sku
         itemName:(NSString*)itemName
            price:(double)price
         quantity:(NSUInteger)quantity
         currency:(NSString*)currency
        eventInfo:(NSDictionary*) eventInfo;

@end
