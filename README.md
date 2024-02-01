# Overview

This is a Java demo project using JNI (Java Native Interface), 
    which invokes native C code through Java code and outputs "Hello from C!".

# How to build from source

## Requirements
- Java Development Kit (e.g. OpenJDK)
- C++ compiler (e.g. gcc(for Linux), MinGW(for Windows))

## 1. Install MinGW-w64 on Windows (Skip the step if your Windows already have MinGW installed)

If your Windows doesn't have MinGW installed, 
    you can follow the steps below to install MinGW-w64 in PowerShell (run as an administrator). 

### 1). Run the command below to install Chocolatey:
```bash
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```

### 2). Run the following command to install MinGW-w64:
```bash
choco install mingw -y
```

### 3). Restart the Powershell, and run the following command to check if the installation is successful:
```bash
gcc --version
```
If the powershell prints a MinGW-w64 version output, then we are done.

## 2. Compile Java source file and generate a JNI header file:
```
cd C:\ideaprojects\janwee-sha\simple-jni-app\
javac -h .\src\cpp src\top\janweehisa\Greeting.java
```

## 3. 运行如下命令，编译本地代码，在Windows中生成C++代码的动态链接库：
```bash
# 编译 C++ 本地代码生成本地库
g++ -shared -o Greeting.dll -I $env:JAVA_HOME\include -I $env:JAVA_HOME\include\win32 src\cpp\Greeting.cpp

# 编译 Java 代码生成类文件
javac src\top\janweehsia\Greeting.java
```

## 4. 打包为 JAR 文件：

```bash
jar cf QtJambiDemo.jar -C build .
```

# How to use JNIExample

```bash
java -jar QtJambiDemo.jar
```