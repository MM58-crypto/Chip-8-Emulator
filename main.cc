#include<iostream>
/*
* #include opengl graphics + input
* */
#include<GLFW/glfw3.h>
#include "chip8.h"

chip8 myChip8;

using namespace std;

int main () {

setupGraphics();
setupInput();

myChip8.intialize();

// emulation loop
for() {

    //emulate 1 cycle
    mychip8.emulateCycle();

    // update screen
    if(mychip8.drawFlag){
        drawGraphics();
    }

    mychip8.setKeys();


}


return 0;
}

