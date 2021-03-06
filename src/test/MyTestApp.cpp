//
//  IcTestWindow.cpp
//  IcEngLib
//
//  Created by Sherman Chen on 12/23/16.
//  Copyright (c) 2016 Simviu Technology Inc.
//  All rights reserved.
//  http://www.simviu.com/dev
//
//

#include "MyTestApp.h"

using namespace Ic3d;
using namespace ctl;
using namespace std;

//----------------------------
// MyTestScn
//----------------------------
class MyTestScn : public IcScene
{
protected:
    Sp<IcObject> m_pObj = nullptr;
    float m_degree = 0; // rotation degree
    
public:
    //--------------------------
    //  onInit
    //--------------------------
    void onInit() override
    {
        IcScene::onInit();
        logInfo("MyTestScn::onInit()");

        IcMeshData mshd;
        mshd.createCube(TVec3(1,1,1), TVec3(0,0,0));
        auto pModel = makeSp<IcModel>(mshd);
        auto pObj   = makeSp<IcObject>(pModel);
        addObj(pObj);
        auto& cam = *getCamera();
        cam.setPos(TVec3(10, 4, -6));
        cam.lookAt(TVec3(0,0,0), TVec3(0,1,0));
        m_pObj = pObj;
    };
    //--------------------------
    //  onUpdate
    //--------------------------
    void onUpdate(double deltaT) override
    {        
        static float K_rotSpeed = 30.0;
        float dt = deltaT > 1.0 ? 1.0 : deltaT;
        if(m_pObj==nullptr) return;
        m_degree += K_rotSpeed*dt;
        if(m_degree>360) m_degree -= 360;
        TQuat q(TVec3(0, deg2rad(m_degree), 0));
        m_pObj->setQuat(q);
    }
};
//----------------------------
// MyTestWindow
//----------------------------
class MyTestWindow : public IcWindow
{
public:
    virtual  void onInit() override
    {
        IcWindow::onInit();
        logInfo("MyTestWindow::onInit()");
        addScene(makeSp<MyTestScn>());
    }
};
//----------------------------
// MyTestApp
//----------------------------
void MyTestApp::onInit()
{
    IcApp::onInit();
    logInfo("MyTestApp::onInit()");
    addWindow(makeSp<MyTestWindow>());
};

