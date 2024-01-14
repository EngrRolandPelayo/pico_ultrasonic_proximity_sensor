/*
* Ultrasonic Proximity Sensor with Raspberry Pi Pico
* by R. Pelayo
*
* tutorial: https://www.teachmemicro.com/interfacing-hc-sr04-ultrasonic-sensor-with-raspberry-pi-pico/
*/

//Pin assignments
const int buzz_pin = 19;
const int trig_pin = 15;
const int echo_pin = 14;

//Speed of sound in m/s
#define SOUND_SPEED 331.3
//Trigger pulse
#define TRIG_PULSE_DURATION_US 10

//A template for writing serial outputs in one-line only
template <typename T>
Print& operator<<(Print& printer, T value)
{
    printer.print(value);
    return printer;
}

void setup() {
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  pinMode(buzz_pin, OUTPUT); 
  //PWM settings for the buzzer
  analogWriteFreq(1000);
  analogWriteResolution(16);

}

void loop() {
  float distance_cm = getDistance();  
  //Do not print out distance values = zero
  if (distance_cm > 0.00)
    Serial << "Distance (cm): " << distance_cm << '\n';

  //Buzzer duty-cycle varies with obstacle distance
  analogWrite(buzz_pin, distance_cm * 1000.00);
}

float getDistance() {
 
  unsigned long echo_time;
  //Send out 10 microsecond pulse to TRIGGER pin
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(TRIG_PULSE_DURATION_US);
  digitalWrite(trig_pin, LOW);
  //Read pulse from ECHO pin
  echo_time = pulseIn(echo_pin, HIGH);
  //Compute obstacle distance, with consideration for temperature
  float comp_sound_speed = SOUND_SPEED + 0.606 * analogReadTemp();
  float distance_cm = 0.0001 * (echo_time * comp_sound_speed) / 2;
  return distance_cm;
}
