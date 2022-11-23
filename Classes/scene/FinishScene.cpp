#include "FinishScene.h"
#include "Level1Scene.h"
#include "../MainScene.h"

USING_NS_CC;

Scene *FinishScene::createScene() {
    return FinishScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool FinishScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("victory\n", "fonts/Marker Felt.ttf", 72);
    if (label == nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    } else {
        label->setPosition(
                Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    auto exitItem = MenuItemImage::create(
            "img/exit.png",
            "img/exitSelected.png",
            CC_CALLBACK_1(FinishScene::closeCallback, this));
    auto backMenuItem = MenuItemImage::create(
            "img/back.png",
            "img/backSelected.png",
            CC_CALLBACK_1(FinishScene::backToMainCallback, this));

    if (exitItem == nullptr ||
        exitItem->getContentSize().width <= 0 ||
        exitItem->getContentSize().height <= 0) {
        problemLoading("'img/exit.png' and 'img/exitSelected.png'");
    } else {
        float x = origin.x + visibleSize.width / 5 * 3 - exitItem->getContentSize().width / 2;
        float y = origin.y + visibleSize.height / 2 - exitItem->getContentSize().height / 2;
        exitItem->setPosition(Vec2(x, y));
    }

    if (backMenuItem == nullptr ||
        backMenuItem->getContentSize().width <= 0 ||
        backMenuItem->getContentSize().height <= 0) {
        problemLoading("'img/entrance.png' and 'img/entranceSelected.png'");
    } else {
        float x = origin.x + visibleSize.width / 5 * 2 - backMenuItem->getContentSize().width / 2;
        float y = origin.y + visibleSize.height / 2 - backMenuItem->getContentSize().height / 2;
        backMenuItem->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(exitItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto menu2 = Menu::create(backMenuItem, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);

    return true;
}


void FinishScene::closeCallback(Ref *pSender) {
    Director::getInstance()->end();
}

void FinishScene::backToMainCallback(Ref *pSender) {
    Director::getInstance()->replaceScene(MainScene::createScene());
}
