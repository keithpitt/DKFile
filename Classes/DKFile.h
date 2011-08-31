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

/** Initializes the class with the path provided
 
 The path doesn't need to exist - nor is the file read when the class is initialized.
 
 @param path Path to the file on the filesystem
 @return Returns initialized object.
 */
- (id)initWithPath:(NSString *)filePath;

///---------------------------------------------------------------------------------------
/// @name Writing to the file
///---------------------------------------------------------------------------------------

/** Writes the contents of NSData to the file
 
 @param data Data to write
 @param error If there is an error writing out the data, upon return contains an NSError object that describes the problem
 @return YES if the operation succeeds, otherwise NO.
 */
- (BOOL)writeData:(NSData *)data error:(NSError **)error;

///---------------------------------------------------------------------------------------
/// @name Deleting the file
///---------------------------------------------------------------------------------------

/** Delete the file from the filesystem
 
 @param error If there is an error writing out the data, upon return contains an NSError object that describes the problem
 @return YES if the operation succeeds, otherwise NO.
 */
- (BOOL)delete:(NSError **)error;

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