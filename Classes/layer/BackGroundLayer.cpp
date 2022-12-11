//
// Created by Mystical on 2022/11/26.
//
#include "math.h"
#include "BackGroundLayer.h"

USING_NS_CC;

bool BackGroundLayer::init() {
    if (!Layer::init()) return false;
    log("layer init success");
    this->setColor(Color3B(redColor, 162, 77));
    return true;
}

void BackGroundLayer::changeColor() {
    redColor += 10;
    this->setColor(Color3B(redColor, 162, 77));
}