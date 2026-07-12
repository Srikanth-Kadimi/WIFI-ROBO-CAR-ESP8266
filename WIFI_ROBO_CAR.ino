#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "WiFi Robo Car"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// L298N Connections
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

void setup()
{
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connected...");
}

void loop()
{
  Blynk.run();
}

//---------------- Motor Functions ----------------//

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

//---------------- Blynk Controls ----------------//

BLYNK_WRITE(V0)    // Forward
{
  if(param.asInt())
    forward();
  else
    stopCar();
}

BLYNK_WRITE(V1)    // Backward
{
  if(param.asInt())
    backward();
  else
    stopCar();
}

BLYNK_WRITE(V2)    // Left
{
  if(param.asInt())
    left();
  else
    stopCar();
}

BLYNK_WRITE(V3)    // Right
{
  if(param.asInt())
    right();
  else
    stopCar();
}