direcoes = ['N','S','E','W','NW','SE','SW','NE']


def e_direcao(direcao):
    if direcao in direcoes:
        return True
    else:
        return False
    
def e_norte(direcao):
    if direcao=='N':
        return True
    else:
        return False
    
def e_sul(direcao):
    if direcao=='S':
        return True
    else:
        return False
   
def e_leste(direcao):
    if direcao=='E':
        return True
    else:
        return False
   
def e_oeste(direcao):
    if direcao=='W':
        return True
    else:
        return False
   
def e_nordeste(direcao):
    if direcao=='NE':
        return True
    else:
        return False
   
def e_noroeste(direcao):
    if direcao=='NW':
        return True
    else:
        return False
   
def e_sudeste(direcao):
    if direcao=='SE':
        return True
    else:
        return False
   
def e_sudoeste(direcao):
    if direcao=='SW':
        return True
    else:
        return False
   
def direcoes_iguais(d1,d2):
    return d1==d2


def direcao_oposta(direcao):
    rosa_ventos={'N':'S','S':'N','E':'W','W':'E','NE':'SW','SW':'NE','NW':'SE','SE':'NW'}
    return rosa_ventos[direcao]

#Construtor
def coordenada(l,c,d):
    """
    coordenada: N0 x N0 x direcao --> coordenada
    coordenada(l, c, d) tem como valor a coordenada referente a posicao (l,c) e direcao d.
    """  
    if (d in direcoes) and isinstance(l,int) and isinstance(c,int) and l>=0 and c>=0 :
        return (l,c,d)
    else:
        raise ValueError('coordenada: argumentos invalidos')

#Selector
def coord_linha(c):
    """
    coord_linha : coordenada --> N0
    coord_linha(c) tem como valor a linha da coordenada.
    """
    return c[0]

def coord_coluna(c):
    """
    coord_coluna : coordenada --> N0
    coord_coluna(c) tem como valor a coluna da coordenada.
    """
    return c[1]

def coord_direcao(c):
    """
    coord_direcao : coordenada --> N0
    coord_direcao(c) tem como valor a direcao da coordenada.
    """    
    return c[2]


#Reconhecedor

def e_coordenada(c):
    """
    e_coordenada : universal --> logico
    e_coordenada(arg) tem o valor verdadeiro se o arg for do tipo coordenada e falso caso contrario.
    """
    return (isinstance(c,tuple) and 3==len(c) and isinstance(c[0] and c[1],int) and c[2] in direcoes)


#Testes
def coordenadas_iguais(c1,c2):
    """
    coordenadas_iguais : coordenada x coordenada --> logico
    coordenadas_iguais(c1, c2) devolve o valor verdadeiro se as coordenadas c1 e c2 forem iguais e falso caso contrario.
    """
    return c1==c2


#Outras Operacoes
def coordenada_string(c):
    """
    coordenada_string : coordenada --> string
    coordenada_string(c) devolve a representacao externa de c: uma cadeia de caracteres iniciada por parentesis esquerdo '(' seguido pelo numero da linha e da coluna, separados por virgula e um espaco ',' , seguido por parentesis direito e traco ')-', apos os quais se apresenta a direcao.
    """
    return '(' + str(coord_linha(c)) + ', ' + str(coord_coluna(c)) + ')-' + str(coord_direcao(c))


def grelha(lst):
    if isinstance(lst,list) and len(lst)!=0:
        for i in lst:
            if not isinstance(i,str):
                raise ValueError('grelha: argumentos invalidos')
        for i in range(1,len(lst)):
            if len(lst[0]) != len(lst[i]):
                raise ValueError('grelha: argumentos invalidos')
            return lst
    else:
        raise ValueError('grelha: argumentos invalidos')

     
def grelha_nr_linhas(lst):
    return len(lst)

def grelha_nr_colunas(lst):
    return len(lst[0])


def grelha_elemento(lst,l,c):
    if (l>=0 and len(lst)>l) and (c>=0 and len(lst[0])>c):
        return lst[l][c]        
    else:
        raise ValueError('grelha_elemento: argumentos invalidos')


def grelha_linha(lst,coord):
   return True 





def e_grelha(lst):
    if isinstance(lst,list) and len(lst)!=0:
        for i in lst:
            if not isinstance(i,str):
                return False
        for i in range(1,len(lst)):
            if len(lst[0]) != len(lst[i]):
                return False
        return True
    else:
        return False
