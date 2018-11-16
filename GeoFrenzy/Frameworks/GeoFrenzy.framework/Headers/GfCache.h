//
//  GfCache.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/23/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CouchbaseLite/CouchbaseLite.h>
#import "Smartfence.pbobjc.h"

@class GfClient;

@interface GfCache : NSObject

@property CBLDatabase *database;

/**
 A class method to return the GfCache singleton
 
 @return A shared instance of GfCache
 */
+ (instancetype)sharedInstance;
@property GfClient *owningClient;
@property NSTimer *ttlReaperTimer;

- (instancetype)init NS_UNAVAILABLE;
- (void) start;
- (void) upsertRecord: (ResourceRecord*) entry;
- (ResourceRecord*) fetchAllRecordsWithName: (NSString*) name;
- (ResourceRecord*) fetchRecordWithName: (NSString*) name andWithRRType: (ResourceRecord_QueryType) recordType;
- (void) ttlReaper: (NSTimer*) timer;
- (NSArray*) fetchAllRecordsOfRole: (NSString*) role andOfRecordVariant: (ResourceRecord_QueryType) recordVariant;
- (void) dropDatabase;
- (void) purgeCacheEntryForName: (NSString*) name andWithRRType: (ResourceRecord_QueryType) recordType;

@end
