//
// Created by Administrator on 2022/12/11.
//

#include "cocos2d.h"
USING_NS_CC;

class MenuLayer :public Layer{
public :
    CREATE_FUNC(MenuLayer);

    bool init() override;

    void menuCloseCallback(cocos2d::Ref *pSender);
};
