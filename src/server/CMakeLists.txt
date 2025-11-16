# SRC_LIST变量，包含所有源文件
aux_source_directory(. SRC_LIST)

# 生成可执行文件
add_executable(ChatServer ${SRC_LIST})

# 为 ChatServer 目标添加头文件搜索路径
# target_include_directories(ChatServer PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(ChatServer PRIVATE ${PROJECT_SOURCE_DIR}/include/server)

# 可执行文件链接时依赖的库文件
target_link_libraries(ChatServer muduo_net muduo_base pthread)