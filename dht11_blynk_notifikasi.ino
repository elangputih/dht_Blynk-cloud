#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL61HBQuXCC"
#define BLYNK_TEMPLATE_NAME "DHT MOnitoring"
#define BLYNK_AUTH_TOKEN "HW8gZlEl9HuZ_lnR6ggOi1Pr3X3WebJe"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi 9";
char pass[] = "elang507";

char auth [] = BLYNK_AUTH_TOKEN;
#define DHTPIN D1          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
   Serial.begin(115200);
  // coneksi dengan wifi
  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay (1000);
    Serial.println ("conecting to wifi...");
  }
 
   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   // menginisiasi sensor dht 
   dht.begin();
}

void loop()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  
  Serial.println("Temperature: ");
  Serial.println(temperature);
  Serial.println(" °C, Humidity: ");
  Serial.println(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V0, humidity);
  Blynk.virtualWrite(V1, temperature);

  delay(1000); // Update every 2 seconds
}
