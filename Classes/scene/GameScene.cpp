#include <ui/CocosGUI.h>
#include "GameScene.h"
#include "FinishScene.h"
#include "math.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene *GameScene::createScene() {
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init() {
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
    myListener->onTouchBegan = std::bind(&GameScene::onTouchBegan, this, std::placeholders::_1,
                                         std::placeholders::_2);
    myListener->onTouchEnded = std::bind(&GameScene::onTouchEnded, this, std::placeholders::_1,
                                         std::placeholders::_2);
    dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
    this->schedule(SEL_SCHEDULE(&GameScene::running), 0.01f, kRepeatForever, 0);

    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    backGroundLayer->changeColor();
    mainLayer->hookAction();
    return true;
}

bool GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
//    layerMutiplex->switchTo(layerIdx % 2);
//    layerIdx++;
    return true;
}

void GameScene::menuCloseCallback(Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5, scene, true));
}

void GameScene::running(float dt) {
    mainLayer->swing(0);
}
