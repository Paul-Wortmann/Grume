# Grume

Copyright Paul Wortmann. GNU GPL v2

![Grume](https://raw.githubusercontent.com/Paul-Wortmann/Grume/master/screenshots/screenshot_001.png)

## Requirements

- Graphics card supporting OpenGL 3.3+
- +2GB of free RAM.
- Linux kernel 4.2+
- AMD or Intel CPU, x86_64.

- While only the Linux build is currently being worked on, it should be trivial to get Grume working on Windows as most of the code and dependencies are cross platform. There are no plans to ever support Apple.

## Build:

Build using gcc and the included cmake file:
```sh
cmake . && make
```

Make sure you have all the relevant dependencies installed:
- [Assimp](https://www.assimp.org/)
- [GLFW](https://www.glfw.org/)
- [glm](https://glm.g-truc.net/)
- [OpenAL](https://openal.org/)
- OpenGL
- [Physfs](https://icculus.org/physfs/)
- [Vorbis](https://xiph.org/vorbis/)

## Contributions:

Please note, I am not looking for contributions.
While I do appreciate the offer, this is a personal project I use for testing ideas and improving my code.
However feel free to open issues.

## Known bugs:

As this is still a work in progress the format of the savegames may, and quite often changes.
It is recommended you either overwrite your older savegames with new ones, or delete the older ones when upgrading to a newer version of Grume.
Or better still remove the older version of the game completely, before installing a newer version.
If the game fails to load, try deleting all config files, the game will recreate them with default settings.

## License:

Copyright (C) 2011-2021 Paul Wortmann.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, version 2 of the License

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the gpl.txt file for more details. 

## Contact:

- Paul Wortmann: physhex@gmail.com
- Website:            http://www.physhexgames.com
- Development:   https://github.com/Paul-Wortmann/Grume
- Discord:   https://discord.gg/JCqmb5Vd

