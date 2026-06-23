#ifndef __GAL_GAME_SCENE_H__
#define __GAL_GAME_SCENE_H__

#include "cocos2d.h"
#include "script/ScriptEngine.h"
#include "character/CharacterManager.h"
#include "background/BackgroundManager.h"
#include "ui/DialogueBox.h"
#include "ui/ChoiceBox.h"

class GalGameScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GalGameScene);

private:
    ScriptEngine* scriptEngine;
    CharacterManager* characterManager;
    BackgroundManager* backgroundManager;
    DialogueBox* dialogueBox;
    ChoiceBox* choiceBox;

    void setupUI();
    void loadScript(const std::string& scriptPath);
};

#endif // __GAL_GAME_SCENE_H__