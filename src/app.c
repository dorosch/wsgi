#include "app.h"


PyObject* import_module(char *name) {
    PyObject *module = NULL;
    PyObject *module_name = NULL;

    module_name = PyUnicode_FromString(name);
    module = PyImport_Import(module_name);

    Py_DECREF(module_name);

    return module;
}


PyObject* import_function(PyObject *module, char *name) {
    PyObject *function = NULL;

    function = PyObject_GetAttrString(module, name);

    if (!PyCallable_Check(function)) {
        function = NULL;
    }

    return function;
}


PyObject* callback(PyObject *self, PyObject *args) {
    Py_RETURN_NONE;
}
