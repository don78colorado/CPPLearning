enable_testing()

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set (HEADER_FILES ${PROJECT_SOURCE_DIR}/src/mergeSort.h ${PROJECT_SOURCE_DIR}/src/bubbleSort.h)


find_package(Qt5Test REQUIRED)

add_executable(mergesorttest mergesorttest.cpp ${SOURCES} ${HEADER_FILES})
add_test(mergesorttest mergesorttest ${SOURCES} ${HEADER_FILES})
add_executable(bubblesorttest bubblesorttest.cpp ${SOURCES} ${HEADER_FILES})
add_test(bubblesorttest bubblesorttest ${SOURCES} ${HEADER_FILES})

target_link_libraries(bubblesorttest Qt5::Test)
target_link_libraries(mergesorttest Qt5::Test)
