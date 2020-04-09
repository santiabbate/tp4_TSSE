#include <unity.h>
#include "tp4.h"
#include "mock_xil_io.h"

#include "my_stubs.h"

/**
 * Tests creados
 * > Se puede leer el valor de un registro de 32 bits
 * > Se puede escribir a un registro de 32 bits
 * > Se puede escribir a un bit específico dentro de un registro
 * > Se puede leer el estado de un bit específico dentro de un registro
 * > Se puede conocer el estado de configuración leyendo a una estructura, el modo, la habilitación de modulación y el tipo de modulación
 * > Se puede configurar modo, habilitación de modulación y tipo de modulación mediante una estructura de configuración
 */

/**
 * > Se puede leer el valor de un registro de 32 bits
 */
void test_readReg()
{
    uint32_t dato = 0xFFFFFFFF;
    uint32_t addr = 0;

    // Mock de función de acceso al bus AXI
    Xil_In32_ExpectAndReturn(addr, dato);

    uint32_t retVal = readReg(addr);
    
    TEST_ASSERT_EQUAL(dato, retVal);
}

/**
 * > Se puede escribir a un registro de 32 bits
 */
void test_writeReg()
{
    uint32_t dato = 0xFFFFFFFF;
    uint32_t addr = 0;

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, dato);
    uint32_t retVal = readReg(addr);
    
    TEST_ASSERT_EQUAL(dato, retVal);
}

/**
 * > Se puede escribir a un bit específico dentro de un registro
 * Testeo escritura por True
 */
void test_writeBitTrue()
{
    bool valor = 1;     // Valor a escribir
    uint32_t bit = 5;   // Número de bit a escribir
    uint32_t addr = 0;  // Dirección de registro a escribir

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, 0);  // Condición inicial, registro en cero
    
    writeBit(addr, bit, valor); // Función a testear
    uint32_t retVal = readReg(addr);
    
    TEST_ASSERT_EQUAL((valor << bit), retVal);
}

/**
 * > Se puede escribir a un bit específico dentro de un registro
 * Testeo escritura por False
 */
void test_writeBitFalse()
{
    uint32_t valorInicial = 0xFFFFFFFF;

    bool valor = 0;     // Valor a escribir
    uint32_t bit = 5;   // Número de bit a escribir
    uint32_t addr = 0;  // Dirección de registro a escribir

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, valorInicial);   // Condición inicial

    writeBit(addr, bit, valor);     // Función a testear
    uint32_t retVal = readReg(addr);
    
    TEST_ASSERT_EQUAL(valorInicial & ~(1 << bit), retVal);
}

/**
 * > Se puede leer el estado de un bit específico dentro de un registro
 */
void test_readBitZero()
{
    uint32_t valorInicial = 0xFFFFFFFF;
    uint32_t addr = 1;          // Registro a leer
    uint32_t bit = 5;           // Número de bit a leer
    bool valorEscrito = 0;      // Condición inicial del bit a leer
    bool valorLeido;

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, valorInicial);
    writeBit(addr, bit, valorEscrito);  // Condición inicial

    valorLeido = readBit(addr, bit);

    TEST_ASSERT_EQUAL(valorEscrito, valorLeido);
}

/**
 * > Se puede leer el estado de un bit específico dentro de un registro
 */
void test_readBitOne()
{
    uint32_t valorInicial = 0;
    uint32_t addr = 1;          // Registro a leer
    bool valorEscrito = 1;      // Número de bit a leer
    uint32_t bit = 5;           // Condición inicial del bit a leer
    bool valorLeido;

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, valorInicial);
    writeBit(addr, bit, valorEscrito);      // Condición inicial

    valorLeido = readBit(addr, bit);

    TEST_ASSERT_EQUAL(valorEscrito, valorLeido);
}


/**
 * > Se puede conocer el estado de configuración leyendo a una estructura, el modo, la habilitación de modulación y el tipo de modulación
 */
void test_readModState()
{   
    uint32_t addr = MOD_REGISTER;       // Para escribir la condición inicial en el registro de modulación
    modulationReg_t modInicial = {
                                .tmod = 1,
                                .mod = 1,
                                .cnP = 1
    };

    uint32_t estadoInicial = (modInicial.tmod << 2) | (modInicial.mod << 1) | modInicial.cnP;
    
    modulationReg_t modLeida;

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeReg(addr, estadoInicial);  // Condición inicial

    readModState(&modLeida);        // Función a testear               

    TEST_ASSERT_EQUAL(modInicial.tmod, modLeida.tmod);
    TEST_ASSERT_EQUAL(modInicial.mod, modLeida.mod);
    TEST_ASSERT_EQUAL(modInicial.cnP, modLeida.cnP);
}

/**
 * > Se puede configurar modo, habilitación de modulación y tipo de modulación mediante una estructura de configuración
 */
void test_writeModState()
{   
    modulationReg_t modAEscribir;
    modAEscribir.tmod = 1;
    modAEscribir.mod = 0;
    modAEscribir.cnP = 1;
    
    modulationReg_t modLeida;

    // Stub function callbacks para acceso al bus AXI
    Xil_Out32_Stub(Xil_Out32_Cb);
    Xil_In32_Stub(Xil_In32_Cb);

    writeModState(modAEscribir);    // Función a testear

    readModState(&modLeida);

    TEST_ASSERT_EQUAL(modAEscribir.tmod, modLeida.tmod);
    TEST_ASSERT_EQUAL(modAEscribir.mod, modLeida.mod);
    TEST_ASSERT_EQUAL(modAEscribir.cnP, modLeida.cnP);
}

