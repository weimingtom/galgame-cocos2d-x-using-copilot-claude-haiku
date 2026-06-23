#include "ui/ChoiceBox.h"

USING_NS_CC;

bool ChoiceBox::init() {
    if (!Node::init()) {
        return false;
    }
    
    visible = false;
    setupUI();
    return true;
}

ChoiceBox* ChoiceBox::create() {
    ChoiceBox* pRet = new(std::nothrow) ChoiceBox();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void ChoiceBox::setupUI() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    menu = Menu::create();
    menu->setPosition(origin.x + visibleSize.width / 2,
                     origin.y + visibleSize.height / 4);
    addChild(menu);
}

void ChoiceBox::addChoice(const std::string& text, std::function<void()> callback) {
    Choice choice;
    choice.text = text;
    choice.callback = callback;
    choices.push_back(choice);
    
    auto label = Label::createWithTTF(text, "fonts/Marker Felt.ttf", 20);
    auto item = MenuItemLabel::create(label, CC_CALLBACK_1(ChoiceBox::onChoiceSelected, this));
    menu->addChild(item);
}

void ChoiceBox::clearChoices() {
    choices.clear();
    menu->removeAllChildren();
}

void ChoiceBox::show(float duration) {
    visible = true;
    setOpacity(0);
    runAction(FadeIn::create(duration));
}

void ChoiceBox::hide(float duration) {
    visible = false;
    runAction(FadeOut::create(duration));
}

bool ChoiceBox::isVisible() const {
    return visible;
}

void ChoiceBox::onChoiceSelected(size_t index) {
    if (index < choices.size() && choices[index].callback) {
        choices[index].callback();
    }
}