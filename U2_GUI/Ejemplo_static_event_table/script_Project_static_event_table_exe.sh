g++.exe -Wall -fexceptions -O2 -I"C:\Program Files (x86)\wxWidgets\include\wx-3.1" -I"C:\Program Files (x86)\wxWidgets\lib\wx\include\msw-unicode-3.1" -c "C:\Users\LMC\2021\ProyectoPA_02\static_event_table\button.cpp" -o button.o
g++.exe -Wall -fexceptions -O2 -I"C:\Program Files (x86)\wxWidgets\include\wx-3.1" -I"C:\Program Files (x86)\wxWidgets\lib\wx\include\msw-unicode-3.1" -c "C:\Users\LMC\2021\ProyectoPA_02\static_event_table\main.cpp" -o main.o
g++.exe -Xlinker -Map=Project_static_event_table02.map -L"C:\Program Files (x86)\wxWidgets\lib" -o Project_static_event_table02.exe button.o main.o  -s  -lwx_baseud-3.1.dll -lwx_mswud_core-3.1.dll

