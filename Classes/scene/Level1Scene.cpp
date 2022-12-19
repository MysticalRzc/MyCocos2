#include <ui/CocosGUI.h>
#include "Level1Scene.h"
#include "FinishScene.h"
#include "math.h"

USING_NS_CC;
using namespace cocos2d::ui;

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
    //创建景层
    backGroundLayer = BackGroundLayer::create();
    mainLayer = MainLayer::create();
    menuLayer = MenuLayer::create();
    //创建景层管理类
    layerMutiplex = LayerMultiplex::create(mainLayer, menuLayer, NULL);
    //添加背景色
//    this->addChild(menuLayer, 1);
//    this->addChild(mainLayer,2);
    this->addChild(backGroundLayer, 0);
    this->addChild(layerMutiplex, 3);

    // 添加屏幕点击事件监听
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto myListener = EventListenerTouchOneByOne::create();
    myListener->setSwallowTouches(true);
    myListener->onTouchBegan = std::bind(&Level1Scene::onTouchBegan, this, std::placeholders::_1,
                                         std::placeholders::_2);
    myListener->onTouchEnded = std::bind(&Level1Scene::onTouchEnded, this, std::placeholders::_1,
                                         std::placeholders::_2);
    dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
    this->schedule(SEL_SCHEDULE(&Level1Scene::running), 0.01f, kRepeatForever, 0);

    return true;
}

bool Level1Scene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    backGroundLayer->changeColor();
    return true;
}

bool Level1Scene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
//    layerMutiplex->switchTo(layerIdx % 2);
//    layerIdx++;
    return true;
}

void Level1Scene::menuCloseCallback(Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, scene, true));
}

void Level1Scene::running(float dt) {
    mainLayer->running(0);
}
