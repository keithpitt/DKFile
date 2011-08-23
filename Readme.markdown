# DKFile

`DKFile` is a wrapper around NSFileManager that provides an easier syntax for working with files.

It is used in the apps written by [Mostly Disco](http://www.mostlydisco.com) and [The Frontier Group](http://www.thefrontiergroup.com.au)

## Installation

Copy `DKFile.h` and `DKFile.m` into to your project folder, and add them to your Xcode project.

If you also want to use the `jsonFromBundle:pathForResource:` method, you'll also need to include the `JSON` library found in the External folder.

## Usage

For more documentation, visit http://keithpitt.github.com/DKFile

### Creating a DKFile from a file from a bundle

    // Passing nil uses [NSBundle mainBundle]
    DKFile * file = [DKFile fileFromBundle:nil pathForResource:@"SomeFile" ofType:@"png"];

### Creating a DKFile from a file in the Documents folder

    DKFile * file = [DKFile fileFromDocuments:@"SomeFile.png"];

### Creating a DKFile from a file using a specific path

    // Passing nil uses [NSBundle mainBundle]
    DKFile * file = [[DKFile alloc] initWithPath:@"some/random/path.txt"];

### Writing an NSImage to the file system

    // Create in instance of DKFile
    DKFile * file = [DKFile fileFromDocuments:@"SomeFile.jpg"];

    // Load an image from the bundle
    NSImage * someImage = [UIImage imageNamed:@"SomeImage"];

    // Turn the image into data with a compression of 90%
    NSData * imageData = UIImageJPEGRepresentation(someImage, 0.9);

    NSError * error = nil;

    if ([file writeData:imageData error:&error])
      NSLog(@"File save success!");
    else
      NSLog(@"%@", [error localizedDescription]);

### Loading JSON from the file system

    // Will read and parse Users.json from [NSBundle mainBundle]
    NSDictionary * json = [DKFile jsonFromBundle:nil pathForResource:@"Users"];

### File contents (for text files)

    DKFile * file = [[DKFile alloc] initWithPath:@"some/random/path.txt"];

    NSLog("Contents of: %@, %@", file.path, [file contents]);

### File existance

    DKFile * file = [[DKFile alloc] initWithPath:@"some/random/path.txt"];

    if ([file exists]) {
        NSLog(@"File exists");
    } else {
        NSLog(@"File DOES NOT exist");
    }

### File attributes

    DKFile * file = [[DKFile alloc] initWithPath:@"some/random/path.txt"];

    NSLog("File size: %i", [file size]);
    NSLog("File modification date: %@", [file lastModificationDate]);
    NSLog("File age: %i", [file age]);

## Running Specs

To run the specs, open [DKFile.xcodeproj](https://github.com/keithpitt/DKFile/tree/master/DKFile.xcodeproj) project, and run the `Specs` target.

## Documentation

To build the documentation, just run `rake` in the root of the project. You will need [appledoc](http://www.gentlebytes.com/home/appledocapp/) installed, and an environment variable `APPLEDOC_TEMPLATE_PATH` set pointing to the path of your appledoc templates.

## Libraries Used

* http://code.google.com/p/json-framework
* https://github.com/petejkim/expecta
* https://github.com/pivotal/cedar

## Note on Patches/Pull Requests

* Fork the project.
* Make your feature addition or bug fix.
* Send me a pull request. Bonus points for topic branches.

## Contributers

* [Keith Pitt](http://www.keithpitt.com)

## License

DKFile is licensed under the MIT License:

  Copyright (c) 2011 Keith Pitt (http://www.keithpitt.com/)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
