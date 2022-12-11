//
// Created by Administrator on 2022/12/10.
//
#include "cocos2d.h"

USING_NS_CC;

class MainLayer : public Layer {

public :
    CREATE_FUNC(MainLayer);

    bool init() override;
    int rotation = 80;
    int swingSpeed = 1;
    cocos2d::Sprite *hook = nullptr;


    void running(float dt);
};