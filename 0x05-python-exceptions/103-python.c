#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec;

#include <Python.h>

void print_python_list(PyObject *p) {
    printf("[*] Python list info\n");

    if (!PyList_Check(p)) {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(element)->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    printf("  size: %zd\n", size);

    printf("  trying string: %s\n", PyBytes_AsString(p));

    printf("  first %d bytes: ", (int)(size > 10 ? 10 : size));
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    printf("[.] float object info\n");

    if (!PyFloat_Check(p)) {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    printf("  value: %.17g\n", PyFloat_AsDouble(p));
}
