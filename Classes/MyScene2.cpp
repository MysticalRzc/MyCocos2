#include "MyScene2.h"

USING_NS_CC;

Scene *MyScene2::createScene() {
    return MyScene2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MyScene2::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
            "img/entrance.png",
            "img/entranceSelected.png",
            CC_CALLBACK_1(MyScene2::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0) {
        problemLoading("'img/entrance.png' and 'img/entranceSelected.png'");
    } else {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2 - 30;
        float y = origin.y + closeItem->getContentSize().height/2  + 30;
        closeItem->setPosition(Vec2(x, y));
    }
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto label = Label::createWithTTF("This MyScene2\n", "fonts/Marker Felt.ttf", 36);
    if (label == nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    } else {
        label->setPosition(
                Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }
    return true;
}


void MyScene2::menuCloseCallback(Ref *pSender) {
    Director::getInstance()->end();
}
