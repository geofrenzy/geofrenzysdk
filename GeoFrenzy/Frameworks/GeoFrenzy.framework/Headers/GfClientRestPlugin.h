//
//  GfClientRestPlugin.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/29/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import "GfClientPlugin.h"

//#import "FencingAgentConfiguration.h"

@interface GfClientRestPlugin : GfClientPlugin <NSURLSessionDelegate>
//@property (nonatomic, strong)  AFHTTPSessionManager *manager;
//@property (nonatomic, strong) FencingAgentConfiguration* config;
- (void) requestRecord: (NSString*) hostName withRecordType: (ResourceRecord_QueryType) recordType;
//- (void) fetchAnchorPoints: (NSString*) hostname withCpIdx: (NSString*) cpIdx;
@end
