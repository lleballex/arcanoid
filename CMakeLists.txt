# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)
project(Arcanoid)

# Set the policy to NEW for CMP0079
if(POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

# Enable Hot Reload for MSVC compilers if supported.
#if (POLICY CMP0141)
#  cmake_policy(SET CMP0141 NEW)
#  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
#endif()

# Find the SFML library (you need to set the SFML_DIR to the directory where SFML is installed)
#set(SFML_DIR "D:/SFML-2.6.0/bin")  # Replace with the actual path to your SFML installation

set(SFML_DIR "D:/SFML-2.6.0")
list(APPEND CMAKE_PREFIX_PATH "D:/SFML-2.6.0")
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Включите подпроекты.
add_subdirectory ("Arcanoid")

#add_executable(Arcanoid Arcanoid/Arcanoid.cpp)

# Link your target with the SFML libraries
target_link_libraries(Arcanoid PRIVATE sfml-system sfml-window sfml-graphics)
