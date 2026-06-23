#ifndef __DIALOGUE_BOX_H__
#define __DIALOGUE_BOX_H__

#include "cocos2d.h"
#include <string>
#include <functional>

class DialogueBox : public cocos2d::Node {
public:
    static DialogueBox* create();
    virtual bool init();

    void setDialogue(const std::string& characterName, const std::string& text);
    void setText(const std::string& text);
    void setCharacterName(const std::string& name);
    void show(float duration = 0.3f);
    void hide(float duration = 0.3f);
    void clear();
    
    void setOnNextButtonClicked(std::function<void()> callback);
    bool isVisible() const;

private:
    cocos2d::LayerColor* background;
    cocos2d::Label* characterNameLabel;
    cocos2d::Label* textLabel;
    cocos2d::Sprite* nextIndicator;
    std::function<void()> onNextCallback;
    bool visible;

    void setupUI();
    void onNextButtonTapped();
};

#endif // __DIALOGUE_BOX_H__