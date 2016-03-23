#import <UIKit/UIKit.h>
#import "DLAdStateDelegate.h"

typedef NS_ENUM (NSUInteger, DLBannerPosition) {
    DL_BANNER_POSITION_TOP = 1,
    DL_BANNER_POSITION_BOTTOM = 2,
};

@interface DLBannerView : UIView

@property NSString* _Nonnull placementId;
@property DLBannerPosition position;
@property (weak) id<DLAdStateDelegate> _Nullable adStateDelegate;

// public
-(void) show;
-(void) dismissView;

// protected
-(void) triggerLoadSuccess;
-(void) triggerLoadFailed;

@end
