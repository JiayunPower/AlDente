#include <arpa/inet.h>
#include <dlfcn.h>
#include <ifaddrs.h>
#include <objc/runtime.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#import <Foundation/Foundation.h>

extern NSString* log_prefix;

@interface LSApplicationProxy : NSObject
@property (nonatomic, readonly) NSString* bundleIdentifier;
@end

@interface LSApplicationWorkspace : NSObject
+ (instancetype)defaultWorkspace;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
@end


enum {
    SPAWN_FLAG_ROOT     = 1,
    SPAWN_FLAG_NOWAIT   = 2,
};
int spawn(NSArray* args, NSString** stdOut, NSString** stdErr, pid_t* pidPtr, int flag);

int platformize_me();
int set_memory_limit(int pid, int mb);
BOOL localPortOpen(int port);
NSString* getAppEXEPath();
void runAsDaemon(void(^Block)(), int flag=0);

#define STR(X) #X

#ifdef THEOS_PACKAGE_INSTALL_PREFIX
#define ROOTDIR STR(THEOS_PACKAGE_INSTALL_PREFIX)
#else
#define ROOTDIR
#endif
enum {
    JBTYPE_ROOTLESS     = 0,
    JBTYPE_ROOT         = 1,
    JBTYPE_TROLLSTORE   = 8,
};
int getJBType();

BOOL isAirEnable();
void setAirEnable(BOOL flag);
BOOL isBlueEnable();
void setBlueEnable(BOOL flag);
BOOL isLPMEnable();
void setLPMEnable(BOOL flag);
float getBrightness();
void setBrightness(float val);
