#ifndef __ENV_H__
#define __ENV_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>
#include <stdlib.h>

PyObject *get_env_dict(char **);

#endif