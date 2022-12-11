#include "cocos2d.h"

USING_NS_CC;


class BackGroundLayer : public LayerColor {

public :
    CREATE_FUNC(BackGroundLayer);

    bool init() override;
    int redColor = 0;
    void changeColor();

//    virtual bool onTouchBegan(Touch * touch, Event * unused_event);
//
//    virtual void onTouchMoved(Touch *touch, Event *unused_event);
//
//    virtual void onTouchEnded(Touch *touch, Event *unused_event);
//
//    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
};