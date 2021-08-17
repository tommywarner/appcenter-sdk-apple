// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#if !TARGET_OS_OSX
#import <UIKit/UIKit.h>
#endif

#import "MSACGuidedAccessUtil.h"

@implementation MSACGuidedAccessUtil

+ (BOOL)isGuidedAccessEnabled {
#if !TARGET_OS_OSX
  return UIAccessibilityIsGuidedAccessEnabled();
#else
    return no;
#endif
}

@end
