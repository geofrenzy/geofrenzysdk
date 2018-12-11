//
//  FencingAgent.h
//  GeoNet
//
//  Created by Ben Tally on 10/27/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

#import "bin2hex.h"
#import "SmartFence.h"
#import "bin2hex.h"
//#import "FencingAgentConfiguration.h"
//#import "ThresholdEntitlement.h"
//#import "ColorEntitlement.h"
//#import "BooleanSetEntitlement.h"
//#import "IntervalEntitlement.h"
//#import "ProfileEntitlement.h"
//#import "BlobEntitlement.h"
#import "FenceClass.h"
#import "Utilities.h"
#import "FencingAgentService.h"
#import "GfCodecObjc.hh"
#import "JsonLogic.h"
#import "GfClient.h"
#import "GfClientDnsPlugin.h"
#import "GfClientRestPlugin.h"
#import "FencingAgentSpeech.h"
#import "ComplianceDriver.h"
//#import "SmartFenceMap.h"

//#import "GfCoreObjc.h"

//@class GfCoreObjc;
//@class FencingAgentSpeech;
//@class FencingAgentConfig;
//@class bin2hex;
//@class SmartFence;
//@class Utilities;
//@class FencingAgentService;
//@class GfCodecObjc;
//@class JsonLogic;
//@class GfClient;
//@class GfClientDnsPlugin;
//@class GfClientRestPlugin;
//@class FencingAgentSpeech;
//@class SmartFenceFactory;

/**
 This protocol provides the delegate methods that serve as the primary interface to the GeoFrenzy Fence Delivery Network.
 */
@protocol FencingAgentDelegate <NSObject>

@required




-(void) approachingFences: (NSMutableSet*_Nonnull) fenceSet;

/**
 Provides notice of fences that are being entered at this moment

 @param fenceSet A set of all fences that are being entered
 */
-(void) enteringFences: (NSMutableSet*_Nonnull) fenceSet;

/**
 Provides notice of fences that are being exited at this moment
 
 @param fenceSet A set of all fences that are being exited
 */
-(void) exitingFences: (NSMutableSet*_Nonnull) fenceSet;

-(void) leftFences: (NSMutableSet*_Nonnull) fenceSet;

/**
 Provides notice of fences that are being dwelled inside of at this moment
 
 @param fenceSet A set of all fences that are being dwelled inside of
 */
-(void) dwellingInsideFences: (NSMutableSet*_Nonnull) fenceSet;

/**
 Provides notice of fences that have rules or contitions that are in conflict with eachother
 
@param fenceSet A set of fences that have conflicting rules
*/
-(void) conflictFences: (NSMutableSet*_Nonnull) fenceSet;


@optional
/**
 Provides notice that fences in the COI (cell of interest) were received from the Fence Delivery Network

@param fenceCount Count of fences received from Fence Delivery Network
@param fenceDictionary Dictionary of all fences recieved with fence ID as a key and a Fence object as it's value
*/
-(void) newAmbientFences: (NSNumber*_Nonnull) fenceCount fenceDictionary: (NSDictionary*_Nonnull) fenceDictionary;

-(void) removedAmbientFences: (NSNumber*_Nonnull) fenceCount fenceDictionary: (NSDictionary*_Nonnull) fenceDictionary;

/**
 Provides an evasive thrust vector to avoid breach of an approaching fence edge. This is x, y, z in a local reference frame.

 @param x x axis
 @param y y axis
 @param z z axis
 @param meters distance of thrust vector
 */
- (void) executeEvasiveThrustWithX: (float) x y: (float) y z: (float) z meters: (float) meters;

/**
 Provides an evasive thrust vector to avoid breach of an approaching fence edge in a local frame

  @warning  UNIMPLEMENTED!
 
 @param heading thrust heading in degrees
 @param meters distance of thrust vector
 @param z z axis (altitiude)
 @param magnetic use magnetic north if YES rather than the default of true north
 */
- (void) executeEvasiveThrustWithHeadingInLocalFrame: (float) heading meters: (float) meters z: (float) z magnetic: (Boolean) magnetic;

/**
 Provides an evasive thrust vector to avoid breach of an approaching fence edge in a global frame

  @warning  UNIMPLEMENTED!
 
 @param heading thrust heading in degrees
 @param meters distance of thrust vector
 @param z z axis (altitiude)
 @param magnetic use magnetic north if YES rather than the default of true north
 */
- (void) executeEvasiveThrustWithHeadingInGlobalFrame: (float) heading meters: (float) meters z: (float) z magnetic: (Boolean) magnetic;

@end

//forward refs
@class BreachPredictor;
@class FencingAgentService;

/**
 An instance of FencingAgent should be included in any classes or view controllers that you would like to receive notice through delegate methods of fences and entitlements that your devices and apps are interacting with. Each instance of FencingAgent will register and unregister itself with the singlton FencingAgentService in your AppDelgate during it's lifecycle.
 */
@interface FencingAgent : NSObject

/**
 An instance of the BreachPredictor if present. A Breach Predictor will exist if this FencingAgent's FencingAgentConfiguration has the detectApproching property set to YES.
 */
@property (nonatomic, strong) BreachPredictor* _Nonnull breachPredictor;

/**
 The FencingAgentDelegate that owns this instance of FencingAgent
 */
@property (nonatomic, assign) id <FencingAgentDelegate> _Nonnull delegate;
//@property (nonatomic,strong) NSOperationQueue* queue;

/**
 A dictionary of location properties from CoreLocaiton or the FencingAgent's external source of location (vehicle)
 */
@property (nonatomic, strong)  NSMutableDictionary* _Nonnull locDictionary;

/**
 The FencingAgentConfiguration that was used to initialize this instance of FencingAgent.
 */
@property (nonatomic, strong) FencingAgentConfig* _Nonnull agentConfig;

/**
 This appears to be a redundant property.
 
 @warnig This will most likely be deprectated in favor of ambient fence count.
 */
@property (nonatomic, strong) NSNumber* _Nonnull lastFenceCount;

/**
 FencingAgent longitude
 */
@property (nonatomic) double agentLong;

/**
 FencingAgent latitude
 */
@property (nonatomic) double agentLat;

/**
 FencingAgent altitude
 */
@property (nonatomic) double agentAlt;

/**
 FencingAgent heading
 */
@property (nonatomic) double agentHeading;

/**
 FencingAgent course
 */
@property (nonatomic) double agentCourse;

/**
 FencingAgent speed
 */
@property (nonatomic) double agentSpeed;



/**
 An NSSet of fences in the area (Region of Interest)
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull outsideFenceSet;

/**
 An NSSet of fences that this FencingAgent is currently dwelling inside of
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull insideFenceSet;/**
 An NSSet of fences that this FencingAgent has entered, but is not yet dwelling in
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull dwellingFenceSet;

@property (nonatomic, strong) NSMutableSet* _Nonnull leftFenceSet;

/**
 An NSSet of fences that this FencingAgent is currently approaching.
 
 @warning this set will always be empy unless the FencingAgentConfiguration for this FencingAgent has it's detectApproaching property set to YES.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull approachingFenceSet;


/**
 An NSSet of SmartFence that that have rules or conditions that are in conflict with the rules of another SmartFence.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull conflictFenceSet;

/**
  An NSSet of fences that this FencingAgent is currently ranging to.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull rangingFenceSet;

/**
 An NSSet of fences that are currently in an inflation state.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull inflationFenceSet;

/**
 An NSSet of fences that are currently in a compliant state.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull compliantFenceSet;

/**
 An NSSet of fences to which entry is not allowed by this fencing agent.
  @discussion This state may change during the automatic compliance efforts of the fencing agent.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull noEntrytFenceSet;

/**
 An NSSet of fences to which exit is not allowed by this fencing agent.
 @discussion This state may change during the automatic compliance efforts of the fencing agent.
 */
@property (nonatomic, strong) NSMutableSet* _Nonnull noExitFenceSet;



@property (nonatomic) CLLocationCoordinate2D agentCoord;

/**
 The control panel ID (hex) which was used to initialize this instance.
 */
@property (nonatomic, strong) NSString* _Nonnull controlPanelId;


/**
 A dictionary of all ambient fences
 */
@property (nonatomic, strong) NSMutableDictionary* _Nonnull ambientFences;

/**
 PRIVATE PROPERTY IN FINAL RELEASE
 */
@property (nonatomic) double agentFakeSpeed;

/**
 The FencingAgentService that this instance if FencingAgent is registered to.
 */
@property (nonatomic, strong) FencingAgentService* _Nonnull service;

@property (nonatomic) CLLocationCoordinate2D probePoint;
@property (nonatomic, strong) GfClient* _Nonnull gfClient;
@property (nonatomic, strong) ComplianceDriver* _Nonnull complianceDriver;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull mapDictionary;

/**
 Register application states to be monitored for complance with rules provided by your control panel.
 */
- (void) registerCondition: (NSString*_Nonnull) propertyName withPath: (NSString*_Nonnull) path onObject: (id _Nonnull ) object atRate: (double) seconds;
/**
 Register handler for conditional logic expressions expressed by users of your control panel with a polling rate in milliseconds.
 */
- (void) registerCondition: (NSString*_Nonnull) propertyName withPath: (NSString*_Nonnull) path onObject: (id _Nonnull ) object;

/**
 Register handler for conditional logic expressions expressed by users of your control panel.
 */
- (void) registerAction: (NSString*_Nonnull) methodName withPath: (NSString*_Nonnull) path onObject: (id _Nonnull ) object;
- (void) processStates;
- (void) processCommands;
/**
 Creates a new instance of FencingAgent from an instance of the configuration class "FencingAgentConfiguration"

 @param profile A FencingAgentConfiguration which specifies the configuration properties for a FencingAgent.
 @param controlPanel The Control Panel Id for your Application or Device. (Found in the web portal during control panel creation)
 @return The new instance of FencingAgent. Be sure to set the delegate property of your new instance to your own <FencingAgentDelegate> class.
 */
- (id _Nonnull )initWithConfig:(FencingAgentConfig*_Nullable) profile;

/**
 Invokes "- (void) executeEvasiveThrustWithX: (float) x y: (float) y z: (float) z meters: (float) meters" in the FencingAgentDelegate protocol.

 @warning  This is a private API and is not intended for final public release
 */
- (void) informDelegateEvasiveThrustRequiredWithX: (float) x y: (float) y z: (float) z meters: (float) meters;

- (void) dataBaseWarmupPeriod: (NSTimer*_Nullable) timer;

- (NSMutableArray*_Nonnull) recordPartsForGfPointArray: (NSMutableArray*_Nonnull) gfPoints;


/**
 Indicates wheter or not a point is contained within a fence bounds in 2D.
 
 @param point The point to test
 @param fence A Fence instance
 @param fa Only search for fences owned by the given FencingAgent
 @return YES indicates that the point is inside of a fence.
 */

- (void) fetchAnchorpointsAllDomains;
- (void) smartFenceMapColdStart:(NSTimer*_Nullable)timer;
- (void) mapColdStart:(NSTimer*_Nullable)timer;
- (void) informDelegateOfRemovedAmbientFences: (NSDictionary*_Nullable) fenceDic;
- (void) informDelegateOfNewAmbientFences;
- (void) activateRulespaceForFenceNotification:(NSNotification*_Nonnull) n;
- (void) deactivateRulespaceForFenceNotification:(NSNotification*_Nonnull) n;

- (void) rangeMonitor: (NSTimer*_Nullable)timer;
- (void) addFenceToApproachingSet: (SmartFence*_Nonnull) fence;
- (void) removeFenceFromApproachingSet: (SmartFence*_Nonnull) fence;

NS_ASSUME_NONNULL_BEGIN
- (MapType*) getMapWithName: (NSString*) domainName;
- (LegendType*) getLegendWithName: (NSString*) domainName;
- (NameSpaceType*) getNameSpaceWithName: (NSString*) domainName;
NS_ASSUME_NONNULL_END

@end




