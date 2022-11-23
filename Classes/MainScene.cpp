/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainScene.h"
#include "scene/Level1Scene.h"


USING_NS_CC;

Scene *MainScene::createScene() {
    return MainScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename) {
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("Welcome MyCocos ~\n", "fonts/Marker Felt.ttf", 36);
    if (label == nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    } else {
        label->setPosition(
                Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    Vector<MenuItem *> menuItems;
    auto entrance = MenuItemLabel::create(Label::createWithTTF("Entrance Game\n", "fonts/Marker Felt.ttf", 36),
                                          CC_CALLBACK_1(MainScene::entranceCallback, this));
    auto exit = MenuItemLabel::create(Label::createWithTTF("Exit\n", "fonts/Marker Felt.ttf", 36),
                                      CC_CALLBACK_1(MainScene::exit, this));

    menuItems.pushBack(entrance);
    menuItems.pushBack(exit);
    auto myMenu = Menu::createWithArray(menuItems);
    myMenu->alignItemsVerticallyWithPadding(5);
    myMenu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(myMenu, 1);

    return true;
}


void MainScene::menuCloseCallback(Ref *pSender) {
    auto scene = Level1Scene::createScene();
    //auto scene = createScene();

    //Director::getInstance()->runWithScene(scene);
    Director::getInstance()->replaceScene(scene);
}

void MainScene::entranceCallback(Ref *pSender) {
    auto scene = Level1Scene::createScene();
    //auto scene = createScene();

    //Director::getInstance()->runWithScene(scene);
    Director::getInstance()->replaceScene(scene);
}

void MainScene::exit(Ref *pSender) {
    Director::getInstance()->end();
}
