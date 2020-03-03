#ifndef __APP_H__
#define __APP_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>

void import_module(PyObject **, char *);
void import_function(PyObject *, PyObject **, char *);
void build_arguments(PyObject **);

PyObject* callback(PyObject *, PyObject *);

#endif
