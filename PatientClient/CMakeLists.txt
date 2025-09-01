cmake_minimum_required(VERSION 3.5)

project(PatientClient LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON) # 我们使用 qt5_add_resources，这个可以关闭

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找所有需要的 Qt 组件，包括 Widgets, Sql, 和 Network
find_package(Qt5 COMPONENTS Widgets Sql Network REQUIRED)

# ==================== 资源文件处理 ====================
set(RESOURCE_FILES
    patientclient.qrc
)
qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})
# ======================================================


# ==================== 源文件列表 ====================
add_executable(PatientClient
    # 主程序文件
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui

    # 个人资料
    patientinfodialog.h
    patientinfodialog.cpp
    patientinfodialog.ui

    # 我的预约
    myappointmentsdialog.h
    myappointmentsdialog.cpp
    myappointmentsdialog.ui

    # 预约流程
    doctorselectiondialog.h
    doctorselectiondialog.cpp
    doctorselectiondialog.ui
    timeselectiondialog.h
    timeselectiondialog.cpp
    timeselectiondialog.ui

    # 支付功能
    billsdialog.h
    billsdialog.cpp
    billsdialog.ui
    paymentdialog.h
    paymentdialog.cpp
    paymentdialog.ui

    # 电子病历
    emrdialog.h
    emrdialog.cpp
    emrdialog.ui

    # 医生详情
    doctordetailsdialog.h
    doctordetailsdialog.cpp
    doctordetailsdialog.ui

    # AI 诊断 (来自队友)
    Aidialog.h
    Aidialog.cpp
    # Aidialog.ui # 如果有 .ui 文件，也需要加进来

    # 聊天功能 (来自你)
    # chatdialog.h
    # chatdialog.cpp
    # chatdialog.ui
    # chatmessagewidget.h
    # chatmessagewidget.cpp
    # chatmessagewidget.ui

    # 编译好的资源文件
    ${RESOURCE_SOURCES}
)
# ======================================================

# 链接所有需要的 Qt 库
target_link_libraries(PatientClient PRIVATE Qt5::Widgets Qt5::Sql Qt5::Network)
