if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_HABETS39 habets39)

FIND_PATH(
    HABETS39_INCLUDE_DIRS
    NAMES habets39/api.h
    HINTS $ENV{HABETS39_DIR}/include
        ${PC_HABETS39_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    HABETS39_LIBRARIES
    NAMES gnuradio-habets39
    HINTS $ENV{HABETS39_DIR}/lib
        ${PC_HABETS39_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/habets39Target.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(HABETS39 DEFAULT_MSG HABETS39_LIBRARIES HABETS39_INCLUDE_DIRS)
MARK_AS_ADVANCED(HABETS39_LIBRARIES HABETS39_INCLUDE_DIRS)
