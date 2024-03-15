#define BLYNK_AUTH_TOKEN "CClU3v5S3WiZ1y2PM0xnMGnCdbA0duaU"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 

#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Harapan Bersama";  // type your wifi name
char pass[] = "poltekharber";  // type your wifi password

#define DHTPIN D1          // Mention the digital pin where you connected 
#define DHTTYPE DHT11     // DHT 11  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;



void setup(){
   Serial.begin(115200);
  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
  Serial.print("SUHU : ");
  Serial.print(t);
  Serial.print("|| KELEMBAPAN : ");
  Serial.println(h);


  //if(t > 30){
    //Blynk.logEvent("notifikasi","Suhu diatas 30 Derajat celcius");
  }
