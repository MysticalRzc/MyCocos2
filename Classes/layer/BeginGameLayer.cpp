//
// Created by Mystical on 2022/11/26.
//

#include "BeginGameLayer.h"
USING_NS_CC;

bool BeginGameLayer::init() {
    if (!Layer::init()) return false;
    log("layer init success");
    return true;
}

//bool onTouchBegan(Touch * touch, Event * unused_event) {
//    log("Touch begin");
//    return true;
//}
//
//void onTouchMoved(Touch *touch, Event *unused_event) {
//    log("Touch moved");
//}
//
//void onTouchEnded(Touch *touch, Event *unused_event) {
//    log("Touch ended");
//}
//
//void onTouchCancelled(Touch *touch, Event *unused_event) {
//    log("Touch canceled");
//
//}