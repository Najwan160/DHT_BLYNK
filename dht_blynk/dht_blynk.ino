#include <SimpleTimer.h>

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <ESP8266WiFi.h>

#define suhu 4
#define BLYNK_PRINT Serial

DHT sh(suhu, DHT11);
SimpleTimer timer;
char auth[] = "SZl6bH1wtYNqIFST9QbpcIMT9v6-YbB3";
char ssid[] = "NajwanNuha";
char pswd[] = "blacktrajet";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pswd);
  sh.begin();
  timer.setInterval(1000, senddata);
}
void senddata() {
  float temp = sh.readTemperature();
  float hum = sh.readHumidity();
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
}

void loop() {

  Blynk.run();
  timer.run();
}
