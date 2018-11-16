//
//  Compliance.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/27/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ComplianceUnit.h"
#import "ColorComplianceUnit.h"
#import "ProfileComplianceUnit.h"
#import "IntervalComplianceUnit.h"
#import "SwitchComplianceUnit.h"
#import "ComplianceDriver.h"

@class ComplianceUnit;
@class ColorComplianceUnit;
@class ProfileComplianceUnit;
@class IntervalComplianceUnit;
@class SwitchComplianceUnit;

@class SmartFenceMap;
@class ComplianceUnit;



/**
 Compliance Class
 
 A Compliance instance is owned by the individual SmartFenceMaps;
 
 
 It maintains compliance with rulesets and conditions.
 
 
 IMPORTANT TO NOTE THAT EACH FENCING AGENT REGISTERS A SET OF STATES FOR MONITORING AND COMMAND HANDLERS
 This means that each fencing agent may be operating in it’s own geodomains.
 
 It is not required that objects provided to “registerdCommandHandler” are also delegates, but if not, the delegate must own the object provided.
 
 [_fa registerCommandHandler:@"willSpeakPerformanceReport" withPath:@"place.controls.geofrenzy.fenceexplorer.performancereportonexit" onObject:_motionFeatures];
 
 */
@interface Compliance : NSObject
@property (nonatomic, strong) NSMutableDictionary* _Nonnull namespaceParityDict;
@property (nonatomic, strong) ComplianceDriver* _Nullable complianceDriver;
@property (nonatomic) Boolean isInitialized;
@property (nonatomic, weak) SmartFenceMap* _Nullable owningMap;

@property (nonatomic, strong) NSDictionary* _Nonnull previousStates;
@property (nonatomic) Boolean isMonitoring;
@property Boolean isCompliant;

@property (nonatomic, strong) NSTimer* _Nonnull complianceTimer;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull commandsDict;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull rulesDict;

- (void) processCommands;
- (void) startMonitoringCompliance;
- (void) stopMonitoringCompliance;
- (instancetype _Nonnull)initWithMap: (SmartFenceMap*_Nonnull) smartFenceMap;
- (void) invokeCommandOnComplianceUnit: (id _Nonnull *_Nonnull) cu;
- (Boolean) complianceUnitIsCompliant: (id _Nonnull) cu;
- (ComplianceUnit*_Nonnull) complianceUnitFromRule: (RuleType*_Nonnull) rule;
- (NSString*_Nonnull) keyForRule: (RuleType*_Nonnull) rule;
- (void) addComplianceUnitForRule: (RuleType*) rule;
- (void) removeComplianceUnitForRule: (RuleType*) rule;

@end

