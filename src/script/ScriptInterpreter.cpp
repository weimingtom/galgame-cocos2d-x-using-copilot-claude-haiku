#include "script/ScriptInterpreter.h"
#include "cocos2d.h"

ScriptInterpreter::ScriptInterpreter() {
    setupDefaultHandlers();
}

ScriptInterpreter::~ScriptInterpreter() {}

void ScriptInterpreter::execute(ScriptCommand* command) {
    if (!command) return;
    
    auto it = commandHandlers.find(command->type);
    if (it != commandHandlers.end()) {
        it->second(command->parameters);
    } else {
        CCLOG("Unknown command type: %s", command->type.c_str());
    }
}

void ScriptInterpreter::registerCommand(const std::string& type, std::function<void(const std::map<std::string, std::string>&)> handler) {
    commandHandlers[type] = handler;
}

void ScriptInterpreter::setupDefaultHandlers() {
    // Register default command handlers
    registerCommand("dialogue", [](const std::map<std::string, std::string>& params) {
        auto charIt = params.find("character");
        auto textIt = params.find("text");
        if (charIt != params.end() && textIt != params.end()) {
            CCLOG("Dialogue - %s: %s", charIt->second.c_str(), textIt->second.c_str());
        }
    });
    
    registerCommand("show_character", [](const std::map<std::string, std::string>& params) {
        auto nameIt = params.find("name");
        if (nameIt != params.end()) {
            CCLOG("Showing character: %s", nameIt->second.c_str());
        }
    });
    
    registerCommand("background", [](const std::map<std::string, std::string>& params) {
        auto pathIt = params.find("path");
        if (pathIt != params.end()) {
            CCLOG("Setting background: %s", pathIt->second.c_str());
        }
    });
}