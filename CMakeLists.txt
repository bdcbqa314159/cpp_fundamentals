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
set(EX_4 ch_2_ex_4)
set(EX_5 ch_2_ex_5)
set(EX_6 ch_2_ex_6)
set(EX_7 ch_2_act_3)
set(EX_8 ch_2_act_4)
set(EX_9 ch_2_act_5)
set(EX_10 ch_2_act_6)

add_subdirectory(exercises_activities_chapter_2)

set(EX_11 ch_3_ex_7)
set(EX_12 ch_3_ex_8)
set(EX_13 ch_3_act_7)
set(EX_14 ch_3_ex_9)
set(EX_15 ch_3_act_8)
set(EX_16 ch_3_act_9)
set(EX_17 ch_3_ex_10)
set(EX_18 ch_3_act_10)
set(EX_19 ch_3_act_11)
set(EX_20 ch_3_act_12)


add_subdirectory(exercises_activities_chapter_3)

set(EX_21 ch_4_ex_11)
set(EX_22 ch_4_act_13)
set(EX_23 ch_4_act_14)
set(EX_24 ch_4_act_15)

add_subdirectory(exercises_activities_chapter_4)