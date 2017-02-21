#include <jni.h>
#include <string>
#include <android/log.h>


#include "MyTestApp.h"
#include "IcEngJNI.h"
#include "../../../../../../../src/test/MyTestApp.h"

#define  LOG_TAG    "IcAppJNI"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

using namespace Ic3d;

static ctl::Sp<MyTestApp> l_pApp = nullptr;
extern "C" JNIEXPORT void JNICALL Java_com_simviu_IcEngTest_MainActivity_createIcApp(JNIEnv * env, jobject obj)
{
    //---- Configure App
    LOGI("MyTestApp instanciated at [0x%x]", l_pApp.get());
    l_pApp = ctl::makeSp<MyTestApp>();

}
extern "C" JNIEXPORT void JNICALL Java_com_simviu_IcEngTest_MainActivity_releaseIcApp(JNIEnv * env, jobject obj)
{
    //---- Configure App
    LOGI("MyTestApp released at [0x%x]", l_pApp.get());
    l_pApp = nullptr;

}
