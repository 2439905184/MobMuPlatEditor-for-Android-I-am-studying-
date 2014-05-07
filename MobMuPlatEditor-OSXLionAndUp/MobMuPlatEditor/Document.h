//
//  Document.h
//  MobMuPlatEd1
//
//  Created by Daniel Iglesia on 12/26/12.
//  Copyright (c) 2012 Daniel Iglesia. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CanvasView.h"
#import "DocumentModel.h"
#import "MMPControl.h"
#import "MMPSlider.h"
#import "MMPKnob.h"
#import "MMPButton.h"
#import "MMPToggle.h"
#import "MMPLabel.h"
#import "MMPXYSlider.h"
#import "MMPGrid.h"
#import "MMPPanel.h"
#import "MMPMultiSlider.h"
#import "MMPMultiTouch.h"
#import "MMPMenu.h"
#import "MMPTable.h"

#import "OSCManager.h"
#import "MMPDocumentController.h"
#define LOGLINES 12

@interface Document : NSDocument<MMPControlEditingDelegate, OSCManagerDelegate>{
    

    DocumentModel* documentModel;
    MMPControl* currentSingleSelection;
   
    IBOutlet CanvasView* canvasView;
    IBOutlet NSView* canvasOuterView;
    IBOutlet NSWindow		*documentWindow;
    IBOutlet NSScrollView* documentView;
    IBOutlet NSScrollView* documentScrollView;
    
    NSTabView *_tabView;
    int currentPageIndex;//0-index
    
    NSMutableArray* textLineArray;//array (last N) of strings for display
    
    //page controls
    NSButton *_pageDownButton;
    NSButton *_pageUpButton;
    NSTextField *_pageIndexLabel;
    NSTextField *_controlGuideLabel;
  
    //tab view (doc,add,prop,lock)
    //doc
    NSPopUpButton *_canvasTypePopButton;
    NSPopUpButton *_orientationPopButton;
    NSColorWell *_docBGColorWell;
    NSTextField *_docPageCountField;
    NSTextField *_docStartPageField;
    NSTextField *_docPortField;
    NSButton *_docChooseFileButton;
    NSTextField *_docFileTextField;
    
    
    //add
    NSButton *_addSliderButton;
    NSButton *_addKnobButton;
    NSButton *_addXYSliderButton;
    NSButton *_addLabelButton;
    NSButton *_addButtonButton;
    NSButton *_addToggleButton;
    NSButton *_addGridButton;
    NSButton *_addPanelButton;
    NSButton *_addMultiSliderButton;
    
    //prop
    NSColorWell *_propColorWell;
    NSColorWell *_propHighlightColorWell;
    NSView *_propVarView;
    NSTextField *_propAddressTextField;
    NSButton *_propDeleteButton;
    NSButton *_bringForwardButton;
    NSButton *_bringBackwardButton;
    
    //variable subviews of prop
    NSView *_propSliderView;
    NSPopUpButton *_propSliderOrientationPopButton;
    NSTextField *_propSliderRangeTextField;
    
    NSView *_propKnobView;
    NSTextField *_propKnobRangeTextField;
    NSColorWell *_propKnobIndicatorColorWell;
    
    NSView *_propToggleView;
    NSTextField *_propToggleThicknessTextField;
    
    NSView *_propLabelView;
    NSTextField *_propLabelTextField;
    NSTextField *_propLabelSizeTextField;
    NSPopUpButton *_propLabelFontPopButton;
    NSPopUpButton *_propLabelFontTypeButton;
    
    NSView *_propGridView;
    NSTextField *_propGridDimXField;
    NSTextField *_propGridDimYField;
    NSTextField *_propGridBorderThicknessField;
    NSTextField *_propGridPaddingField;
    
    NSView *_propPanelView;
    NSButton *_propPanelChooseImageButton;
    NSTextField *_propPanelImagePathTextField;
    NSButton *_propPanelPassTouchesButton;
  
    NSView *_propMultiSliderView;
    NSTextField *_propMultiSliderRangeField;
  
    NSView *_propMenuView;
    NSTextField *_propMenuTitleTextField;
  
    //lock
    NSTextView *_lockTextView;
    NSButton *_lockClearButton;
    NSSlider *_lockTiltXSlider;
    NSSlider *_lockTiltYSlider;
    NSButton *_lockShakeButton;
  
    
}

-(void)loadFromModel;

//page
- (IBAction)pageDownHit:(NSButton *)sender;
- (IBAction)pageUpHit:(NSButton *)sender;

//doc
- (IBAction)canvasChanged:(NSPopUpButton*)sender;
- (IBAction)orientationChanged:(NSPopUpButton *)sender;
- (IBAction)docBGColorChanged:(NSColorWell *)sender;
- (IBAction)docPageCountChanged:(NSTextField *)sender;
- (IBAction)docStartPageChanged:(NSTextField *)sender;
- (IBAction)docPortChanged:(NSTextField *)sender;
- (IBAction)docChooseFile:(NSButton *)sender;
- (IBAction)docFileFieldChanged:(NSTextField *)sender;


//add
- (IBAction)addSlider:(NSButton *)sender;
- (IBAction)addKnob:(NSButton *)sender;
- (IBAction)addXYSlider:(NSButton *)sender;
- (IBAction)addLabel:(NSButton *)sender;
- (IBAction)addButton:(NSButton *)sender;
- (IBAction)addToggle:(NSButton *)sender;
- (IBAction)addGrid:(NSButton *)sender;
- (IBAction)addPanel:(NSButton *)sender;
- (IBAction)addMultiSlider:(NSButton *)sender;
- (IBAction)addLCD:(NSButton *)sender;
- (IBAction)addMultiTouch:(NSButton *)sender;
- (IBAction)addMenu:(NSButton *)sender;
- (IBAction)addTable:(NSButton *)sender;

- (IBAction)propDelete:(NSButton *)sender;
- (IBAction)bringForward:(NSButton *)sender;
- (IBAction)bringBackward:(id)sender;


//prop
- (IBAction)propColorWellChanged:(NSColorWell*)sender;
- (IBAction)propHighlightColorWellChanged:(NSColorWell *)sender;
- (IBAction)propAddressChanged:(NSTextField*)sender;
//prop variable subview
- (IBAction)propSliderOrientationChanged:(NSPopUpButton *)sender;
- (IBAction)propSliderRangeChanged:(NSTextField *)sender;
- (IBAction)propKnobRangeChanged:(NSTextField *)sender;
- (IBAction)propKnobIndicatorColorWellChanged:(NSColorWell *)sender;
- (IBAction)propLabelTextChanged:(NSTextField *)sender;
- (IBAction)propLabelTextSizeChanged:(NSTextField *)sender;
- (IBAction)propLabelFontChanged:(NSPopUpButton *)sender;
- (IBAction)propLabelFontTypeChanged:(NSPopUpButton *)sender;
- (IBAction)propToggleThicknessChanged:(NSTextField *)sender;
- (IBAction)propGridDimXChanged:(NSTextField *)sender;
- (IBAction)propGridDimYChanged:(NSTextField *)sender;
- (IBAction)propGridBorderThicknessChanged:(NSTextField *)sender;
- (IBAction)propGridCellPaddingChanged:(NSTextField *)sender;
- (IBAction)propPanelChooseImage:(NSButton *)sender;
- (IBAction)propPanelImagePathTextChanged:(NSTextField *)sender;
- (IBAction)propPanelPassTouchesChanged:(NSButton *)sender;
- (IBAction)propMultiSliderRangeChanged:(NSTextField *)sender;
- (IBAction)propMenuTitleTextChanged:(NSTextField *)sender;
- (IBAction)propTableSelectionColorWellChanged:(NSColorWell *)sender;
- (IBAction)propTableModeChanged:(NSPopUpButton *)sender;

//lock
- (IBAction)lockClearButtonHit:(NSButton *)sender;
- (IBAction)lockTiltXSliderChanged:(NSSlider *)sender;
- (IBAction)lockTiltYSliderChanged:(NSSlider *)sender;
- (IBAction)lockShakeButtonHit:(NSButton *)sender;

//copyo/paste
-(IBAction)copy:(id)sender;
-(IBAction)paste:(id)sender;


//as editing delegate
@property (nonatomic) BOOL isEditing;

//from nib
@property (strong) IBOutlet NSPopUpButton *canvasTypePopButton;
@property (strong) IBOutlet NSPopUpButton *orientationPopButton;
@property (strong) IBOutlet NSButton *addSliderButton;
@property (strong) IBOutlet NSButton *bringForwardButton;
@property (strong) IBOutlet NSButton *bringBackwardButton;
@property (strong) IBOutlet NSView *propKnobView;
@property (strong) IBOutlet NSView *propVarView;
@property (strong) IBOutlet NSColorWell *propColorWell;
@property (strong) IBOutlet NSTextField *propAddressTextField;
@property (strong) IBOutlet NSColorWell *propHighlightColorWell;
@property (strong) IBOutlet NSTextField *propKnobRangeTextField;
@property (strong) IBOutlet NSColorWell *docBGColorWell;
@property (strong) IBOutlet NSButton *addKnobButton;
@property (strong) IBOutlet NSButton *addXYSliderButton;
@property (strong) IBOutlet NSButton *addLabelButton;
@property (strong) IBOutlet NSButton *addButtonButton;
@property (strong) IBOutlet NSButton *addToggleButton;
@property (strong) IBOutlet NSButton *addGridButton;
@property (strong) IBOutlet NSTabView *tabView;
@property (strong) IBOutlet NSScrollView *lockTextScrollView;
@property (strong) IBOutlet NSTextView *lockTextView;
@property (strong) IBOutlet NSView *propLabelView;
@property (strong) IBOutlet NSTextField *propLabelTextField;
@property (strong) IBOutlet NSTextField *propLabelSizeTextField;
@property (strong) IBOutlet NSButton *docChooseFileButton;
@property (strong) IBOutlet NSTextField *docFileTextField;
@property (strong) IBOutlet NSTextField *propGridDimXField;
@property (strong) IBOutlet NSTextField *propGridDimYField;
@property (strong) IBOutlet NSTextField *propGridBorderThicknessField;
@property (strong) IBOutlet NSTextField *propGridPaddingField;
@property (strong) IBOutlet NSView *propGridView;
@property (strong) IBOutlet NSButton *lockClearButton;
@property (strong) IBOutlet NSSlider *lockTiltXSlider;
@property (strong) IBOutlet NSSlider *lockTiltYSlider;
@property (strong) IBOutlet NSButton *lockShakeButton;
@property (strong) IBOutlet NSTextField *docPageCountField;
@property (strong) IBOutlet NSTextField *docStartPageField;
@property (strong) IBOutlet NSButton *pageDownButton;
@property (strong) IBOutlet NSButton *pageUpButton;
@property (strong) IBOutlet NSTextField *pageIndexLabel;
@property (strong) IBOutlet NSTextField *controlGuideLabel;
@property (strong) IBOutlet NSView *propSliderView;
@property (strong) IBOutlet NSPopUpButton *propSliderOrientationPopButton;
@property (strong) IBOutlet NSTextField *propSliderRangeTextField;
@property (strong) IBOutlet NSPopUpButton *propLabelFontPopButton;
@property (strong) IBOutlet NSButton *addPanelButton;
@property (strong) IBOutlet NSView *propPanelView;
@property (strong) IBOutlet NSButton *propDeleteButton;
@property (strong) IBOutlet NSButton *propPanelChooseImageButton;
@property (strong) IBOutlet NSTextField *propPanelImagePathTextField;
@property (strong) IBOutlet NSButton *propPanelPassTouchesButton;
@property (strong) IBOutlet NSTextField *docPortField;
@property (strong) IBOutlet NSPopUpButtonCell *propLabelFontType;
@property (strong) IBOutlet NSPopUpButton *propLabelFontTypeButton;
@property (strong) IBOutlet NSColorWell *propKnobIndicatorColorWell;
@property (strong) IBOutlet NSButton *addMultiSliderButton;
@property (strong) IBOutlet NSButton *addLCDButton;
@property (strong) IBOutlet NSButton *addMultiTouchButton;
@property (strong) IBOutlet NSButton *addMenuButton;
@property (strong) IBOutlet NSView *propMultiSliderView;
@property (strong) IBOutlet NSTextField *propMultiSliderRangeField;
@property (strong) IBOutlet NSView *propToggleView;
@property (strong) IBOutlet NSTextField *propToggleThicknessTextField;
@property (strong) IBOutlet NSView *propMenuView;
@property (strong) IBOutlet NSTextField *propMenuTitleTextField;

@property (strong) IBOutlet NSButton *addTableButton;
@property (strong) IBOutlet NSView *propTableView;
@property (strong) IBOutlet NSColorWell *propTableSelectionColorWell;
@property (strong) IBOutlet NSPopUpButton *propTableModePopButton;
@end
