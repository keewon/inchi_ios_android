#!/bin/sh
lipo -create -output libinchi-static-ios.a Release-iphoneos/libinchi-static-ios.a Release-iphonesimulator/libinchi-static-ios.a
