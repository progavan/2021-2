#REF:
#https://stackoverflow.com/questions/15146152/how-to-get-the-absolute-path-of-specific-header-file
cpp -MD -I"C:\Program Files (x86)\wxWidgets\include\wx-3.1" -I"C:\Program Files (x86)\wxWidgets\lib\wx\include\msw-unicode-3.1" main.cpp | sed -n '/\.h"/s/.*"\(.*\)".*/\1/p' | sort -u > main.headers
#cpp -MD $1 | sed -n '/\.h"/s/.*"\(.*\)".*/\1/p' | sort -u
