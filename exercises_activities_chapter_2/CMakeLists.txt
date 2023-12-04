set(EXE_SOURCES_1
    exercise_3.cpp
    log.hpp
    log.cpp)

set(EXE_SOURCES_2
    exercise_4.cpp
    fibonacci.hpp
    fibonacci.cpp)

add_executable(${EX_3} ${EXE_SOURCES_1})
add_executable(${EX_4} ${EXE_SOURCES_2})


