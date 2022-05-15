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

'#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "ssid";
const char* password = "password";

#define NTP_OFFSET  19800   //  In seconds 
#define NTP_INTERVAL 60*1000    // In milliseconds
#define NTP_ADDRESS  "in.pool.ntp.org"  //NTP server for India

Adafruit_SSD1306 display(-1); 
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
void setup() {
  display.begin();
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  initWiFi();
  Serial.print("connected");
  timeClient.begin();

  display.begin(SSD1306_SWITCHCAPVCC);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("  Internet ");
  display.println("  Clock ");
  display.display();
  delay(3000);
}
void loop() {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();

  Serial.println(formattedTime);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(formattedTime);

  display.display();   // write the buffer to the display
  delay(10);
  delay(100);

} '


## Problems faced
The clock is printing the wrong time. Every time it starts from around 5:30 only.  We are not sure about the error, but I think it is receiving wrong input from the server, or worse it isn’t receiving any input, hence every time it starts from 5:30, by logic of 19800 sec we provided while defining NTP_OFFSET in the code. I’m still working on this.

## Output
The clock first displays “Internet clock”, and then the current time.
