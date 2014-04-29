![Frost and Flame](http://www.weebly.com/uploads/5/9/6/4/596446/76313.png?399)

README file for Frost and Flame
=============================

This is Frost and Flame, a free/open source computer game.

- More information can be found in the game_guide.pdf file.

About:
-----
Frost and Flame is still in its early stages of infancy.  Currently a non-playable WIP.
Frost and flame is an isometric, action role playing game.
Planned features include, a particle engine, rich in content and re-playability with random item, quest and level generation.

Compiling:
---------
Included are the project files for use with the Code::Blocks IDE. (http://www.codeblocks.org/)
Also required are the SDL2 development libraries.
It is recommended that you build the DLL files (SDL2 etc...) with the same compiler that you use to build Frost and Flame.
Also included is the CMakeLists.txt file, which should help with Linux builds.

Compiling under Ubuntu:
-----------------------
Make sure you have all the relevant dependencies installed.
The dependencies required are the SDL2 development libraries as well as OpenGL, Glew and Physfs.
To install development libraries you could use the commands below:

- sudo apt-get install libsdl2-dev 
- sudo apt-get install libsdl2-image-dev 
- sudo apt-get install libsdl2-mixer-dev 
- sudo apt-get install libsdl2-ttf-dev 
- sudo apt-get install libsdl2-net-dev 
- sudo apt-get install libglew-dev
- sudo apt-get install libphysfs-dev

Or in one single line:

- sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-net-dev libglew-dev libphysfs-dev

Next you need to generate a make file, you can use the following command, make sure you are in the Frost and Flame directory:

- cmake CMakeLists.txt

And finally you can use make to build the Frost and Flame binary:

- make

So in summery the commands are as follows:

- sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-net-dev libglew-dev
- cmake CMakeLists.txt
- make

Contributions:
------------
Please note, I am not looking for code contributions. While I do appreciate the offer, this is a personal project I use for testing ideas and improving my code.
Although if you are interested in creating resources for Frost and Flame, I may be interested to include them if they fit the genre and quality of the existing resources.
But at this moment in time, I am undecided as to what direction the game will go, probably 3D at some point, thus 2D resources would probably be unnecessary in the long run.
As for music I am interested in Diablo 2 style music in MOD form....

Known bugs:
----------
I am currently writing a new graphics engine for Frost and Flame, so expect graphical glitches for now...
As this is still a work in progress, the format of the savegames may, and does change quite often.
It is recommended you either overwrite your older savegames with new ones, or delete the older ones when upgrading to a newer version of Frost and Flame.
Or better still remove the older version of the game completely, before installing a newer version.
If the game fails to load, try deleting the Frost_And_Flame.cfg file, this may be due to recent improvements to the game.

License:
-------
Copyright (C) 2011-2014 Paul Wortmann.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the gpl.txt file for more details. 

Contact:
-------
- Paul Wortmann: physhex@gmail.com
- Website:          http://www.physhexgames.co.nr
- Downloads:      https://sourceforge.net/projects/frostandflame/
- Development:   https://github.com/Paul-Wortmann/Frost_And_Flame

