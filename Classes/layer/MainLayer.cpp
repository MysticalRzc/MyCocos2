//
// Created by Administrator on 2022/12/10.
//

#include "MainLayer.h"
#include "../utils/DrawUtils.h"

USING_NS_CC;

bool MainLayer::init() {
    if (!Layer::init()) return false;
    log("Main layer init success");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //添加挖矿老人
    auto goldMan = Sprite::create("img/goldMan.png");
    goldMan->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100));
    hook = Sprite::create("img/hook.png");
    hook->setPosition(Vec2(35, 28));
    hook->setRotation(rotation);
    hook->setAnchorPoint(Vec2(hook->getScaleX() / 2, hook->getScaleY()));
    //颜色混合
    hook->setBlendFunc(BlendFunc::ADDITIVE);

    auto draw = DrawUtils::create();
    this->addChild(draw);
    draw->drawLineR();

//    goldMan->addChild(hook, 0);
//    this->addChild(goldMan, 0);

//need delete
    hook->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100));
    this->addChild(hook, 0);

    return true;
}

void MainLayer::running(float df) {
    log("running is active");
    rotation += swingSpeed;
    if (abs(rotation) > 80) {
        swingSpeed = -swingSpeed;
    }
    hook->setRotation(rotation);
}

