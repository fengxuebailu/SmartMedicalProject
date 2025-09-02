# 设置CMake所需的最低版本
cmake_minimum_required(VERSION 3.5)

# 定义项目名称和所用语言
project(PatientClient LANGUAGES CXX)

# --- CMake和Qt的自动化配置 ---
set(CMAKE_INCLUDE_CURRENT_DIR ON) # 允许 #include "mainwindow.h" 这样的写法

set(CMAKE_AUTOUIC ON)             # 自动处理 .ui 文件，生成 ui_*.h
set(CMAKE_AUTOMOC ON)             # 自动处理 Q_OBJECT 宏，运行 MOC (Meta-Object Compiler)
# set(CMAKE_AUTORCC ON)           # 我们选择手动处理.qrc文件，以获得更精确的控制

# --- C++ 标准配置 ---
set(CMAKE_CXX_STANDARD 11)        # 设置C++标准为 C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 查找项目所需的Qt5模块 ---
# 确保所有需要的模块都在这里列出，特别是与多媒体相关的
find_package(Qt5 COMPONENTS Widgets Sql Network Multimedia MultimediaWidgets REQUIRED)

# --- 资源文件 (.qrc) 处理 ---
# 分别为每个资源文件调用 qt5_add_resources 是最稳妥的方式
# 这会生成对应的 qrc_*.cpp 文件，并将其路径存入变量中
qt5_add_resources(PATIENTCLIENT_RESOURCE_SOURCES patientclient.qrc)
qt5_add_resources(MEDIA_RESOURCE_SOURCES media.qrc)

# --- 定义可执行文件及其源文件 ---
# 这是项目的核心部分，列出了所有需要编译的文件
add_executable(PatientClient
    # --- 核心文件 ---
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui

    # --- 功能模块 (按功能分组，方便管理) ---
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

    # AI 助手
    Aidialog.h
    Aidialog.cpp
    # Aidialog.ui # 注意: 如果AI助手有.ui文件，需要取消这行的注释

    # 聊天功能
    chatdialog.h
    chatdialog.cpp
    chatdialog.ui
    chatmessagewidget.h
    chatmessagewidget.cpp
    chatmessagewidget.ui

    # 放松小岛 (心理舒缓)
    relaxationdialog.h
    relaxationdialog.cpp
    relaxationdialog.ui

    # 亲子健康打卡 (整合进来的新功能)
    healthcheckindialog.h
    healthcheckindialog.cpp
    healthcheckindialog.ui

    # --- 添加由.qrc文件生成的源文件 ---
    ${PATIENTCLIENT_RESOURCE_SOURCES}
    ${MEDIA_RESOURCE_SOURCES}
)

# --- 链接Qt5库 ---
# 将可执行文件链接到之前找到的Qt模块上
target_link_libraries(PatientClient PRIVATE
    Qt5::Widgets
    Qt5::Sql
    Qt5::Network
    Qt5::Multimedia
    Qt5::MultimediaWidgets
)

# --- 构建后自定义命令：复制媒体文件 ---
# "放松小岛"功能可能需要从文件系统直接加载媒体文件
# 这个命令会在每次构建时，将源目录下的 media 文件夹完整复制到构建目录下
set(MEDIA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/media)
set(MEDIA_DESTINATION_DIR ${CMAKE_BINARY_DIR}/media)

# 创建一个自定义目标来执行复制操作
add_custom_target(copy_media_files ALL
    # 在复制前先删除旧目录，确保文件同步
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${MEDIA_DESTINATION_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${MEDIA_SOURCE_DIR} ${MEDIA_DESTINATION_DIR}
    COMMENT "正在复制媒体文件到构建目录..."
)

# 确保在编译主程序之前，文件复制操作已经完成
add_dependencies(PatientClient copy_media_files)
