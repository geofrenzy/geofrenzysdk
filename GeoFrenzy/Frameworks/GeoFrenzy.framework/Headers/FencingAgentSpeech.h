//
//  FencingAgentSpeech.h
//  GeoNetDevTools
//
//  Created by Ben Tally on 3/11/17.
//  Copyright © 2017 GeoFrenzy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FencingAgentConfig.h"
@class FencingAgentConfig;


@import AVFoundation;

@interface FencingAgentSpeech : NSObject <AVSpeechSynthesizerDelegate>
@property (nonatomic, strong) FencingAgentConfig* config;
@property (readwrite, nonatomic, strong) AVSpeechSynthesizer *maleSpeechSynthesizer;
@property (readwrite, nonatomic, strong) AVSpeechSynthesizer *femaleSpeechSynthesizer;
- (void) maleSpeak:(NSString*) utteranceString andAllowInteruption: (Boolean) allowInteruption;
- (void) femaleSpeak:(NSString*) utteranceString andAllowInteruption:(Boolean) allowInteruption;
@end
