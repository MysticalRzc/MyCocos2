#include "Level1Scene.h"
#include "FinishScene.h"

USING_NS_CC;

Scene *Level1Scene::createScene() {
    return Level1Scene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level1Scene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto goldMan = Sprite::create("img/goldMan.png");
    goldMan->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height - 100));
    this->addChild(goldMan);

    auto closeItem = MenuItemImage::create(
            "img/entrance.png",
            "img/entranceSelected.png",
            CC_CALLBACK_1(Level1Scene::menuCloseCallback, this));
    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2 - 30;
    float y = origin.y + closeItem->getContentSize().height / 2 + 30;
    closeItem->setPosition(Vec2(x, y));
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}

void addTitle() {

}


void Level1Scene::menuCloseCallback(Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
