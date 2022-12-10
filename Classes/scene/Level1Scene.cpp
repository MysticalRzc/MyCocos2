#include <ui/CocosGUI.h>
#include "Level1Scene.h"
#include "FinishScene.h"
#include "../layer/BeginGameLayer.h"
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

//    Image image = new Image();
//    Image imag2 =image->initWithImageFile("img/kfc.png");
//
//    Texture2D *text = Texture2D::initWithImage();
    auto bgcollor = LayerColor::create(Color4B(10,10,0,22));
    this->addChild(bgcollor);
    //添加背景色
//    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("img/kfc.png");
//    auto bgTexture = Sprite::createWithTexture(texture, Rect(0, 0, visibleSize.width, visibleSize.height));
//    bgTexture->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

    //添加图层
    auto layer = LayerColor::create();
    layer->initWithColor(Color4B(0xFF, 0x00, 0x00, 0x80));
    GLenum src = GL_ZERO;
    GLenum dst = GL_ONE_MINUS_SRC_COLOR;
    BlendFunc a = {backend::BlendFactor::ZERO,backend::BlendFactor::DST_COLOR};

    this->addChild(layer,0);

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
    layer->addChild(goldMan,0);
    //颜色混合
    goldMan->setBlendFunc(BlendFunc::ADDITIVE);
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

    this->schedule(SEL_SCHEDULE(&Level1Scene::swing), 0.01f, kRepeatForever, 0);


    return true;
}

void Level1Scene::swing(float dt) {
    rotation += swingSpeed;
    if (abs(rotation) > 80) {
        swingSpeed = -swingSpeed;
    }
    hook->setRotation(rotation);
}

bool Level1Scene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    rotation = -rotation;
    hook->setRotation(rotation);
    return true;
}

bool Level1Scene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) {
    rotation = -rotation;
    hook->setRotation(rotation);
    return true;
}

void Level1Scene::menuCloseCallback(Ref *pSender) {
    auto scene = FinishScene::createScene();
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5,scene,true));
}
