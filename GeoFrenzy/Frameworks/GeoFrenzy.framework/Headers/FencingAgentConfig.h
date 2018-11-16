//
//  FencingAgentConfiguration.h
//  GeoNet
//
//  Created by Ben Tally on 10/27/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FencingAgent.h"
#import "GfClient.h"

@class FencingAgent;
@class GfClient;

/**
 A configuration object for FencingAgents. The FencingAgents act as KVO observers, so updates to an existing FencingAgentConfiguration will automatically update FencingAgents that have been initialized with it.
 */
@interface FencingAgentConfig : NSObject

/**
 The FencingAgent which owns (and was instantiated with) this instance
 */
@property (nonatomic, strong) FencingAgent* owner;

/**
 GeoDomains that the configured Fencing Agent will search for SmartFences.
 */
@property (nonatomic, strong) NSMutableArray* geoDomains;

/**
 When set to YES, the FencingAgent initialized with this FencingAgentConfiguration will not use corelocation as it's source of location, but instead, it will use an externally provided source.
 */
@property (nonatomic) Boolean useVehicleLocation;

/**
 When set to YES the FencingAgent initialized with this FencingAgentConfiguration will compute ranges and estimated breach times for approaching fences
 
 @warning This is a compute intensive feature that should be used only when necessary.
 */
@property (nonatomic) Boolean detectApproaching;

@property (nonatomic) Boolean monitorFencesInBackground;
@property (nonatomic) Boolean faManagesBackgroundTasks;
/**
 FencingAgent will swap the interior and exterior rulespace.
 */
@property (nonatomic) Boolean swapFocus;

//@property (nonatomic) Boolean cacheClassMDForever;
//@property (nonatomic) Boolean cacheGeometryForever;
@property (nonatomic) Boolean smartPurge;
//@property (nonatomic) Boolean showCoi;

/**
 Enables spoken annunciations.
 */
@property (nonatomic) Boolean voiceSynth;

/**
 Spoken annunciations of the state of the fence factory. States include Anchorpoints, Legends, Namespace, SmartFences and Boundaries.
 */
@property (nonatomic) Boolean annunciateFactoryStages;

/**
 Upon dwelling, the compliance monitor will start. Default is YES.
 */
@property (nonatomic) Boolean monitorComplianceOnDwell;

/**
 When set to NO, the Fencing Agent will use the staging/development versions of services.
 */
@property (nonatomic) Boolean useProductionServices;


/**
 Number of seconds that a Fencing Agent is "mostly inside" before transitioning a SmartFence into the Dwelling state.
 */
@property (nonatomic) NSNumber* dwellTime;

/**
 Closing time in seconds of an approaching Fencing Agent. Closing times at or below this value are considered an imminent breach and trigger more vigilant edge monitoring and pre-breach compliance.
 */
@property (nonatomic) NSNumber* approachRange;

/**
 Range time in seconds of a passing FencingAgent which is not on an intercept course with a SmartFence edge. These "inflated" fences may either consider the FencingAgent to be inside or consider them to be approaching. This inflation escalation method is controlled with the treatInflationAsApproaching option.
 */
@property (nonatomic) NSNumber* inflationRange;

/**
 When this value is set to YES, SmartFences in the inflation state are considered to be approaching instead of inflated. Normal approach compliance will be triggered.
 */
@property (nonatomic) NSNumber* treatInflationAsApproaching;

/**
 Distance in meters. SmartFences within this distance of the Fencing Agent will start monitoring the nearest edge for possible breach.
 */
@property (nonatomic) NSNumber* edgeMonitorDistance;

/**
 The base frequency in seconds that range from Fencing Agent to SmartFence is recalculated
 */
@property (nonatomic) NSNumber* rangeBaseFrequency;

/**
 The base frequency in seconds that range from Fencing Agent to the nearest SmartFence edge is recalculated
 */
@property (nonatomic) NSNumber* edgeBaseFrequency;

/**
 The frequency in seconds that the TTL of cached resource records are purged or refreshed.
 */
@property (nonatomic) NSNumber* ttlFrequency;

/**
 /Time in seconds for the gfClient plugins to wait on their transports before giving up
 */
@property (nonatomic) NSNumber* gfClientTimout;

/**
 Frequency in seconds at which the SmartFence cache should be filled
 */
@property (nonatomic) NSNumber* smartFenceColdStartFrequency;

/**
 Factor at which timers are compounded in order to ease network pressure from gfClient plugins.
 */
@property (nonatomic) NSNumber* backoffTimeFactor;

/**
 Number of times that dead records (SmartFence coldstart failures) will be retried.
 */
@property (nonatomic) NSNumber* deadRecordRetry;

/**
 Frequency in seconds at which dead records (SmartFence coldstart failures) will be retried.
 */
@property (nonatomic) NSNumber* deadRecordRetryFrequency;
/**
Frequency in seconds at which the Fence Factory should fetch and assemble messages into SmartFences
*/
@property (nonatomic) NSNumber* fenceFactoryFrequency;
/**
 Frequency in seconds at which compliance with SmartFence rules should be tested and goal commands sent to registered handlers.
 */
@property (nonatomic) NSNumber* complianceFrequency;

/**
 Control Panel Index in hexidecimal.
 */
@property (nonatomic,strong) NSString* controlPanelIdx;


/**
 A Region of Interest in meters in which a search for fence geometry will be performed.
 */
@property (nonatomic) NSNumber* roi;

/**
 Visualized the nearest edges of all ranging fence geometry
 */
@property (nonatomic) Boolean visualizeBreach;

/**
 A probe vector for testing.
 By using the pressure value from 3D touch as a substitute for speed and magnetic heading in place of course, this tool gives the user a "point and press" probe to trigger approach to distant SmartFences.
 */
@property (nonatomic) Boolean use3dProbeVector;

@property (nonatomic) Boolean probeSimDevLoc;
/**
 Enables several testing features that should be left alone unless you know what you are doing.
 */
@property (nonatomic) Boolean betaFeatures;

@property (nonatomic, strong) NSNumber* mapFactoryFrequency;

/**
 Add a GeoDomain to the Fencing Agent Configuration
 
 @param geoDomain name (sandwich.shops.pickle.place)
 */
- (void) addGeoDomain:(NSString *)geoDomain;

/**
 Remove a GeoDomain to the Fencing Agent Configuration
 
 @param geoDomain name (sandwich.shops.pickle.place)
 */
- (void) removeGeoDomain:(NSString *)geoDomain;
/**
 Initializes a new FencingAgentConfiguration

 @return A new instance of FencingAgentConfiguration
 */
- (id) init;
+ (instancetype) sharedInstance;
- (void) synchronize;

@end
