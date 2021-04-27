def add(a, b): 
    if type(a) == int and type(b) == str or type(b) == int and type(a) == str: 
        return a * b
    return a + b

print(add(1, 2), add('a', 'b'), add(2, 'a'), add('b', 2)    )
