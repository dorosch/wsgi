#ifndef __ENV_H__
#define __ENV_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>
#include <stdlib.h>

void expand_python_system_paths();
PyObject *get_env_dict(char **);

#endif
