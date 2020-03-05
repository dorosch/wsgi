#ifndef __APP_H__
#define __APP_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>

PyObject* import_module(char *);
PyObject* import_function(PyObject *, char *);
PyObject* callback(PyObject *, PyObject *);

#endif
