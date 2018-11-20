//
//  ComplianceDriver.h
//  GeoFrenzy
//
//  Created by Ben Tally on 10/3/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Utilities.h"

NS_ASSUME_NONNULL_BEGIN

@interface ComplianceDriver : NSObject


@property (nonatomic, strong) NSMutableSet* _Nonnull stateSdkObjectSet;
@property (nonatomic, strong) NSMutableSet* _Nonnull commandSdkObjectSet;

@property (nonatomic, strong) NSMutableArray* _Nonnull flatStateSdkPropertyNameArray;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatStateSdkPropertyGeoDomainArray;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatCommandSdkOperationNameArray;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatCommandSdkOperationGeoDomainArray;

@property (nonatomic, strong) NSMutableDictionary* _Nonnull stateSdkObjectsByPropertyDict;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull stateSdkObjectsByGeoDomainDict;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull commandSdkObjectsByOperationDict;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull commandSdkObjectsByGeoDomainDict;

@property (nonatomic, strong) NSMutableDictionary* _Nonnull previousStatesByPropertyDict;

@property (nonatomic, strong) NSMutableDictionary* _Nonnull currentStates;

@property (nonatomic, strong) NSMutableDictionary* _Nonnull complianceUnitByStateIndex;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull complianceUnitByCommandIndex;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull complianceUnitByGeoDomain;
@property (nonatomic, strong) NSMutableDictionary* _Nonnull allCompliance;

@property (nonatomic, strong) NSMutableArray* _Nonnull flatFdnStateNames;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatFdnStates;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatFdnCommandNames;
@property (nonatomic, strong) NSMutableArray* _Nonnull flatFdnAllNames;
@property (nonatomic) Boolean fdnNameSpaceIsInitialized;

- (NSString*_Nullable) propertyNameForGeodomain:(NSString*_Nonnull) propertyName;
- (NSString*_Nonnull) geoDomainForPropertyName:(NSString*_Nonnull) geoDomain;
- (NSString*_Nullable) operationNameForGeodomain:(NSString*_Nonnull) geoDomain;
- (NSString*_Nonnull) geoDomainForOperationName:(NSString*_Nonnull) operationName;


- (void) registerCondition: (NSString*) propertyName withPath: (NSString*) path onObject: (id) object;
- (void) registerCondition: (NSString*) propertyName withPath: (NSString*) path onObject: (id) object atRate: (double) seconds;
- (void) registerAction: (NSString*) methodName withPath: (NSString*) path onObject: (id) object;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
