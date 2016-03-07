def mdc(e,n):
    while e % n != 0:
        e, n = n, e%n
    return n