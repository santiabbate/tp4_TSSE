#include "my_stubs.h"

/**
 * Stubs tipo callback para las funciones que acceden al bus AXI 
 * Simulan el acceso a dos registros
 */

static uint32_t virtualReg0;
static uint32_t virtualReg1;


// Lectura de registro
void Xil_Out32_Cb(uint32_t addr, uint32_t dato, int NumCalls)
{  
    switch (addr)
    {
    case 0:
        virtualReg0 = dato;
        break;
    case 1:
        virtualReg1 = dato;
        break;
    
    default:
        break;
    }
}

// Escritura de registro
uint32_t Xil_In32_Cb(uint32_t addr, int NumCalls)
{
    switch (addr)
    {
    case 0:
        return virtualReg0;
        break;
    case 1:
        return virtualReg1;
        break;
    
    default:
        return -1;
        break;
    }
}
