//
//  JSON.m
//  DKFile
//
//  Created by Keith Pitt on 31/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "DKFile+JSON.h"

@implementation DKFile (JSON)

+ (id)jsonFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path {
    
    DKFile * file = [self fileFromBundle:bundle pathForResource:path ofType:@"json"];
    
    return [[file contents] performSelector:@selector(objectFromJSONString)];
    
}

@end