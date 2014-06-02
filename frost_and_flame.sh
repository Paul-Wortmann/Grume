#!/bin/bash
# Launcher for the Linux version of frost_and_flame

# Getting game executable name.
GAMEFILE=`ls | egrep x86$`

# Checking if OS is 32 or 64 bits and adjusting the game executable name accordingly.
OSVERSION=`uname -m`
if [[ $OSVERSION == "x86_64" ]]
    then GAMEFILE=${GAMEFILE}_64
fi

#Puts the game executable as... executable if not the case.
if [ ! -x $GAMEFILE ]
    then chmod +x $GAMEFILE
fi

#launching the game.
./$GAMEFILE


