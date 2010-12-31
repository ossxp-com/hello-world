#include <stdio.h>
#include <getopt.h>

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
    int c;
    char *uname = NULL;

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"help", 0, 0, 'h'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "h",
                        long_options, &option_index);
        if (c == -1)
           break;

        switch (c) {
        case 'h':
            return usage(0);
        default:
            return usage(1);
        }
    }

    if (optind < argc) {
        uname = argv[optind];
    }

    if (uname == NULL) {
        printf ("Hello world.\n");
    } else {
        printf ("Hi, %s.\n", uname);
    }

    printf( "(version: %s)\n", _VERSION );
    return 0;
}


/*
 * vim: et ts=4 sw=4
 */
