echo Compiling app...
sudo g++ ./src/main.cpp ./src/filestats.cpp ./src/wildcards.cpp -I ./inc/ -o /usr/bin/linecounter
echo Install complete