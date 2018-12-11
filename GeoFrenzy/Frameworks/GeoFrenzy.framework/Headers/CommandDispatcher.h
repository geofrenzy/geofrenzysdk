//
//  CommandDispatcher.h
//  GeoFrenzy
//
//  Created by Ben Tally on 10/2/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ComplianceUnit;
@class FencingAgent;
@class SmartFenceMap;

NS_ASSUME_NONNULL_BEGIN

@interface CommandDispatcher : NSObject
@property (nonatomic, weak) ComplianceUnit *_Nullable owningComplianceUnit;
@property (nonatomic, strong) NSInvocation *_Nonnull invocation;

- (void) invokeMethodForCommand: (NSString*) geoDomain withArgument: (id _Nonnull) argument;

@end

NS_ASSUME_NONNULL_END
