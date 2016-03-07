#tipo resposta

def resposta(lst):
    """
    resposta : lista de tuplos(string; coordenada) --> resposta
    resposta(lst) tem como valor a resposta que contem cada um dos tuplos que
    compoem a lista lst.
    """
    if isinstance (lst, list):
        for a in range (len(lst)):
            if isinstance(lst[a], tuple):
                if isinstance (lst[a][0], string) and e_coordenada(lst[a][1]):
                    return lst
    raise ValueError('resposta: argumentos invalidos')

def resposta_elemento(res,n):
    """
    resposta_elemento : resposta x N0 --> tuplo(string; coordenada)
    resposta_elemento(res; n) devolve o en�simo elemento da resposta res.
    """
    if n <= 0 or n >= len(res):
            raise ValueError('resposta_elemento: argumentos invalidos')
    return res[n]
    
def resposta_tamanho(res):
    """
    resposta_tamanho : resposta --> N0
    resposta_tamanho(res) devolve o n�mero de elementos da resposta res.
    """
    return len(res)

def acrescenta_elemento (r,s,c):
    """
    acrescenta_elemento : resposta x string x coordenada --> resposta
    acrescenta_elemento(r; s; c) devolve a resposta r com mais um elemento
    - o tuplo (s, c).
    """
    mais_resposta=(s,c)
    r=r+[mais_reposta]
    return r

def e_resposta (arg):
    """
    e_resposta : universal --> logico
    e_resposta(arg) tem o valor verdadeiro se o arg for do tipo resposta e falso
    caso contrario.
    """
    if isinstance (lst, list):
            for a in range (len(lst)):
                if isinstance(lst[a], tuple):
                    if isinstance (lst[a][0], string) and\
                       e_coordenada(lst[a][1]):
                        return True
    return False

def respostas_iguais(r1,r2):
    """
    respostas_iguais : resposta x resposta --> logico
    respostas_iguais(r1; r2) devolve o valor verdadeiro se as respostas r1 e r2
    contiverem os mesmos tuplos e falso caso contrario.
    """
    return r1==r2

def resposta_string (res):
    """
    resposta_string : resposta --> string
    resposta_string(res) devolve a representa��o externa da resposta res: uma
    cadeia de caracteres iniciada pelo par�ntesis recto esquerdo �[� e que cont�m
    a descri��o de cada elemento da resposta separados por v�rgulas e espa�o �,
    �, terminando com o par�ntesis recto direito �]�.
    Cada elemento � representado por: �<�PALAVRA�:�COORDENADA�>�,
    em que PALAVRA � a palavra encontrada, e COORDENADA a coordenada
    onde se encontra a palavra.
    """
    rep_externa_resposta='['
    for a in range (len(res)-1):
        rep_externa_resposta = rep_externa_resposta+'<'+res[a][0]+':'+\
            coordenada_string(res[a][1])+'>, '
    rep_externa_reposta = rep_externa_resposta+'<'+res[len(res)-1][0]+':'+\
            coordenada_string(res[len(res)][1])+'>]'
    return rep_externa_resposta
