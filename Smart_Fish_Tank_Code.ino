#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
 
NewPing Sonar(10, 11, 20); //TrigPin, EchoPin, Max Distance in Cm

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  delay (50);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("The Distance is: ");
  int distance = Sonar.ping_cm();
  Serial.print(distance);
  Serial.println(" cm");
  delay(5000);


  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000);

}
