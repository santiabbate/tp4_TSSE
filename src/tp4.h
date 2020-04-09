#include <stdint.h>
#include <stdbool.h>

#define MOD_REGISTER 1

#define MOD_CNP_BIT 0
#define MOD_MOD_BIT 1
#define MOD_TMOD_BIT 2

typedef struct
{
    bool tmod;
    bool mod;
    bool cnP;
}modulationReg_t;

uint32_t readReg(uint32_t r);

void writeReg(uint32_t addr, uint32_t dato);

bool readBit(uint32_t addr, uint32_t bit);

void writeBit(uint32_t addr, uint32_t bit, bool valor);

void readModState(modulationReg_t * modReg);

void writeModState(modulationReg_t mod);