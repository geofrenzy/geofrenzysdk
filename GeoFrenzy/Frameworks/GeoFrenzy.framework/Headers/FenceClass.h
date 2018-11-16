//
//  FenceClass.h
//  FencingAgentWorkshop
//
//  Created by Ben Tally on 10/31/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A fence class acts as a container for Fences that share the same Entitlements
 */
@interface FenceClass : NSObject <NSCoding>
/**
 An array of Entitlement indices (idx) from the GeoFrenzy Web Portal
 */
@property (nonatomic, strong) NSMutableArray* entitlements;
/**
 The FenceClass index (idx) from the GeoFrenzy Web Portal
 */
@property (nonatomic, strong) NSNumber* idx;
/**
 Time to Live is the number of seconds that a fence should remain in cache.
 */
@property (nonatomic, strong) NSNumber* ttl;

@end
