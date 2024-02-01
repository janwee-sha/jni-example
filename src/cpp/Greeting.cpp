// 文件路径：src/native/SimpleLibrary.cpp

#include <iostream>
#include "top_janweehisa_Greeting.h"

JNIEXPORT void JNICALL Java_com_example_QtJambiDemo_sayHello(JNIEnv *, jobject) {
    std::cout << "Hello from C++ using JNI!" << std::endl;
}