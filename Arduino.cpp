#ifdef USE_ARDUINO_MAIN
#include <Arduino.hpp>

void setup(), loop();

int main(){
	setup();
	while(true){loop();}
	return 0;
}

#endif
