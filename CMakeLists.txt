cmake_minimum_required(VERSION 3.16)

project(image2ct VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appimage2ct
    main.cpp
)

qt_add_qml_module(appimage2ct
    URI image2ct
    VERSION 1.0
    SOURCES helper.h
    QML_FILES Main.qml
)

target_link_libraries(appimage2ct
    PRIVATE
    Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appimage2ct
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
