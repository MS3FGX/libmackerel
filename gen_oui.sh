#!/bin/bash
# Generate OUI list for libmackerel

# Delete existing
rm oui.*

# Get new, strip
echo "Downloading file from IEEE..."
wget -O oui.tmp http://standards.ieee.org/develop/regauth/oui/oui.txt

echo "Reformatting..."
grep "(hex)" oui.tmp | awk '{print $1","$3,$4,$5,$6,$7,$8}' > oui.txt
sed -i 's/-/:/g' oui.txt

# Clean up
rm oui.tmp

echo "Done."
#EOF
