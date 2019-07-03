//
//  WECreativeReplayView.h
//
//  Copyright 2018-2019 Twitter, Inc.
//  Licensed under the webeye SDK License Agreement
//

#import <UIKit/UIKit.h>
#import "WECreativePlayerView.h"

@class WECreativeReplayView;

typedef void (^WECreativeBReplayActionBlock)(WECreativeReplayView *replayView);

@interface WECreativeReplayView : UIView

@property (nonatomic, copy) WECreativeBReplayActionBlock actionBlock;

- (instancetype)initWithFrame:(CGRect)frame displayMode:(WECreativePlayerDisplayMode)displayMode;

@end
