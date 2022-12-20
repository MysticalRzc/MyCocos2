//
// Created by Administrator on 2022/12/10.
//

#include "MainLayer.h"

USING_NS_CC;

#define PI (3.14159265358979323846)
#define PI_DIV_180 (0.017453292519943296)

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

//    goldMan->addChild(hook, 0);
//    this->addChild(goldMan, 0);

//need delete
    hook->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100));
    this->addChild(hook, 0);
    draw = DrawUtils::create();
    this->addChild(draw);
    return true;
}

void MainLayer::swing(float df) {
    log("swing is active");
    rotation += swingSpeed;
    if (abs(rotation) > 80) {
        swingSpeed = -swingSpeed;
    }
    hook->setRotation(rotation);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    draw->drawLineR(hook->getPosition(),(rotation + 180) * PI_DIV_180,100);
}

void MainLayer::swingRope(float dt) {

}

