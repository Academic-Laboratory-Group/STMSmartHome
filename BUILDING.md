# Software development environment

For development Keil µVision V5.33.0.0 is used with licence: MDK Professional 5.33 (Flex) (mdk_pro).

Tool Version Numbers: 
C Compiler:         ArmClang.exe                        V6.15 
Assembler:          Armasm.exe                          V6.15 
Linker/Locator:     ArmLink.exe                         V6.15 
Library Manager:    ArmAr.exe                           V6.15 
Hex Converter:      FromElf.exe                         V6.15 
CPU DLL:            SARMCM3.DLL                         V5.33.0.0 
Dialog DLL:         TCM.DLL                             V1.48.0.0 
Target DLL:         STLink\ST-LINKIII-KEIL_SWO.dll      V3.0.8.0 
Dialog DLL:         TCM.DLL                             V1.48.0.0 

## Things to set 
* In Options/Target
Code Generation/ARM Compiler: V6.15

* in Options/'C/C++ (AC6)'/
Language C++:   C++11
Language C:     C99 
Misc Controls:  -xc++ -std=c++11

After setting this things, compilation shoud work without any errors. Because of Keil lots of warnings can run through the output window. Select Options/'C/C++ (AC6)'/Warnings to "No Warnings" and take care of yourself 😅 For c++11 it is the only way that we know.
