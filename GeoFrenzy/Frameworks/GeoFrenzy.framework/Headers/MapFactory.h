//
//  MapFactory.h
//  GeoFrenzy
//
//  Created by Ben Tally on 11/12/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FencingAgent.h"
#import "SmartFenceMap.h"
#import "FencingAgentSpeech.h"
#import "GfCoreObjc.h"

NS_ASSUME_NONNULL_BEGIN


@class GfCoreObjc;

@interface MapFactory : NSObject
@property (nonatomic, strong) GfCoreObjc* gfCoreObjc;
@property (nonatomic, strong) FencingAgent* owningAgent;

- (void) enqueue: (MapType*) smartFencePb;
- (void) start;

@end

NS_ASSUME_NONNULL_END
