cmake_minimum_required(VERSION 3.16)

project(brute_force_C VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Find libcurl and curlpp
find_package(CURL REQUIRED)
find_library(CURLPP_LIBRARY curlpp)

# Add sources
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(brute_force_C
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


        httpreq.h httpreq.cpp
        sender.h sender.cpp


    )
else()
    if(ANDROID)
        add_library(brute_force_C SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(brute_force_C
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link libraries
target_link_libraries(brute_force_C PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(brute_force_C PRIVATE CURL::libcurl ${CURLPP_LIBRARY})

# Set target properties
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.brute_force_C)
endif()
set_target_properties(brute_force_C PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS brute_force_C
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(brute_force_C)
endif()
