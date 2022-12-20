//
// Created by Administrator on 2022/12/19.
//
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class DrawUtils : public cocos2d::DrawNode{
public:
    CREATE_FUNC(DrawUtils);

    static DrawUtils *createUtils();

    bool init() override;

    void drawLineR(Vec2 origin,float angle,int length);
};