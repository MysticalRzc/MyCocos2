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

    auto color4b = Color4B(40,40,40,160);
    this->drawLine(origin,end,Color4F(color4b));

    int step = 50;
    for(int i =0;i * step< 1000;i +=1){
        this->drawPoint(Vec2(i * step,10),i ,Color4F(1,0,0,0.3));
    }

    for(int i =0;i * 50 < 1000;i +=1){
        this->drawPoint(Vec2(30,i * step),i ,Color4F(0,0,1,0.3));
    }
}
