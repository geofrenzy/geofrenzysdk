//
//  ProfileComplianceUnit.h
//  GeoFrenzy
//
//  Created by Ben Tally on 10/2/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <GeoFrenzy/GeoFrenzy.h>
#import "ComplianceUnit.h"

@class ComplianceUnit;


NS_ASSUME_NONNULL_BEGIN

@interface ProfileComplianceUnit : ComplianceUnit <StatesAndCompliance>

- (instancetype)initWithKey:(NSString*) key withUnitType:(cuUnitType) unitType withRuleType: (cuRuleType) ruleType andRule: (RuleType*) rule;
- (void) interiorRuleValue:(id _Nullable) interiorRuleValue;
- (void) setExteriorCommandArgument:(id _Nullable)exteriorRuleValue;
- (id) goalForStateValue: (id) state;

@end

NS_ASSUME_NONNULL_END
