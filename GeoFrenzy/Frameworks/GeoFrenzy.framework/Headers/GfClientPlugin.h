//
//  GfClientPlugin.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/24/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Smartfence.pbobjc.h"

@protocol GfClientDelegate <NSObject>
@required

@end

@class GfClient;

@interface GfClientPlugin : NSObject
@property (nonatomic, strong) GfClient* _Nonnull gfClient;
@property NSMutableSet* _Nullable resultQueue;
- (void) register;
- (void) unregister;
- (void) requestRecord: (NSString*_Nonnull) hostName withRecordType: (ResourceRecord_QueryType) recordType;
- (NSSet*_Nonnull) getRecentRecords;
@end
