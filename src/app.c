#include "app.h"


void import_module(PyObject **module, char *name) {
    PyObject *module_name;

    module_name = PyUnicode_FromString(name);
    *module = PyImport_Import(module_name);
    Py_DECREF(module_name);
}
