#include "inc/system.h"
void designInit() { }
void designApp() {
    volatile uint32 *led = (volatile uint32*)(0x80000040);
    static uint32 cnt = 0;
    cnt++; *led = cnt & 0xF;
    for(volatile int i=0;i<100000;i++);
}
