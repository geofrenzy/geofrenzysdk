//
//  GfCodecObjc.h
//  GeoFrenzy
//
//  Created by Ben Tally on 5/23/18.
//  Copyright © 2018 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Smartfence.pbobjc.h"

@interface GfCodecObjc : NSObject


+ (NSString*) encode: (MessageType*) protoBufMessage;
+ (MessageType*) decode: (NSString*) z85EncodedString;

@end
