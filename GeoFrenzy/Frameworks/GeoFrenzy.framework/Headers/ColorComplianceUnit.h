//
//  ColorComplianceUnit.h
//  GeoFrenzy
//
//  Created by Ben Tally on 10/2/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <GeoFrenzy/GeoFrenzy.h>

#import "Compliance.h"

@class ComplianceUnit;


NS_ASSUME_NONNULL_BEGIN

@interface ColorComplianceUnit : ComplianceUnit <StatesAndCompliance>

@property (nonatomic, strong) UIColor* currentColor;

- (instancetype)initWithKey:(NSString*) key withUnitType:(cuUnitType) unitType withRuleType: (cuRuleType) ruleType andRule: (RuleType*) rule;
- (void) interiorRuleValue:(id _Nullable) interiorRuleValue;
- (void) setExteriorCommandArgument:(id _Nullable)exteriorRuleValue;

@end

NS_ASSUME_NONNULL_END
