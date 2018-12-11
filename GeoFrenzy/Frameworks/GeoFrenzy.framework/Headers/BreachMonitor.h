//
//  BreachMonitor.h
//  GeoFrenzy
//
//  Created by Ben Tally on 7/6/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "SmartFence.h"
#import "GfCoreObjc.h"
#import "FencingAgentSpeech.h"
#import "FencingAgentConfig.h"

@class FencingAgentConfig;
@class GfCoreObjc;
@class FencingAgentSpeech;
@class SmartFence;

@interface BreachMonitor : NSObject
@property (nonatomic, strong) FencingAgentConfig* _Nullable fencingAgentConfig;
@property (nonatomic, strong) GfCoreObjc* _Nullable gfCore;
@property (nonatomic) double monitorRateSeconds;
@property (nonatomic, strong) SmartFence* _Nullable owningFence;
@property (nonatomic) Boolean isMonitoring;
@property (nonatomic, strong) MKPolyline* _Nullable lineFromCentroidToFencingAgentLocation;
@property (nonatomic, strong) NSTimer* _Nullable monitorTimer;
@property (nonatomic) double closingTime;
@property (nonatomic) CLLocationCoordinate2D fenceCentroidCoord;
@property (nonatomic, strong) NSArray* _Nonnull edges;
@property (nonatomic) double approachBegan;

- (void) startMonitoringBreach: (NSTimer* _Nullable) t;
- (void) stopMonitoringBreach;
- (void) drawNearestFenceEdge;
- (instancetype _Nonnull )initWithFence: (SmartFence*_Nonnull) smartFence;
@end
