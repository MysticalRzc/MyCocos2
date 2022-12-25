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
    int ropeMaxLength = 700;
    int rotation = 0;
    int swingSpeed = 1;
    int level = 1;
    Vec2 hookOrigin = Vec2(0, 0);

    cocos2d::Sprite *hook = nullptr;
    DrawUtils *draw = nullptr;

    void swing(float dt);

    void hookAction();

    void levelLoader();
};