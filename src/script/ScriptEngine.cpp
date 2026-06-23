#include "script/ScriptEngine.h"
#include <fstream>
#include <sstream>
#include <algorithm>

ScriptEngine::ScriptEngine() : currentIndex(0) {}

ScriptEngine::~ScriptEngine() {}

bool ScriptEngine::loadScript(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return parseScript(buffer.str());
}

bool ScriptEngine::parseScript(const std::string& scriptContent) {
    std::istringstream stream(scriptContent);
    std::string line;

    while (std::getline(stream, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;  // Skip empty lines and comments
        
        ScriptCommand cmd = parseCommand(line);
        if (!cmd.type.empty()) {
            commands.push_back(cmd);
        }
    }

    currentIndex = 0;
    return true;
}

ScriptCommand* ScriptEngine::getNextCommand() {
    if (currentIndex < commands.size()) {
        return &commands[currentIndex++];
    }
    return nullptr;
}

bool ScriptEngine::hasMoreCommands() const {
    return currentIndex < commands.size();
}

void ScriptEngine::reset() {
    currentIndex = 0;
}

int ScriptEngine::getCurrentLineNumber() const {
    return currentIndex;
}

ScriptCommand ScriptEngine::parseCommand(const std::string& line) {
    ScriptCommand cmd;
    
    // Simple parser for script commands
    // Format example: "dialogue|character:John|text:Hello there!"
    size_t pos = line.find('|');
    if (pos != std::string::npos) {
        cmd.type = line.substr(0, pos);
        
        std::string params = line.substr(pos + 1);
        std::istringstream paramStream(params);
        std::string param;
        
        while (std::getline(paramStream, param, '|')) {
            size_t eqPos = param.find(':');
            if (eqPos != std::string::npos) {
                std::string key = param.substr(0, eqPos);
                std::string value = param.substr(eqPos + 1);
                cmd.parameters[key] = value;
            }
        }
    }
    
    return cmd;
}

std::string ScriptEngine::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}