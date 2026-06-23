#ifndef __SCRIPT_ENGINE_H__
#define __SCRIPT_ENGINE_H__

#include <string>
#include <vector>
#include <map>

struct ScriptCommand {
    std::string type;  // "dialogue", "choice", "bgm", "se", "show_character", etc.
    std::map<std::string, std::string> parameters;
};

class ScriptEngine {
public:
    ScriptEngine();
    ~ScriptEngine();

    bool loadScript(const std::string& filePath);
    bool parseScript(const std::string& scriptContent);
    
    ScriptCommand* getNextCommand();
    bool hasMoreCommands() const;
    void reset();
    int getCurrentLineNumber() const;

private:
    std::vector<ScriptCommand> commands;
    size_t currentIndex;
    
    ScriptCommand parseCommand(const std::string& line);
    std::string trim(const std::string& str);
};

#endif // __SCRIPT_ENGINE_H__