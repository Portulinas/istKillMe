def calcula_e (n):
    e=2
    while e<n:
        if mdc(n,e):
            return e
        else:
            e=e+1

def mdc(maior,menor):
    while menor!=0:
        maior,menor= menor,maior%menor
    if maior ==1:
        return True
    else:
        return False



def calcula_d (e,n):
    for k in range (n):
        d=(1+k*n)//e
        if (((1+k*n)/e)-int(((1+k*n)/e)))==0:
            return d
     
               
        
def e_primo (n):
    divisor=2
    while divisor<n:
        if n%divisor==0:
            return False
        divisor=divisor+1
    return True

def n_esimo_primo (n):
    conta=0
    divisor=2
    while conta<n:
        if e_primo(divisor):
            conta=conta+1
        divisor=divisor+1
    return (divisor-1)

def encripta (N,i,j):
    p=n_esimo_primo(i)
    q=n_esimo_primo(j)
    m=p*q
    n=(p-1)*(q-1)
    e=calcula_e(n)
    if N>=m:
        raise ValueError('encripta: a mensagem tem de ser inferior a '+str(m))  
    C=N**e%m
    return C


def decifra (C,i,j):
    p=n_esimo_primo(i)
    q=n_esimo_primo(j)
    m=p*q
    n=(p-1)*(q-1)
    e=calcula_e(n)
    d=calcula_d(e,n)
    if C>=m:
        raise ValueError('encripta: a mensagem tem de ser inferior a',m)    
    N=(C**d)%m
    return N
    
