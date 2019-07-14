const int motor = 9;  // the pin number (PWM) for the motor.
const int ldr = A0; // the pin number for the input sensor.

// new and old values (speed) for motor device.
int x = 0;
int y = 0;

const int sensorMin = 0;   // set the appropriate value of the light sensor.
const int sensorMax = 900; // set the appropriate value of the light sensor.

const int LIGHT_SENSE = 5; // difference level sensitivity value.
const long delayTime = 30; // motor delay time in millis.

void setup () 
{
  // set sensor as input.
  pinMode(ldr, INPUT);

  // set motor as output.
  pinMode(motor, OUTPUT);

  Serial.begin(9600);
}

// loop the main sketch.
void loop () 
{
  // get the value from the light sensor.
  x = analogRead(ldr);
  Serial.println("");
  Serial.print("LRD input = ");
  Serial.println(x);

  // map the value to the min, max of the motor.
  x = map (x, sensorMin, sensorMax, 20, 255);

  // ensure that the value is between min, max of the motor.
  x = constrain(x, 20, 255);
  
  // assume the new value only if there was enough difference.
  if (abs(x - y) > LIGHT_SENSE) 
  {
    // get the new value.
    y = x;
  }

  Serial.println("");
  Serial.print("Motor output = ");
  Serial.println(y);

  // set the signal to the motor.
  analogWrite(motor, y);
  
  // wait some time the motor to move.
  delay(delayTime);
}
