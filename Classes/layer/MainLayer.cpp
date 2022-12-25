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

    auto mainBgd = Sprite::create("img/mainBgd.png");
    mainBgd->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

    //添加挖矿老人
    auto goldMan = Sprite::create("img/goldMan.png");
    goldMan->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100));
    hookOrigin = Vec2(35, 28);
    hook = Sprite::create("img/hook.png");
    hook->setPosition(hookOrigin);
    hook->setRotation(rotation);
    hook->setAnchorPoint(Vec2(hook->getScaleX() / 2, hook->getScaleY()));
    //颜色混合
    hook->setBlendFunc(BlendFunc::ADDITIVE);

    draw = DrawUtils::create();
    goldMan->addChild(hook, 0);
    goldMan->addChild(draw, 1);

    levelLoader();
    this->addChild(mainBgd, 0);
    this->addChild(goldMan, 1);
    return true;
}

void MainLayer::swing(float df) {
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    draw->drawLineR(hookOrigin, (rotation + 180) * PI_DIV_180, ropeLength);
    if (hookStatus == 0) {
        rotation += swingSpeed;
        if (abs(rotation) > 80) {
            swingSpeed = -swingSpeed;
        }
        hook->setRotation(rotation);
    } else if (hookStatus == 1) {
        if (ropeLength > ropeMaxLength) {
            hookStatus = 2;
        }
        auto angle = rotation * PI_DIV_180;
        ropeLength += 4;
        hook->setPosition(Vec2(hookOrigin.x - sin(angle) * ropeLength, hookOrigin.y - cos(angle) * ropeLength));
    } else if (hookStatus == 2) {
        if (ropeLength < 10) {
            hookStatus = 0;
            hook->setPosition(hookOrigin);
        }
        auto angle = rotation * PI_DIV_180;
        ropeLength -= 10;
        hook->setPosition(Vec2(hookOrigin.x - sin(angle) * ropeLength, hookOrigin.y - cos(angle) * ropeLength));
    }
}

void MainLayer::hookAction() {
    if (hookStatus == 0) {
        hookStatus = (hookStatus + 1) % 3;
    }
}

void MainLayer::levelLoader() {
    auto gold = CatchSprite::create();
    gold->initWithFile("img/gold_b.png");
    gold->setPosition(Vec2(300, 100));
    auto gold2 = Sprite::create("img/stone.png");
    gold2->setPosition(Vec2(800, 200));
    this->addChild(gold, 2);
    this->addChild(gold2, 3);
}

