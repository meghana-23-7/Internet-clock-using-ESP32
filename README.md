# Internet-clock-using-ESP32
Using ESP32 to fetch current time from the server and display the same on the OLED display and also print the same on the serial monitor.

## Task number: 02

## Task name: Internet clock using ESP32.

## Reference
https://circuitdigest.com/microcontroller-projects/esp32-internet-clock
For I2C OLED: https://arduinogetstarted.com/tutorials/arduino-oled

## Components used
ESP32, I2C OLED, breadboard, jumper wires, USB cable.

Connections: Connect SDA of oled to D21 of ESP32, SCK to D18. Connect VCC and ground of the OLED to that of ESP32. Connect ESP32 to computer.
Theory 
Connect ESP32 to NTP(network time protocol) and UDP(user datagram protocol) to fetch time from the internet. NTP is used for synchronization of time between systems and data networks. Here we are getting time from the internet and displaying it on OLED.

## Code
Here offset is 19800 sec, because Indian Standard Time is 5hr 30 mins ahead of GMT. And, interval is for how often it should receive a new value, here it is 60 seconds.
https://github.com/meghana-23-7/Internet-clock-using-ESP32/blob/main/sketch_task2.ino

## Problems faced
The clock is printing the wrong time. Every time it starts from around 5:30 only.  We are not sure about the error, but I think it is receiving wrong input from the server, or worse it isn’t receiving any input, hence every time it starts from 5:30, by logic of 19800 sec we provided while defining NTP_OFFSET in the code. I’m still working on this.

## Output
The clock first displays “Internet clock”, and then the current time.
