def ver_primo(n):
    i=2
    while i<n:
        if n%i == 0:
            return False
        i = i+1
    return True
   
def n_esimo_primo(n):
    i = 2
    conta = 0
    while conta < n:
        if ver_primo(i):
            conta = conta + 1
        i = i + 1
    return(i-1)
