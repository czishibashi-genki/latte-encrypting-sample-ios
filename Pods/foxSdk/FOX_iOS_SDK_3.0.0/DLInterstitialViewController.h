#import <UIKit/UIKit.h>
#import "DLAdStateDelegate.h"

@interface DLInterstitialViewController : UIViewController

@property NSString* _Nonnull placementId;
@property (weak) id<DLAdInterstitialStateDelegate> _Nullable adStateDelegate;

+(void) showInterstitial:(NSString* _Nonnull) placementId InController:(UIViewController* _Nonnull) controller;
+(void) showInterstitial:(NSString* _Nonnull) placementId InController:(UIViewController* _Nonnull) controller WithDelegate:(id<DLAdInterstitialStateDelegate> _Nullable) adDelegate;

@end
