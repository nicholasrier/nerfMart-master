//
//  SRReporter.h
//  ShakeReport
//
//  Created by Jeremy Templier on 5/29/13.
//  Copyright (c) 2013 Jeremy Templier. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIWindow+SRReporter.h"
#import <MessageUI/MessageUI.h>
#import <MessageUI/MFMailComposeViewController.h>
#import "SRReportViewController.h"

typedef NSString* (^SRCustomInformationBlock)();


@interface SRReporter : NSObject <MFMailComposeViewControllerDelegate, UINavigationControllerDelegate, SRReportViewControllerDelegate, NSURLConnectionDataDelegate>

@property (readwrite, nonatomic, copy) SRCustomInformationBlock customInformationBlock;
@property (nonatomic, copy) NSString *defaultEmailAddress;
@property (nonatomic, copy) NSURL *backendURL;
@property (nonatomic, copy) NSString *ApiKey;
@property (nonatomic, copy) NSString *applicationToken;
@property (nonatomic, assign) int ApplicationID;
@property (nonatomic, assign) BOOL lastSessionCrashed;
@property (nonatomic, assign) BOOL displayReportComposerWhenShakeDevice;
@property (nonatomic, assign) BOOL recordsCrashes;

+ (instancetype)reporter;

- (void)startListenerConnectedToBackendURL:(NSURL *)url;
- (void)startListener;

- (void)stopListener;

- (void)setCustomInformationBlock:(NSString* (^)())block;

/**
 Display one of the report composer (depends on the settings).
 Call this method if you want to link a button to the action of creating a new report.
 **/
- (void)displayReportComposer;
- (void)viewControllerDidPressCancel:(UIViewController *)viewController;
- (BOOL)canSendNewReport;
- (void)saveToCrashFile:(NSString *)crashContent;
- (void)onCrash:(NSException *)exception;

- (NSDictionary *)paramsForHTTPReportWithTitle:(NSString *)title andMessage:(NSString *)message;
- (void)addAttachmentsToMailComposer:(MFMailComposeViewController *)mailComposer;
- (NSMutableURLRequest *)requestForHTTPReportWithTitle:(NSString *)title andMessage:(NSString *)message;

@end
