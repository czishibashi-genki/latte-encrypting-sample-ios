#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DLAdStateDelegate<NSObject>

@optional
-(void) onAdSuccess:(UIView*) view;
-(void) onAdFailed:(UIView*) view;

@end

@protocol DLAdBannerStateDelegate<DLAdStateDelegate>

@end

@protocol DLAdInterstitialStateDelegate<DLAdStateDelegate>

@optional
-(void) onAdExit;

@end


