project(app)
cmake_minimum_required(VERSION 3.18)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Settings.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Libraries.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Headers.cmake)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/headers)

include_directories(${HEADERS_DIR})

add_executable(${PROJECT_NAME})

file(
  GLOB
  SRCS
  CONFIGURE_DEPENDS
  ${SRC_DIR}/*.cpp
)

file(
  GLOB
  HEADERS_PCH
  CONFIGURE_DEPENDS
  ${SRC_DIR}/headers/pch/*.hpp
)

file(
  GLOB
  HEADERS
  CONFIGURE_DEPENDS
  ${SRC_DIR}/headers/*.hpp
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  ${SRCS}
  ${HEADERS}
  ${HEADERS_PCH}
)

target_precompile_headers(
  ${PROJECT_NAME}
  PRIVATE
  ${HEADERS_DIR}/pch/default.hpp
)