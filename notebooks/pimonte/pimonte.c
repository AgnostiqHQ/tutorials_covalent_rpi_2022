#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* compute_pi(PyObject* self, PyObject* args) {
    unsigned int partitions;
    double area = 0.0;
    double dh;

    if (!PyArg_ParseTuple(args, "I", &partitions)) {
        return NULL;
    }

    dh = 1.0/partitions;

    for (int i = 0; i < partitions; i++) {
        double x = dh * (i - 0.5);
        area += (4.0/(1.0 + x*x));
    }


    // pi approximation
    return PyFloat_FromDouble(area*dh);
}

static PyMethodDef PimonteMethods[] = {
    {"compute_pi",  compute_pi, METH_VARARGS, "Compute an approximation to PI"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef pimonte = {
    PyModuleDef_HEAD_INIT,
    "pimonte",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    PimonteMethods
};


PyMODINIT_FUNC PyInit_pimonte(void) {
    return PyModule_Create(&pimonte);
}