# CodexPopupList

CodexPopupList is an iOS component designed to facilitate using the WEPopup libary to create pupup lists of
choices, from which the user can select an item or cancel.

This example project contains an XCode 4.3 project that uses ARC and targets iOS 5.0+

The example project contains a full copy of all files from the WEPopover library needed for distribution.
If you already have WEPopover in your project, then you just need to add these two files:
- PopupListComponent.h
- PopupListComponent.m

If you do not already have the WEPopover library, you don't need to download it separately. A full copy
is already included here. Just add this entire folder to your project:
- PopupListComponent

WEPopover library:  https://github.com/PaulSolt/WEPopover

This file contains an example of how to use the CodexPopuList component:
- ViewController.m

There is extensive documentation in the component's header file that you should read (how-to example code,
plust notes about default settings, etc):
- PopuListComponent.h


## Example Usage

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
	



