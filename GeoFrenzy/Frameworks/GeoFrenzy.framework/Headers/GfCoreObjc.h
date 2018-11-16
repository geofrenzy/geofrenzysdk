//
//  GfCoreObjc.h
//  GeoFrenzy
//
//  Created by Ben Tally on 8/8/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "gfcorecpp.h"
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import "SmartFence.h"
#import "FencingAgent.h"
#import "FencingAgentConfig.h"
#import "Utilities.h"

@class Utilities;
@class SmartFence;
@class FencingAgent;
@class FencingAgentConfig;

@interface GfCoreObjc : NSObject;

@property (nonatomic, strong) FencingAgentConfig* _Nonnull config;

- (MKPolyline*_Nonnull) closestPolyLineToPointObjc:(MKMapPoint) line withFence: (SmartFence*_Nonnull) fence;
- (NSInteger) closestPolygonEdgeToPointObjc:(MKMapPoint) point withFence: (SmartFence*_Nonnull) fence;
- (NSMutableArray*_Nonnull) pointArrayForGfPointArray: (NSMutableArray*_Nonnull) gfPoints;
- (Boolean) pointIsInsideFence:(NSArray*_Nonnull)point withFence:(SmartFence*_Nonnull)fence  withFa:(FencingAgent*_Nonnull)fa;
- (CLLocationCoordinate2D) locationFromGroupedHex: (NSString*_Nonnull) groupedHex;
- (CLLocationCoordinate2D) intersectionOfLines: (CLLocationCoordinate2D) lineOneStart
                                    lineOneEnd: (CLLocationCoordinate2D) lineOneEnd
                                  lineTwoStart: (CLLocationCoordinate2D) lineTwoStart
                                    lineTwoEnd: (CLLocationCoordinate2D) lineTwoEnd;
- (CLLocationCoordinate2D) offsetFromCoordinate: (CLLocationCoordinate2D) coord atDistance: (double) distance atHeading: (double) heading;
- (NSArray*_Nonnull) closestEdgeToCoordObjc:(CLLocationCoordinate2D) coord  withFence: (SmartFence*_Nonnull) fence;
- (double) distanceBetweenCoord: (CLLocationCoordinate2D) origin andDestination: (CLLocationCoordinate2D) destination;

+ (NSString* _Nonnull) gfEncodeCoord: (CLLocationCoordinate2D) coord;

+ (instancetype _Nonnull )sharedInstance;

@end

