# Install script for directory: /home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/chris/RIN/catkinws_extern/install")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  include("/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/safe_execute_install.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi/msg" TYPE FILE FILES "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/msg/TypeDef.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi/srv" TYPE FILE FILES
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/DeleteParam.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/GetActionServers.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/GetParam.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/GetParamNames.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/GetTime.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/HasParam.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/MessageDetails.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/Nodes.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/NodeDetails.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/Publishers.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/SearchParam.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceHost.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceNode.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceProviders.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceRequestDetails.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceResponseDetails.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/Services.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServicesForType.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/ServiceType.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/SetParam.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/Subscribers.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/Topics.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/TopicsForType.srv"
    "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/srv/TopicType.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi/cmake" TYPE FILE FILES "/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/installspace/rosapi-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/include/rosapi")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/share/roseus/ros/rosapi")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/share/common-lisp/ros/rosapi")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/share/gennodejs/ros/rosapi")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/chris/RIN/catkinws_extern/devel/lib/python2.7/dist-packages/rosapi")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/lib/python2.7/dist-packages/rosapi" REGEX "/\\_\\_init\\_\\_\\.py$" EXCLUDE REGEX "/\\_\\_init\\_\\_\\.pyc$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/chris/RIN/catkinws_extern/devel/lib/python2.7/dist-packages/rosapi" FILES_MATCHING REGEX "/home/chris/RIN/catkinws_extern/devel/lib/python2.7/dist-packages/rosapi/.+/__init__.pyc?$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/installspace/rosapi.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi/cmake" TYPE FILE FILES "/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/installspace/rosapi-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi/cmake" TYPE FILE FILES
    "/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/installspace/rosapiConfig.cmake"
    "/home/chris/RIN/catkinws_extern/build/rosbridge_suite/rosapi/catkin_generated/installspace/rosapiConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/rosapi" TYPE FILE FILES "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rosapi" TYPE PROGRAM FILES "/home/chris/RIN/catkinws_extern/src/rosbridge_suite/rosapi/scripts/rosapi_node")
endif()

