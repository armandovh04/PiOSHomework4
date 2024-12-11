#include <stdint.h>

// Define the MU IO register address for Raspberry Pi 5
#define MU_IO_REG ((volatile uint32_t *)(0xFE215040))

// Function to write a single character to the serial port
void putc(int data) {
  *MU_IO_REG = (uint32_t)data;
}

void print_execution_level(int (*getEL)(void)) {
  extern void esp_printf(void (*putc_func)(int), const char *fmt, ...);
  esp_printf(putc, "Current Execution Level is %d\r\n", getEL());
}
