#ifndef __APP_H__
#define __APP_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>

void import_module(PyObject **, char *);
void import_function(PyObject *, PyObject **, char *);
PyObject* callback(PyObject *, PyObject *);

#endif
