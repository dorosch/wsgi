#include "app.h"
#include "arg.h"
#include "env.h"


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

struct arguments args = {
    "127.0.0.1", 9000, "", "",
};


int main (int argc, char **argv, char **env) {
    PyObject *module = NULL;
    PyObject *function = NULL;
    PyObject *arguments = NULL;
    PyObject *environ = NULL;
    PyObject *start_response = NULL;

    Py_Initialize();
    expand_python_system_paths();

    argp_parse(&argp, argc, argv, 0, 0, &args);

    module = import_module(args.module);
    if (!module) goto exit;
    function = import_function(module, args.function);
    if (!function) goto exit;

    PyMethodDef callback_define = {
        "start_response", callback, METH_VARARGS, ""
    };
    start_response = PyCFunction_New(&callback_define, NULL);

    environ = get_env_dict(env);

    arguments = Py_BuildValue("OO", environ, start_response);

    PyObject_CallObject(function, arguments);

exit:
    Py_XDECREF(module);
    Py_XDECREF(function);
    Py_XDECREF(arguments);
    Py_XDECREF(environ);
    Py_XDECREF(start_response);
    Py_Finalize();

    return 0;
}
