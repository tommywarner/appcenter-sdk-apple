// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import "MSACSerializableObject.h"
#import "MSACExceptionModel.h"

@interface MSACException : MSACExceptionModel

/*
 * Inner exceptions of this exception [optional].
 */
@property(nonatomic) NSArray<MSACException *> *innerExceptions;

/*
 * Name of the wrapper SDK that emitted this exception.
 * Consists of the name of the SDK and the wrapper platform, e.g. "appcenter.xamarin", "hockeysdk.cordova" [optional].
 */
@property(nonatomic, copy) NSString *wrapperSdkName;

@end
