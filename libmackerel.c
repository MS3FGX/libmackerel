/*
 *  libmackerel - Library to manipulate MAC strings
 * 
 *  Written by Tom Nardi (MS3FGX@gmail.com), released under the GPLv2.
 *  For more information, see: www.digifail.com
 */

#include <time.h>
#include <stdlib.h>

#define LIBVERSION "0.1"
#define LIBNAME "libmackerel"

/*
 * CRC functions based on CRC tester 1.3 written by Sven Reifegerste
 * Available at: http://www.zorc.breitbandkatze.de/crc.html
*/

// CRC parameters (default values are for CRC-32):
const int order = 32;
const unsigned long polynom = 0x4c11db7;
const int direct = 1;
const unsigned long crcinit = 0xffffffff;
const unsigned long crcxor = 0xffffffff;
const int refin = 1;
const int refout = 1;

// Global values:
unsigned long crcmask;
unsigned long crchighbit;
unsigned long crcinit_direct;
unsigned long crcinit_nondirect;
unsigned long crctab[256];

// Get things ready
int mac_init ()
{
	// Make sure PRNG is seeded for MAC gen
	srand(time(NULL));
	
	// This sets up CRC encoding
	int i;
	unsigned long bit, crc;

	crcmask = ((((unsigned long)1<<(order-1))-1)<<1)|1;
	crchighbit = (unsigned long)1<<(order-1);

	crcinit_direct = crcinit;
	crc = crcinit;
	for (i=0; i<order; i++)
	{
		bit = crc & 1;
		if (bit) crc^= polynom;
			crc >>= 1;

		if (bit) crc|= crchighbit;	
	}	
	crcinit_nondirect = crc;
	return(0);
}

// Generate random MAC address
// Adapted from "SpoofTooph" by JP Dunning (.ronin)
char* mac_random (void)
{	
	char addr_part[3] = {0};
	static char addr[18] = {0};
	int i = 0;
	
	// Fill in the middle
	while ( i < 14)
	{
		sprintf(addr_part, "%02x", (rand() % 254));	
		addr[i++] = addr_part[0];
		addr[i++] = addr_part[1];
		addr[i++] = ':';
	}

	// Tack 2 more random characters to finish it
	sprintf(addr_part, "%02x", (rand() % 254));	
	addr[i++] = addr_part[0];
	addr[i++] = addr_part[1];

	return(addr);
}

// Used internally for CRC
unsigned long reflect (unsigned long crc, int bitnum)
{
	unsigned long i, j=1, crcout=0;
	for (i=(unsigned long)1<<(bitnum-1); i; i>>=1) {
		if (crc & i) crcout|=j;
		j<<= 1;
	}
	return (crcout);
}

// Encode MAC with CRC32
char* mac_encode (char* p)
{
	unsigned long i, j, c, bit;
	unsigned long crc = crcinit_direct;
	
	// Static length, fix this
	int len = 17;
	
	// For return formatting
	static char addr[18] = {0};

	for (i=0; i < len; i++)
	{
		c = (unsigned long)*p++;
		if (refin) c = reflect(c, 8);

		for (j=0x80; j; j>>=1) {

			bit = crc & crchighbit;
			crc<<= 1;
			if (c & j) bit^= crchighbit;
			if (bit) crc^= polynom;
		}
	}	

	if (refout) crc=reflect(crc, order);
	crc^= crcxor;
	crc&= crcmask;

	// Format it
	sprintf(addr,"%.8X",(unsigned int)crc);
	return(addr);
}
