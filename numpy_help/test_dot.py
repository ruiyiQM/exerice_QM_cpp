import ctypes
import os
import sys
import numpy as np
#from functools import reduce, partial, update_wrapper #wraps
#dot = ctypes.CDLL(r'/home/ruiyi/exerice_QM_cpp/numpy_help/dot_test.so')
from ctypes import cdll
lib = cdll.LoadLibrary('/home/ruiyi/exerice_QM_cpp/numpy_help/dot_test.so')
def local_dot(A,B):
    m=A.shape[0]
    n=A.shape[1]
    l=B.shape[1]
    C=np.zeros((m,l),order='C')
    lib.dot(A.ctypes.data_as(ctypes.c_void_p),B.ctypes.data_as(ctypes.c_void_p),C.ctypes.data_as(ctypes.c_void_p),ctypes.c_int(m),ctypes.c_int(n),ctypes.c_int(l))
    return C



A=np.asarray(np.random.random((10,10)))
B=np.asarray(np.random.random((10,10)))

print local_dot(A,B)-np.dot(A,B)
