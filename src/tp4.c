#include "tp4.h"
#include "xil_io.h"

#include <stdio.h>

uint32_t readReg(uint32_t r)
{
    return Xil_In32(r);
}

void writeReg(uint32_t addr, uint32_t dato)
{
    Xil_Out32(addr, dato);
}

bool readBit(uint32_t addr, uint32_t bit)
{
    // Leo el registro entero
    uint32_t temp = readReg(addr);
    // Enmascaro el bit solicitado
    temp &= 1 << bit;
    // Devuelvo el valor
    return (temp);
    // return (readReg(addr) << bit);
}

void writeBit(uint32_t addr, uint32_t bit, bool valor)
{
    uint32_t reg = readReg(addr);

    if (valor)
    {
        reg = reg | (1 << bit);
    }
    else
    {
        reg = reg & ~(1 << bit);
    }

    writeReg(addr,reg);
}

void readModState(modulationReg_t * modReg)
{
    uint32_t reg = readReg(MOD_REGISTER);

    modReg->cnP = (reg >> MOD_CNP_BIT) & 1;
    modReg->mod = (reg >> MOD_MOD_BIT) & 1;
    modReg->tmod = (reg >> MOD_TMOD_BIT) & 1;
}


void writeModState(modulationReg_t mod)
{
    uint32_t reg = (mod.tmod << 2) | (mod.mod << 1) | mod.cnP;
    writeReg(MOD_REGISTER, reg);
}