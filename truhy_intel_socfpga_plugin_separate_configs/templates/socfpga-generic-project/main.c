/*
	Version: 20240428
	Target: ARM Cortex-A9 on the DE10-Nano development board

	Template main.
*/

#include "tru_logger.h"

#ifdef SEMIHOSTING
	extern void initialise_monitor_handles(void);  // Reference function header from the external Semihosting library
#endif

void wait_forever(void){
	DEBUG_PRINTF("Starting infinity loop\n");
	while(1);
}

int main(int argc, char **argv){
	#ifdef SEMIHOSTING
		initialise_monitor_handles();  // Initialise Semihosting
	#endif

	wait_forever();

	return 0;
}
