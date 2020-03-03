#include "app.h"


void import_module(PyObject **module, char *name) {
    PyObject *module_name;

    module_name = PyUnicode_FromString(name);
    *module = PyImport_Import(module_name);
    Py_DECREF(module_name);
}


void import_function(PyObject *module, PyObject **function, char *name) {
    *function = PyObject_GetAttrString(module, name);

    if (!PyCallable_Check(*function)) {
        fprintf(stderr, "Object '%s' is not callable\n", name);
        *function = NULL;
    }
}
