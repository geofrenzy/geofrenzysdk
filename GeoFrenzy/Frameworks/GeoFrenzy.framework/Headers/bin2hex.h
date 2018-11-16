//
//  bin2hex.h
//  bin2hex
//
//  Created by Ben Tally on 1/26/15.
//  Copyright (c) 2015 Priority Registration. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface bin2hex : NSObject

+ (NSString *)convertBin:(NSString *)bin;

+ (NSString *)convertBinToBaseFour:(NSString *)binaryString;

+ (NSString *)convertBinNew:(NSString *)binaryString;

+ (NSString *)convertHexToBin:(NSString *)binaryString;

@end

