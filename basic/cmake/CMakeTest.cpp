/**
 * @Author: Yansea
 * @Date:   2024-04-19
 * @Last Modified by:   Yansea
 * @Last Modified time: 2024-04-19
 */

#include <iostream>
#include <string>
#include "CMakeTestConfig.h"

#ifdef USE_MYLIB
    #include "MyLib.h"
#endif

int main(int argc, char const *argv[])
{
    std::cout << "Version " << CMakeTest_VERSION_MAJOR << "." << CMakeTest_VERSION_MINOR
              << "." << CMakeTest_VERSION_PATCH << std::endl;
    std::cout << "Compile Time " << TIMESTAMP << std::endl;
    
    #ifdef USE_MYLIB
        PrintHelloWorld();
    #endif
    
    return 0;
}
