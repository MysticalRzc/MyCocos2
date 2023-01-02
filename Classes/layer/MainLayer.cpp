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
    mainBgd->setContentSize(cocos2d::Size(1024, 768));

    //添加挖矿老人
    goldMan = Sprite::create("img/goldMan.png");
    goldMan->setPosition(Vec2(origin.x + visibleSize.width / 2 - goldMan->getContentSize().width / 2,
                              origin.y + visibleSize.height - 118));
    goldMan->setAnchorPoint(Vec2(0, 0));
    hookOrigin = Vec2(32, 25);
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

void MainLayer::cacheTest(float dt) {
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
            hookStatus = 3;
        } else if (goldList != nullptr) {
            Vec2 hp = hook->getPosition();
            Vec2 hpn = Vec2(hp.x + goldMan->getPositionX(), hp.y + goldMan->getPositionY());
            for (int i = 0; i < cacheSize; i++) {
                if (abs(hpn.x - goldList[i]->getPositionX()) < goldList[i]->getContentSize().width / 2 &&
                    abs(hpn.y - goldList[i]->getPositionY()) < goldList[i]->getContentSize().height / 2) {
                    cacheIdx = i;
                    hookStatus = 2;
                    return;
                }
            }
        }
        auto angle = rotation * PI_DIV_180;
        ropeLength += 5;
        hook->setPosition(Vec2(hookOrigin.x - sin(angle) * ropeLength, hookOrigin.y - cos(angle) * ropeLength));
    } else if (hookStatus == 2) {
        Vec2 hp = hook->getPosition();
        Vec2 gp = goldMan->getPosition();
        Vec2 hpn = Vec2(hp.x + gp.x, hp.y + gp.y);
        Size hs = hook->getContentSize();
        Size gs = goldList[cacheIdx]->getContentSize();
        auto angle = rotation * PI_DIV_180;
        int offset = 20;

        goldList[cacheIdx]->setPosition(Vec2(hpn.x - sin(angle) * (hs.height + gs.height / 2 - offset),
                                             hpn.y - cos(angle) * (hs.height + gs.width / 2 - offset)));
        if (ropeLength < 10) {
            if (cacheIdx != -1) {
                goldList[cacheIdx]->removeFromParent();
                for (int i = cacheIdx; i < cacheSize; i++) {
                    if (i + 1 < cacheSize) {
                        goldList[i] = goldList[i + 1];
                    }
                }
                cacheSize--;
            }
            hookStatus = 0;
            hook->setPosition(hookOrigin);
        }
        ropeLength -= 1;
        hook->setPosition(Vec2(hookOrigin.x - sin(angle) * ropeLength, hookOrigin.y - cos(angle) * ropeLength));
    } else if (hookStatus == 3) {
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

    std::string name[] = {"gold_b.png", "gold_b.png", "gold_b.png", "gold_b.png", "random_pack.png"};
    cacheSize = 6;
    x = new int[cacheSize]{817, 20, 817, 8, 450};
    y = new int[cacheSize]{565, 136, 121, 566, 111};

    for (int i = 0; i < cacheSize; i++) {
        goldList[i] = CatchSprite::create();
        auto fileName = "img/" + name[i];
        goldList[i]->initWithFile(fileName);
        goldList[i]->setPosition(
                Vec2(x[i] + goldList[i]->getContentSize().width / 2, y[i] - goldList[i]->getContentSize().height / 2));
        this->addChild(goldList[i], 2);
    }
}

