cmake_minimum_required(VERSION 3.5)

project(PatientClient LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

if(ANDROID)
  add_library(PatientClient SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
    set(RESOURCE_FILES
        patientclient.qrc
    )
    qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})

  add_executable(PatientClient
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    patientinfodialog.cpp
    patientinfodialog.h
    patientinfodialog.ui
    myappointmentsdialog.cpp
    myappointmentsdialog.h
    myappointmentsdialog.ui
    doctorselectiondialog.cpp
    doctorselectiondialog.h
    doctorselectiondialog.ui
    timeselectiondialog.cpp
    timeselectiondialog.h
    timeselectiondialog.ui
    billsdialog.cpp
    billsdialog.h
    billsdialog.ui
    paymentdialog.cpp
    paymentdialog.h
    paymentdialog.ui
    emrdialog.cpp
    emrdialog.h
    emrdialog.ui
    doctordetailsdialog.cpp
    doctordetailsdialog.h
    doctordetailsdialog.ui
    patientclient.qrc

    ${RESOURCE_SOURCES}
  )
endif()

target_link_libraries(PatientClient PRIVATE Qt5::Widgets Qt5::Sql)
