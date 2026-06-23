#include "GalGameScene.h"

USING_NS_CC;

Scene* GalGameScene::createScene() {
    return GalGameScene::create();
}

bool GalGameScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Initialize managers
    characterManager = new CharacterManager();
    backgroundManager = new BackgroundManager();
    scriptEngine = new ScriptEngine();

    // Setup UI
    setupUI();

    // Load and execute script
    loadScript("scripts/game.gal");

    return true;
}

void GalGameScene::setupUI() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    dialogueBox = DialogueBox::create();
    this->addChild(dialogueBox);

    choiceBox = ChoiceBox::create();
    this->addChild(choiceBox);
}

void GalGameScene::loadScript(const std::string& scriptPath) {
    if (scriptEngine->loadScript(scriptPath)) {
        // Script loaded successfully
        CCLOG("Script loaded: %s", scriptPath.c_str());
    } else {
        CCLOG("Failed to load script: %s", scriptPath.c_str());
    }
}