#include <WiFi.h>
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

}
