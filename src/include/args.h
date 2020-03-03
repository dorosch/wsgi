#ifndef __ARGS_H__
#define __ARGS_H__

#include <argp.h>
#include <stdlib.h>


error_t parse_opt(int, char *, struct argp_state *);

struct arguments {
    char *host;
    int port;
};

#endif
