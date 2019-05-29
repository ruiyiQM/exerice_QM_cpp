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

#print local_dot(A,B)-np.dot(A,B)
import ctypes
test=[1,2,3]
A=np.ones((100,100))
B=np.diag(np.ones((100)))
C=np.ones((100,100))

test=[A.ctypes.data_as(ctypes.c_void_p),B.ctypes.data_as(ctypes.c_void_p),C.ctypes.data_as(ctypes.c_void_p)]*100
arr = (ctypes.c_void_p * len(test))(*test)
#print test,arr
data1 = [np.zeros((100)) for i in range(3)]*100
result_value=[l.ctypes.data_as(ctypes.c_void_p) for l in data1]
#print  result_value
value = (ctypes.c_void_p * len(result_value))(*result_value)

data2 = [np.zeros((100,100)) for i in range(3)]*100
result_vector=[m.ctypes.data_as(ctypes.c_void_p) for m in data2]
vector = (ctypes.c_void_p * len(result_vector))(*result_vector)
#print result_vector
size = [100,100,100]*100
size = (ctypes.c_int * len(size))(*size)
lib.peig(arr,size,ctypes.c_int(300),value,vector)
#print data1
#print data2
#./c	print result_value

#result_value = np.zeros((3))
#result_vector = np.zeros((3,3))

#lib.test_eig(A.ctypes.data_as(ctypes.c_void_p),ctypes.c_int(3),ctypes.c_int(1),result_value.ctypes.data_as(ctypes.c_void_p),result_vector.ctypes.data_as(ctypes.c_void_p))
