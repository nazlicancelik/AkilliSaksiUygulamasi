#include <SoftwareSerial.h>
#define yesil_led_pin 11
#define kirmizi_led_pin 10
#define motor_pin 9
#define nem_sensoru A0
#define calisma_siniri 600

SoftwareSerial yeniSeriPort (10, 11);
int nem_degeri = 0;

void setup()
{ Serial.begin(9600);
  pinMode(yesil_led_pin , OUTPUT);
  pinMode(kirmizi_led_pin , OUTPUT);
  pinMode(motor_pin , OUTPUT);
  yeniSeriPort.begin(9600);
  
}

void loop()
{
  nem_degeri = analogRead(nem_sensoru);
  Serial.println(nem_degeri);
  if (nem_degeri > calisma_siniri)
  {
    digitalWrite(motor_pin, HIGH);
    digitalWrite(kirmizi_led_pin, HIGH);
    Serial.println("Cicek sulanmali :(");
    digitalWrite(yesil_led_pin, LOW);
    delay(3000);
    digitalWrite(motor_pin, LOW);
    delay(5000);
  }
  else
  {
    digitalWrite(yesil_led_pin, HIGH);
    Serial.println("Cicek sulandi :))");
    digitalWrite(motor_pin, LOW);
    digitalWrite(kirmizi_led_pin, LOW);
  }
}
