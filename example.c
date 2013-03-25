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
		//addr_buffer = mac_gen();
		addr_buffer = "E0:E7:51:B7:03:66";
		// Print
		printf("Random MAC: %s\n", addr_buffer);
		printf("------------------------------------\n");
	
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
		
		printf("\n");
		
		// Print a random OUI
		printf("Random half MAC: %s\n", mac_gen_half());
		printf("------------------------------------\n");
		
		
		
		printf("Manufacturer: %s\n", mac_get_vendor(addr_buffer));
	
	}	
	
	return(0);
}
