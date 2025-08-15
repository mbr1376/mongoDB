cmake_minimum_required(VERSION 3.16)

project(Cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# پیدا کردن کتابخانه‌ها
find_package(bsoncxx REQUIRED)
find_package(mongocxx REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.7)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------------
# Executable اصلی اپلیکیشن
# -----------------------------
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
    RESOURCES
        ui/icon/add-database.png
        ui/icon/contact.png
        ui/icon/delete-all.png
        ui/icon/delete.png
        ui/icon/email.png
        ui/icon/phone.png
        ui/icon/search-property.png
        ui/icon/update.png
    SOURCES
        listmodel.h listmodel.cpp
        mongomanager.h mongomanager.cpp
)

target_link_libraries(appCpp
    PRIVATE
        Qt6::Quick
        Qt6::Core
        mongo::mongocxx_shared
        mongo::bsoncxx_shared
)

# -----------------------------
# Executable برای تست
# -----------------------------
add_executable(TestMongoManager
    Test/tst_testmongomanager.cpp
    mongomanager.cpp       # کلاس مورد تست
)

target_include_directories(TestMongoManager
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}  # مسیر فایل‌های هدر
)

target_link_libraries(TestMongoManager
    PRIVATE
        gtest
        gmock
        gtest_main
        gmock_main
        pthread                  # لینوکس
        mongo::mongocxx_shared
        mongo::bsoncxx_shared
        Qt6::Core                # فقط Qt Core برای تست
)

# فعال کردن CTest
enable_testing()
add_test(NAME TestMongoManager COMMAND TestMongoManager)

# -----------------------------
# نصب اپلیکیشن
# -----------------------------
include(GNUInstallDirs)
install(TARGETS appCpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
