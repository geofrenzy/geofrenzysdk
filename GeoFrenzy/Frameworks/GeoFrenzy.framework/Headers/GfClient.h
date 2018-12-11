//
//  GfClient.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/23/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GfCache.h"
#import "Smartfence.pbobjc.h"
#import "GfCodecObjc.hh"
#import "GfClientDnsPlugin.h"
#import "FencingAgent.h"
#import "GfAnchorPointClient.h"
#import "Utilities.h"

@class FencingAgent;
@class FencingAgentService;

@interface GfClient : NSObject

@property GfCache* _Nonnull cache;

//@property (nonatomic, strong) NSHashTable *plugins; //use NSHashTable in order to hold weak references
@property (nonatomic, strong) NSMutableSet * _Nonnull plugins;
//TODO: switch back to hashtable and tune the plugin lifecycle

@property (nonatomic, strong) FencingAgent * _Nonnull owningFencingAgent;
@property (nonatomic, strong) NSMutableDictionary * _Nonnull pendingRecords;
@property (nonatomic, strong) NSMutableDictionary * _Nonnull deadRecords;
@property (nonatomic, strong) GfAnchorPointClient * _Nonnull anchorPointClient;
@property (nonatomic,strong) NSMutableSet* _Nonnull additionalMultiRecords;
@property (nonatomic) int adjustedMultiRecordCount;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull customTtlDictionary;

- (instancetype _Nonnull )init;
-(void) registerPluginWithGfClient:(NSNotification*_Nonnull) n;
-(void) unRegisterPluginWithGfClient:(GfClientPlugin*_Nonnull) pi;

/**
 A class method to return the GfClient singleton
 
 @return A shared instance of GfClient
 */
+ (instancetype _Nonnull )sharedInstance;
- (id _Nonnull ) getMessageForName: (NSString*_Nonnull) name withMessageType: (MessageType_MessageVariant) messageType andWithNewTtl: (double) ttl;
- (id _Nonnull ) getMessageForName: (NSString*_Nonnull) name withMessageType: (MessageType_MessageVariant) messageType;
- (NSArray*_Nonnull) getHostsForPtr: (NSString*_Nonnull) name;
- (void) harvestRecordQueues;
- (void) requestRecordsWithAllPlugins: (NSString*_Nonnull) name withRecordType: (ResourceRecord_QueryType) recordType;
- (NSString*_Nonnull) stringForQtype: (ResourceRecord_QueryType) qtype;
- (ResourceRecord_QueryType) qtypeForString: (NSString*_Nonnull) string;
- (void) retryDeadRecords;
@end
