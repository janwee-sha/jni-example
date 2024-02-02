# Overview

This is a Java demo project using JNI (Java Native Interface), 
    which invokes native C++ code through Java code and prints "Hello from C++ using JNI!".

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
g++ --version
```
If the powershell prints a MinGW-w64 version output, then we are done.

## 2. Compile Java source file and generate a JNI header file:

Switch to the project's root directory and run the following `javac` command:
```bash
javac -h .\src\cpp\ -d .\out\ .\src\top\janweehsia\Greeting.java
```

## 3. Compile C++ native code to generate a local library (on Windows a library is a DLL file):
```bash
g++ -shared -o sayhello.dll -I $env:JAVA_HOME\include -I $env:JAVA_HOME\include\win32 src\cpp\Greeting.cpp
```

## 4. Package to JAR file：

```bash
jar cfe JNIExample.jar top.janweehsia.Greeting -C out .
```

# How to use

## Requirements:
- Java Runtime Kit (e.g. OpenJRE)

## Command to run

```bash
java -jar JNIExample.jar
``` 
