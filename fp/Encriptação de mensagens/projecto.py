def mdc(e,n):
    """
    mdc(e, n) devolve o maximo divisor comum entre as variaveis 'e' e 'n'
    """
    while e % n != 0:
        e, n = n, e%n
    return n 


def calcula_e(n):
    """
    calcula_e(n) gera um valor entre se situe 1 e 'n' e seja verdadeira para operacao mdc(e,n)==1
    Utiliza as funcoes: mdc(e,n)
    """
    e=2
    while e<n:
        if mdc(n,e) ==1:
            return e
        else:
            e = e+1
            
        
def calcula_d(e,n):
    """
    
    """
    k = 1
    d = (1 + k * n)/(e)
    while int(d) != (1+k *n)/(e):
        k = k +1
        d = (1 + k * n)/(e)
    return int(d)

def ver_primo(n):
    """
    
    """
    i=2
    while i<n:
        if n%i == 0:
            return False
        i = i+1
    return True
   
def n_esimo_primo(n):
    """
    
    """
    i = 2
    conta = 0
    while conta < n:
        if ver_primo(i):
            conta = conta + 1
        i = i + 1
    return(i-1)

def encripta(N,i,j):
    """
    
    """
    p = n_esimo_primo(i)
    q = n_esimo_primo(j)

    m = p*q
    n = (p-1)*(q-1)    

    if N >= m:
        raise ValueError('encripta: a mensagem tem de ser inferior a ' + str(m))
    else:
        C = (N**calcula_e(n)) % m
        return C

def decifra(C,i,j):
    """
    
    """
    m = n_esimo_primo(i)*n_esimo_primo(j)
    n = (n_esimo_primo(i)-1)*(n_esimo_primo(j)-1)    

    if C >= m:
        raise ValueError('decifra: a mensagem tem de ser inferior a ' + str(m))
    else:    
        N = (C**calcula_d(calcula_e(n),n)) % m
        return N