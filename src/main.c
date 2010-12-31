#include <stdio.h>
#include "version.h"

int usage(int code)
{
    printf("Hello world example %s\n"
           "Copyright Jiang Xin <jiangxin AT ossxp DOT com>, 2009.\n"
           "\n"
           "Usage:\n"
           "    hello\n"
           "            say hello to the world.\n\n"
           "    hello <username>\n"
           "            say hi to the user.\n\n"
           "    hello -h, -help\n"
           "            this help screen.\n\n", _VERSION);
    return code;
}

int
main(int argc, char **argv)
{
    if (argc == 1) {
        printf ("Hello world.\n");
    } else if ( strcmp(argv[1],"-h") == 0 ||
                strcmp(argv[1],"--help") == 0 ) {
                return usage(0);
    } else {
        printf ("Hi, %s.\n", argv[1]);
    }

    printf( "(version: %s)\n", _VERSION );
    return 0;
}
