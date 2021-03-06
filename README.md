VimR
====

Project VimR — Vim Refined

About
-----

Project VimR is an attempt to refine the Vim experience.

The very first goal is to get a naked Vim running using [MacVimFramework](https://github.com/qvacua/macvim). Once we have that, we'll start to add convenience GUI features similar to those present in modern editors for Mac. Let's see how far we get! :)

[![Build Status](https://travis-ci.org/qvacua/vimr.svg?branch=master)](https://travis-ci.org/qvacua/vimr)

![Screenshot](https://raw.github.com/qvacua/vimr/master/Meta/screenshot.png)

How to Build
------------
First, clone the submodules:

```
$ git submodule update --init
```

Then, build the `macvim` submodule: Assuming you're in the project root

```
$ cd macvim/src
$ ./configure --with-features=huge --enable-rubyinterp --enable-pythoninterp --enable-perlinterp --enable-cscope
$ make
```

We use [CocoaPods](http://cocoapods.org) to include other open source libraries, eg [OCHamcrest](https://github.com/hamcrest/OCHamcrest) and [TBCacao](https://github.com/qvacua/tbcacao). Thus, install CocoaPods and do the following in the project root

```
$ pod install
```

Then, either open the `VimR.xcworkspace` file and run the `VimR` scheme or do the following in the project root

```
$ xcodebuild -workspace VimR.xcworkspace -configuration Release -scheme VimR -derivedDataPath ./build clean build
```

In case you used the above `xcodebuild` command, the `VimR.app` will be in `build/Build/Products/Release`.

From time to time, we'll edit some files of `macvim` that are not registered in the `macvim/src/MacVim/MacVim.xcodeproj` file like `macvim/src/MacVim/MMBackend.m`. In this case we have to `make` `macvim` again, ie it does not suffice to recompile `VimR` (or `macvim/src/MacVim/MacVim.xcodeproj`).

Source Code License
-------------------

For now, the source code of VimR is licensed under GNU General Public License version 3 as published by the Free Software Foundation.
