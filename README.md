# Raspberry Pi Pico Ultrasonic Proximity Sensor


An ultrasonic sensor (HC-SR04) is wired to a Raspberry Pi Pico. The distance of the obstacle in front of the sensor is displayed in the serial monitor.
A buzzer connected to GPIO19 will change frequency according to the distance of the obstacle.

Coded using Arduino IDE; requires Earl Philhower's Pico SDK port for Arduino: https://github.com/earlephilhower/arduino-pico

The wiring diagram includes extra level shifters because the HC-SR04's echo pin produces a 5V pulse while the Pico's GPIOs can only receive 3.3V.

The code also considers temperature effects on speed of sound, using the Pico's built-in temperature sensor.

Full tutorial on https://www.teachmemicro.com/interfacing-hc-sr04-ultrasonic-sensor-with-raspberry-pi-pico/

