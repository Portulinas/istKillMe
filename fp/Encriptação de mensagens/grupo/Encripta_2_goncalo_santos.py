def e_primo(n):
    """
    e_primo: int--> log
    e_primo(n) recebe um numero inteiro positivo e verifica se e um numero primo
    """
    divisor = 2
    while divisor < n:
        if n % divisor == 0:
            return False
        divisor = divisor + 1
    return True

def n_esimo_primo(n):
    """
    n_esimo_primo: int--> int
    n_esimo_primo(n) recebe um numero inteiro positivo e devolve o numero primo
    correspondente a esse numero
    """
    i = 2
    conta = 0
    while conta < n:
        if e_primo(i):
            conta = conta + 1
        i = i + 1
    return (i-1)

def mdc(n,e):
    """
    mdc: int * int--> int
    mdc(n,e) recebe dois numeros inteiros positivos e devolve o maximo divisor
    comum entre os dois
    """
    while e != 0:
        n, e = e, n % e
    return n

def calcula_e(n):
    """
    calcula_e: int--> int
    calcula_e(n) recebe um numero inteiro positivo e devolve o valor da variavel 'e'
    """
    e = 2
    if int(n) == n and n > 0:
        while mdc(n,e) != 1:
            e = e + 1
    else:
        raise ValueError ('n tem de ser um numero inteiro positivo')
    if 1 < e < n:
        return e
    else:
        raise ValueError ('n tem que ser maior do que 2')

def calcula_d(e,n):
    """
    calcula_d: int * int--> int
    calcula_d(e,n) recebe a variavel 'e' e a variavel 'n' e devolve a variavel 'd'
    """
    k = 0
    d = (1 + k * n) / e
    if e > 0 and n > 0:    
        while int(d) != d:
            k = k + 1
            d = (1 + k * n) / e
        return int(d)
    else:
        raise ValueError ('e e n tem que ser inteiros positivo')

def calcula_m(i,j):
    """
    calcula_m: int * int--> int
    calcula_m(i,j): recebe dois numeros primos e devolve a variavel 'm'
    """    
    p = n_esimo_primo(i)
    q = n_esimo_primo(j)
    m = p * q  
    return m

def calcula_n(i,j):
    """calcula_n: int * int--> int
    calcula_m(i,j): recebe dois numeros primos e devolve a variavel 'n'
    """
    p = n_esimo_primo(i)
    q = n_esimo_primo(j)    
    n = (p - 1) * (q - 1)
    return n

def encripta(N,i,j):
    """encripta: int * int * int-->int
    encripta(N,i,j) recebe a mensagem original e dois numeros primos e devolve 
    a mensagem encriptada
    """
    m = calcula_m(i,j)
    n = calcula_n(i,j)
    e = calcula_e(n)
    if N >= m:
        raise ValueError ('encripta: a mensagem tem de ser inferior a ' + str(m))
    C = N ** e % m
    return C
    
def decifra(C,i,j):
    """
    decifra: int * int * int--> int
    decifra(C,i,j) recebe a mensagem encriptada e dois numeros primos e devolve 
    a mensagem original decifrada
    """
    m = calcula_m(i,j)
    n = calcula_n(i,j)
    e = calcula_e(n)
    d = calcula_d(e,n)
    if C >= m:
        raise ValueError ('decifra: a mensagem tem de ser inferior a ' + str(m))
    N = C ** d % m
    return N