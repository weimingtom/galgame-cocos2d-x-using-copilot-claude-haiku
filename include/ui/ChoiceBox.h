#ifndef __CHOICE_BOX_H__
#define __CHOICE_BOX_H__

#include "cocos2d.h"
#include <string>
#include <vector>
#include <functional>

struct Choice {
    std::string text;
    std::function<void()> callback;
};

class ChoiceBox : public cocos2d::Node {
public:
    static ChoiceBox* create();
    virtual bool init();

    void addChoice(const std::string& text, std::function<void()> callback);
    void clearChoices();
    void show(float duration = 0.3f);
    void hide(float duration = 0.3f);
    bool isVisible() const;

private:
    std::vector<Choice> choices;
    std::vector<cocos2d::MenuItemLabel*> choiceItems;
    cocos2d::Menu* menu;
    bool visible;

    void setupUI();
    void onChoiceSelected(size_t index);
};

#endif // __CHOICE_BOX_H__