def failsafe(func):
    """\
    Decorator (wrapper):\tDon't crash the program\
    if an exception is thrown while executing this function.\
    """
    def decorated(*args, **kwargs):
        try:
            result = func(*args, **kwargs)
        except:
            print(f"function '{func.__name__}' failed",
                f"with args {args}" if args else '',
                f"keyword args {kwargs}" if kwargs else '')
            return None
        return result
    
    return decorated


@failsafe
def add(a, b):
    return a + b


print(f"int + int: { add(1, 2) }")
print(f"str + str: { add('a', 'b') }")
print(f"int + str: { add(1, 'b') }")
