#ifndef __CHARACTER_MANAGER_H__
#define __CHARACTER_MANAGER_H__

#include <string>
#include <map>
#include "cocos2d.h"

struct Character {
    std::string name;
    std::string imagePath;
    cocos2d::Sprite* sprite;
    float x, y;
    float scaleX, scaleY;
};

class CharacterManager {
public:
    CharacterManager();
    ~CharacterManager();

    void loadCharacter(const std::string& name, const std::string& imagePath);
    void showCharacter(const std::string& name, float x, float y, const std::string& position = "center");
    void hideCharacter(const std::string& name);
    void moveCharacter(const std::string& name, float x, float y, float duration = 0.5f);
    void setCharacterScale(const std::string& name, float scaleX, float scaleY);
    void setCharacterOpacity(const std::string& name, float opacity);
    void removeCharacter(const std::string& name);
    void clearAllCharacters();
    
    Character* getCharacter(const std::string& name);

private:
    std::map<std::string, Character*> characters;
};

#endif // __CHARACTER_MANAGER_H__