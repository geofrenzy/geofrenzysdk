// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: smartfence.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class BoundaryType;
@class CaseType;
@class ColorType;
@class GrantType;
@class IntervalType;
@class LegendType;
@class MapType;
@class NameSpaceType;
@class ProfileType;
@class ResourceRecord;
@class RuleType;
@class RuleValue;
@class SmartFenceType;
@class SwitchType;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum ResourceRecord_QueryType

typedef GPB_ENUM(ResourceRecord_QueryType) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  ResourceRecord_QueryType_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  ResourceRecord_QueryType_UnknownQuerytype = 0,
  ResourceRecord_QueryType_A = 1,
  ResourceRecord_QueryType_Aaaa = 2,
  ResourceRecord_QueryType_Cname = 3,
  ResourceRecord_QueryType_Ptr = 4,
  ResourceRecord_QueryType_Txt = 5,
  ResourceRecord_QueryType_Multi = 6,
};

GPBEnumDescriptor *ResourceRecord_QueryType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL ResourceRecord_QueryType_IsValidValue(int32_t value);

#pragma mark - Enum MessageType_MessageVariant

typedef GPB_ENUM(MessageType_MessageVariant) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  MessageType_MessageVariant_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  MessageType_MessageVariant_UnknownMessagevariant = 0,
  MessageType_MessageVariant_Legend = 1,
  MessageType_MessageVariant_Smartfence = 2,
  MessageType_MessageVariant_Boundary = 3,
  MessageType_MessageVariant_Namespace = 4,
  MessageType_MessageVariant_Map = 5,
};

GPBEnumDescriptor *MessageType_MessageVariant_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL MessageType_MessageVariant_IsValidValue(int32_t value);

#pragma mark - Enum RuleType_RuleVariant

typedef GPB_ENUM(RuleType_RuleVariant) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  RuleType_RuleVariant_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  RuleType_RuleVariant_UnknownRulevariant = 0,
  RuleType_RuleVariant_Switch = 1,
  RuleType_RuleVariant_Interval = 2,
  RuleType_RuleVariant_Profile = 3,
  RuleType_RuleVariant_Color = 4,
};

GPBEnumDescriptor *RuleType_RuleVariant_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL RuleType_RuleVariant_IsValidValue(int32_t value);

#pragma mark - Enum RuleValue_RuleVariant

typedef GPB_ENUM(RuleValue_RuleVariant) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  RuleValue_RuleVariant_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  RuleValue_RuleVariant_UnknownRulevariant = 0,
  RuleValue_RuleVariant_Switch = 1,
  RuleValue_RuleVariant_Interval = 2,
  RuleValue_RuleVariant_Profile = 3,
  RuleValue_RuleVariant_Color = 4,
};

GPBEnumDescriptor *RuleValue_RuleVariant_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL RuleValue_RuleVariant_IsValidValue(int32_t value);

#pragma mark - Enum GrantType_Grant

typedef GPB_ENUM(GrantType_Grant) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  GrantType_Grant_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  GrantType_Grant_UnknownGrant = 0,
  GrantType_Grant_Use = 1,
  GrantType_Grant_Aggregation = 2,
  GrantType_Grant_Delegation = 3,
  GrantType_Grant_Federation = 4,
  GrantType_Grant_Equivalency = 5,
  GrantType_Grant_Subscription = 6,
};

GPBEnumDescriptor *GrantType_Grant_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL GrantType_Grant_IsValidValue(int32_t value);

#pragma mark - Enum LegendType_Crs

typedef GPB_ENUM(LegendType_Crs) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  LegendType_Crs_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  LegendType_Crs_UnknownCrs = 0,
  LegendType_Crs_Wgs84 = 1,
  LegendType_Crs_Webmercator = 2,
};

GPBEnumDescriptor *LegendType_Crs_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL LegendType_Crs_IsValidValue(int32_t value);

#pragma mark - Enum LegendType_Topology

typedef GPB_ENUM(LegendType_Topology) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  LegendType_Topology_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  LegendType_Topology_UnknownTopology = 0,
  LegendType_Topology_Gf01 = 1,
};

GPBEnumDescriptor *LegendType_Topology_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL LegendType_Topology_IsValidValue(int32_t value);

#pragma mark - Enum LegendType_Units

typedef GPB_ENUM(LegendType_Units) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  LegendType_Units_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  LegendType_Units_UnknownUnits = 0,
  LegendType_Units_Si = 1,
  LegendType_Units_Usc = 2,
  LegendType_Units_Nist = 3,
};

GPBEnumDescriptor *LegendType_Units_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL LegendType_Units_IsValidValue(int32_t value);

#pragma mark - Enum LegendType_Zaxis

typedef GPB_ENUM(LegendType_Zaxis) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  LegendType_Zaxis_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  LegendType_Zaxis_UnknownZaxis = 0,
  LegendType_Zaxis_Agl = 1,
  LegendType_Zaxis_Msl = 2,
  LegendType_Zaxis_Gnss = 3,
  LegendType_Zaxis_Floor = 4,
};

GPBEnumDescriptor *LegendType_Zaxis_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL LegendType_Zaxis_IsValidValue(int32_t value);

#pragma mark - SmartfenceRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface SmartfenceRoot : GPBRootObject
@end

#pragma mark - SmartFenceType

typedef GPB_ENUM(SmartFenceType_FieldNumber) {
  SmartFenceType_FieldNumber_NameSpaceFqdnArray = 1,
  SmartFenceType_FieldNumber_BoundaryFqdn = 2,
  SmartFenceType_FieldNumber_LegendFqdn = 3,
  SmartFenceType_FieldNumber_RulesetArray = 4,
  SmartFenceType_FieldNumber_ConditionalCaseArray = 5,
  SmartFenceType_FieldNumber_Key = 6,
  SmartFenceType_FieldNumber_ControlPanelIndex = 7,
};

@interface SmartFenceType : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *nameSpaceFqdnArray;
/** The number of items in @c nameSpaceFqdnArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger nameSpaceFqdnArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *boundaryFqdn;

@property(nonatomic, readwrite, copy, null_resettable) NSString *legendFqdn;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<RuleType*> *rulesetArray;
/** The number of items in @c rulesetArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger rulesetArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<CaseType*> *conditionalCaseArray;
/** The number of items in @c conditionalCaseArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger conditionalCaseArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@property(nonatomic, readwrite) uint32_t controlPanelIndex;

@end

#pragma mark - MapType

typedef GPB_ENUM(MapType_FieldNumber) {
  MapType_FieldNumber_NameSpaceFqdnArray = 1,
  MapType_FieldNumber_LegendFqdn = 2,
  MapType_FieldNumber_RulesetArray = 3,
  MapType_FieldNumber_ConditionalCaseArray = 4,
  MapType_FieldNumber_Key = 5,
  MapType_FieldNumber_ControlPanelIndex = 6,
};

@interface MapType : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *nameSpaceFqdnArray;
/** The number of items in @c nameSpaceFqdnArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger nameSpaceFqdnArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *legendFqdn;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<RuleType*> *rulesetArray;
/** The number of items in @c rulesetArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger rulesetArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<CaseType*> *conditionalCaseArray;
/** The number of items in @c conditionalCaseArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger conditionalCaseArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@property(nonatomic, readwrite) uint32_t controlPanelIndex;

@end

#pragma mark - DnsCacheEntry

typedef GPB_ENUM(DnsCacheEntry_FieldNumber) {
  DnsCacheEntry_FieldNumber_Qname = 1,
  DnsCacheEntry_FieldNumber_RecordArray = 2,
  DnsCacheEntry_FieldNumber_QueriedRrExists = 3,
  DnsCacheEntry_FieldNumber_Key = 4,
};

@interface DnsCacheEntry : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *qname;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ResourceRecord*> *recordArray;
/** The number of items in @c recordArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger recordArray_Count;

@property(nonatomic, readwrite) BOOL queriedRrExists;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - ResourceRecord

typedef GPB_ENUM(ResourceRecord_FieldNumber) {
  ResourceRecord_FieldNumber_Qtype = 1,
  ResourceRecord_FieldNumber_Content = 2,
  ResourceRecord_FieldNumber_Ttl = 3,
  ResourceRecord_FieldNumber_Expires = 4,
  ResourceRecord_FieldNumber_Qname = 5,
  ResourceRecord_FieldNumber_MultiRecordArray = 6,
  ResourceRecord_FieldNumber_Key = 7,
};

@interface ResourceRecord : GPBMessage

@property(nonatomic, readwrite) ResourceRecord_QueryType qtype;

@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

@property(nonatomic, readwrite) double ttl;

@property(nonatomic, readwrite) double expires;

@property(nonatomic, readwrite, copy, null_resettable) NSString *qname;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ResourceRecord*> *multiRecordArray;
/** The number of items in @c multiRecordArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger multiRecordArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c ResourceRecord's @c qtype property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t ResourceRecord_Qtype_RawValue(ResourceRecord *message);
/**
 * Sets the raw value of an @c ResourceRecord's @c qtype property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetResourceRecord_Qtype_RawValue(ResourceRecord *message, int32_t value);

#pragma mark - MessageType

typedef GPB_ENUM(MessageType_FieldNumber) {
  MessageType_FieldNumber_MessageVariant = 1,
  MessageType_FieldNumber_Legend = 2,
  MessageType_FieldNumber_SmartFence = 3,
  MessageType_FieldNumber_Boundary = 4,
  MessageType_FieldNumber_NameSpace = 5,
  MessageType_FieldNumber_Map = 6,
  MessageType_FieldNumber_Key = 7,
};

@interface MessageType : GPBMessage

@property(nonatomic, readwrite) MessageType_MessageVariant messageVariant;

@property(nonatomic, readwrite, strong, null_resettable) LegendType *legend;
/** Test to see if @c legend has been set. */
@property(nonatomic, readwrite) BOOL hasLegend;

@property(nonatomic, readwrite, strong, null_resettable) SmartFenceType *smartFence;
/** Test to see if @c smartFence has been set. */
@property(nonatomic, readwrite) BOOL hasSmartFence;

@property(nonatomic, readwrite, strong, null_resettable) BoundaryType *boundary;
/** Test to see if @c boundary has been set. */
@property(nonatomic, readwrite) BOOL hasBoundary;

@property(nonatomic, readwrite, strong, null_resettable) NameSpaceType *nameSpace;
/** Test to see if @c nameSpace has been set. */
@property(nonatomic, readwrite) BOOL hasNameSpace;

@property(nonatomic, readwrite, strong, null_resettable) MapType *map;
/** Test to see if @c map has been set. */
@property(nonatomic, readwrite) BOOL hasMap;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c MessageType's @c messageVariant property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t MessageType_MessageVariant_RawValue(MessageType *message);
/**
 * Sets the raw value of an @c MessageType's @c messageVariant property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetMessageType_MessageVariant_RawValue(MessageType *message, int32_t value);

#pragma mark - RuleType

typedef GPB_ENUM(RuleType_FieldNumber) {
  RuleType_FieldNumber_RuleVariant = 1,
  RuleType_FieldNumber_StateNsIdx = 2,
  RuleType_FieldNumber_CommandNsIdx = 3,
  RuleType_FieldNumber_InteriorSwitch = 4,
  RuleType_FieldNumber_ExteriorSwitch = 5,
  RuleType_FieldNumber_InteriorInterval = 6,
  RuleType_FieldNumber_ExteriorInterval = 7,
  RuleType_FieldNumber_InteriorProfile = 8,
  RuleType_FieldNumber_ExteriorProfile = 9,
  RuleType_FieldNumber_InteriorColor = 10,
  RuleType_FieldNumber_ExteriorColor = 11,
  RuleType_FieldNumber_Key = 12,
};

@interface RuleType : GPBMessage

@property(nonatomic, readwrite) RuleType_RuleVariant ruleVariant;

@property(nonatomic, readwrite) int32_t stateNsIdx;

@property(nonatomic, readwrite) int32_t commandNsIdx;

@property(nonatomic, readwrite, strong, null_resettable) SwitchType *interiorSwitch;
/** Test to see if @c interiorSwitch has been set. */
@property(nonatomic, readwrite) BOOL hasInteriorSwitch;

@property(nonatomic, readwrite, strong, null_resettable) SwitchType *exteriorSwitch;
/** Test to see if @c exteriorSwitch has been set. */
@property(nonatomic, readwrite) BOOL hasExteriorSwitch;

@property(nonatomic, readwrite, strong, null_resettable) IntervalType *interiorInterval;
/** Test to see if @c interiorInterval has been set. */
@property(nonatomic, readwrite) BOOL hasInteriorInterval;

@property(nonatomic, readwrite, strong, null_resettable) IntervalType *exteriorInterval;
/** Test to see if @c exteriorInterval has been set. */
@property(nonatomic, readwrite) BOOL hasExteriorInterval;

@property(nonatomic, readwrite, strong, null_resettable) ProfileType *interiorProfile;
/** Test to see if @c interiorProfile has been set. */
@property(nonatomic, readwrite) BOOL hasInteriorProfile;

@property(nonatomic, readwrite, strong, null_resettable) ProfileType *exteriorProfile;
/** Test to see if @c exteriorProfile has been set. */
@property(nonatomic, readwrite) BOOL hasExteriorProfile;

@property(nonatomic, readwrite, strong, null_resettable) ColorType *interiorColor;
/** Test to see if @c interiorColor has been set. */
@property(nonatomic, readwrite) BOOL hasInteriorColor;

@property(nonatomic, readwrite, strong, null_resettable) ColorType *exteriorColor;
/** Test to see if @c exteriorColor has been set. */
@property(nonatomic, readwrite) BOOL hasExteriorColor;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c RuleType's @c ruleVariant property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t RuleType_RuleVariant_RawValue(RuleType *message);
/**
 * Sets the raw value of an @c RuleType's @c ruleVariant property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetRuleType_RuleVariant_RawValue(RuleType *message, int32_t value);

#pragma mark - RuleValue

typedef GPB_ENUM(RuleValue_FieldNumber) {
  RuleValue_FieldNumber_RuleVariant = 1,
  RuleValue_FieldNumber_InteriorSwitchValue = 2,
  RuleValue_FieldNumber_ExteriorSwitchValue = 3,
  RuleValue_FieldNumber_InteriorIntervalValue = 4,
  RuleValue_FieldNumber_ExteriorIntervalValue = 5,
  RuleValue_FieldNumber_InteriorProfileValue = 6,
  RuleValue_FieldNumber_ExteriorProfileValue = 7,
  RuleValue_FieldNumber_InteriorColorValue = 8,
  RuleValue_FieldNumber_ExteriorColorValue = 9,
  RuleValue_FieldNumber_Key = 10,
};

@interface RuleValue : GPBMessage

@property(nonatomic, readwrite) RuleValue_RuleVariant ruleVariant;

@property(nonatomic, readwrite) BOOL interiorSwitchValue;

@property(nonatomic, readwrite) BOOL exteriorSwitchValue;

@property(nonatomic, readwrite) double interiorIntervalValue;

@property(nonatomic, readwrite) double exteriorIntervalValue;

@property(nonatomic, readwrite, copy, null_resettable) NSString *interiorProfileValue;

@property(nonatomic, readwrite, copy, null_resettable) NSString *exteriorProfileValue;

@property(nonatomic, readwrite) uint32_t interiorColorValue;

@property(nonatomic, readwrite) uint32_t exteriorColorValue;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c RuleValue's @c ruleVariant property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t RuleValue_RuleVariant_RawValue(RuleValue *message);
/**
 * Sets the raw value of an @c RuleValue's @c ruleVariant property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetRuleValue_RuleVariant_RawValue(RuleValue *message, int32_t value);

#pragma mark - BoundaryType

typedef GPB_ENUM(BoundaryType_FieldNumber) {
  BoundaryType_FieldNumber_GfpointArray = 1,
  BoundaryType_FieldNumber_Key = 2,
};

@interface BoundaryType : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *gfpointArray;
/** The number of items in @c gfpointArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger gfpointArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - GrantType

typedef GPB_ENUM(GrantType_FieldNumber) {
  GrantType_FieldNumber_Grant = 1,
  GrantType_FieldNumber_Key = 2,
};

@interface GrantType : GPBMessage

@property(nonatomic, readwrite) GrantType_Grant grant;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c GrantType's @c grant property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t GrantType_Grant_RawValue(GrantType *message);
/**
 * Sets the raw value of an @c GrantType's @c grant property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetGrantType_Grant_RawValue(GrantType *message, int32_t value);

#pragma mark - LegendType

typedef GPB_ENUM(LegendType_FieldNumber) {
  LegendType_FieldNumber_AllowedGrantTypesArray = 1,
  LegendType_FieldNumber_Crs = 2,
  LegendType_FieldNumber_Ipv6Network = 3,
  LegendType_FieldNumber_Pcs = 4,
  LegendType_FieldNumber_PublicKey = 5,
  LegendType_FieldNumber_SpatialDimensions = 6,
  LegendType_FieldNumber_TilesetNamesArray = 7,
  LegendType_FieldNumber_Topology = 8,
  LegendType_FieldNumber_Units = 9,
  LegendType_FieldNumber_Zaxis = 10,
  LegendType_FieldNumber_Key = 11,
};

@interface LegendType : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<GrantType*> *allowedGrantTypesArray;
/** The number of items in @c allowedGrantTypesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger allowedGrantTypesArray_Count;

@property(nonatomic, readwrite) LegendType_Crs crs;

@property(nonatomic, readwrite, copy, null_resettable) NSString *ipv6Network;

@property(nonatomic, readwrite, copy, null_resettable) NSString *pcs;

@property(nonatomic, readwrite, copy, null_resettable) NSString *publicKey;

@property(nonatomic, readwrite) uint32_t spatialDimensions;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *tilesetNamesArray;
/** The number of items in @c tilesetNamesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger tilesetNamesArray_Count;

@property(nonatomic, readwrite) LegendType_Topology topology;

@property(nonatomic, readwrite) LegendType_Units units;

@property(nonatomic, readwrite) LegendType_Zaxis zaxis;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

/**
 * Fetches the raw value of a @c LegendType's @c crs property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t LegendType_Crs_RawValue(LegendType *message);
/**
 * Sets the raw value of an @c LegendType's @c crs property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetLegendType_Crs_RawValue(LegendType *message, int32_t value);

/**
 * Fetches the raw value of a @c LegendType's @c topology property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t LegendType_Topology_RawValue(LegendType *message);
/**
 * Sets the raw value of an @c LegendType's @c topology property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetLegendType_Topology_RawValue(LegendType *message, int32_t value);

/**
 * Fetches the raw value of a @c LegendType's @c units property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t LegendType_Units_RawValue(LegendType *message);
/**
 * Sets the raw value of an @c LegendType's @c units property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetLegendType_Units_RawValue(LegendType *message, int32_t value);

/**
 * Fetches the raw value of a @c LegendType's @c zaxis property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t LegendType_Zaxis_RawValue(LegendType *message);
/**
 * Sets the raw value of an @c LegendType's @c zaxis property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetLegendType_Zaxis_RawValue(LegendType *message, int32_t value);

#pragma mark - CaseType

typedef GPB_ENUM(CaseType_FieldNumber) {
  CaseType_FieldNumber_ComplianceTimeout = 1,
  CaseType_FieldNumber_Logic = 2,
  CaseType_FieldNumber_TargetCommand = 3,
  CaseType_FieldNumber_Met = 4,
  CaseType_FieldNumber_Notmet = 5,
  CaseType_FieldNumber_Timeout = 6,
  CaseType_FieldNumber_ComplianceConflict = 7,
  CaseType_FieldNumber_Key = 8,
};

@interface CaseType : GPBMessage

@property(nonatomic, readwrite) uint32_t complianceTimeout;

@property(nonatomic, readwrite, copy, null_resettable) NSString *logic;

@property(nonatomic, readwrite) uint32_t targetCommand;

@property(nonatomic, readwrite, strong, null_resettable) RuleValue *met;
/** Test to see if @c met has been set. */
@property(nonatomic, readwrite) BOOL hasMet;

@property(nonatomic, readwrite, strong, null_resettable) RuleValue *notmet;
/** Test to see if @c notmet has been set. */
@property(nonatomic, readwrite) BOOL hasNotmet;

@property(nonatomic, readwrite, strong, null_resettable) RuleValue *timeout;
/** Test to see if @c timeout has been set. */
@property(nonatomic, readwrite) BOOL hasTimeout;

@property(nonatomic, readwrite, strong, null_resettable) RuleValue *complianceConflict;
/** Test to see if @c complianceConflict has been set. */
@property(nonatomic, readwrite) BOOL hasComplianceConflict;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - ColorType

typedef GPB_ENUM(ColorType_FieldNumber) {
  ColorType_FieldNumber_Rgba = 1,
  ColorType_FieldNumber_Key = 2,
};

@interface ColorType : GPBMessage

@property(nonatomic, readwrite) int32_t rgba;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - ProfileType

typedef GPB_ENUM(ProfileType_FieldNumber) {
  ProfileType_FieldNumber_Name = 1,
  ProfileType_FieldNumber_Value = 2,
  ProfileType_FieldNumber_Key = 3,
};

@interface ProfileType : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

@property(nonatomic, readwrite, copy, null_resettable) NSString *value;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - IntervalType

typedef GPB_ENUM(IntervalType_FieldNumber) {
  IntervalType_FieldNumber_InitialState = 1,
  IntervalType_FieldNumber_StateChangesArray = 2,
  IntervalType_FieldNumber_Key = 3,
};

@interface IntervalType : GPBMessage

@property(nonatomic, readwrite) BOOL initialState;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleArray *stateChangesArray;
/** The number of items in @c stateChangesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger stateChangesArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

#pragma mark - SwitchType

typedef GPB_ENUM(SwitchType_FieldNumber) {
  SwitchType_FieldNumber_Value = 1,
};

@interface SwitchType : GPBMessage

@property(nonatomic, readwrite) BOOL value;

@end

#pragma mark - NameSpaceType

typedef GPB_ENUM(NameSpaceType_FieldNumber) {
  NameSpaceType_FieldNumber_StatesArray = 1,
  NameSpaceType_FieldNumber_CommandsArray = 2,
  NameSpaceType_FieldNumber_Key = 3,
};

@interface NameSpaceType : GPBMessage

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *statesArray;
/** The number of items in @c statesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger statesArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *commandsArray;
/** The number of items in @c commandsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger commandsArray_Count;

@property(nonatomic, readwrite, copy, null_resettable) NSString *key;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
