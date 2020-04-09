#include "build/temp/_test_tp4.c"
#include "src/my_stubs.h"
#include "build/test/mocks/mock_xil_io.h"
#include "src/tp4.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


void test_readReg()

{

    uint32_t dato = 0xFFFFFFFF;

    uint32_t addr = 0;





    Xil_In32_CMockExpectAndReturn(26, addr, dato);



    uint32_t retVal = readReg(addr);



    UnityAssertEqualNumber((UNITY_INT)((dato)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}









void test_writeReg()

{

    uint32_t dato = 0xFFFFFFFF;

    uint32_t addr = 0;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, dato);

    uint32_t retVal = readReg(addr);



    UnityAssertEqualNumber((UNITY_INT)((dato)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}











void test_writeBitTrue()

{

    

   _Bool 

        valor = 1;

    uint32_t bit = 5;

    uint32_t addr = 0;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, 0);



    writeBit(addr, bit, valor);

    uint32_t retVal = readReg(addr);



    UnityAssertEqualNumber((UNITY_INT)(((valor << bit))), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

}











void test_writeBitFalse()

{

    uint32_t valorInicial = 0xFFFFFFFF;



    

   _Bool 

        valor = 0;

    uint32_t bit = 5;

    uint32_t addr = 0;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, valorInicial);



    writeBit(addr, bit, valor);

    uint32_t retVal = readReg(addr);



    UnityAssertEqualNumber((UNITY_INT)((valorInicial & ~(1 << bit))), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

}









void test_readBitZero()

{

    uint32_t valorInicial = 0xFFFFFFFF;

    uint32_t addr = 1;

    uint32_t bit = 5;

    

   _Bool 

        valorEscrito = 0;

    

   _Bool 

        valorLeido;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, valorInicial);

    writeBit(addr, bit, valorEscrito);



    valorLeido = readBit(addr, bit);



    UnityAssertEqualNumber((UNITY_INT)((valorEscrito)), (UNITY_INT)((valorLeido)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}









void test_readBitOne()

{

    uint32_t valorInicial = 0;

    uint32_t addr = 1;

    

   _Bool 

        valorEscrito = 1;

    uint32_t bit = 5;

    

   _Bool 

        valorLeido;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, valorInicial);

    writeBit(addr, bit, valorEscrito);



    valorLeido = readBit(addr, bit);



    UnityAssertEqualNumber((UNITY_INT)((valorEscrito)), (UNITY_INT)((valorLeido)), (

   ((void *)0)

   ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);

}











void test_readModState()

{

    uint32_t addr = 1;

    modulationReg_t modInicial = {

                                .tmod = 1,

                                .mod = 1,

                                .cnP = 1

    };



    uint32_t estadoInicial = (modInicial.tmod << 2) | (modInicial.mod << 1) | modInicial.cnP;



    modulationReg_t modLeida;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeReg(addr, estadoInicial);



    readModState(&modLeida);



    UnityAssertEqualNumber((UNITY_INT)((modInicial.tmod)), (UNITY_INT)((modLeida.tmod)), (

   ((void *)0)

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((modInicial.mod)), (UNITY_INT)((modLeida.mod)), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((modInicial.cnP)), (UNITY_INT)((modLeida.cnP)), (

   ((void *)0)

   ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_INT);

}









void test_writeModState()

{

    modulationReg_t modAEscribir;

    modAEscribir.tmod = 1;

    modAEscribir.mod = 0;

    modAEscribir.cnP = 1;



    modulationReg_t modLeida;





    Xil_Out32_Stub(Xil_Out32_Cb);

    Xil_In32_Stub(Xil_In32_Cb);



    writeModState(modAEscribir);



    readModState(&modLeida);



    UnityAssertEqualNumber((UNITY_INT)((modAEscribir.tmod)), (UNITY_INT)((modLeida.tmod)), (

   ((void *)0)

   ), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((modAEscribir.mod)), (UNITY_INT)((modLeida.mod)), (

   ((void *)0)

   ), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((modAEscribir.cnP)), (UNITY_INT)((modLeida.cnP)), (

   ((void *)0)

   ), (UNITY_UINT)(195), UNITY_DISPLAY_STYLE_INT);

}
