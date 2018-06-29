#import "MSAnalyticsInternal.h"
#import "MSAnalyticsTransmissionTargetInternal.h"
#import "MSAnalyticsTransmissionTargetPrivate.h"

@implementation MSAnalyticsTransmissionTarget

- (instancetype)initWithTransmissionTargetToken:(NSString *)transmissionTargetToken {
  self = [super init];
  if (self) {
    _transmissionTargetToken = transmissionTargetToken;
    _childTransmissionTargets = [NSMutableDictionary<NSString *, MSAnalyticsTransmissionTarget *> new];
  }
  return self;
}

/**
 * Track an event.
 *
 * @param eventName  event name.
 */
- (void)trackEvent:(NSString *)eventName {
  [MSAnalytics trackEvent:eventName forTransmissionTarget:self];
}

/**
 * Track an event.
 *
 * @param eventName  event name.
 * @param properties dictionary of properties.
 */
- (void)trackEvent:(NSString *)eventName withProperties:(nullable NSDictionary<NSString *, NSString *> *)properties {
  [MSAnalytics trackEvent:eventName withProperties:properties forTransmissionTarget:self];
}

- (MSAnalyticsTransmissionTarget *)transmissionTargetForToken:(NSString *)token {

  // Look up for the token in the dictionary, create a new transmission target if doesn't exist.
  MSAnalyticsTransmissionTarget *target = self.childTransmissionTargets[token];
  if (!target) {
    target = [[MSAnalyticsTransmissionTarget alloc] initWithTransmissionTargetToken:token];
    self.childTransmissionTargets[token] = target;
  }
  return target;
}

@end