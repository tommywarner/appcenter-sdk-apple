// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import "AppCenter+Internal.h"
#import "MSACSerializableObject.h"

@class MSACStackFrame;

static NSString *const kMSACExceptionModelFrames = @"frames";
static NSString *const kMSACExceptionModelType = @"type";
static NSString *const kMSACExceptionModelMessage = @"message";
static NSString *const kMSACExceptionModelStackTrace = @"stackTrace";

@interface MSACExceptionModel : NSObject <MSACSerializableObject>

    /*
     * Exception type.
     */
    @property(nonatomic, copy) NSString *type;

    /*
     * Exception reason.
     */
    @property(nonatomic, copy) NSString *message;

    /*
     * Raw stack trace. Sent when the frames property is either missing or unreliable.
     */
    @property(nonatomic, copy) NSString *stackTrace;

    /*
     * Stack frames [optional].
     */
    @property(nonatomic) NSArray<MSACStackFrame *> *frames;

    /*
     * Convert NSError to MSACExceptionModel.
     *
     * @param error - NSError object.
     *
     * @return MSACExceptionModel exception.
     */
    + (MSACExceptionModel*)convertNSErrorToMSACExceptionModel:(NSError*)error;

    /**
     * Checks if the object's values are valid.
     *
     * @return YES, if the object is valid.
     */
    - (BOOL)isValid;
@end
