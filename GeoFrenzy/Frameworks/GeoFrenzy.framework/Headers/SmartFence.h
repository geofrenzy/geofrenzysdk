//
//  Fence.h
//  FencingAgentWorkshop
//
//  Created by Ben Tally on 10/27/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "Smartfence.pbobjc.h"
#import "Compliance.h"
#import "FencingAgent.h"
#import "BreachMonitor.h"
#import "FenceEdge.h"


@class BreachMonitor;
@class Compliance;
@class FencingAgent;
@class FenceEdge;
@class SmartFenceMap;

/**
 A Fence is a single geometric definition of space along with it's entitlement data and properties describing the FencingAgent's current physical relation to the Fence geometry.
 */
@interface SmartFence : NSObject <NSCoding>

@property (nonatomic, strong) FenceEdge* _Nonnull nearestEdge;

@property (nonatomic) NSInteger nearestEdgeIdx;

@property (nonatomic) NSUInteger hashValue;

/**
 The geometry points in GF encoding
 
 @warning  This is a private API and is not intended for final public release
 */
@property (nonatomic, strong) NSMutableArray* _Nonnull recordParts;

/**
 The uniquie id of this fence
 */
@property (nonatomic, strong) NSString* _Nonnull id;
/**
 The geometry points of this fence represented in cartisian lon/lat coordinates
 */
@property (nonatomic, strong) NSMutableArray* _Nonnull geometry;

/**
 The centroid point of this fence in geodetic lon/lat coordinates
 */
@property (nonatomic, strong) NSArray* _Nonnull centroid;

@property (nonatomic, strong) CLLocation* _Nonnull centroidCLLocation;

/**
 Range in meters from the FencingAgent to the nearest edge of this fence
 
 @warning this property will be nil if the FencingAgent's FencingAgentConfiguration does not have detectApproaching set to YES.
 */
@property (nonatomic, strong) NSNumber* _Nonnull nearestEdgeRange;
/**
 Bearing in degrees to the nearest edge of this fence.
 
 @warning this property will be nil if the FencingAgent's FencingAgentConfiguration does not have detectApproaching set to YES.
 */
@property (nonatomic, strong) NSNumber* _Nonnull nearestEdgeBearing;
/**
 Range in meteres from the FencingAgent to the centroid point of this fence
 */
@property (nonatomic, strong) NSNumber* _Nonnull centroidRange;
/**
 Bearing in degrees to the centroid point of this fence
 */
@property (nonatomic, strong) NSNumber* _Nonnull centroidBearing;
/**
 Estimated time in seconds to close the distance to the nearest edge of this fence at current bearing and velocity.
 */
@property (nonatomic) double closingTime;
/**
 This is the method by which the aviation industry volumizes airspace. The values represented in the span are offsets from MSL (mean sea level).
 */
@property (nonatomic, strong) NSNumber* _Nonnull extrusionValue;
/**
 Number of seconds that this fence has been in a dwelling state
 */
@property (nonatomic) NSTimeInterval dwellTime;

@property (nonatomic) NSTimeInterval leaveTime;

/**
 The time that this SmartFence was entered by it's owning agent.
 */
@property (nonatomic, strong) NSDate* _Nonnull enterTime;

@property (nonatomic, strong) NSDate* _Nonnull exitTime;

/**
This property indicates that a fencing agent is currently occupying this SmartFence
 */
@property (nonatomic) Boolean agentIsInside;

/**
 This property set to NO indicates that this SmartFence should be ignored for all ranging, approaching, enter, exit and dwell events.
 */
@property (nonatomic) Boolean active;

/**
 Private instance of protobuf smartfence message
 */
@property (nonatomic, strong) SmartFenceType * _Nonnull smartFencePb;
///**
// This SmartFence's compliance calculator
// */
//@property (nonatomic, strong) Compliance * _Nullable compliance;

/**
 Array of namespaces from all control panels and domains related to this SmartFence instance
 */
@property (nonatomic, strong) NSMutableArray * _Nonnull namespaceArray;

/**
 YES indicates that this SmartFence instance is fully initialized
 */
@property (nonatomic) Boolean isInitialized;

/**
 The owning Fencing Agent of this SmartFence
 */
@property (nonatomic,strong) FencingAgent * _Nullable owningAgent;

/**
 An instance of MKPolygon representing the geometry of this SmartFence
 */
@property (nonatomic, strong) MKPolygon* _Nonnull mkPolygon;

/**
 A 32 bit color indicating the color of this fence when displayed to the user
 */
@property (nonatomic, strong) UIColor* _Nonnull color;

/**
 An instance of the BreachMonitor class which monitors approach, compliance and breach of the nearest fence edge or feature.
 */
@property (nonatomic, strong) BreachMonitor* _Nonnull breachMonitor;

/**
 A value of YES indicates that this SmartFence geometry has been rendered on screen for use by a user
 */
@property (nonatomic) Boolean isRendered;


@property (nonatomic) NSMutableSet* _Nonnull conflictFences;

/**
 An intersection point between the FencingAgent and the nearest edge
 */
@property (nonatomic) CLLocationCoordinate2D nearestIntersection;

/**
 A value of YES indicates that this fence is within the defined ranging distance and is being periodically evaluated as a candidate for approaching
 */
@property (nonatomic) Boolean isRanging;

/**
 A value of YES indicates that this SmartFence is in approaching state
 */
@property (nonatomic) Boolean isApproaching;
/**
 A value of YES indicates that this SmartFence is in dwelling state
 */
@property (nonatomic) Boolean isDwelling;
/**
 A value of YES indicates that this SmartFence is in conflict state
 */
@property (nonatomic) Boolean isConflict;
/**
 A value of YES indicates that this SmartFence is in inflation state
 */
@property (nonatomic) Boolean isInflation;
/**
 A value of YES indicates that this SmartFence has a conditional expression which yields a state which permits transition across boundary edges
 */
@property (nonatomic) Boolean transitionAllowed;

//- (void) escalateInflationToTransitioned;
//- (void) escalateInflationToApproach;


@property (nonatomic, weak) SmartFenceMap* _Nullable smartFenceMap;

/**
 Sets the centroid of a fence.
 
 @warning  This is a private API and is not intended for final public release

 @param lon longitude
 @param lat latitude
 */
- (void) setCentroidWithLong:(double) lon lat:(double) lat ;

- (id _Nonnull ) initWithAgent:(FencingAgent*_Nonnull) agent;

@end
