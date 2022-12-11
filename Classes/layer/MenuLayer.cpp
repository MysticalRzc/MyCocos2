//
// Created by Administrator on 2022/12/11.
//

#include "MenuLayer.h"
#include "../scene/FinishScene.h"

bool MenuLayer::init() {
    if (!Layer::init()) return false;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto closeItem = MenuItemImage::create(
            "img/entrance.png",
            "img/entranceSelected.png",
            CC_CALLBACK_1(MenuLayer::menuCloseCallback, this));
    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2 - 30;
    float y = origin.y + closeItem->getContentSize().height / 2 + 30;
    closeItem->setPosition(Vec2(x, y));
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}

void MenuLayer::menuCloseCallback(cocos2d::Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, scene, true));

}
