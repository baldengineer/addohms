//exercise-pyramiduino.ino

const byte digitalPins[] = {2,3,4,5,6,7,8,9,10,11,12,13};
const byte analogPins[] = {A0,A1,A2,A3,A4,A5};

void setup() {
  // put your setup code here, to run once:
	for (int x=2; x<14; x++){
		pinMode(x, OUTPUT);
		digitalWrite(x, LOW);
	}
}

void loop() {
	digitalTest();
	//analogTest();
}

void analogTest() {
	for (int x=0; x < (sizeof(analogPins)/sizeof(analogPins[0])); x++) {
		digitalWrite(analogPins[x], HIGH);
		delay(10);
		digitalWrite(analogPins[x], LOW);
		delay(10);
	}
	delay(100);
}

void digitalTest() {
	for (int x=0; x < (sizeof(digitalPins)/sizeof(digitalPins[0])); x++) {
		digitalWrite(digitalPins[x], HIGH);
		delay(10);
		digitalWrite(digitalPins[x], LOW);
		delay(10);
	}
	delay(100);
}

void directPort() {
	// PORTD: D2-D7
	int output = 0x4;
	for (int x=0; x < 7; x++) {
		PORTD = output;
		output = output << 1;
		delayMicroseconds(5);
		PORTD = 0;
	}

	// PORTB: D8-D13
	output = 0x1;
	for (int x=0; x<9; x++) {
		PORTB = output;
		output = output << 1;
		delayMicroseconds(5);
		PORTB=0;
	}
}

/*

B0000 0100
D7654 3210

*/
