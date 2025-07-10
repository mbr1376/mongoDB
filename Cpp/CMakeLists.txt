cmake_minimum_required(VERSION 3.16)

project(Cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appCpp
    main.cpp
)

qt_add_qml_module(appCpp
    URI Cpp
    VERSION 1.0
    QML_FILES
    ui/Main.qml
        ui/InputItem.qml
        ui/InsertData.qml
        ui/ListItem.qml
        ui/RemoveData.qml
        ui/RootItem.qml
        ui/SearchData.qml
        ui/UpdateData.qml
        RESOURCES ui/icon/add-database.png ui/icon/contact.png ui/icon/delete-all.png ui/icon/delete.png ui/icon/email.png ui/icon/phone.png ui/icon/search-property.png ui/icon/update.png
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCpp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCpp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCpp
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
