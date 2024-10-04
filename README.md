# Minesweeper

Minesweeper game made with C++ that can be played in the terminal

![minesweeper-gif](https://github.com/leoalopes/minesweeper/blob/main/assets/minesweeper.gif?raw=true)

**Note**: requires a [Nerd Font](https://www.nerdfonts.com) for some icons to work properly

## Building

The project uses CMake to create a `core` and `ui` library from their respective folders and link them together with the `main.cpp` file.

You can build it by using the 3-line script that will clean the build directory and use CMake to build everything

```
./build.sh
```

The binary file will be at the root of the build directory and can be run like this

```
./build/minesweeper
```

## Libraries

The code is separated in the `core` and `ui` libraries. This is to organize what is part of the core game mechanics from what will deal with I/O operations to get data from the player.

The `ui` library was coded based on a main abstract class to allow for adding new UI handlers in the future, like mouse support or a full GUI, and just be a plug n play change.
Since CLI and GUI work very differently, it might not be that simple, but having the code separated will make it easier.

## Linter

TODO

## Testing

TODO
