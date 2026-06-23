#include "script/DialogueManager.h"

DialogueManager::DialogueManager() : isDisplaying(false) {}

DialogueManager::~DialogueManager() {}

void DialogueManager::displayDialogue(const std::string& character, const std::string& text) {
    currentCharacter = character;
    currentText = text;
    isDisplaying = true;
}

void DialogueManager::displaySystemMessage(const std::string& text) {
    currentCharacter = "[System]";
    currentText = text;
    isDisplaying = true;
}

void DialogueManager::clearDialogue() {
    currentCharacter.clear();
    currentText.clear();
    isDisplaying = false;
}

void DialogueManager::setOnDialogueComplete(std::function<void()> callback) {
    onCompleteCallback = callback;
}

void DialogueManager::advanceDialogue() {
    if (onCompleteCallback) {
        onCompleteCallback();
    }
    clearDialogue();
}

bool DialogueManager::isDialogueDisplaying() const {
    return isDisplaying;
}