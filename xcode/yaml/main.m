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
