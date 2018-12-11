//
//  JsonLogic.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/25/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@interface JsonLogic : NSObject

@property JSContext *context;

- (Boolean) evaluate: (NSString*) logic  withData: (NSString*) data;


@end
