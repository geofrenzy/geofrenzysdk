//
//  GfClientDnsPlugin.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/24/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GfClientPlugin.h"
#import <dns_sd.h>
//#import <resolv.h>

@interface GfClientDnsPlugin : GfClientPlugin
//@property DNSServiceRef serviceRef;
- (void) requestRecord: (NSString*) hostName withRecordType: (ResourceRecord_QueryType) recordType;


@end
