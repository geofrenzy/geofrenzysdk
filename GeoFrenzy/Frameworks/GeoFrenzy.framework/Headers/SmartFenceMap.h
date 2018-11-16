//
//  SmartFenceMap.h
//  GeoFrenzy
//
//  Created by Ben Tally on 11/12/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Compliance.h"

//#import "FencingAgent.h"

NS_ASSUME_NONNULL_BEGIN

@class Compliance;
//@class FencingAgent;

@interface SmartFenceMap : NSObject

/**
 A Fence is a single geometric definition of space along with it's entitlement data and properties describing the FencingAgent's current physical relation to the Fence geometry.
 */



@property (nonatomic) NSUInteger hashValue;

@property (nonatomic, strong) MapType* map;

/**
 The uniquie id of this fence
 */
@property (nonatomic, strong) NSString* _Nonnull id;

/**
 This property set to NO indicates that this SmartFence should be ignored for all ranging, approaching, enter, exit and dwell events.
 */
@property (nonatomic) Boolean active;


/**
 This SmartFence's compliance calculator
 */
@property (nonatomic, strong) Compliance * _Nullable compliance;

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
 A value of YES indicates that this SmartFence is monitoring compliance as a result of approach, leave or dwell.
 */
@property (nonatomic) Boolean isMonitoringCompliance;

@property (nonatomic, strong) NSMutableSet* fencesWithActiveRulespace;
@property (nonatomic, strong) NSMutableSet * _Nonnull ruleSet;
@property (nonatomic, strong) NSMutableSet * _Nonnull conditionSet;
@property (nonatomic, strong) NSTimer* _Nonnull mapChangesTimer;


- (void) activateRulespaceForFenceKey:(NSString*) key;
- (void) deactivateRulespaceForFenceKey:(NSString*) key;

- (id) initWithAgent:(FencingAgent*) agent;

@end

NS_ASSUME_NONNULL_END
