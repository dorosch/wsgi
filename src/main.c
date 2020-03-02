#include <argp.h>
#include <error.h>
#include <stdlib.h>


const char *argp_program_version = "wsgi-0.1";

const char *argp_program_bug_address = "<dorosch.github.io@yandex.ru>";

static char doc[] = "Pure wsgi server";

static char args_doc[] = "";

static struct argp_option options[] = {
  {"host", 'h', "HOST", 0, "Host"},
  {"port", 'p', "PORT", 0, "Port"},
  { 0 }
};

struct arguments {
  char *host;
  int port;
};


static error_t parse_opt(int key, char *arg, struct argp_state *state) {
  struct arguments *arguments = state->input;

  switch (key) {
    case 'h':
      arguments->host = arg;
      break;
    case 'p':
      arguments->port = atoi(arg);
      break;
    default:
      return ARGP_ERR_UNKNOWN;
  }

  return 0;
}


int main (int argc, char **argv) {
  struct arguments arguments;
  static struct argp argp = {
    options,
    parse_opt,
    args_doc,
    doc
  };

  arguments.host = "127.0.0.1";
  arguments.port = 9000;

  argp_parse(&argp, argc, argv, 0, 0, &arguments);

  printf("http://%s:%d\n", arguments.host, arguments.port);

  return 0;
}
