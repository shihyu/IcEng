//
//  IcEngJNI.h
//  IcEngLib
//
//  Created by Sherman Chen on 1/4/17.
//  Copyright (c) 2016 Simviu Technology Inc.
//  All rights reserved.
//  http://www.simviu.com/dev
//
//

#ifndef IcEngJNI_h
#define IcEngJNI_h
#include "Ic3d.h"
#include <jni.h>
#include <string>

namespace Ic3d {
    //----------------
    //  JNI Wrapper
    //----------------
    // All android JNI related util put here.
    class IcEngJNI
    {
    public:
        //---- JNI util
        static std::string jstr2str(JNIEnv * env, jstring jstr);
        static void setIcAppInstance(IcApp* pApp);
        static void initIcApp(const std::string& sPathRes,
                              const std::string& sPathDoc);
    };
}
//--------------------------------------------
//  Define Macro
//--------------------------------------------
#define IMPLEMENT_ICAPP(T) \
static T l_app; \
extern "C" JNIEXPORT void JNICALL Java_com_simviu_IcEng_IcEngJNI_createIcApp(JNIEnv * env,  jobject obj) \
{ \
    Ic3d::IcEngJNI::setIcAppInstance(&l_app); \
} \


#endif /* IcEngJNI_h */
