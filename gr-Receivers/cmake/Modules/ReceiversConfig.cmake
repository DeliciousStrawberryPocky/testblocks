INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_RECEIVERS Receivers)

FIND_PATH(
    RECEIVERS_INCLUDE_DIRS
    NAMES Receivers/api.h
    HINTS $ENV{RECEIVERS_DIR}/include
        ${PC_RECEIVERS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    RECEIVERS_LIBRARIES
    NAMES gnuradio-Receivers
    HINTS $ENV{RECEIVERS_DIR}/lib
        ${PC_RECEIVERS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/ReceiversTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(RECEIVERS DEFAULT_MSG RECEIVERS_LIBRARIES RECEIVERS_INCLUDE_DIRS)
MARK_AS_ADVANCED(RECEIVERS_LIBRARIES RECEIVERS_INCLUDE_DIRS)
