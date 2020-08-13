#include <dht.h>
#include <stdlib.h>

dht DHT;

// DHT use: https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
// Pin for temperature sensor (analog 0 as digital)
#define DHT11_PIN A0

// 4 digits 7 segment display use: https://theokelo.co.ke/how-to-get-your-hs420361k-32-4-digit-7-segment-display-working-with-an-arduino/
// assigning arduino digital pins for the various led display pins
int pinA = 3;
int pinB = 7;
int pinC = 12;
int pinD = 10;
int pinE = 9;
int pinF = 4;
int pinG = 13;
int pinDP = 11; // the decimal point pin
int D1 = 2;
int D2 = 5;
int D3 = 6;
int D4 = 8;


void setup()
{
	// initialise the digital pins as outputs.
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);
	pinMode(pinE, OUTPUT);
	pinMode(pinF, OUTPUT);
	pinMode(pinG, OUTPUT);
	pinMode(pinDP, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
}


int temp = 0;
int increment = 0;

void loop()
{
	
	if (increment % 1000 == 0) {
		int chk = DHT.read11(DHT11_PIN);
		if (chk == DHTLIB_OK) {
			temp = DHT.temperature;
		}

		increment = 0;
	}

	increment++;

	write_D1(); //function call to turn on D1 to write characters for the first digit
	if (temp < 0) { // Minus sign printing
		print_dash();
	}
	else {
		print_off();
	}
	delay(1);

	write_D2(); //function call to turn on D2 to write characters for the second digit
	print_digit(abs(temp) / 10 % 10); // Tens printing
	delay(1);

	write_D3(); //function call to turn on D3 to write characters for the third digit
	print_digit(abs(temp) % 10); // Units printing
	delay(1);

	write_D4(); //function call to turn on D4 to write characters for the fourth digit
	print_C(); // Celcuis "C" printing
	delay(1);
}

/* THE FUNCTIONS */


// Function printing given digit
void print_digit(int d) {
	switch (d) {
		case 0:
			print_0();
			break;
		case 1:
			print_1();
			break;
		case 2:
			print_2();
			break;
		case 3:
			print_3();
			break;
		case 4:
			print_4();
			break;
		case 5:
			print_5();
			break;
		case 6:
			print_6();
			break;
		case 7:
			print_7();
			break;
		case 8:
			print_8();
			break;
		case 9:
			print_9();
			break;
		default:
			print_off();

	}
}

// the functions for selecting the common pin to turn on
void write_D1()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, HIGH);
}

void write_D2()
{
	digitalWrite(D1, HIGH);
	digitalWrite(D2, LOW);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, HIGH);
}

void write_D3()
{
	digitalWrite(D1, HIGH);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, LOW);
	digitalWrite(D4, HIGH);
}

void write_D4()
{
	digitalWrite(D1, HIGH);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, LOW);
}

// the functions for writing characters to the display
void print_0() // writing 0
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW); // the decimal point is always off by default
}

void print_1() // writing 1
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_2() // writing 2
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_3() // writing 3
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_4() // writing 4
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_5() // writing 5
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_6() // writing 6
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_7() // writing 7
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_8() // writing 8
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_9() // writing 9
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_A() // writing A
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_b() // writing b
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_C() // writing C
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_d() // writing d
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_E() // writing E
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_F() // writing F
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_H() // writing H
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_h() // writing h
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_J() // writing J
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_L() // writing L
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_n() // writing n
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_O() // writing O
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_o() // writing o
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_P() // writing P
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_r() // writing r
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_t() // writing t
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_u() // writing u
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_y() // writing y
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_dash() // writing dash
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinDP, LOW);
}

void print_decimal() // writing the decimal point
{
	digitalWrite(pinDP, HIGH);
}

void print_OFF() // turning all 7 segments plus the decimal point off
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}

void print_off() // turning all 7 segments plus the decimal point off
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
	digitalWrite(pinDP, LOW);
}
