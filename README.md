# Minesweeper

Minesweeper game made with C++ that can be played in the terminal

![minesweeper-gif](https://github.com/leoalopes/minesweeper/blob/main/assets/minesweeper.gif?raw=true)

**Note**: requires a [Nerd Font](https://www.nerdfonts.com) for some icons to work properly

## Building

The project structure is divided in `core` and `app`.

The `core` library has the main classes that will manage the game and provides an api to perform game actions.

The app has the cli interface class, with methods to interact with I/O, and the main file which uses the `core` library and cli class to run the actual game.

Each folder has their own CMakeLists to build that piece of code. You can build it by using the 3-line script that will clean the build directory and build everything at once

```
./build.sh
```

The binary file will be at the `app` folder in the build directory. It can be run like this

```
./build/app/minesweeper
```

## Libraries

The `core` library should include everything necessary for the game to run, without including any I/O operation. It exposes a class `GameManager` that can be used to perform all game actions.

The app instantiates a `GameManager` and has the responsibility to deal with all I/O and be the bridge between the player and the game.

The current app is configured to use a CLI, but in the future we can reuse the same core library to create a GUI app, for example, allowing the `core` library to be multi-purpose and interface agnostic.

## Linter

The build uses [clang-tidy](https://clang.llvm.org/extra/clang-tidy) to warn on most checks and will fail on any warning.

Most guidelines are configured, removing mostly preference checks and project specific ones. Build can get quite slow with so many checks, so probably need to create a separate command to not lint on every build.

## Testing

TODO
