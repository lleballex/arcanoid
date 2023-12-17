# CMakeList.txt: проект CMake для Arcanoid; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Arcanoid "Arcanoid.cpp"  "Object/Object.h" "Object/Object.cpp" "Rect/Rect.h" "Rect/Rect.cpp" "Circle/Circle.h" "Circle/Circle.cpp" "Block/Block.h" "Block/Block.cpp" "SolidBlock/SolidBlock.h" "SolidBlock/SolidBlock.cpp" "App/App.h" "App/App.cpp" "BaseScene/BaseScene.h" "Game/Game.h" "Game/Game.cpp" "Platform/Platform.h" "Platform/Platform.cpp" "Ball/Ball.h" "Ball/Ball.cpp"   "HorizontalPlatform/HorizontalPlatform.h" "HorizontalPlatform/HorizontalPlatform.cpp" "VerticalPlatform/VerticalPlatform.h" "VerticalPlatform/VerticalPlatform.cpp" "MultiBlock/MultiBlock.h" "MultiBlock/MultiBlock.cpp" "Home/Home.h" "Home/Home.cpp" "Button/Button.h" "Button/Button.cpp" "ColorTransition/ColorTransition.h" "ColorTransition/ColorTransition.cpp" "VerticalLayout/VerticalLyout.h" "VerticalLayout/VerticalLayout.cpp"  "config.h" "EventManager/EventManager.h" "EventManager/EventManager.cpp" "BaseScene/BaseScene.cpp" "Game/utils.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Arcanoid PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
