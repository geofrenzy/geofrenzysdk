//
//  Utilities.h
//  GeoNet
//
//  Created by Ben Tally on 11/20/16.
//  Copyright © 2016 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+Reverse.h"
#import "Smartfence.pbobjc.h"
#import "GfCodecObjc.hh"

@interface Utilities : NSObject

+ (NSString *)hexFromShort:(short)val;
+  (NSString *)hexFromByte:(Byte)val;
+ (NSString *)formatValue:(int)value forDigits:(int)zeros;
+ (NSString*) addColonsToStringEvery4chrsLeftToRight:(NSString*) aString;
+ (const char** ) getArray: (NSArray*) a_array;
+ (void)freeArray:(const char **)array;
+ (NSNumber*) labelCountFor: (NSString*) domainName;
+ (NSString*) reverseLabels: (NSString*) domainName;
+ (NSString*) replaceLabel: (NSString*) domainName withLabel: (NSString*) label atLevel: (NSNumber*) level;
+ (NSString*) insertLabel: (NSString*) label intoDomainName: (NSString*) domainName atLevel: (NSNumber*) level;
+ (NSString*) stripColons: (NSString*) stringWithColons;
+ (NSString*) getLabelFromDomain: (NSString*) domain atLevel: (NSNumber*) level;
+ (NSString*) getLastLabel: (NSString*) domain;
+ (NSString*) replaceLastLabel: (NSString*) domain withReplacement: (NSString*) replacement;
+ (NSString*) addLeadingDotIfNeeded: (NSString*) inputString;
+ (NSString*) addTrailingDotIfNeeded: (NSString*) inputString;
+ (NSString*) removeLeadingAndTrailingDotIfNeeded: (NSString*) inputString;
+ (NSString*) removeLeadingDotIfNeeded: (NSString*) inputString;
+ (NSString*) removeTrailingDotIfNeeded: (NSString*) inputString;
+ (NSString*) removeLabel: (NSString*) domain atLevel: (NSNumber*) level;
+ (double) kmDistanceForSpeed: (double) speed;
+(void) displayCourseVectorWithAgentLat: (double) agentLat andAgentLon: (double) agentLon andDestLat: (double) destLat destLon: (double) destLon;

+ (id) messageForResourceRecord: (ResourceRecord*) record;
+ (void) registerBackgroundTask;

char* MakeStringCopy (const char* string);
void runOnMainQueueWithoutDeadlocking(void (^block)(void));
UInt8* short_to_byteArr (short value);

@end
