//
//  FencingAgentService.h
//  GeoNet
//
//  Created by Ben Tally on 11/20/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
//#import <dns_sd.h>
//#import <resolv.h>
#import "gfcorecpp.h"
#import "Smartfence.pbobjc.h"

#import "FencingAgentConfig.h"
#import "SmartFence.h"
#import "FencingAgent.h"
#import "FencingAgentSpeech.h"

@class FencingAgent;
@class SmartFence;
@class FencingAgentConfig;
@class FencingAgentSpeech;

/**
 The FencingAgentService provides services to multiple instances of the FencingAgent which may exist in your view controllers or other classes.
 The services provided include access to the GeoFrenzy FDN, offline servcies/caching, prefetching, location services and performance obptimizations
 */
@interface FencingAgentService : NSObject <CLLocationManagerDelegate>

@property NSNumber* _Nonnull roi;

//@property CLLocation *theLocation;

/**
 A class method to return the FencingAgentService singleton

 @return A shared instance of FencingAgentService
 */
+ (instancetype _Nonnull )sharedInstance;

//@property (nonatomic, assign) id <FencingAgentDelegate> delegate;
//@property (nonatomic,strong) NSOperationQueue* queue;

/**
 A dictionary of all ambient fences for all registered FencingAgents
 */
@property (nonatomic, strong) NSMutableDictionary* _Nonnull ambientFences;


//@property (nonatomic, strong) NSMutableSet* fencingAgents;
/**
 A single instance of Core Location Manager
 */
@property (nonatomic, strong) CLLocationManager * _Nonnull locationManager;

/**
 FencingAgentService Initializer
 
 @return An instance of the FencingAgentService
 */

@property (nonatomic, strong) dispatch_queue_t _Nonnull sharedSerialQueue;

@property (nonatomic, strong) MapType * _Nonnull smartFenceMap;

//@property (nonatomic, strong) LocalCache* localCache;

@property (nonatomic, strong) FencingAgentSpeech* _Nonnull faSpeech;

- (instancetype _Nonnull )init;


-(void) unRegisterFencingAgentWithService:(FencingAgent*_Nonnull) fa;
- (NSString*_Nonnull) currentLocationGfEncoded;

//
//
- (void)locationManager:(CLLocationManager *_Nonnull)manager didUpdateHeading:(CLHeading *_Nonnull)newHeading;

@end
