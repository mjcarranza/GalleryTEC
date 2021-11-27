cmake_minimum_required(VERSION 3.20)
project(GalleryTEC)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GalleryTEC main.cpp StorageManager.cpp StorageManager.h mainwindow.cpp mainwindow.h mainwindow.ui ClientWindow.cpp ClientWindow.h clientwindow.ui CompressionAlgorithm.cpp CompressionAlgorithm.h)
target_link_libraries(GalleryTEC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

