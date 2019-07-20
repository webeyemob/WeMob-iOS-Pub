//
//  WeTrackImpressionTimer.h
//  WeDSPDemo
//
//  Created by tangzheng on 2019/6/19.
//  Copyright © 2019 WeSdk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WeMobTrackImpressionTimerDelegate <NSObject>

@required

/*
 * Called when the required visibility time has been satisfied. This delegate method
 * will only be called once for the lifetime of this object.
 */
- (void)weAdViewImpressionTracked:(UIView *)adView;

@end

@interface WeMobTrackImpressionTimer : NSObject

@property (nonatomic, weak) id<WeMobTrackImpressionTimerDelegate> delegate;

/*
 * Initializes and returns an object that will tell its delegate certain number of pixels of the view
 * has been visible for a given amount of time.
 *
 * requiredSecondsForImpression represents the number of seconds a view needs to be visible for impression counting. Range of the value: [0, infinite).
 * visibilityPixels is a float number, ranging from [0, infinite) . For example, 1 represents 1 pixel.
 */
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiredViewVisibilityPixels:(CGFloat)visibilityPixels NS_DESIGNATED_INITIALIZER;

/*
 * Initializes and returns an `MPAdImpressionTimer` instance which will alert its delegate when the given
 * percentage of a view (given by `startTrackingView`) has been visible for the given amount of time.
 *
 * requiredSecondsForImpression represents the number of seconds a view needs to be visible to count an impression. Range of the value: [0, infinite).
 * visibilityPercentage is a float number, ranging from [0, 1]. 0 represents 0%, and 1 represents 100%.
 */
- (instancetype)initWithRequiredSecondsForImpression:(NSTimeInterval)requiredSecondsForImpression requiredViewVisibilityPercentage:(CGFloat)visibilityPercentage NS_DESIGNATED_INITIALIZER;

/*
 * Starts tracking a view based on the rules given in `initWithRequiredSecondsForImpression:requiredViewVisibilityPixels`
 * or `initWithRequiredSecondsForImpression:requiredViewVisibilityPercentage`. Calls `adViewWillLogImpression:` on the
 * delegate when an impression has been tracked.
 *
 * view is the view to track
 */
- (void)startTrackingView:(UIView *)view;

- (void)stopTracking;

/**
 * `init` is not available.
 */
- (instancetype)init __attribute__((unavailable("init not available")));
@end

NS_ASSUME_NONNULL_END