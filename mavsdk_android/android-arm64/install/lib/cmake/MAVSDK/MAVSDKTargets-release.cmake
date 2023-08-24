#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MAVSDK::mavsdk" for configuration "Release"
set_property(TARGET MAVSDK::mavsdk APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(MAVSDK::mavsdk PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmavsdk.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS MAVSDK::mavsdk )
list(APPEND _IMPORT_CHECK_FILES_FOR_MAVSDK::mavsdk "${_IMPORT_PREFIX}/lib/libmavsdk.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
