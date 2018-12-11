//
//  ComplianceUnit.h
//  GeoFrenzy
//
//  Created by Ben Tally on 6/29/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Utilities.h"
#import "PropertyTester.h"
#import "CommandDispatcher.h"
//#import "Smartfence.pbobjc.h"

@class Utilities;
@class Compliance;
@class SmartFenceMap;

@protocol StatesAndCompliance <NSObject>

@optional
- (void) setCurrentStateValue: (id _Nonnull) currentStateValue;
- (void) setCompianceForStateValue: (id _Nonnull) state;
@end

@interface ComplianceUnit : NSObject

typedef enum {
    Color,
    Profile,
    Switch,
    Interval
} cuRuleType;

typedef enum {
    State,
    Command,
    Hybrid
} cuUnitType;

@property (nonatomic) NSTimeInterval conditionalCaseStartTime;
//@property cuRuleType ruleType;
@property cuUnitType unitType;
@property (nonatomic, strong) CaseType* _Nonnull conditionalCase;
@property (nonatomic, strong) PropertyTester* _Nonnull propertyTester;
@property (nonatomic, strong) CommandDispatcher* _Nonnull commandDispatcher;
@property (nonatomic, strong) Compliance* _Nullable owningCompliance;
@property (nonatomic, strong) NSObject* _Nonnull registeredObject;
@property (nonatomic, strong) NSString* _Nonnull key;
@property (nonatomic, strong) NSString* _Nonnull label;
@property (nonatomic) int32_t flatNamespaceStateIndex;
@property (nonatomic) int32_t flatNamespaceCommandIndex;
@property (nonatomic) SEL _Nullable commandSelector;
@property (nonatomic) Boolean isCompliant;
@property (nonatomic, strong) id _Nullable lastCommandArgementSent;
@property (nonatomic, strong) id _Nullable interiorCommandArgument;
@property (nonatomic, strong) id _Nullable exteriorCommandArgument;
@property (nonatomic, strong) id _Nullable interiorRule;
@property (nonatomic, strong) id _Nullable exteriorRule;
@property (nonatomic, strong) id _Nullable ruleSpaceValue;
@property (nonatomic, strong) id _Nullable ruleSpaceCommandArgument;
@property (nonatomic, strong) id _Nullable ruleSpaceRule;
@property (nonatomic, strong) id _Nonnull currentStateValue;
@property (nonatomic, strong) id _Nullable goalValue;
@property (nonatomic) Boolean interiorFocus;
@property (nonatomic) cuRuleType ruleType;
@property (nonatomic, strong) RuleType* _Nonnull rule;
@property (nonatomic,strong) id _Nullable currentGoalValue;

//@property (nonatomic, strong) NSDictionary* _Nonnull currentStates;
//@property (nonatomic, strong) NSDictionary* _Nonnull previousStates;
//
//@property (nonatomic, strong) NSMutableArray* _Nonnull flatNamespace;
//@property (nonatomic, strong) NSMutableDictionary* _Nonnull commandsDict;
//@property (nonatomic, strong) NSMutableDictionary* _Nonnull rulesDict;

//- (instancetype _Nonnull)initWithFence: (SmartFence*_Nonnull) smartFence;

- (instancetype _Nonnull)initWithKey:(NSString *_Nonnull)key withUnitType:(cuUnitType)unitType withRuleType:(cuRuleType)ruleType andRule:(RuleType * _Nonnull)rule;
- (void) start;
- (void) stop;
- (void) setInteriorFocus:(Boolean)interiorFocus;
@end
