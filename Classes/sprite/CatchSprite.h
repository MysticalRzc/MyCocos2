//
// Created by Mystical on 2022/12/25.
//

#pragma once

#include "cocos2d.h"

USING_NS_CC;


class CatchSprite : public cocos2d::Sprite {
public:
    CREATE_FUNC(CatchSprite);

    static CatchSprite *createCatch(int type, Vec2 position, int value, int weight);

    bool init() override;

private:
    int type;
    Vec2 position;
    int value;
    int weight;
};
