cmake_minimum_required(VERSION 3.0)
project(asn1c_sequence_of_extensible_defect C)

add_subdirectory(proto)

file(GLOB APP_SRC "${PROJECT_SOURCE_DIR}/src/*.c")
add_executable(asn1c_sequence_of_extensible_defect "${APP_SRC}")

target_link_libraries(asn1c_sequence_of_extensible_defect PUBLIC proto dl m)

