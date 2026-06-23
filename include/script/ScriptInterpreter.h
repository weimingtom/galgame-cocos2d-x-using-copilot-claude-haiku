#ifndef __SCRIPT_INTERPRETER_H__
#define __SCRIPT_INTERPRETER_H__

#include <string>
#include <map>
#include <functional>
#include "ScriptEngine.h"

class ScriptInterpreter {
public:
    ScriptInterpreter();
    ~ScriptInterpreter();

    void execute(ScriptCommand* command);
    void registerCommand(const std::string& type, std::function<void(const std::map<std::string, std::string>&)> handler);

private:
    std::map<std::string, std::function<void(const std::map<std::string, std::string>&)>> commandHandlers;
    
    void setupDefaultHandlers();
};

#endif // __SCRIPT_INTERPRETER_H__