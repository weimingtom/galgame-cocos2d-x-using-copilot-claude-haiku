# Galgame Cocos2d-x Script Engine Template

This is a template project for creating Visual Novel / Galgame games using Cocos2d-x and a custom script engine.

## Project Structure

```
├── include/              # Header files
│   ├── GalGameScene.h
│   ├── script/          # Script engine headers
│   ├── character/       # Character management
│   ├── background/      # Background management
│   └── ui/              # UI components
├── src/                 # Implementation files
│   ├── main.cpp
│   ├── GalGameScene.cpp
│   ├── script/
│   ├── character/
│   ├── background/
│   └── ui/
├── scripts/             # Game scripts (*.gal files)
├── assets/              # Game assets (images, audio)
└── CMakeLists.txt       # Build configuration
```

## Features

- **Script Engine**: Parse and execute game scripts in simple text format
- **Character Manager**: Handle character display, positioning, and animations
- **Background Manager**: Manage background images and transitions
- **Dialogue System**: Display character dialogue with names
- **Choice System**: Multiple choice dialogue branches
- **Scene Management**: Cocos2d-x scene-based architecture

## Script Format

Game scripts use a simple pipe-delimited format:

```
command|param1:value1|param2:value2
```

### Available Commands

- **dialogue**: Display character dialogue
  ```
  dialogue|character:CharacterName|text:Hello world!
  ```

- **show_character**: Display a character sprite
  ```
  show_character|name:Alice|position:left
  ```

- **hide_character**: Hide a character
  ```
  hide_character|name:Alice
  ```

- **background**: Set background image
  ```
  background|path:assets/bg_school.png
  ```

- **bgm**: Play background music
  ```
  bgm|path:assets/music/bgm.mp3
  ```

- **se**: Play sound effect
  ```
  se|path:assets/sfx/click.wav
  ```

## Building

### Prerequisites

- CMake 3.10+
- Cocos2d-x development environment
- C++14 compiler

### Build Steps

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Create game scripts in the `scripts/` directory
2. Add character sprites to `assets/`
3. Modify `GalGameScene` to load your scripts
4. Build and run the project

## Extending the Script Engine

To add custom commands:

1. Register a handler in `ScriptInterpreter::setupDefaultHandlers()`
2. Add the command parsing logic in `ScriptEngine::parseCommand()`
3. Implement the functionality in the appropriate manager class

## Example Script

See `scripts/game.gal` for a complete example script.

## License

MIT License
