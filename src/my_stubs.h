#ifndef _MY_STUBS_H
#define _MY_STUBS_H

#include <stdint.h>

void Xil_Out32_Cb(uint32_t addr, uint32_t dato, int NumCalls);

uint32_t Xil_In32_Cb(uint32_t addr, int NumCalls);


#endif