// Simple example program using libmackerel

#include <stdio.h>
#include <string.h>

#include "libmackerel.c"

int main()
{
	// Misc variables
	int i;
	char *addr_buffer = {0};
	
	// Get CRC ready
	mac_init();
	
	// Main loop
	for (i = 1; i <= 10; i++)
	{
		// Create random MAC, save to buffer
		addr_buffer = mac_random();
		
		// Print
		printf("MAC: %s ", addr_buffer);
		
		// Encode it with CRC32
		printf("CRC: %s\n", mac_encode(addr_buffer));
	}	
	
	return(0);
}
