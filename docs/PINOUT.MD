# PINOUT for digital temperature sensor DS18B20
                                                NUCLEO PIN                SENSOR PIN
                                                   PC8  ------------------->  DQ
                                                   +5V  ------------------->  VDD
                                                   GND  ------------------->  GND
To correct work temperature sensor should be connected also resistor pull up between pin VDD and DQ.

Scheamtic to correct connection:
![NUCLEO_SENSOR](docs/NUCLEO_SENSOR.png)

             
        
