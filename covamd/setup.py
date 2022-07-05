from distutils.core import setup, Extension

covamd = Extension('covamd', sources=['covamd.c'])

setup(name='covamd', version='1.0', description='MD using Covalent', ext_modules=[covamd])