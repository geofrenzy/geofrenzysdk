//
//  GfAnchorPointClient.h
//  GeoFrenzy
//
//  Created by Ben Tally on 7/17/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface GfAnchorPointClient : NSObject

//@property (nonatomic, strong) AFHTTPSessionManager *manager;
@property (nonatomic, strong) NSMutableDictionary *anchorPointDict;
@property (nonatomic, strong) NSString* baseUrl;
//- (void) newBaseUrl: (NSNotification*) n;
- (void) fetchAnchorPointsForGeoDomain: (NSString*) geoDomain andCpIdx: (NSString*) cpIdx;
- (NSArray*) getAnchorPointsForGeoDomain: (NSString*) geoDomain andCpIdx: (NSString*) cpIdx;
- (NSArray*) getAllAnchorPoints;
- (void) removeAnchorPointsForGeoDomain: (NSString*) geoDomain andCpIdx: (NSString*) cpIdx;
@end
