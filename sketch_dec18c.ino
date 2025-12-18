#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* ssid = "WLAN-ESP";
const char* password = "agsesp32";
const char* mqtt_server = "10.204.119.15";
const char* topic_temp = "ags/sensor/temperatur";

const int oneWireBus = 4;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Verbinde mit ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi verbunden, IP: ");
  Serial.println(WiFi.localIP());
}

/* =========================
   MQTT Reconnect
========================= */
void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT verbinden... ");

    String clientId = "ESP32-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("verbunden");
    } else {
      Serial.print("Fehler, rc=");
      Serial.print(client.state());
      Serial.println(" → neuer Versuch in 5s");
      delay(5000);
    }
  }
}

/* =========================
   SETUP
========================= */
void setup() {
  Serial.begin(115200);
  delay(1000);

  randomSeed(micros());

  setup_wifi();

  client.setServer(mqtt_server, 1883);

  sensors.begin();
  Serial.println("DS18B20 gestartet");
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  static unsigned long lastMsg = 0;
  unsigned long now = millis();

  if (now - lastMsg > 5000) {
    lastMsg = now;

    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);

    if (tempC == DEVICE_DISCONNECTED_C) {
      Serial.println("❌ DS18B20 nicht gefunden");
      return;
    }

    Serial.print("🌡 Temperatur: ");
    Serial.print(tempC);
    Serial.println(" °C");

    char tempString[10];
    dtostrf(tempC, 4, 2, tempString);

    client.publish(topic_temp, tempString);
  }
}
