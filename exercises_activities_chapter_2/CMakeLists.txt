set(EXE_SOURCES_1
    exercise_3.cpp
    log.hpp
    log.cpp)

set(EXE_SOURCES_2
    exercise_4.cpp
    fibonacci.hpp
    fibonacci.cpp)

set(EXE_SOURCES_3
    exercise_5.cpp
    by_value.hpp
    by_value.cpp)

set(EXE_SOURCES_4
    exercise_6.cpp
    by_reference.hpp
    by_reference.cpp)

set(EXE_SOURCES_5
    activity_3.cpp
    by_reference.hpp
    by_reference.cpp)

set(EXE_SOURCES_6
    activity_4.cpp)

set(EXE_SOURCES_7
    activity_5.cpp
    cars.hpp
    cars.cpp)

add_executable(${EX_3} ${EXE_SOURCES_1})
add_executable(${EX_4} ${EXE_SOURCES_2})
add_executable(${EX_5} ${EXE_SOURCES_3})
add_executable(${EX_6} ${EXE_SOURCES_4})
add_executable(${EX_7} ${EXE_SOURCES_5})
add_executable(${EX_8} ${EXE_SOURCES_6})
add_executable(${EX_9} ${EXE_SOURCES_7})


