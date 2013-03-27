// Header file for libmackerel
#ifndef LIBMACKEREL_H
#define LIBMACKEREL_H
int mac_init();
int mac_verify();
char* mac_rand ();
char* mac_rand_half();
char* mac_encode (char* mac);
char* mac_get_oui(char* mac);
char* mac_get_hex (char* mac);
char* mac_obfuscate (char* mac);
char* mac_get_vendor (char* mac);
#endif
