//
// Created by Administrator on 2022/12/10.
//
#include "cocos2d.h"
#include "../utils/DrawUtils.h"
#include "../sprite/CatchSprite.h"

USING_NS_CC;

class MainLayer : public Layer {

public :
    CREATE_FUNC(MainLayer);

    bool init() override;

    int hookStatus = 0;
    int ropeLength = 0;
    int ropeMaxLength = 800;
    int rotation = 0;
    int swingSpeed = 1;
    int cacheIdx = -1;
    int level = 1;
    Vec2 hookOrigin = Vec2(0, 0);

    int *x;
    int *y;
    int cacheSize = 0;

    cocos2d::Sprite *hook = nullptr;
    cocos2d::Sprite *goldMan = nullptr;
    DrawUtils *draw = nullptr;
    CatchSprite *goldList[10];

    void swing(float dt);

    cocos2d::Sprite *hookTest = nullptr;
    cocos2d::Sprite *goldTest = nullptr;
    int  rotationTest = 0;
    void cacheTest(float dt);

    void hookAction();

    void levelLoader();
};