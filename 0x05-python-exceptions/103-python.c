#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec;

#include <Python.h>

void print_python_list(PyObject *p) {
    printf("[*] Python list info\n");

    if (!PyObject_TypeCheck(p, &PyList_Type)) {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyObject_Length(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, element->ob_type->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    printf("[.] bytes object info\n");

    if (!PyObject_TypeCheck(p, &PyBytes_Type)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyObject_Length(p);
    printf("  size: %zd\n", size);

    printf("  trying string: ");
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf("%02x ", (unsigned char)((PyBytesObject *)p)->ob_sval[i]);
    }
    printf("\n");
}
