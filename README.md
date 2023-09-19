# So Long...

<div align="center">
  <img src="https://i.imgur.com/WwFiJGM.png"/>
</div>  
<br/>
...and Thanks for All the Fish

<br/>
<div align="center">

[![Norminette](https://github.com/hde-oliv/so_long/actions/workflows/norminette.yml/badge.svg)](https://github.com/hde-oliv/so_long/actions/workflows/norminette.yml)
[![Build](https://github.com/hde-oliv/so_long/actions/workflows/build.yml/badge.svg)](https://github.com/hde-oliv/so_long/actions/workflows/build.yml)
[![Tests](https://github.com/hde-oliv/so_long/actions/workflows/tests.yml/badge.svg)](https://github.com/hde-oliv/so_long/actions/workflows/tests.yml)

</div>

## What is it?
It's a simple rendition of a top-down 2D game, made with C and utilizing a custom-made graphics library called MiniLibX, a basic wrapper for the [X Window System](https://pt.wikipedia.org/wiki/X_Window_System).
The goal is to pick up every coin and then go to the exit on the map.  

**Succeeded with 105%**

## Skills
 - Imperative programming
 - Graphics


## How it works
Requirements:
```shell
# It needs X11 miscellaneous extensions library and utility functions from BSD
# Also, I recommend compiling with clang
sudo apt install libx11-dev xorg-dev libbsd-dev clang
```

After compiling it, you'll need a map (just a text file) with the extension `.ber` with the following configuration:
 - It has to be a rectangle.
 - It has to be surrounded by walls.
 - It needs to have at least one coin and one exit.
 - It needs to have only one player.

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

Then, run the binary providing the map's path.
``` sh
./so_long <path-to-map>
```

The folder `tests/tests_maps`, has some map examples.  


## Found any bugs?
Feel free to contact me or create an issue!

## License
This project is licensed under the GNU General Public License v3.0 - see the [COPYING](https://github.com/hde-oliv/so_long/blob/master/COPYING) file for details.

