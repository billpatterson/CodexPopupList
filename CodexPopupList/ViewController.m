//
//  ViewController.m
//
// Example that shows use of CodexPopupControl.
// You do not need this file to use the popup control in your own project.

#import "ViewController.h"


@interface ViewController ()

@property (nonatomic, strong) PopupListComponent* activePopup;

@end



@implementation ViewController

@synthesize activePopup = _activePopup;


- (IBAction)actionTextListButton:(id)sender 
{
    // Put up a list of text items
    
    if (self.activePopup) {
        // A popup is already active. Since we re-use our PopupListComponent object
        // for all popups, we need to cancel the active popup first:
        [self.activePopup hide];
    }

    PopupListComponent *popupList = [[PopupListComponent alloc] init];
    NSArray* listItems = nil;
    listItems = [NSArray arrayWithObjects:
                 [[PopupListComponentItem alloc] initWithCaption:@"Item A" image:nil itemId:1 showCaption:YES],
                 [[PopupListComponentItem alloc] initWithCaption:@"Item B is longer" image:nil itemId:2 showCaption:YES],
                 [[PopupListComponentItem alloc] initWithCaption:@"Item C" image:nil itemId:3 showCaption:YES],
                 nil];
    
    // Optional: override any default properties you want to change, such as:
    popupList.textColor = [UIColor redColor];   
    
    // Optional: store any object you want to have access to in the delegeate callback(s):
    popupList.userInfo = @"Value to hold on to";
        
    [popupList showAnchoredTo:sender inView:self.view withItems:listItems withDelegate:self];
    
    self.activePopup = popupList;
}


- (IBAction)actionImageListButton:(id)sender 
{
    // Put up a list of image items
    
    if (self.activePopup) {
        // A popup is already active. Since we re-use our PopupListComponent object
        // for all popups, we need to cancel the active popup first:
        [self.activePopup hide];
    }
    
    PopupListComponent *popupList = [[PopupListComponent alloc] init];
    NSArray* listItems = nil;
    listItems = [NSArray arrayWithObjects:
                 [[PopupListComponentItem alloc] initWithCaption:nil image:[UIImage imageNamed:@"color_red"] 
                                                          itemId:1 showCaption:NO],
                 [[PopupListComponentItem alloc] initWithCaption:nil  image:[UIImage imageNamed:@"color_green"] 
                                                          itemId:2 showCaption:NO],
                 [[PopupListComponentItem alloc] initWithCaption:nil  image:[UIImage imageNamed:@"color_blue"] 
                                                          itemId:3 showCaption:NO],
                 nil];
    
    // Optional: override any default properties you want to change, such as:
    popupList.imagePaddingVertical = 25;  
    
    // Optional: store any object you want to have access to in the delegeate callback(s):
    popupList.userInfo = @"Value to hold on to";
    
    [popupList showAnchoredTo:sender inView:self.view withItems:listItems withDelegate:self];
    
    self.activePopup = popupList;
}


- (IBAction)actionBothListButton:(id)sender 
{
    // Put up a list of images with captions
    
    if (self.activePopup) {
        // A popup is already active. Since we re-use our PopupListComponent object
        // for all popups, we need to cancel the active popup first:
        [self.activePopup hide];
    }
    
    PopupListComponent *popupList = [[PopupListComponent alloc] init];
    NSArray* listItems = nil;
    listItems = [NSArray arrayWithObjects:
                 [[PopupListComponentItem alloc] initWithCaption:@"Red" image:[UIImage imageNamed:@"color_red"] 
                                                          itemId:1 showCaption:YES],
                 [[PopupListComponentItem alloc] initWithCaption:@"Green"  image:[UIImage imageNamed:@"color_green"] 
                                                          itemId:2 showCaption:YES],
                 [[PopupListComponentItem alloc] initWithCaption:@"Blue Text Here"  image:[UIImage imageNamed:@"color_blue"] 
                                                          itemId:3 showCaption:YES],
                 nil];
    
    // Optional: override any default properties you want to change:
    popupList.imagePaddingHorizontal = 5;  
    popupList.imagePaddingVertical = 2;  // Images are taller than text, so this will be determining factor!
    popupList.textPaddingHorizontal = 5;  
    popupList.alignment = UIControlContentHorizontalAlignmentLeft;
    [popupList useSystemDefaultFontNonBold];  // Instead of bold font, which is component default.

    // Optional: store any object you want to have access to in the delegeate callback(s):
    popupList.userInfo = @"Value to hold on to";
    
    [popupList showAnchoredTo:sender inView:self.view withItems:listItems withDelegate:self];
    
    self.activePopup = popupList;
}



#pragma mark - Delegate Callbacks


- (void) popupListcomponent:(PopupListComponent *)sender choseItemWithId:(int)itemId
{
    NSLog(@"User chose item with id = %d", itemId);
    
    // If you stored a "userInfo" object in the popup, access it as:
    id anyObjectToPassToCallback = sender.userInfo;
    NSLog(@"popup userInfo = %@", anyObjectToPassToCallback);
    
    // Free component object, since our action method recreates it each time:
    self.activePopup = nil;  
}

- (void) popupListcompoentDidCancel:(PopupListComponent *)sender
{
    NSLog(@"Popup cancelled");
    
    // Free component object, since our action method recreates it each time:
    self.activePopup = nil;  
}



#pragma mark - View Lifecycle

/*
 Standard iOS View Lifecycle stuff. Nothing interesting or custom here.
 Straight "generated by xcode" template.
*/


- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}
@end
