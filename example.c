// Simple example program using libmackerel

#include <stdio.h>

#include "libmackerel.h"

int main()
{
	// Misc variables
	int i;
	char *addr_buffer = {0};
	
	// How many MACs to create
	int runs = 5;
	
	// Get libmackerel ready
	mac_init();
	
	// Working with a static MAC
	addr_buffer = "F0:DE:F1:B7:0E:F6";
	
	printf("MAC: %s\n", addr_buffer);
	printf("----------------------------\n");
	
	// See if it's a MAC
	if (mac_verify(mac_get_hex(addr_buffer)) == 0)
		printf("This is a valid MAC.\n");
	else
		printf("This is not a valid MAC!\n");
		
	// Print OUI
	printf("OUI: %s\n", mac_get_oui(addr_buffer));
		
	// Encode it with CRC32
	printf("CRC: %s\n", mac_encode(addr_buffer));

	// Obfuscate
	printf("Anonymized: %s\n", mac_obfuscate(addr_buffer));
					
	// Hex version
	printf("HEX notation: %s\n", mac_get_hex(addr_buffer));
	
	// Manufacturer
	printf("Manufacturer: %s\n", mac_get_vendor(addr_buffer));
		
	printf("\n");
	
	printf("Random MACs:\n");
	// Main loop
	for (i = 1; i <= runs; i++)
	{
		// Create random MAC, save to buffer
		addr_buffer = mac_rand();
		
		// Print
		printf("%s\n", addr_buffer);	
	}	
	
	return(0);
}
