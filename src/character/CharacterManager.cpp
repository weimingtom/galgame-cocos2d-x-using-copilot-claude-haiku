#include "character/CharacterManager.h"

USING_NS_CC;

CharacterManager::CharacterManager() {}

CharacterManager::~CharacterManager() {
    clearAllCharacters();
}

void CharacterManager::loadCharacter(const std::string& name, const std::string& imagePath) {
    if (characters.find(name) != characters.end()) {
        return;  // Character already loaded
    }
    
    Character* character = new Character();
    character->name = name;
    character->imagePath = imagePath;
    character->sprite = Sprite::create(imagePath);
    character->scaleX = 1.0f;
    character->scaleY = 1.0f;
    character->x = 0;
    character->y = 0;
    
    characters[name] = character;
}

void CharacterManager::showCharacter(const std::string& name, float x, float y, const std::string& position) {
    auto it = characters.find(name);
    if (it == characters.end()) {
        return;
    }
    
    Character* character = it->second;
    character->x = x;
    character->y = y;
    character->sprite->setPosition(x, y);
}

void CharacterManager::hideCharacter(const std::string& name) {
    auto it = characters.find(name);
    if (it != characters.end()) {
        it->second->sprite->setOpacity(0);
    }
}

void CharacterManager::moveCharacter(const std::string& name, float x, float y, float duration) {
    auto it = characters.find(name);
    if (it == characters.end()) {
        return;
    }
    
    Character* character = it->second;
    character->sprite->runAction(MoveTo::create(duration, Vec2(x, y)));
    character->x = x;
    character->y = y;
}

void CharacterManager::setCharacterScale(const std::string& name, float scaleX, float scaleY) {
    auto it = characters.find(name);
    if (it != characters.end()) {
        it->second->sprite->setScaleX(scaleX);
        it->second->sprite->setScaleY(scaleY);
    }
}

void CharacterManager::setCharacterOpacity(const std::string& name, float opacity) {
    auto it = characters.find(name);
    if (it != characters.end()) {
        it->second->sprite->setOpacity(static_cast<int>(opacity * 255));
    }
}

void CharacterManager::removeCharacter(const std::string& name) {
    auto it = characters.find(name);
    if (it != characters.end()) {
        delete it->second;
        characters.erase(it);
    }
}

void CharacterManager::clearAllCharacters() {
    for (auto& pair : characters) {
        delete pair.second;
    }
    characters.clear();
}

Character* CharacterManager::getCharacter(const std::string& name) {
    auto it = characters.find(name);
    if (it != characters.end()) {
        return it->second;
    }
    return nullptr;
}