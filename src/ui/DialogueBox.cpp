#include "ui/DialogueBox.h"

USING_NS_CC;

Bool DialogueBox::init() {
    if (!Node::init()) {
        return false;
    }
    
    visible = false;
    setupUI();
    return true;
}

DialogueBox* DialogueBox::create() {
    DialogueBox* pRet = new(std::nothrow) DialogueBox();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void DialogueBox::setupUI() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Background
    background = LayerColor::create(Color4B(0, 0, 0, 200),
                                   visibleSize.width,
                                   visibleSize.height * 0.25f);
    background->setPosition(origin.x, origin.y);
    addChild(background);
    
    // Character name label
    characterNameLabel = Label::createWithTTF("Character", "fonts/Marker Felt.ttf", 24);
    characterNameLabel->setPosition(origin.x + 50, origin.y + visibleSize.height * 0.2f);
    characterNameLabel->setAnchorPoint(Vec2(0, 0.5f));
    addChild(characterNameLabel);
    
    // Text label
    textLabel = Label::createWithTTF("Dialogue text here...", "fonts/Marker Felt.ttf", 20);
    textLabel->setPosition(origin.x + 50, origin.y + visibleSize.height * 0.1f);
    textLabel->setAnchorPoint(Vec2(0, 0.5f));
    addChild(textLabel);
}

void DialogueBox::setDialogue(const std::string& characterName, const std::string& text) {
    characterNameLabel->setString(characterName);
    textLabel->setString(text);
}

void DialogueBox::setText(const std::string& text) {
    textLabel->setString(text);
}

void DialogueBox::setCharacterName(const std::string& name) {
    characterNameLabel->setString(name);
}

void DialogueBox::show(float duration) {
    visible = true;
    setOpacity(0);
    runAction(FadeIn::create(duration));
}

void DialogueBox::hide(float duration) {
    visible = false;
    runAction(FadeOut::create(duration));
}

void DialogueBox::clear() {
    characterNameLabel->setString("");
    textLabel->setString("");
}

void DialogueBox::setOnNextButtonClicked(std::function<void()> callback) {
    onNextCallback = callback;
}

bool DialogueBox::isVisible() const {
    return visible;
}

void DialogueBox::onNextButtonTapped() {
    if (onNextCallback) {
        onNextCallback();
    }
}