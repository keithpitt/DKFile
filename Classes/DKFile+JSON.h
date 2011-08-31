//
//  JSON.h
//  DKFile
//
//  Created by Keith Pitt on 31/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "DKFile.h"

// Only include JSONKit if it exists...
#ifdef JSONKIT_VERSION_MAJOR
    #import "JSONKit.h"
#endif

@interface DKFile (JSON)

/** Shortcut method to read JSON from the file system
 
 @param bundle Bundle to use. Passing `nil` will make it default to `[NSBundle mainBundle]`
 @param path The path to the file (minus the extension). A "json" extension is assumed.
 @return Returns the JSON object
 */
+ (id)jsonFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path;

@end