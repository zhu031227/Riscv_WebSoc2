#include "inc/lcpu_general.h"
void designInit() { LCPU_SET_LED(0); }
void designApp() {
    static uint32 c=0;
    while(1) {
        if(!LCPU_RD_EMPTY()) { LCPU_RD_START_PACKET(); c++; LCPU_SET_LED(c&0xF); }
    }
}
