cmake_minimum_required(VERSION 3.20)
project(mini-tuple LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 컴파일러별 경고 설정
if(MSVC)
    add_compile_options(/W4 /WX /wd4819)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# 헤더 온리 라이브러리
add_library(mini-tuple INTERFACE)
target_include_directories(mini-tuple INTERFACE include)

# 테스트 실행 파일
add_executable(test_tuple test_main.cpp)
target_link_libraries(test_tuple PRIVATE mini-tuple)
