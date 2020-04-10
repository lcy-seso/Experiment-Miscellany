set(THIRD_PARTY_PATH
    "${CMAKE_BINARY_DIR}/third_party"
    CACHE STRING
          "A path setting third party libraries download & build directories.")

set(THIRD_PARTY_CACHE_PATH
    "${CMAKE_SOURCE_DIR}"
    CACHE STRING
          "A path cache third party source code to avoid repeated download.")

set(THIRD_PARTY_BUILD_TYPE Release)

# ~~~
# cache funciton to avoid repeat download code of third_party.
# This function has 4 parameters, URL / REPOSITOR / TAG / DIR:
# 1. URL:           specify download url of 3rd party
# 2. REPOSITORY:    specify git REPOSITORY of 3rd party
# 3. TAG:           specify git tag/branch/commitID of 3rd party
# 4. DIR:           overwrite the original SOURCE_DIR when cache directory
#
# The function Return 1 PARENT_SCOPE variables:
#  - TARGETDOWNLOADCMD:Simplyplace"{TARGET}_DOWNLOAD_CMD" in ExternalProject_Add,
#                            and you no longer need to set any donwnload steps in ExternalProject_Add.
# For example:
#    Cache_third_party(${TARGET}
#            REPOSITORY ${TARGET_REPOSITORY}
#            TAG        ${TARGET_TAG}
#            DIR        ${TARGET_SOURCE_DIR})
# ~~~
function(cache_third_party TARGET)
  set(options "")
  set(oneValueArgs URL REPOSITORY TAG DIR)
  set(multiValueArgs "")
  cmake_parse_arguments(cache_third_party "${optionps}" "${oneValueArgs}"
                        "${multiValueArgs}" ${ARGN})

  string(REPLACE "extern_" "" TARGET_NAME ${TARGET})
  string(REGEX REPLACE "[0-9]+" "" TARGET_NAME ${TARGET_NAME})
  string(TOUPPER ${TARGET_NAME} TARGET_NAME)
  if(cache_third_party_REPOSITORY)
    set(${TARGET_NAME}_DOWNLOAD_CMD GIT_REPOSITORY
                                    ${cache_third_party_REPOSITORY})
    if(cache_third_party_TAG)
      list(APPEND ${TARGET_NAME}_DOWNLOAD_CMD GIT_TAG ${cache_third_party_TAG})
    endif()
  elseif(cache_third_party_URL)
    set(${TARGET_NAME}_DOWNLOAD_CMD URL ${cache_third_party_URL})
  else()
    message(
      FATAL_ERROR "Download link (Git repo or URL) must be specified for cache!"
    )
  endif()

  # Pass ${TARGET_NAME}_DOWNLOAD_CMD to parent scope, the double quotation marks
  # can't be removed
  set(${TARGET_NAME}_DOWNLOAD_CMD
      "${${TARGET_NAME}_DOWNLOAD_CMD}"
      PARENT_SCOPE)
endfunction()

include(external/isl)
include(external/pybind)
