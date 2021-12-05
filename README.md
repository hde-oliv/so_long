# So Long!

## What it is
A basic 2D game using MiniLibX (a wrapper for X server).  
The goal is to pick every coin and then exit from the map.  

Succeeded with 105%

## Skills
 - Imperative programming
 - Graphics


## How it works
Requisites:
```shell
clang
```

After compiling it, you'll need a map in with the extension `.ber` with this configuration:
 - Needs to be a rectangle.
 - Needs to be surrounded by walls.
 - Needs to have a least one coin and one exit.
 - Needs to have only one player.

Key:
 - 1: wall
 - 0: background
 - P: player
 - E: exit
 - C: coin
 
 Example:
 ```shell
 11111111111
 10000000001
 100C000C0E1
 1P000C01011
 11111111111
 ```

Then run the binary providing the map's path.
``` sh
./so_long <path-to-map>
```

<div align="center">
  <img src="https://i.imgur.com/WwFiJGM.png"/>
</div>

## Found any bug?
Feel free to contact me or create an issue!

###### Licensed under GPLv3
