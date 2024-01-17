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
set(EX_25 ch_4_act_16)
set(EX_26 ch_4_act_17)
set(EX_27 ch_4_act_18)

add_subdirectory(exercises_activities_chapter_4)

set(EX_28 ch_5_act_19)
set(EX_29 ch_5_act_20)
set(EX_30 ch_5_act_21)
set(EX_31 ch_5_ex_12)
set(EX_32 ch_5_ex_13)
set(EX_33 ch_5_ex_14)
set(EX_34 ch_5_act_22)
set(EX_35 ch_5_ex_15)
set(EX_36 ch_5_ex_16)
set(EX_37 ch_5_ex_17)
set(EX_38 ch_5_ex_18)
set(EX_39 ch_5_ex_19)

add_subdirectory(exercises_activities_chapter_5)

set(EX_40 ch_6_ex_20)
set(EX_41 ch_6_ex_21)
set(EX_42 ch_6_act_23)
set(EX_43 ch_6_ex_22)
set(EX_44 ch_6_act_24)
set(EX_45 ch_6_act_25)

add_subdirectory(exercises_activities_chapter_6)
