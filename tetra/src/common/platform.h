#include <stdio.h>

/**
 * Determination a platform of an operation system
 * Fully supported supported only GNU GCC/G++, partially on Clang/LLVM
 */

#if defined(__linux__)
    #define TT_PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #define TT_PLATFORM_MACOS
#elif defined(_WIN32)
    #define TT_PLATFORM_WINDOWS
#elif defined(_WIN64)
    #define TT_PLATFORM_WINDOWS
#else
    #error "unsupported platform"
#endif
