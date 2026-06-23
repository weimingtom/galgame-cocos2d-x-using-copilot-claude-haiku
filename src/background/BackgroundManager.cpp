#include "background/BackgroundManager.h"

USING_NS_CC;

BackgroundManager::BackgroundManager() : currentBackground(nullptr) {}

BackgroundManager::~BackgroundManager() {
    clearBackground();
}

void BackgroundManager::loadBackground(const std::string& imagePath) {
    if (currentBackground) {
        currentBackground->removeFromParent();
    }
    
    currentBackgroundPath = imagePath;
}

void BackgroundManager::showBackground(const std::string& imagePath, float duration) {
    currentBackgroundPath = imagePath;
    
    if (currentBackground) {
        currentBackground->runAction(Sequence::create(
            FadeOut::create(duration / 2),
            RemoveSelf::create(),
            nullptr
        ));
    }
}

void BackgroundManager::fadeBackground(float duration) {
    if (currentBackground) {
        currentBackground->runAction(FadeOut::create(duration));
    }
}

void BackgroundManager::transitionBackground(const std::string& newImagePath, float duration) {
    fadeBackground(duration);
    showBackground(newImagePath, duration);
}

void BackgroundManager::setBackgroundColor(float r, float g, float b, float a) {
    // Implementation for setting background color
}

void BackgroundManager::clearBackground() {
    if (currentBackground) {
        currentBackground->removeFromParent();
        currentBackground = nullptr;
    }
    currentBackgroundPath.clear();
}