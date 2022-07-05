#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h>
#include <stdio.h>


static struct Coordinate {
    double x;
    double y;
};


/*
Routine to compute the total potential energy of all the particles in the system
Input(s)
List of particles instances
Potential object
Simulation domain
*/
PyObject* TotalPotentialEnergy(PyObject *self, PyObject *args) {

    printf("here\n");
    PyObject *particles;
    PyObject *potential;
    PyObject *domain;
    double x = 0.0;

    double total = 0.0;
    // Extract all coordinates into arrays

    Py_ssize_t numParticles = PyList_Size(particles);

    struct Coordinate* coordinates = (struct Coordinate*)malloc(numParticles*sizeof(struct Coordinate));

    for (Py_ssize_t i = 0; i < numParticles; i++) {
        PyArg_Parse(PyObject_GetAttrString(PyList_GetItem(particles, i), "x"), "d", &coordinates[i].x);
        PyArg_Parse(PyObject_GetAttrString(PyList_GetItem(particles, i), "y"), "d", &coordinates[i].y);
    }


    for (int i = 0; i < numParticles; i++) {
        printf("Particle %d, x=%lf, y=%lf\n", i, coordinates[i].x, coordinates[i].y);
    }


    free(coordinates);


    return Py_None;
}

static PyMethodDef CovaMDMethods[] = {
    {"total_pe", *TotalPotentialEnergy, METH_VARARGS, "Python interface for computing the total potential energy"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef covaMDModule = {
    PyModuleDef_HEAD_INIT,
    "covamd",
    NULL,
    -1,
    CovaMDMethods
};

PyMODINIT_FUNC PyInit_covamd(void) {
    return PyModule_Create(&covaMDModule);
}
