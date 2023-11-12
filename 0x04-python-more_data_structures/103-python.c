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

    printf("  size: %ld\n", ((PyVarObject *)p)->ob_size);

    printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);

    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < ((PyVarObject *)p)->ob_size && i < 10; ++i) {
        printf("%02x ", ((unsigned char *)((PyBytesObject *)p)->ob_sval)[i]);
    }
    printf("\n");
}

void print_python_list(PyObject *p) {
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");

    size = ((PyVarObject *)p)->ob_size;
    printf("[*] Size of the Python List = %ld\n", size);

    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; ++i) {
        item = ((PyListObject *)p)->ob_item[i];
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
