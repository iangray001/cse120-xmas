/**
 * Bluetooth test code
 * Echo USB serial onto pins 0 and 1, and vice versa (for AT commands), or print test
 * See datasheet for commands
 * http://elecfreaks.com/store/download/datasheet/Bluetooth/HC-0305%20serail%20module%20AT%20commamd%20set%20201104%20revised.pdf
 */

const int ledPin = 13;   // Teensy has LED on 11, Teensy++ on 6
char input;


void setup() {
	pinMode(ledPin, OUTPUT);

	// Delay on start in case we want to enter AT mode (hold button)
	digitalWrite(ledPin, HIGH);
	delay(5000);
	digitalWrite(ledPin, LOW);

	// Start both serial ports (USB and Bluetooth)
	Serial.begin(115200);
	Serial1.begin(115200); // Default is 9600, or 38400 for AT mode
}


void loop() {

	// Link UARTs for entering AT commands (both echo to USB, USB echoes to Bluetooth)
	
	// while (Serial1.available()) {
	// 	input = Serial1.read();
	// 	Serial.print(input);
	// }

	// while (Serial.available()) {
	// 	input = Serial.read();
	// 	// Add missing \n on return
	// 	if (input == '\r') {
	// 		Serial.print("\r\n");
	// 		Serial1.print("\r\n");
	// 	}
	// 	else {
	// 		Serial.print(input);
	// 		Serial1.print(input);
	// 	}
	// }


	///////////////////////////////////


	// Link USB and Bluetooth UARTs completely (with line feed correction)
	
	while (Serial1.available()) {
		input = Serial1.read();
		// Add missing \n on return
		if (input == '\r') {
			Serial.print("\r\n");
			Serial1.print("\r\n");
		}
		else {
			Serial.print(input);
			Serial1.print(input);
		}
	}

	while (Serial.available()) {
		input = Serial.read();
		// Add missing \n on return
		if (input == '\r') {
			Serial.print("\r\n");
			Serial1.print("\r\n");
		}
		else {
			Serial.print(input);
			Serial1.print(input);
		}
	}
	

	///////////////////////////////////


	// Echo 'Test' onto USB and Bluetooth serial

	// digitalWrite(ledPin, HIGH);
	// delay(50);

	// digitalWrite(ledPin, LOW);
	// delay(1950);

	// Serial.println("Test\r\n");
	// Serial1.println("Test\r\n");
}
