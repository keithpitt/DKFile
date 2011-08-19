//
//  DKFile.h
//  DiscoKit
//
//  Created by Keith Pitt on 30/07/11.
//  Copyright 2011 Mostly Disco. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DKFile : NSObject

@property (nonatomic, retain) NSString * path;

+ (id)fileFromDocuments:(NSString *)name;

+ (id)fileFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path ofType:(NSString *)type;

+ (id)jsonFromBundle:(NSBundle *)bundle pathForResource:(NSString *)path;

- (id)initWithPath:(NSString *)filePath;

- (NSString *)contents;

- (BOOL)exists;

- (NSInteger)size;

- (NSDate *)lastModificationDate;

- (NSTimeInterval)age;

@end