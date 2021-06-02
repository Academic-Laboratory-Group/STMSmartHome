# PINOUT for digital temperature sensor DS18B20
                                                NUCLEO PIN                SENSOR PIN
                                                   PC8  <------------------>  DQ
                                                   +5V  <------------------>  VDD
                                                   GND  <------------------>  GND
Pull up resistor should be connected between pin VDD and DQ to assure correct work of temperature sensor.

Schematic of correct connections:

![NucleoSensor](assets/NucleoSensor.jpg)

# PINOUT for diode LED
                                                NUCLEO PIN                LED PIN
                                                   PB14  <------------------>  PWM (+)
                                                   GND   <------------------>  GND (-)
Schematic of correct connections:

![NucleoLight](assets/NucleoLight.jpg)

             
        
