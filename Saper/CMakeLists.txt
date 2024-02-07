cmake_minimum_required(VERSION 3.25)
project(Saper)

add_executable(Saper main.cpp cmake-build-debug/things/Button.cpp cmake-build-debug/things/Button.h
        cmake-build-debug/things/Menu.cpp cmake-build-debug/things/Menu.h
        cmake-build-debug/things/Background.cpp cmake-build-debug/things/Background.h
        cmake-build-debug/things/Plate.cpp cmake-build-debug/things/Plate.h
        cmake-build-debug/things/Board.cpp cmake-build-debug/things/Board.h
        cmake-build-debug/things/Interface.cpp cmake-build-debug/things/Interface.h
        cmake-build-debug/things/Application.cpp cmake-build-debug/things/Application.h
        cmake-build-debug/things/MainMenu.cpp cmake-build-debug/things/MainMenu.h
        cmake-build-debug/things/Game.cpp cmake-build-debug/things/Game.h
        cmake-build-debug/things/Tile.cpp cmake-build-debug/things/Tile.h)

set(Cmake_CXX_STANDARD 17)
set(SFML_DIR "/usr/include/SFML")
include_directories("/usr/include/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Saper sfml-system sfml-window sfml-graphics sfml-audio sfml-network)