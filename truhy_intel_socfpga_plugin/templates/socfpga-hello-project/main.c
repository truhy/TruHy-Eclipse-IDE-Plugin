/*
	Version: 20240505
	Target : ARM Cortex-A9 on the DE10-Nano development board

	Template main.

	A basic "Hello, World!" bare-metal C program for the DE10-Nano
	development board.  It is for the SoC (aka HPS) part of the FPGA so it
	should work on other Cyclone V SoC-FPGA dev boards, e.g.: DE1-SoC, DE-10
	Standard, Arrow SoCKit, etc.
*/

#include "tru_logger.h"
#include <stdio.h>

#ifdef SEMIHOSTING
	extern void initialise_monitor_handles(void);  // Reference function header from the external Semihosting library
#endif

int main(int argc, char **argv){
	#ifdef SEMIHOSTING
		initialise_monitor_handles();  // Initialise Semihosting
	#endif

	printf("Hello, World!\n");

	DEBUG_PRINTF("Starting infinity loop\n");
	while(1);

	return 0;
}
