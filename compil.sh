#!/usr/bin/env bash

make re
make clean
cd lib/SFML/
make re
make clean
cd ../../games/Nibbler
make re
make clean
cd ../../