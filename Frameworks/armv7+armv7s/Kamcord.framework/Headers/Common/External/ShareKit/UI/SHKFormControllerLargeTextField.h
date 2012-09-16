//
//  SHKFacebookForm.h
//  ShareKit
//

#import <UIKit/UIKit.h>

@protocol KC_SHKFormControllerLargeTextFieldDelegate;

@class KC_SHKFormControllerLargeTextField;
@compatibility_alias SHKFormControllerLargeTextField KC_SHKFormControllerLargeTextField;

@interface SHKFormControllerLargeTextField : UIViewController <UITextViewDelegate>

@property (nonatomic, readonly, assign) id <KC_SHKFormControllerLargeTextFieldDelegate> delegate;
@property (nonatomic, retain) UITextView *textView;

// these properties are used for counter text display only. 
// Counter shows, only if they are set by your sharer.
@property NSUInteger maxTextLength;
@property (nonatomic, retain) UIImage *image;//ready for showing up image, like ios5 twitter
@property NSUInteger imageTextLength; //set only if image subtracts from text length (e.g. Twitter)
@property BOOL hasLink; //only if the link is not part of the text in a text view
@property (nonatomic, retain) NSString *text;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil delegate:(id <KC_SHKFormControllerLargeTextFieldDelegate>)aDelegate;

@end

@protocol KC_SHKFormControllerLargeTextFieldDelegate <NSObject> 

- (void)sendForm:(SHKFormControllerLargeTextField *)form;
+ (NSString *)sharerTitle;
- (void)sendDidCancel;

@end
