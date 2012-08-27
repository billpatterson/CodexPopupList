//
//  PopupListComponent.h
//
// Copyright 2012, 7thCodex Software, Bill Patterson.
// www.7thcodex.com
//
// License:
// This software provided without warranty of any kind. 
// You are free to use this in any way you like, so long as 
// you keep this copyright and license notice intact.


#import <Foundation/Foundation.h>

@protocol PopupListComponentDelegate;

/*
 HOW TO USE:
 
 There are three pieces:
 PopupListComponent         - Object you talk to. It creates and shows/hides popup UI for you.
 PopupListComponentItem     - Items to put in your list.
 PopupListComponentDelegate - Methods called when user taps one of your items or cancels.
 
 
 -(void) showSomePopup
 {
   PopupListComponent *popupList = [[PopupListComponent alloc] init];
   NSArray* listItems = ... some PopupListComponentItem objects you create ...;
   // Note: be sure all your items have uniqueID's so you can distinguish item in callback!
 
   // Optional: override any default properties you want to change, such as:
   popupList.textColor = [UIColor greenColor];   
 
   // Optional: store any object you want to have access to in the delegeate callback(s):
   popupList.userInfo = anyObjectToPassToCallback;
 
   [popupList showAnchoredTo:anchorUIView inView:self.view withItems:listItems withDelegate:self];
 
   Note: be sure you've saved a strong reference to popupList somewhere! 
   If you let it get garbage collected, then when the internal response code fires 
   you're going to get a crash from attempt to perform operations inside a deallocated
   object.
 
   // Storing it in a property is a good idea:
   self.activePopupList = popupList;
 }
 
 
 - (void) popupListcomponent:(PopupListComponent *)sender choseItemWithId:(int)itemId
 {
   // respond to user's choice.
   // itemId = object.itemId for one of the PopupListComponentItem's you put in the list
   
   // If you stored a "userInfo" object in the popup, access it as:
   id anyObjectToPassToCallback = sender.userInfo;
 
   Note: you do not have to do *anything* here to "take down" the popup
   or free resources. That was all taken care of for you by the PopupListComponent
   before it invoked this delegate method.
 
   // if you don't intend to reuse your PopupListComponent object, you can release it:
   self.activePopupList = nil;  // or wherever you saved your reference to it...
 }
 
 
 - (void) popupListcompoentDidCancel:(PopupListComponent *)sender
 {
   // Respond however is appropriate.
 
   Note: you do not have to do *anything* here to "take down" the popup
   or free resources. That was all taken care of for you by the PopupListComponent
   before it invoked this delegate method.

   // if you don't intend to reuse your PopupListComponent object, you can release it:
   self.activePopupList = nil;  // or wherever you saved your reference to it...
 }
*/


 
/*
 List component. Your app creates an instance of this class, 
 adds Items to it, and displays the result. 
 Note that a PopupListComponent can be reused multiple times; there is no need
 to destroy and recreate each time you want to show a new PopupList.
 Each time you call showAnchoredTo:... this object will create a new set of
 iOS UI components to actually show your Items. When the popup is dismissed, this
 object will tear down that UI and release all memory/resources.
 You can then call showAnchoredTo:... again to create another popup.
 
 Of course, if you prefer, there's nothing wrong with destroying your instance
 of this class and creating a new one for each popup if desired. Just not necessary.
*/
@interface PopupListComponent : NSObject

// Required. You must set this to some valid receiver to have a useful popup:
@property (nonatomic, weak) id<PopupListComponentDelegate> delegate;

/*
 Optional properties: 
 you can set these properties to override defaults, but all properties
 have reasonable defaults (set during "init") so maybe see if the defaults
 work for you before overriding them.
*/
@property (nonatomic, weak) UIFont* font;        // default: system font, larger on ipad
@property (nonatomic, weak) UIColor* textColor;  // default: white
@property (nonatomic, weak) UIColor* textHilightedColor;  // default: gray
@property int buttonSpacing;               // default: 10
@property int textPaddingHorizontal;       // default: 10
@property int textPaddingVertical;         // default:  5
@property int imagePaddingHorizontal;      // default: 10
@property int imagePaddingVertical;        // default:  5
@property UIControlContentHorizontalAlignment alignment;   // default: center
@property UIPopoverArrowDirection allowedArrowDirections;  // Can OR values together

/* 
 Optional: user data item to remember.
 Any data creator wants to store and access later to identify this popup
 This completely-optional parameter is not used internally in *any* way. 
 It's just a "something" you can store with the popup and have echoed back
 to you when user takes an action (useful if you need a way to "pass" a value
 through from the code that's invoking the popup to the code that will respond 
 to the user's choice/selection).
*/
@property (nonatomic, strong) id userInfo;  


- (id) init;  // Designated initializer

/* 
 Call this method to have this object build and show the UI elements for your
 itemList as a popup list. Puts UI on screen and returns. Does not block waiting
 for user input!
*/
- (void) showAnchoredTo: (UIView*)sourceItem inView:(UIView*)parentView withItems:(NSArray*)itemList withDelegate:(id<PopupListComponentDelegate>)delegate;


- (void) hide;  // Removes visual components, but leaves this object usable again via another call to showAnchoredTo:...

// Leave size and other aspects alone, but switch to non-bold version: 
- (void) useSystemDefaultFontNonBold;
// Leave size and other aspects alone, but switch to bold version: 
- (void) useSystemDefaultFontBold; // (this is the default setting)

@end


// ----------------------------------------------------------------

/*
 Items to go in a PopuListComponent. 
 You'll likely instantiate several Items to g in your ListComponent.
*/
@interface PopupListComponentItem : NSObject

@property (nonatomic, strong) NSString* caption;
@property (nonatomic, strong) UIImage* image;
@property int itemId;
@property BOOL showCaption;

- (id) initWithCaption:(NSString*)caption image:(UIImage*)image itemId:(int)itemId showCaption:(BOOL)showCaption;

@end


// ----------------------------------------------------------------


@protocol PopupListComponentDelegate

- (void) popupListcomponent:(PopupListComponent *)sender choseItemWithId:(int)itemId;
- (void) popupListcompoentDidCancel:(PopupListComponent *)sender;

@end
