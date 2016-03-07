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
    if not isinstance(lst, list) or lst == []:
        raise ValueError('grelha: argumentos invalidos')
    grelha = []
    for e in range(len(lst)):
        if not isinstance(lst[e], str) or lst[e] == '':
            raise ValueError('grelha: argumentos invalidos')
        subgrelha = []
        for i in lst[e]:
            if i != ' ' and i != '\n':
                subgrelha = subgrelha + [str(i)]
        grelha = grelha + [subgrelha]
    for i in range(len(grelha)):
        if len(grelha[0])!= len(grelha[e]):
            raise ValueError('grelha: argumentos invalidos')        
    return grelha     


# =============================================================================            
#Seletores
# =============================================================================

def grelha_nr_linhas(g):
    return len(g)

def grelha_nr_colunas(g):
    return len(g[0])

def grelha_elemento(g,l,c):
    if l > len(g)-1 or l < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    if c > len(g[0])-1 or c < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    return g[l][c]

def grelha_linha(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)
    dirc = coord_direcao(c)
    if not e_coordenada(c):
        raise ValueError('grelha_linha: argumentos invalidos')
    if not 0 <= lin <= len(g)-1 or not 0 <= col <= len(g[lin])-1:
        raise ValueError('grelha_linha: argumentos invalidos')
    if e_norte(dirc):
        return cadeia_norte(g,c)
    elif e_sul(dirc):
        return cadeia_sul(g,c)
    elif e_leste(dirc):
        return cadeia_leste(g,c)    
    elif e_oeste(dirc):
        return cadeia_oeste(g,c)
    elif e_nordeste(dirc): 
        return cadeia_nordeste(g,c)
    elif e_noroeste(dirc):
        return cadeia_noroeste(g,c)
    elif e_sudeste(dirc):
        return cadeia_sudeste(g,c)          
    elif e_sudoeste(dirc):
        return cadeia_sudoeste(g,c)   

def cadeia_norte(g,c):
    col = coord_coluna(c)
    cad = ''
    for i in range(len(g)-1,-1,-1):
        for e in range(len(g[i])):
            if e == col:
                cad = cad + str(g[i][e])
    return cad    

def cadeia_sul(g,c):
    col = coord_coluna(c)
    cad = ''    
    for i in range(len(g)):
        for e in range(len(g[i])):
            if e == col:
                cad = cad + str(g[i][e])   
    return cad

def cadeia_leste(g,c):
    lin = coord_linha(c)
    cad = ''     
    for e in range(len(g[lin])):
        cad = cad + str(g[lin][e])        
    return cad    

def cadeia_oeste(g,c):
    lin = coord_linha(c)
    cad = ''     
    for e in range(len(g[lin])-1,-1,-1):
        cad = cad + str(g[lin][e])        
    return cad    

def cadeia_nordeste(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''
    while lin != len(g) - 1 and col != 0:
        lin = lin + 1
        col = col - 1  
    while lin != -1 and col != len(g[lin]):
        cad = cad + g[lin][col]
        lin = lin - 1
        col = col + 1
    return cad     

def cadeia_noroeste(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''    
    while lin != len(g) - 1  and col != len(g[0]) - 1:
        lin = lin + 1
        col = col + 1          
    while lin != -1 and col != -1:
        cad = cad + g[lin][col]
        lin = lin - 1
        col = col - 1
    return cad     

def cadeia_sudeste(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''     
    while lin != 0  and col != 0:
        lin = lin - 1
        col = col - 1        
    while lin != len(g) and col != len(g[lin]):
        cad = cad + g[lin][col]
        lin = lin + 1
        col = col + 1
    return cad    

def cadeia_sudoeste(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''      
    while lin != 0  and col != len(g[0]) - 1:
        lin = lin - 1
        col = col + 1        
    while lin != len(g) and col != -1:
        cad = cad + g[lin][col]
        lin = lin + 1
        col = col - 1    
    return cad    
# =============================================================================
#Reconhecedor
# =============================================================================

def e_grelha(g):
    if isinstance(g,list) and g != []:
        for i in range(len(g)):
            if not isinstance(g[i],list) or len(g[0]) != len(g[i]):
                return False
            for e in g[i]:
                if not isinstance(e,str):
                    return False
            return True
    else:
        return False
# =============================================================================
#Teste
# =============================================================================

def grelhas_iguais(g1, g2):
    return g1 == g2


def resposta(lst):
    """
    resposta : lista de tuplos(string, coordenada) --> resposta
    resposta(lst) tem como valor a resposta que contem cada um dos tuplos que
    compoem a lista lst.
    """
    if lst==[]:
        return lst
    else:
        if isinstance (lst, list):
            for a in range (len(lst)):
                if isinstance(lst[a], tuple):
                    if isinstance (lst[a][0], str) and e_coordenada(lst[a][1]):
                        return lst
    raise ValueError('resposta: argumentos invalidos')

def resposta_elemento(resposta,n):
    """
    resposta_elemento : resposta x N0 --> tuplo(string, coordenada)
    resposta_elemento(res, n) devolve o enesimo elemento da resposta res.
    """
    if resposta==[]:
        raise ValueError('resposta_elemento: argumentos invalidos')
    if n < 0 or n >= len(resposta):
            raise ValueError('resposta_elemento: argumentos invalidos')
    return resposta[n]
    
def resposta_tamanho(resposta):
    """
    resposta_tamanho : resposta --> N0
    resposta_tamanho(res) devolve o numero de elementos da resposta res.
    """
    return len(resposta)

def acrescenta_elemento (r,s,c):
    """
    acrescenta_elemento : resposta x string x coordenada --> resposta
    acrescenta_elemento(r, s, c) devolve a resposta r com mais um elemento
    - o tuplo (s, c).
    """
    mais_resposta=(s,c)
    r=r+[mais_resposta]
    return r

def e_resposta (arg):
    """
    e_resposta : universal --> logico
    e_resposta(arg) tem o valor verdadeiro se o arg for do tipo resposta e falso
    caso contrario.
    """
    if arg==[]:
        return True
    else:
        if isinstance (arg, list):
            for a in range (len(arg)):
                if isinstance(arg[a], tuple):
                    if isinstance (arg[a][0], str) and e_coordenada(arg[a][1]):
                        return True
    return False
    

def respostas_iguais(r1,r2):
    """
    respostas_iguais : resposta x resposta --> logico
    respostas_iguais(r1, r2) devolve o valor verdadeiro se as respostas r1 e r2
    contiverem os mesmos tuplos e falso caso contrario.
    """
    if r1==[] or r2 ==[]:
        return True
    for i in range (resposta_tamanho(r1)):
        if r1[i] in r2:
            return True
    return False

def resposta_string (res):
    """
    resposta_string : resposta --> string
    resposta_string(res) devolve a representacao externa da resposta res: uma
    cadeia de caracteres iniciada pelo parentesis recto esquerdo '[' e que contem
    a descricao de cada elemento da resposta separados por virgulas e espaco ',
    ', terminando com o parentesis recto direito ']'.
    Cada elemento e representado por: '<'PALAVRA':'COORDENADA'>',
    em que PALAVRA e a palavra encontrada, e COORDENADA a coordenada
    onde se encontra a palavra.
    """
    rep_externa_resposta='>]'
    rep_externa_resposta = '<'+res[0][0]+':'+\
                coordenada_string(res[0][1])+rep_externa_resposta    
    for a in range (1,len(res)):
        rep_externa_resposta = '<'+res[a][0]+':'+\
            coordenada_string(res[a][1])+'>, '+rep_externa_resposta
    rep_externa_resposta='['+rep_externa_resposta
    return rep_externa_resposta

def procura_palavras_numa_direcao(g, p, d):
    res = []
    if e_norte(d):
        for m in p: #Ciclo de palavras a pesquisar
            for i in range(len(g[0])):#Corre todas as linhas
                c = coordenada(len(g)-1,i,d)
                cad_n = grelha_linha(g,c)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(len(g)-1-a,i,d)))]
        return resposta_string(res)
    if e_sul(d):
            for m in p: #Ciclo de palavras a pesquisar
                for i in range(len(g[0])):#Corre todas as linhas
                    c = coordenada(0,i,d)
                    cad_n = grelha_linha(g,c)
                    if m in cad_n:
                        a = procura_string(cad_n,m)
                        res = res + [(m, (coordenada(a,i,d)))]
            return resposta_string(res)
    if e_leste(d):
        for m in p: #Ciclo de palavras a pesquisar
            for i in range(len(g)):#Corre todas as linhas
                c = coordenada(i,0,d)
                cad_n = grelha_linha(g,c)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(a,i,d)))]
        return resposta_string(res) 
    if e_oeste(d):
        for m in p: #Ciclo de palavras a pesquisar
            for i in range(len(g)):#Corre todas as linhas
                c = coordenada(i,len(g[0])-1,d)
                cad_n = grelha_linha(g,c)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(len(g[0])-1-a,i,d)))]
        return resposta_string(res)     

def procura_string(x,y):
    '''Procura a cadeira de caracteres y na string x;
    Devolve o index da primeira letra y em x'''
    for e in range(len(x)):#corre as letras da linha x
        if x[e] == y[0]: #verifica se e igual a primeira letra de y
            c = 0
            if len(x) < e + len(y):
                return False
            for i in y:
                if i != x[e+c]:
                    return False
                c = c + 1
            return e
    