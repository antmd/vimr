/**
 * Tae Won Ha — @hataewon
 *
 * http://taewon.de
 * http://qvacua.com
 *
 * See LICENSE
 */

#import <Cocoa/Cocoa.h>
#import <MacVimFramework/MacVimFramework.h>


@class VRDocumentController;


@interface VRMainWindowController : NSWindowController <NSWindowDelegate, MMVimControllerDelegate>

#pragma mark Properties
@property (readonly) NSMutableArray *documents;
@property (weak) VRDocumentController *documentController;
@property (weak) MMVimController *vimController;
@property (weak) MMVimView *vimView;

- (IBAction)firstDebugAction:(id)sender;
- (IBAction)saveDocument:(id)sender;

#pragma mark NSMainWindowController
- (IBAction)saveDocumentAs:(id)sender;
- (IBAction)revertDocumentToSaved:(id)sender;
- (id)initWithWindowNibName:(NSString *)windowNibName;
- (void)dealloc;

#pragma mark MMVimControllerDelegate
- (void)vimController:(MMVimController *)controller handleShowDialogWithButtonTitles:(NSArray *)buttonTitles
                style:(NSAlertStyle)style message:(NSString *)message text:(NSString *)text
      textFieldString:(NSString *)string data:(NSData *)data;
- (void)vimController:(MMVimController *)controller showScrollbarWithIdentifier:(int32_t)identifier state:(BOOL)state
                 data:(NSData *)data;
- (void)vimController:(MMVimController *)controller setTextDimensionsWithRows:(int)rows columns:(int)columns
               isLive:(BOOL)live keepOnScreen:(BOOL)screen data:(NSData *)data;
- (void)vimController:(MMVimController *)controller openWindowWithData:(NSData *)data;
- (void)vimController:(MMVimController *)controller showTabBarWithData:(NSData *)data;
- (void)vimController:(MMVimController *)controller setScrollbarThumbValue:(float)value
           proportion:(float)proportion identifier:(int32_t)identifier data:(NSData *)data;
- (void)vimController:(MMVimController *)controller destroyScrollbarWithIdentifier:(int32_t)identifier data:(NSData *)data;
- (void)vimController:(MMVimController *)controller tabShouldUpdateWithData:(NSData *)data;
- (void)vimController:(MMVimController *)controller tabDidUpdateWithData:(NSData *)data;
- (void)vimController:(MMVimController *)controller setBufferModified:(BOOL)modified data:(NSData *)data;
- (void)vimController:(MMVimController *)controller setDocumentFilename:(NSString *)filename data:(NSData *)data;

#pragma mark NSWindowDelegate
- (void)windowDidBecomeMain:(NSNotification *)notification;
- (void)windowDidResignMain:(NSNotification *)notification;
- (BOOL)windowShouldClose:(id)sender;

@end
