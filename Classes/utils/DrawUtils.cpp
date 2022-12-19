//
// Created by Administrator on 2022/12/19.
//

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

void DrawUtils::drawLineR() {
    auto begin = Vec2(0,0);
    auto end = Vec2(1000,100);
    auto color = Color4F(0.3,0.3,0.3,1);

    this->drawLine(begin,end,color);
}
