//
//  DKFile.h
//  DiscoKit
//
//  Created by Keith Pitt on 30/07/11.
//  Copyright 2011 Mostly Disco. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DKAPIFormData;

/** NSFileManager wrapper that makes it easy to work with files
 */
@interface DKFile : NSObject

/** Path to the file
 */
@property (nonatomic, retain) NSString * path;

///---------------------------------------------------------------------------------------
/// @name Creating a file
///---------------------------------------------------------------------------------------

/** Returns autoreleased instance of the class data with the document specified
 
 @param name The path to the file within the documents folder
 @return Returns initialized object.
 */
+ (id)fileFromDocuments:(NSString *)name;

/** Returns autoreleased instance of the class data with the file specified from the bundle
 
 @param bundle Bundle to use. Passing `nil` will make it default to `[NSBundle mainBundle]`
 @param path The path to the file (minus the extension)
 @param type The extension of the file
 @return Returns initialized object.
 */
+ (id)fileFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path ofType:(NSString *)type;

/** Shortcut method to read JSON from the file system
 
 @param bundle Bundle to use. Passing `nil` will make it default to `[NSBundle mainBundle]`
 @param path The path to the file (minus the extension). A "json" extension is assumed.
 @return Returns the JSON object
 */
+ (id)jsonFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path;

/** Initializes the class with the path provided
 
 The path doesn't need to exist - nor is the file read when the class is initialized.
 
 @param path Path to the file on the filesystem
 @return Returns initialized object.
 */
- (id)initWithPath:(NSString *)filePath;

///---------------------------------------------------------------------------------------
/// @name Information about the file
///---------------------------------------------------------------------------------------

/** File contents
 
 @return Returns the contents of the file
 */
- (NSString *)contents;

/** File existance
 
 @return Returns whether or not the file exists on the filesystem
 */
- (BOOL)exists;

/** File size
 
 @return Returns the size of the file on disk
 */
- (NSInteger)size;

/** File modification date
 
 @return Returns the date where the file was last modified
 */
- (NSDate *)lastModificationDate;

/** File age
 
 @return Returns the age of the file
 */
- (NSTimeInterval)age;

@end