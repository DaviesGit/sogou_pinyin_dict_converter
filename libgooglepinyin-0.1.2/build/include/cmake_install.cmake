# Install script for directory: /a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/googlepinyin/atomdictbase.h;/usr/include/googlepinyin/dictbuilder.h;/usr/include/googlepinyin/dictdef.h;/usr/include/googlepinyin/dictlist.h;/usr/include/googlepinyin/dicttrie.h;/usr/include/googlepinyin/lpicache.h;/usr/include/googlepinyin/matrixsearch.h;/usr/include/googlepinyin/mystdlib.h;/usr/include/googlepinyin/ngram.h;/usr/include/googlepinyin/pinyinime.h;/usr/include/googlepinyin/searchutility.h;/usr/include/googlepinyin/spellingtable.h;/usr/include/googlepinyin/spellingtrie.h;/usr/include/googlepinyin/splparser.h;/usr/include/googlepinyin/sync.h;/usr/include/googlepinyin/userdict.h;/usr/include/googlepinyin/utf16char.h;/usr/include/googlepinyin/utf16reader.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/googlepinyin" TYPE FILE FILES
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/atomdictbase.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/dictbuilder.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/dictdef.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/dictlist.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/dicttrie.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/lpicache.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/matrixsearch.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/mystdlib.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/ngram.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/pinyinime.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/searchutility.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/spellingtable.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/spellingtrie.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/splparser.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/sync.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/userdict.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/utf16char.h"
    "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/include/utf16reader.h"
    )
endif()

