//
//  DKFileSpec.m
//  DiscoKit
//
//  Created by Keith Pitt on 21/06/11.
//  Copyright 2011 Mostly Disco. All rights reserved.
//

#import "SpecHelper.h"

#import "DKFile.h"

SPEC_BEGIN(DKFileSpec)

context(@"+ (id)fileFromDocuments:", ^{
    
    it(@"should create a file with a path located in the documents directory", ^{
        
        DKFile * file = [DKFile fileFromDocuments:@"Something.txt"];
        
        expect([file.path hasSuffix:@"Documents/Something.txt"]).toBeTruthy();
        
    });
    
});

context(@"+ (id)fileFromBundle:pathForResource:ofType:", ^{
    
    it(@"should create a file with a path from the bundle", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"stevejobs" ofType:@"png"];
        
        expect([file.path hasSuffix:@"Specs.app/stevejobs.png"]).toBeTruthy();
        
    });
    
});

context(@"+ (id)jsonFromBundle:pathForResource:", ^{
    
    it(@"should load a JSON object from a file", ^{
        
        NSDictionary * json = [DKFile jsonFromBundle:nil pathForResource:@"JSON File"];
        
        expect([json valueForKey:@"foo"]).toEqual(@"bar");
        
    });
    
});

context(@"- (id)initWithPath:", ^{
    
    it(@"should create a DKFile with the specified path", ^{
       
        DKFile * file = [[DKFile alloc] initWithPath:@"some/path"];
        
        expect(file.path).toEqual(@"some/path");
        
        [file release];
        
    });
    
});

context(@"- (NSString *)contents", ^{
    
    it(@"should read the contents of the file", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"README" ofType:@"txt"];
        
        expect([file contents]).toEqual(@"Don't read me.");
        
    });
    
});

context(@"- (BOOL)exists", ^{
    
    it(@"should return TRUE if the file exists", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"README" ofType:@"txt"];
        
        expect([file exists]).toBeTruthy();
        
    });
    
    it(@"should return FALSE if it does not exist", ^{

        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"IDontExist" ofType:@"txt"];
        
        expect([file exists]).toBeFalsy();
        
    });
    
});

context(@"- (NSInteger)size", ^{
    
    it(@"should return the correct file size as an integer", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"stevejobs" ofType:@"png"];
        
        expect([file size]).toEqual(161032);
        
    });
    
});

context(@"- (NSDate *)lastModificationDate", ^{
    
    it(@"should return the correct modification date", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"stevejobs" ofType:@"png"];
        
        expect([[file lastModificationDate] description]).toEqual(@"2011-08-19 03:56:48 +0000");
        
    });
    
});

context(@"- (NSTimeInterval)age", ^{
    
    // Not sure how to test this one...
    
    it(@"should return the correct age", ^{
        
        DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"stevejobs" ofType:@"png"];
        
        expect([file age]).Not.toBeNil();
        
    });
    
});

SPEC_END