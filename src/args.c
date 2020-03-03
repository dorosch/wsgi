#include "args.h"


error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;

    switch (key) {
        case 'h':
            arguments->host = arg;
            break;
        case 'p':
            arguments->port = atoi(arg);
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num > 0) {
                argp_usage(state);
                break;
            }
            arguments->module = arg;
            break;
        case ARGP_KEY_END:
            if (!state->arg_num) {
                argp_usage(state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}
