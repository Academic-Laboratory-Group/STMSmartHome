# Software development environment

For development STM32CubeIDE is used.
 
## Things to set in project properties:
* in Properties/ C/C++ Build/ Settings/ Tool Settings/:
  * MCU GCC Compiler/ Include paths/(there should be list of packs as here):
    * ../Drivers/STM32F4xx_HAL_Driver/Inc
    * ../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    * ../Drivers/CMSIS/Device/ST/STM32F4xx/Include
    * ../Drivers/CMSIS/Include
    * ../Core/src
    * ../Core/libs
  * MCU G++ Compiler/ General/ Language standard: GNU++17
  * MCU GCC Compiler/ Include paths/(there should be list of packs as here):
    * ../Core/src
    * ../Core/libs
    * ../Drivers/STM32F4xx_HAL_Driver/Inc
    * ../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    * ../Drivers/CMSIS/Device/ST/STM32F4xx/Include
    * ../Drivers/CMSIS/Include

After setting this things, compilation shoud work without any errors.
