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

struct arguments args = {
    "127.0.0.1", 9000, "", "",
};


int main (int argc, char **argv) {
    PyObject *module = NULL;
    PyObject *function = NULL;
    PyObject *arguments = NULL;
    PyObject *environ = PyDict_New();
    PyObject *start_response = NULL;

    Py_Initialize();
    PyObject* sys_path = PySys_GetObject((char*) "path");
    PyList_Append(sys_path, PyUnicode_FromString("."));

    argp_parse(&argp, argc, argv, 0, 0, &args);

    import_module(&module, args.module);
    if (module) {
        import_function(module, &function, args.function);
    }

    PyMethodDef callback_define = {
        "start_response", callback, METH_VARARGS, ""
    };
    start_response = PyCFunction_New(&callback_define, NULL);

    arguments = Py_BuildValue("OO", environ, start_response);

    PyObject_CallObject(function, arguments);

    Py_Finalize();

    return 0;
}
