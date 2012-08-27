//
//  ViewController.h
//
// Example that shows use of CodexPopupControl.
// You do not need this file to use the popup control in your own project.

#import <UIKit/UIKit.h>
#import "PopupListComponent.h"

@interface ViewController : UIViewController <PopupListComponentDelegate>

- (IBAction)actionTextListButton:(id)sender;
- (IBAction)actionImageListButton:(id)sender;
- (IBAction)actionBothListButton:(id)sender;

@end
