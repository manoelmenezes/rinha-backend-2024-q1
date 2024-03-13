

# Conan automatically generated toolchain file
# DO NOT EDIT MANUALLY, it will be overwritten

# Avoid including toolchain file several times (bad if appending to variables like
#   CMAKE_CXX_FLAGS. See https://github.com/android/ndk/issues/323
include_guard()

message(STATUS "Using Conan toolchain: ${CMAKE_CURRENT_LIST_FILE}")

if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeToolchain' generator only works with CMake >= 3.15")
endif()




########## generic_system block #############
# Definition of system, platform and toolset
#############################################







string(APPEND CONAN_CXX_FLAGS " -m64")
string(APPEND CONAN_C_FLAGS " -m64")
string(APPEND CONAN_SHARED_LINKER_FLAGS " -m64")
string(APPEND CONAN_EXE_LINKER_FLAGS " -m64")



message(STATUS "Conan toolchain: C++ Standard 17 with extensions ON")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Conan conf flags start: 
# Conan conf flags end

foreach(config ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} config)
    if(DEFINED CONAN_CXX_FLAGS_${config})
      string(APPEND CMAKE_CXX_FLAGS_${config}_INIT " ${CONAN_CXX_FLAGS_${config}}")
    endif()
    if(DEFINED CONAN_C_FLAGS_${config})
      string(APPEND CMAKE_C_FLAGS_${config}_INIT " ${CONAN_C_FLAGS_${config}}")
    endif()
    if(DEFINED CONAN_SHARED_LINKER_FLAGS_${config})
      string(APPEND CMAKE_SHARED_LINKER_FLAGS_${config}_INIT " ${CONAN_SHARED_LINKER_FLAGS_${config}}")
    endif()
    if(DEFINED CONAN_EXE_LINKER_FLAGS_${config})
      string(APPEND CMAKE_EXE_LINKER_FLAGS_${config}_INIT " ${CONAN_EXE_LINKER_FLAGS_${config}}")
    endif()
endforeach()

if(DEFINED CONAN_CXX_FLAGS)
  string(APPEND CMAKE_CXX_FLAGS_INIT " ${CONAN_CXX_FLAGS}")
endif()
if(DEFINED CONAN_C_FLAGS)
  string(APPEND CMAKE_C_FLAGS_INIT " ${CONAN_C_FLAGS}")
endif()
if(DEFINED CONAN_SHARED_LINKER_FLAGS)
  string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT " ${CONAN_SHARED_LINKER_FLAGS}")
endif()
if(DEFINED CONAN_EXE_LINKER_FLAGS)
  string(APPEND CMAKE_EXE_LINKER_FLAGS_INIT " ${CONAN_EXE_LINKER_FLAGS}")
endif()


get_property( _CMAKE_IN_TRY_COMPILE GLOBAL PROPERTY IN_TRY_COMPILE )
if(_CMAKE_IN_TRY_COMPILE)
    message(STATUS "Running toolchain IN_TRY_COMPILE")
    return()
endif()

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

# Definition of CMAKE_MODULE_PATH
list(PREPEND CMAKE_MODULE_PATH "/home/manoelmenezes/.conan2/p/b/opens99f145e29a08f/p/lib/cmake")
# the generators folder (where conan generates files, like this toolchain)
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

# Definition of CMAKE_PREFIX_PATH, CMAKE_XXXXX_PATH
# The explicitly defined "builddirs" of "host" context dependencies must be in PREFIX_PATH
list(PREPEND CMAKE_PREFIX_PATH "/home/manoelmenezes/.conan2/p/b/opens99f145e29a08f/p/lib/cmake")
# The Conan local "generators" folder, where this toolchain is saved.
list(PREPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR} )
list(PREPEND CMAKE_LIBRARY_PATH "/home/manoelmenezes/.conan2/p/b/cppre57c6542d4677e/p/lib" "/home/manoelmenezes/.conan2/p/b/boostdac8a15ef664c/p/lib" "/home/manoelmenezes/.conan2/p/b/bzip2e68daa100d9f6/p/lib" "/home/manoelmenezes/.conan2/p/b/libbab9386905bdbcc/p/lib" "/home/manoelmenezes/.conan2/p/b/libpq97a3ec3076cd7/p/lib" "/home/manoelmenezes/.conan2/p/b/libpqf5132fc4d4a2a/p/lib" "/home/manoelmenezes/.conan2/p/b/pista4e93dc80773b5/p/lib" "/home/manoelmenezes/.conan2/p/b/date0c2fdbbdd39fd/p/lib" "/home/manoelmenezes/.conan2/p/b/libcuaf1d7de781722/p/lib" "/home/manoelmenezes/.conan2/p/b/opens99f145e29a08f/p/lib" "/home/manoelmenezes/.conan2/p/b/zlib65f0c156c2dce/p/lib")
list(PREPEND CMAKE_INCLUDE_PATH "/home/manoelmenezes/.conan2/p/b/cppre57c6542d4677e/p/include" "/home/manoelmenezes/.conan2/p/webso7a47c7731495b/p/include" "/home/manoelmenezes/.conan2/p/b/boostdac8a15ef664c/p/include" "/home/manoelmenezes/.conan2/p/b/bzip2e68daa100d9f6/p/include" "/home/manoelmenezes/.conan2/p/b/libbab9386905bdbcc/p/include" "/home/manoelmenezes/.conan2/p/nlohm0567ffc90cfc1/p/include" "/home/manoelmenezes/.conan2/p/b/libpq97a3ec3076cd7/p/include" "/home/manoelmenezes/.conan2/p/b/libpqf5132fc4d4a2a/p/include" "/home/manoelmenezes/.conan2/p/b/pista4e93dc80773b5/p/include" "/home/manoelmenezes/.conan2/p/rapidf7a3355ba53c4/p/include" "/home/manoelmenezes/.conan2/p/b/date0c2fdbbdd39fd/p/include" "/home/manoelmenezes/.conan2/p/b/libcuaf1d7de781722/p/include" "/home/manoelmenezes/.conan2/p/b/opens99f145e29a08f/p/include" "/home/manoelmenezes/.conan2/p/b/zlib65f0c156c2dce/p/include")



if (DEFINED ENV{PKG_CONFIG_PATH})
set(ENV{PKG_CONFIG_PATH} "${CMAKE_CURRENT_LIST_DIR}:$ENV{PKG_CONFIG_PATH}")
else()
set(ENV{PKG_CONFIG_PATH} "${CMAKE_CURRENT_LIST_DIR}:")
endif()




# Variables
# Variables  per configuration


# Preprocessor definitions
# Preprocessor definitions per configuration


if(CMAKE_POLICY_DEFAULT_CMP0091)  # Avoid unused and not-initialized warnings
endif()