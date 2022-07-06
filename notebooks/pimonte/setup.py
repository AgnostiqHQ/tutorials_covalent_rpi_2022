from distutils.core import setup, Extension

pimonte = Extension('pimonte', sources=['pimonte.c'],
    extra_compile_args=["-O3", "-fopenmp"])

setup(name='pimonte',
    version='1.0',
    description='A approximation to PI',
    ext_modules=[pimonte])