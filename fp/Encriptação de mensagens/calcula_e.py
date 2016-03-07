def calcula_e(n):
    e=2
    while e<n:
        if mdc(n,e) ==1:
            return e
        else:
            e = e+1