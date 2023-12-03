cmake_minimum_required(VERSION 3.22...3.27)

project(Cpp_fundamentals_book VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_TEST first_exec)

set(EXE_CH_1_EX_1 ch_1_ex_1)
set(EXE_CH_1_EX_2 ch_1_ex_2)
set(EXE_CH_1_ACT_1 ch_1_act_1)
set(EXE_CH_1_ACT_2 ch_1_act_2)

add_subdirectory(app)
add_subdirectory(exercises_activities_chapter_1)

set(EX_3 ch_2_ex_3)
# set(EXE_CH_2_EX_2 ch_1_ex_2)
# set(EXE_CH_2_ACT_1 ch_1_act_1)
# set(EXE_CH_2_ACT_2 ch_1_act_2)

add_subdirectory(exercises_activities_chapter_2)