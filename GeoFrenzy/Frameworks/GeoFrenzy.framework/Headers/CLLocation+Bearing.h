//
//  CLLocation+Bearing.h
//  GeoFrenzy
//
//  Created by Ben Tally on 7/15/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


@interface CLLocation (Bearing)

-(double) bearingToLocation:(CLLocation *) destinationLocation;

@end
