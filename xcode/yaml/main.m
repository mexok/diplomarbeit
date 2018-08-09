//
//  main.m
//  yaml
//
//  Created by Konstantin Merker on 30.07.18.
//  Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#include "IAAppEntryPoint.h"
#include "MainApp.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        IAAppEntryPoint_setOnAppStart(MainApp_onAppStart);
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
