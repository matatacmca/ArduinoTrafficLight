int redLight = 3;
int orangeLight = 4;
int greenLight = 5;
int redTimer= 5;//Time in seconds
int orangeTimer = 2; // time in seconds
int greenTimer = 15; // time in seconds
int multiplier = 1000; // time multiplier to change to milliseconds

int redLight2 = 6;
int orangeLight2 = 7;
int greenLight2 = 8;
//int redTimer2= 17;//Time in seconds
int orangeTimer2 = 2; // time in seconds
int greenTimer2 = 8; // time in seconds
int input = 0;

 
void setup()
{ pinMode(redLight, OUTPUT);
  pinMode(orangeLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(redLight2, OUTPUT);
  pinMode(orangeLight2, OUTPUT);
  pinMode(greenLight2, OUTPUT);
  //pinMode(input, INPUT);
//Reset
	flash();
	digitalWrite(redLight, LOW);
	digitalWrite(greenLight, LOW);
	digitalWrite(orangeLight, LOW);
	digitalWrite(redLight2, LOW);
	digitalWrite(greenLight2, LOW);
	digitalWrite(orangeLight2, LOW);
	digitalWrite(redLight2, LOW);
 	Serial.begin(9600);
}

void loop()
{
	int phase = analogRead(input);
	Serial.println(phase);
	
	
	
	if (phase <= 511)
	{
		singlePhase();
	}
	else
	{
		twoPhase();
	}
	
}

void singlePhase()
{
	//Green Light
	digitalWrite(greenLight,HIGH);
	digitalWrite(greenLight2,HIGH);
	delay(greenTimer * multiplier);
	digitalWrite (greenLight, LOW);
	digitalWrite(greenLight2, LOW);

	//Orange Light
	digitalWrite (orangeLight,HIGH);
	digitalWrite (orangeLight2, HIGH);
	delay(orangeTimer * multiplier);
	digitalWrite(orangeLight, LOW);
	digitalWrite(orangeLight2,LOW);

	//RedLight
	digitalWrite(redLight, HIGH);
	digitalWrite(redLight2, HIGH);
	delay(redTimer * multiplier);
	digitalWrite (redLight, LOW);
	digitalWrite(redLight2,LOW);
	
}





 
void twoPhase()
{
 //Green Light
 	digitalWrite(redLight2, HIGH);
	digitalWrite(greenLight,HIGH);
	delay(greenTimer * multiplier);
	digitalWrite (greenLight, LOW);

	//Orange Light
	digitalWrite (orangeLight,HIGH);
	delay(orangeTimer * multiplier);
	digitalWrite(orangeLight, LOW);

	//RedLight
	digitalWrite(redLight, HIGH);
	delay (2000);
	digitalWrite(redLight2, LOW);
	digitalWrite(greenLight2, HIGH);
	delay(greenTimer2 * multiplier);
	digitalWrite(greenLight2, LOW);
	digitalWrite(orangeLight2, HIGH);
	delay(orangeTimer2 * multiplier);
	digitalWrite(orangeLight2, LOW);
	digitalWrite(redLight2, HIGH);
	delay(2000);
	digitalWrite (redLight, LOW);
	digitalWrite (redLight2,LOW);
	

}

void flash()
{
	int x;
	for (x=0;x<3;x++)
	{
		digitalWrite(redLight,HIGH);
		digitalWrite(redLight2, HIGH);
		digitalWrite(greenLight, HIGH);
		digitalWrite(greenLight2, HIGH);
		digitalWrite(orangeLight, HIGH);
		digitalWrite(orangeLight2, HIGH);
		delay(500);
		digitalWrite(redLight,LOW);
		digitalWrite(redLight2, LOW);
		digitalWrite(greenLight, LOW);
		digitalWrite(greenLight2, LOW);
		digitalWrite(orangeLight, LOW);
		digitalWrite(orangeLight2, LOW);
		delay(500);
	}
	
}
