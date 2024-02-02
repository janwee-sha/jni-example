#include <iostream>
#include "top_janweehsia_Greeting.h"

JNIEXPORT void JNICALL Java_top_janweehsia_Greeting_sayHello(JNIEnv *, jobject) {
    std::cout << "Hello from C++ using JNI!" << std::endl;
}