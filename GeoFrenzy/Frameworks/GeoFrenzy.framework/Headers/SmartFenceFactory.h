//
//  SmartFenceFactory.h
//  
//
//  Created by Ben Tally on 9/14/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FencingAgent.h"
#import "SmartFence.h"
#import "FencingAgentSpeech.h"
#import "GfCoreObjc.h"

@class GfCoreObjc;

@interface SmartFenceFactory : NSObject
@property (nonatomic, strong) GfCoreObjc* gfCoreObjc;
@property (nonatomic, strong) FencingAgent* owningAgent;

- (void) enqueue: (SmartFenceType*) smartFencePb;
- (void) start;

@end
