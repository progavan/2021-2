cmake_minimum_required(VERSION 3.19)
project(Project_static_event_table_cmake02_created)
add_custom_target(
  BuildDocs ALL
  DEPENDS button.headers
  DEPENDS main.headers
  DEPENDS Project_static_event_table02.exe
)
#Obtener la lista de archivos de cabecera incluidos al preprocesar
#button.cpp
add_custom_command ( OUTPUT button.headers
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/script_para_obtener_button_headers.sh
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)

#Obtener la lista de archivos de cabecera incluidos al preprocesar
#main.cpp
add_custom_command ( OUTPUT main.headers
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/script_para_obtener_main_headers.sh
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)

#Construir el programa ejecutable del proyecto:
#Project_static_event_table02.exe
add_custom_command ( OUTPUT Project_static_event_table02.exe
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/script_Project_static_event_table_exe.sh
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)


