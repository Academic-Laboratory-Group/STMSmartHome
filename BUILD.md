# How to build this project first time

1. Run Quartus.
2. File > New > NIOS II Application.
3. Write "PongFPGA" as a project name.
4. Choose "Create" button.
5. Write "PongFPGA_bsp" as a bsp project name.
6. Choose path (there cannot be any spaces) to .sopcinfo file in extracted and compiled quartus project.
7. Choose "Finish".
8. Choose "Finish" again.
9. PPM on bsp project > NIOSII > Generate bsp.
10. Drag the contents of source directory into the project (not the bsp one).
11. Project > Build all.
12. After that, please refer to "Systemy embedded w FPGA" or Quartus instructions how to run ready project.
