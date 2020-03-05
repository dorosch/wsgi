#include "env.h"


static char *get_env_name(char *env) {
    char *position = NULL;
    char *variable = NULL;
    unsigned int length;

    position = strchr(env, '=');

    if (position) {
        length = position - env;

        variable = malloc(length + 1);
        memcpy(variable, env, length);
        variable[length] = '\0';
    }

    return variable;
}


PyObject *get_env_dict(char **env) {
    char *env_name = NULL;
    PyObject *key = NULL;
    PyObject *value = NULL;
    PyObject *dict = PyDict_New();

    while (*env) {
        env_name = get_env_name(*env++);

        key = PyUnicode_FromString(env_name);
        value = PyUnicode_FromString(getenv(env_name));
        PyDict_SetItem(dict, key, value);

        Py_DECREF(key);
        Py_DECREF(value);
        free(env_name);
    }

    return dict;
}
