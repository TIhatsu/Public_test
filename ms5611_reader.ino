#include<Wire.h>
#include <MS5611.h>

MS5611 MS5611(0x77);
int interval  = 10000;
long baud_rate = 115200;

void setup() {
  Serial.begin(baud_rate);
  Serial.println("****MS5611 reader****");
  Serial.println("\nSerial connection at " + String(baud_rate) + " baud");
  while(!Serial);
  Serial.println("Measurement interval: " +  String(interval) + " ms\n");
  if (!MS5611.begin()) {
    Serial.println("MS5611 not found, check wiring!");
    while (1);
  }
  //Serial.println("setup() done");
}

void loop() {
  MS5611.read();
  Serial.print("T [C], ");
  Serial.print(MS5611.getTemperature(), 2);
  Serial.print(",\tP [mbar], ");
  Serial.print(MS5611.getPressure(), 2);
  Serial.println(",");
  delay(interval);
}
