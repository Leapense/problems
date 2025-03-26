# Install script for directory: /home/monika/Documents/problems

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/monika/Documents/problems/build/19981번： ЕГЭ/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20006번： 랭킹전 대기열/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20152번： Game Addiction/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20153번： 영웅이는 2의 거듭 제곱을 좋아해! 영웅이는 2의 거듭 제곱을 좋아해!/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20162번： 간식 파티/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20413번： MVP 다이아몬드 (Easy)/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20416번： 역전의 제왕 (Easy)/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20438번： 출석체크/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20455번： Калькулятор/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20476번： Занос/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20484번： Игра/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20626번： AiGo/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20837번： Robottävling/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20915번： 숫자 카드 놀이/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20950번： 미술가 미미/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/20954번： 택배 기사 민서/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/21032번： Odd GCD Matching/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/21041번： Largest Exotic Number/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/21049번： Coin Stacks/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/21127번： Binary Supersonic Utahraptors/cmake_install.cmake")
  include("/home/monika/Documents/problems/build/21154번： Over the Hill, Part 1/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/home/monika/Documents/problems/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
