# Filler

![Filler](/images/filler.svg)

Filler is a School 42 project. The purpose of this project is to create bot for map-filler puzzle game.

[`filler.en.pdf`](/filler.en.pdf) is the task file.

## Wiki

You can check [wiki-page](../../wiki/Algorithm) if you want to read a description of the created algorithm.

## How to clone?

This repository includes submodule. So if you want to clone it, you can use the following command:

```
git clone --recurse-submodules <repository url>
```

If you will use `git clone <repository url>` instead of, you will get the empty `libft` folder.

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## How to run program?

There are resources that are provided by task — a virtual machine (`filler_vm`), maps, and bots. They are located at the [`resources` directory](/resources).

The virtual machine moderates a game. It needs [a map file](/resources/maps) and [bots](/resources/players).

The purpose of the project is to create own bot.

A name of the created bot is `vbrazhni.filler`. It will be created after `make` command and placed at the root of the directory.

You can run the virtual machine with the following command:

```
./filler_vm -f MAP_FILE -p1 PLAYER_FILE -p2 PLAYER_FILE
```

## Visualizer

Also this project has a visualizer.

It was written with **SDL2** library.

**Prerequisites**

* ```brew install SDL2```

### How to use visualizer?

```
Usage: ./filler_vm -f MAP_FILE -p1 PLAYER_FILE -p2 PLAYER_FILE | ./vs

Control keys:
> Space       — start/stop
> Right Arrow — next step
> Left Arrow  — previous step
```

![Visualizer](/images/visualizer.png)
