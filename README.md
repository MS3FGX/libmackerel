![Mackerel](http://www.digifail.com/images/misc/mackerel_header.jpg "Mackerel")

libmackerel
==============

### MAC - 48-bit address media access control address
### kerel - (verb, Romani language) To do, make, or produce

libmackerel is a library for doing string manipulations of MAC-48 addresses. It
can create, obfuscate, and encode MAC addresses, and a bunch of other things I
thought would be useful.

Usage
==============
Looking in example.c should give you an idea of how libmackerel can be used, it
shows essentially all the basic functions.

I've provided the header file necessary to build libmackerel into an object and
use it like a "proper" library (see the example Makefile), but the lazy people
(myself included) can just #include the libmackerel.c file into their program.

Functions
==============
Current libmackerel functions:

#### mac_init ()
This is required to get libmackerel setup properly, use it before anything
else.

#### mac_rand ()
This function creates a completely random MAC address.

#### mac_rand_half ()
Same as regular "rand" function, but only returns half the characters. Good for
random OUI or device ID.

#### mac_verify (char* MAC)
Give this function a MAC address, and it will return a 0 if it's valid, and a
1 if it isn't. This function can be fooled maliciously, but should be good
enough to weed out garbage.

#### mac_obfuscate (char* MAC)
This returns the MAC address with the device ID portion X'd out. (AA:BB:XX:XX)

#### mac_encode (char* MAC)
This performs a one-way CRC32 encoding on the MAC address. It will give you a
completely unique ID for that device, but the ID cannot be reversed to get the
original MAC back. This function is useful when you don't want to store the
actual MAC addresses of devices, but want to be able to ID them in the future.

#### mac_get_oui (char* MAC)
This function will return the OUI segment of a given MAC address.

#### mac_get_hex (char* MAC)
Passing a MAC address in standard colon notation (AA:BB:CC:DD) will return the
MAC with dash notation (AA-BB-CC-DD).

#### mac_get_vendor (char* MAC)
This function will return the name of the manufacturer for a given MAC using
the IEEE database. To generate an up-to-date local copy of the database for
libmackerel, use the included "gen_oui.sh" script.

Acknowledgements
==============

libmackerel implements a modified version of the CRC hashing functions from
"CRC Tester" by Sven Reifegerste.

Sven's page about CRC encoding: http://www.zorc.breitbandkatze.de/crc.html

The randomized MAC function got its start in "SpoofTooph", written by JP
Dunning (.ronin).

You can read more about JP Dunning's projects on his site:
http://www.hackfromacave.com/

libmackerel uses a modified version of the OUI lookup code from the "BlueZ"
project by Marcel Holtmann.

For more information, check out the official BlueZ site:
http://www.bluez.org/

License
==============

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License version 2 as published by the Free
Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

For details, see the file "COPYING" in the source directory.

More Info
==============

For more information and updates, please see www.digifail.com
