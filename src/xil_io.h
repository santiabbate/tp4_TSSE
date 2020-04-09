// Xilinx Input Output Functions to AXI Memory Mapped Registers


#define UINTPTR uint32_t
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

uint8_t Xil_In8(UINTPTR Addr);
uint16_t Xil_In16(UINTPTR Addr);
uint32_t Xil_In32(UINTPTR Addr);
uint64_t Xil_In64(UINTPTR Addr);

void Xil_Out8(UINTPTR Addr, u8 Value);
void Xil_Out16(UINTPTR Addr, u16 Value);
void Xil_Out32(UINTPTR Addr, u32 Value);
void Xil_Out64(UINTPTR Addr, u64 Value);