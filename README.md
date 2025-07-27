# Arduino.hpp
A single include Library to implement many known functions from the [Arduino](https://www.arduino.cc) framework.

> [!NOTE]
> This Project is still WIP, right now not very much is implemented.

## Usage
Just place the `Arduino.hpp` file anywhere in your C++ include path, `#include "Arduino.hpp"` and use Arduino functions such as `millis()` or `delay()`.<br>
### Example:
To not interfere with other libraries or builtin functions, everything is put into an `Arduino` namespace, so you could either use:
```cpp 
#include <iostream>
#include "Arduino.h"

using namespace Arduino;

int main(){
    delay(500);
    std::cout << "Program running since " << millis() << "ms!" << std::endl;

    return 0;
}

// Output:
// Program running since 500ms!
```
or
```cpp
#include <iostream>
#include "Arduino.h"

int main(){
    Arduino::delay(500);
    std::cout << "Program running since " << Arduino::millis() << "ms!" << std::endl;

    return 0;
}

//Output:
// Program running since 500ms!
```
### Even more arduino-like example:
Also you could simply use `#define USE_ARDUINO_MAIN` somewhere in your files and simply implement the `void setup()` and `void loop()` functions as seen below.<br>
But remember that you will need to link against a compiled version of `Arduino.cpp`.
```Arduino
#define USE_ARDUINO_MAIN

using namespace Arduino;

void setup(){
    delay(1000);
}

void loop(){
    Serial.println(millis());
    delay(100);
}

// Output:
// 1000
// 1100
// 1200
// ...
```
To compile and build everything needed, you could also use either the `Makefile` or the `CMakeLists.txt`.<br><br>
To use the `Makefile`, simply edit the top part of the `Makefile` and run `make` in the main project directory.<br><br>
To use the `CMakeLists.txt`, simply edit the marked part of the `CMakeLists.txt` and run
```bash
mkdir build && cd build && cmake .. && cmake --build .
```
inside the main project directory.