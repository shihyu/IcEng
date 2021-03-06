cmake_minimum_required(VERSION 3.4.1)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(ICENGROOT    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../..")
set(ICENGLIB     "${ICENGROOT}/IcEng")
set(ICENGBUILD   "${ICENGROOT}/IcEng/IcEngBuild")
set(ICENGDEMO    "${ICENGROOT}/IcEng/src/demo/")
set(ICENGBUILD_BIN 	"${ICENGBUILD}/android/lib/${CMAKE_BUILD_TYPE}/${ANDROID_ABI}")

add_definitions (-D_HAS_EXCEPTIONS=1)

include_directories(${ICENGLIB}/inc ${ICENGLIB}/inc/core ${ICENGDEMO})
link_directories(${ICENGBUILD_BIN})

add_library(IcAppJNI SHARED
    #------ IcEngDemo src
	src/main/cpp/IcAppJNI.cpp
    ${ICENGDEMO}/DemoScene.cpp
    ${ICENGDEMO}/DemoBasic.cpp
    ${ICENGDEMO}/DemoLights.cpp
    ${ICENGDEMO}/DemoRenderToTex.cpp
    ${ICENGDEMO}/DemoModelCreate.cpp
    ${ICENGDEMO}/DemoNestedTrans.cpp
    ${ICENGDEMO}/DemoApp.cpp
			)



# add lib dependencies
target_link_libraries(IcAppJNI
                      IcEng
                      android
                      log
                      EGL
                      GLESv2)
