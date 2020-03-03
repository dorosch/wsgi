#include "app.h"
#include "args.h"


static char doc[] = "Just for fun wsgi server";

static char args_doc[] = "module function";

static struct argp_option options[] = {
    {"host", 'h', "HOST", 0, "Host"},
    {"port", 'p', "PORT", 0, "Port"},
    { 0 }
};

static struct argp argp = {
    options, parse_opt, args_doc, doc
};

struct arguments arguments = {
    "127.0.0.1", 9000, "", "",
};


int main (int argc, char **argv) {
    PyObject *module = NULL;
    PyObject *function = NULL;

    Py_Initialize();

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    import_module(&module, arguments.module);
    if (module) {
        import_function(module, &function, arguments.function);
    }

    Py_Finalize();

    return 0;
}
