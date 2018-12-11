//
//  FenceEdge.h
//  GeoFrenzy
//
//  Created by Ben Tally on 7/22/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "SmartFence.h"
#import "GfCoreObjc.h"

@class SmartFence;
@class GfCoreObjc;

@interface FenceEdge : NSObject

@property (nonatomic, strong) GfCoreObjc* gfCore;
@property (nonatomic, weak) SmartFence* owningFence;
@property (nonatomic, weak) MKPolyline* mkPolyLineEdge;

@property (nonatomic) double firstX;
@property (nonatomic) double firstY;
@property (nonatomic) double secondX;
@property (nonatomic) double secondY;
@property (nonatomic) double centInterX;
@property (nonatomic) double centInterY;

@property (nonatomic, strong) NSArray* firstArrayPoint;
@property (nonatomic, strong) NSArray* secondArrayPoint;
@property (nonatomic, strong) NSArray* centroidIntersectionPoint;
@property (nonatomic, strong) NSArray* nearestFeature;

@property (nonatomic) CLLocationCoordinate2D firstCoord2D;
@property (nonatomic) CLLocationCoordinate2D secondCoord2D;
@property (nonatomic) CLLocationCoordinate2D centInterCoord2D;
@property (nonatomic) CLLocationCoordinate2D nearestFeatureCoord2D;
@property (nonatomic) CLLocationDistance nearestFeatureDistance;

- (void) setEdgeWithFirstCoord:(CLLocationCoordinate2D) first andSecond: (CLLocationCoordinate2D) second;
//- (void) setEdgeWithFirstX:(CLLocationCoordinate2D) firstX andSecond: (CLLocationCoordinate2D) second;
//- (void) setEdgeWithFirstCoord:(CLLocationCoordinate2D) first andSecond: (CLLocationCoordinate2D) second;
- (void) findNearestFeature;
@end
