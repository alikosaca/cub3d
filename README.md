# cub3D

A first-person 3D maze renderer written in C, inspired by *Wolfenstein 3D*. It uses **raycasting** to turn a 2D grid map into a textured 3D view in real time, rendered with the **MiniLibX** graphics library.

Team project by [@alikosaca](https://github.com/alikosaca) and [@yemreaycicek](https://github.com/yemreaycicek).

## Features

- Real-time raycasting with the **DDA** (Digital Differential Analyzer) algorithm
- Different wall textures for **north, south, east and west** faces
- Configurable floor and ceiling colors
- Smooth movement and rotation (keys are tracked on press / release)
- Wall collision
- Strict `.cub` parser with clear error messages for every invalid case
- 1280×720 window

## Controls

| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate the camera |
| `ESC` or window close button | Quit |

## Map format (`.cub`)

```
NO assets/textures/wall_no.xpm
SO assets/textures/wall_so.xpm
WE assets/textures/wall_we.xpm
EA assets/textures/wall_ea.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11000001110101011111011110N0111
11111111 1111111 111111111111
```

| Element | Meaning |
|---|---|
| `NO` `SO` `WE` `EA` | Path to the `.xpm` texture of each wall direction |
| `F` / `C` | Floor / ceiling color as `R,G,B` (0–255) |
| `1` / `0` | Wall / empty space |
| `N` `S` `E` `W` | Player start position and facing direction (exactly one) |

The map must be **closed by walls** — this is verified with a flood fill. Identifiers can appear in any order, but all of them must come before the map.

## Build & run

Linux only (X11). MiniLibX is included as a Git submodule.

```bash
git clone --recurse-submodules https://github.com/alikosaca/cub3d.git
cd cub3d
sudo apt install libx11-dev libxext-dev
make
./bin/cub3D maps/valid/subject_example.cub
```

Try the bigger maze too:

```bash
./bin/cub3D maps/valid/play_backroom.cub
```

## Error handling

`maps/invalid/` contains **60+ broken map files** (missing textures, bad RGB values, open walls, multiple players, wrong extension, …). Each one is rejected with a specific message, for example:

```
Error
Map file has duplicate RGB color definition
```

## How the raycasting works

For every vertical column of the screen:

1. A ray is cast from the player in the direction of that column.
2. **DDA** steps through the grid one cell at a time until the ray hits a wall.
3. The perpendicular distance to the wall determines the height of the wall slice (avoiding the fish-eye effect).
4. Which side was hit (N/S or E/W) selects the texture, and the exact hit position selects the texture column.
5. The column is drawn: ceiling color, textured wall slice, floor color.

## Project structure

```
src/
├── parser/        # .cub reading, textures, RGB, map validation, flood fill
├── executor/      # MiniLibX setup, hooks, textures
│   └── raycasting/  # DDA and wall drawing
└── utils/         # allocation, printing, freeing
```

## License

GPL-3.0
