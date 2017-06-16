cmake_minimum_required(VERSION 3.0)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Cmake prefix" FORCE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "Default to Release" FORCE)
project(test_parser CXX)
set(CMAKE_SUPPRESS_REGENERATION ON)

set(SRC
	src/main.cpp
	src/parser.cpp
	src/parser.h
	)
set(SRCLIB
	src/parser.h
	src/parser.cpp)
	
add_library(parser ${SRCLIB})
add_executable(test_parser ${SRC})
target_link_libraries(test_parser parser)

#set_target_properties(test_parser parser PROPERTIES
#					  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
#					  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
#)

message(STATUS "pouet: ${CMAKE_CURRENT_SOURCE_DIR}/lib")
# Dynamic Libraries don't work, we use static ones
set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED     ON)  
set(Boost_USE_STATIC_RUNTIME    OFF)
set(Boost_NO_BOOST_CMAKE        ON)

find_package(Boost 1.63.0 REQUIRED COMPONENTS program_options)
if (Boost_FOUND)
	target_include_directories(parser PUBLIC ${Boost_INCLUDE_DIRS})
	target_link_libraries(parser ${Boost_LIBRARIES})
endif()

install(TARGETS test_parser parser
		RUNTIME DESTINATION bin
		ARCHIVE DESTINATION lib)
install(FILES src/parser.h DESTINATION include)