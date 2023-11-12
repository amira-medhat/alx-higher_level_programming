#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec;

#include <Python.h>

void print_python_bytes(PyObject *p) {
    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }
    printf("  size: %ld\n", PyBytes_Size(p));
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first 10 bytes: ");
    fflush(stdout);
    for (int i = 0; i < 10 && i < PyBytes_Size(p); i++) {
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
    }
    printf("\n");
}

void print_python_list(PyObject *p) {
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");
    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %ld: ", i);

        if (PyBytes_Check(item)) {
            printf("bytes\n");
            print_python_bytes(item);
        } else if (PyFloat_Check(item)) {
            printf("float\n");
        } else if (PyList_Check(item)) {
            printf("list\n");
            print_python_list(item);
        } else if (PyLong_Check(item)) {
            printf("int\n");
        } else if (PyTuple_Check(item)) {
            printf("tuple\n");
        } else if (PyUnicode_Check(item)) {
            printf("str\n");
        }
    }
}
