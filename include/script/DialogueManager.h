#ifndef __DIALOGUE_MANAGER_H__
#define __DIALOGUE_MANAGER_H__

#include <string>
#include <functional>
#include "cocos2d.h"

class DialogueManager {
public:
    DialogueManager();
    ~DialogueManager();

    void displayDialogue(const std::string& character, const std::string& text);
    void displaySystemMessage(const std::string& text);
    void clearDialogue();
    
    void setOnDialogueComplete(std::function<void()> callback);
    void advanceDialogue();
    
    bool isDialogueDisplaying() const;

private:
    std::function<void()> onCompleteCallback;
    bool isDisplaying;
    std::string currentCharacter;
    std::string currentText;
};

#endif // __DIALOGUE_MANAGER_H__