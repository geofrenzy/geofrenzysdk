//
//  SwitchComplianceUnit.h
//  GeoFrenzy
//
//  Created by Ben Tally on 10/2/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <GeoFrenzy/GeoFrenzy.h>
#import "ComplianceUnit.h"

@class ComplianceUnit;

NS_ASSUME_NONNULL_BEGIN

@interface SwitchComplianceUnit : ComplianceUnit <StatesAndCompliance>

- (instancetype)initWithKey:(NSString*) key withUnitType:(cuUnitType) unitType withRuleType: (cuRuleType) ruleType andRule: (RuleType*) rule;
- (void) setCurrentStateValue:(id _Nonnull) currentStateValue;
- (void) setCompianceForStateValue: (id) state;

@end

NS_ASSUME_NONNULL_END
