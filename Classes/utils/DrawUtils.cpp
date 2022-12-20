//
// Created by Administrator on 2022/12/19.
//
#include "math.h"
#include "DrawUtils.h"

DrawUtils *DrawUtils::createUtils() {
    return DrawUtils::create();
}

bool DrawUtils::init() {
    if (!DrawNode::init()) {
        return false;
    }
    return true;
}

void DrawUtils::drawLineR(Vec2 origin,float angle,int length) {
    this->clear();
    auto end = Vec2(origin.x + sin(angle) * length,origin.y + cos(angle) * length);

    auto color4b = Color4B(255,0,0,255);
    this->drawLine(origin,end,Color4F(color4b));
}
