#include<iostream>
#include<string>
#include<GLFW/glfw3.h>
// include file lib
using namespace std;

/*
The systems memory map:
0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
0x200-0xFFF - Program ROM and work RAM
*/
// create a class?

void setupGraphics() {

}

void setupInput() {

}

void drawGraphics() {

}
class Chip8 {
    public:

        unsigned short opcode;
        unsigned memory[4096]; // chip 8 has a total memory of 4k bytes
        unsigned char V[16]; // register(s)
        unsigned short I; // index register
        unsigned short pc; // program counter
        unsigned char gfx[64 * 32]; // graphics pixel state

        unsigned char delay_timer;
        unsigned char sound_timer;

        unsigned short stack[16]; // used to remember the current location before a jump to an address is performed
        unsigned short sp; // pointer

        unsigned char key[16]; // keypad

        Chip8(unsigned short op, unsigned* mem, unsigned char* v, unsigned short i, unsigned short PC,
          unsigned char* gfcs, unsigned char dt, unsigned char st, unsigned short* stk, unsigned short SP, unsigned char* ks)
        {
            opcode = op;
            std::copy(mem, mem + 4096, memory);
            std::copy(v, v + 16, V);
            I = i;
            pc = PC;
            std::copy(gfcs, gfcs + (64 * 32), gfx);
            delay_timer = dt;
            sound_timer = st;
            std::copy(stk, stk + 16, stack);
            sp = SP;
            std::copy(ks, ks + 16, key);
        }
        // intializing chip8 system, clear memory, registers & screen
        void initialize() {
            pc = 0x200;
            opcode = 0;
            I = 0;
            sp = 0;
            // clear display ?? (maybe using opengl)

            // clear stack
            for (int i = 0; i < 16; i++) {
                stack[i] = 0;
            }
            // clear registers
            for (int i = 0; i < 16; i++) {
                V[i] = 0;
            }
            // clear memory
            for (int i = 0; i < 4096) {
                memory[i] = 0;
            }

            // load fontset ?

            for(int i = 0; i < 80; ++i) {
                memory[i] = chip8_fontset[i];
            }
            // reset timers
            delay_timer = 0;
            sound_timer = 0;
        }
        // loading game into emulator, copy program into memory
        void loadGame(string game_file ) {
            // opening files 
        }
        // emulation cycle -- emulate one cycle of the system
        void emulateCycle() {
            // Fetch opcode, Decode opcode , Execute opcode
            switch(memory[pc++]) {
                
                case 0xA000: // ANNN: Sets I to address NNN
                    I = opcode & 0x0FFF;
                    pc +=2;
                break;
            }
        }
        // update screen, if the draw flag is set
        void drawFlag() {
            /*
            we should set a draw flag when we need to update our screen. 
            Only two opcodes should set this flag:
            0x00E0 – Clears the screen
            0xDXYN – Draws a sprite on the screen
            */
        }
        // store key press state
        void setKeys() {

        }

};
