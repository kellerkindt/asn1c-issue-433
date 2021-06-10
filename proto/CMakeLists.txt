file(GLOB ASN1_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.asn" "${CMAKE_CURRENT_SOURCE_DIR}/*.asn1")

#### CHOSE **ONE** OF THE execute_process CALLS

# invalid hex: 010100000539007b0802d693a409ad27480c01001401861a9fc00084001150
#execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../asn1c/asn1c/asn1c" -S "${CMAKE_CURRENT_SOURCE_DIR}/../asn1c/skeletons/" -fcompound-names -Werror -gen-PER ${ASN1_FILES} WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

# valid hex: 010100000539007b0802d693a409ad27480c01001401861a9fc000420008a8
#execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../riebl_asn1c/asn1c/asn1c" -S "${CMAKE_CURRENT_SOURCE_DIR}/../riebl_asn1c/skeletons/" -fcompound-names -Werror -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-APER ${ASN1_FILES} WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

# valid hex: 010100000539007b0802d693a409ad27480c01001401861a9fc000420008a8
execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../mouse07410_asn1c/asn1c/asn1c" -S "${CMAKE_CURRENT_SOURCE_DIR}/../mouse07410_asn1c/skeletons/" -fcompound-names -Werror -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-APER ${ASN1_FILES} WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/converter-example.c")

file(GLOB ASN1_SRC "${CMAKE_CURRENT_BINARY_DIR}/*.c")
file(GLOB ASN1_HDR "${CMAKE_CURRENT_BINARY_DIR}/*.h")

add_library(proto STATIC ${ASN1_SRC})
target_include_directories(proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

