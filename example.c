// Simple example program using libmackerel

#include <stdio.h>

#include "libmackerel.c"

int main()
{
	// Misc variables
	int i;
	char *addr_buffer = {0};
	
	// Get CRC ready
	mac_init();
	
	// Main loop
	for (i = 1; i <= 1; i++)
	{
		// Create random MAC, save to buffer
		addr_buffer = mac_random();
		
		// Print
		printf("Random MAC: %s\n", addr_buffer);
		printf("------------------------------------\n");
	
		// See if it's a MAC
		if (mac_verify(addr_buffer) == 0)
			printf("This is a valid MAC.\n");
		else
			printf("This is not a valid MAC!\n");
			
		// Print OUI
		printf("OUI: %s\n", mac_get_oui(addr_buffer));
		
		// Encode it with CRC32
		printf("CRC: %s\n", mac_encode(addr_buffer));

		// Obfuscate
		printf("Anonymized: %s\n", mac_obfuscate(addr_buffer));
		
		printf("\n");
		
		// Print a random OUI
		printf("Random half MAC: %s\n", mac_random_half());
		printf("------------------------------------\n");
		
		//printf("Manufacturer: %s\n", mac_get_manufacturer("f0def1"));
	}	
	
	return(0);
}
