# performance of a program

from time import time


def performance(func):
    def wrapper(*args, **kwargs):
        t1 = time()
        result = func(*args, **kwargs)
        t2 = time()
        print(f'took {t2 - t1}s')
        return result
    return wrapper


@performance
def calculate_time():
    for i in range(100000):
        i / 20


calculate_time()
