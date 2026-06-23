#ifndef __BACKGROUND_MANAGER_H__
#define __BACKGROUND_MANAGER_H__

#include <string>
#include "cocos2d.h"

class BackgroundManager {
public:
    BackgroundManager();
    ~BackgroundManager();

    void loadBackground(const std::string& imagePath);
    void showBackground(const std::string& imagePath, float duration = 0.5f);
    void fadeBackground(float duration = 0.5f);
    void transitionBackground(const std::string& newImagePath, float duration = 0.5f);
    void setBackgroundColor(float r, float g, float b, float a = 1.0f);
    void clearBackground();

private:
    cocos2d::Sprite* currentBackground;
    std::string currentBackgroundPath;
};

#endif // __BACKGROUND_MANAGER_H__