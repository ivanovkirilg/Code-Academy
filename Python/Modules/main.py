### WAYS TO IMPORT

# import module1
# module1.log('Hello world!')

# from module1 import log
# log('Hello again!')

# from module1 import *
# log('hi')


### ONLY EXECUTED ONCE

# import module1

# module1.name = 'Anastasia'
# import module1
# module1.log(module1.name)


### (IM)MUTABLE, IMPORTLIB
from small import *

immut = 42
mut[0] = 42

print('in main:', mut, immut)
show_vars()


print('importing entire module...')
import small
import importlib

small.show_vars()
print('in main:', mut, immut, '(without module name)')
print('in main:', small.mut, small.immut, '(with module name)')

print('reloading module...')
importlib.reload(small)

small.show_vars()
print('in main:', mut, immut)
