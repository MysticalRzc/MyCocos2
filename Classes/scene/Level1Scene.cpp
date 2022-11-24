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
    // 添加屏幕点击事件监听
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(true);
    myListener->onTouchBegan = std::bind(&Level1Scene::onTouchBegan, this, std::placeholders::_1,
                                         std::placeholders::_2);
    myListener->onTouchEnded = std::bind(&Level1Scene::onTouchEnded, this, std::placeholders::_1,
                                         std::placeholders::_2);
    dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);

    //添加挖矿老人
    auto goldMan = Sprite::create("img/goldMan.png");
    goldMan->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100));
    hook = Sprite::create("img/hook.png");
    hook->setPosition(Vec2(35, 28));
    hook->setRotation(rotation);
    hook->setAnchorPoint(Vec2(hook->getScaleX() / 2, hook->getScaleY()));
    goldMan->addChild(hook, 0);
    this->addChild(goldMan);

    //t
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

//    this->scheduleUpdate();
    this->schedule(SEL_SCHEDULE(&Level1Scene::updateCustom), 0.01f, kRepeatForever, 0);
    return true;
}

void addTitle() {

}

void Level1Scene::gogogo() {
    rotation += 5;
    if (rotation > 90) {
        rotation = rotation - 70;
    }
    hook->setRotation(rotation - 50);
}

void Level1Scene::updateCustom(float dt) {
    rotation += 1;
    if (rotation > 90) {
        rotation = rotation - 70;
    }
    hook->setRotation(rotation - 50);
}

bool Level1Scene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    rotation += 5;
    if (rotation > 90) {
        rotation = rotation - 70;
    }
    hook->setRotation(rotation - 50);
    return true;
}

bool Level1Scene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    rotation += 5;
    if (rotation > 90) {
        rotation = rotation - 70;
    }
    hook->setRotation(rotation - 50);
    return true;
}

void Level1Scene::menuCloseCallback(Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
