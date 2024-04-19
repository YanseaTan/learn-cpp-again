# 设置 cmake 最低版本
cmake_minimum_required(VERSION 3.15)

# 设置项目名称以及版本号
project(CMakeTest VERSION 1.0.0)

# 记录编译时间的宏
string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)

# 设置配置头文件
configure_file(CMakeTestConfig.h.in CMakeTestConfig.h)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置源文件列表变量
SET(SRC_LIST CMakeTest.cpp)

# ON OFF 的更改需要在清除 cmake 缓存之后才会生效
option(USE_MYLIB "Use mylib" ON)

if(USE_MYLIB)
  # 填写子库路径
  add_subdirectory(mylib)
  list(APPEND EXTRA_LIBS MyLib)
  list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/mylib)
endif()

# 可执行文件设置
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 引用库设置
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# 引用头文件设置
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${EXTRA_INCLUDES}
                           )

