direcoes=['N','E','NE','NW','SE','SW','W','S']


def e_direcao(direcao):
    return direcao in direcoes
        
def e_norte(direcao):
    return direcao=='N'
    
def e_sul(direcao):
    return direcao=='S'
        
def e_leste(direcao):
    return direcao=='E'
   
def e_oeste(direcao):
    return direcao=='W'
   
def e_nordeste(direcao):
    return direcao=='NE'
   
def e_noroeste(direcao):
    return direcao=='NW'
   
def e_sudeste(direcao):
    return direcao=='SE'
   
def e_sudoeste(direcao):
    return direcao=='SW'
   
def direcoes_iguais(d1,d2):
    return d1==d2


def direcao_oposta(direcao):
    for e in range(len(direcoes)):
        if dir == direcoes[e]:
            return direcoes[len(direcoes)-1-e]

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
    grelha = []      
    for e in range(2, len(lst)):
        if '\n' in lst[e]:
            lst[e] = lst[e][:-1]
        subgrelha = grelha_auxiliar(lst[e])
        grelha = grelha + [subgrelha]
    grelha = remove_espacos(grelha)
    return grelha      

def remove_espacos(g):
    nova_lst = []
    for i in range(len(g)):
        nova_cad = ''
        for e in g[i]:
            if e != ' ':
                nova_cad = nova_cad + e
        nova_lst = nova_lst + [nova_cad]
    return nova_lst
        
def grelha_auxiliar(string):
    str_nova = ''
    for i in range(len(string)-1):
        if string[i] == ' ' and string[i] == string[i+1]:
            return str_nova
        else:
            str_nova = str_nova + string[i]
        
    return str_nova
# =============================================================================            
#Seletores
# =============================================================================

def grelha_nr_linhas(g):
    return len(g)

def grelha_nr_colunas(g):
    return len(g[0])

def grelha_elementos(g,l,c):
    if l > len(g)-1 or l < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    if c > len(g[0])-1 or c < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    return g[l][c]

def grelha_linha(g,c):
    lin = coord_linha(c)
    col = coord_coluna(c)
    dirc = coord_direcao(c)
    cad = ''
    if not e_coordenada(c):
        raise ValueError('grelha_linha: argumentos invalidos')
    if not 0 <= lin <= len(g) or not 0 <= col <= len(g[lin]):
        raise ValueError('grelha_linha: argumentos invalidos')
    if e_norte(dirc):
        for i in range(len(g)-1,-1,-1):
            for e in range(len(g[i])):
                if e == col:
                    cad = cad + str(g[i][e])
        return cad
    elif e_sul(dirc):
        for i in range(0,len(g)):
            for e in range(len(g[i])):
                if e == col:
                    cad = cad + str(g[i][e])
        return cad
    elif e_leste(dirc):
        for e in range(0,len(g[lin])):
            cad = cad + str(g[lin][e])        
        return cad    
    elif e_oeste(dirc):
        for e in range(len(g[lin])-1,-1,-1):
            cad = cad + str(g[lin][e])        
        return cad
    elif e_nordeste(dirc):
        while lin != len(g) - 1 and col != 0:
            lin = lin + 1
            col = col - 1  
        while lin != -1 and col != len(g[lin]):
            cad = cad + g[lin][col]
            lin = lin - 1
            col = col + 1
        return cad 
    elif e_noroeste(dirc):
        while lin != len(g) - 1  and col != len(g[0]) - 1:
                    lin = lin + 1
                    col = col + 1          
        while lin != -1 and col != -1:
            cad = cad + g[lin][col]
            lin = lin - 1
            col = col - 1
        return cad 
    elif e_sudeste(dirc):
        while lin != 0  and col != 0:
                            lin = lin - 1
                            col = col - 1        
        while lin != len(g) and col != len(g[lin]):
                cad = cad + g[lin][col]
                lin = lin + 1
                col = col + 1
        return cad
    elif e_sudoeste(dirc):
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
    if isinstance(g,list) and len(g)!=0:
        for i in lst:
            if not isinstance(i,str):
                return False
        for i in range(1,len(g)):
            if len(len[0]) != len(g[i]):
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
    if isinstance (lst, list):
        for a in range (len(lst)):
            if isinstance(lst[a], tuple):
                if isinstance (lst[a][0], string) and e_coordenada(lst[a][1]):
                    return lst
    raise ValueError('resposta: argumentos invalidos')

def resposta_elemento(res,n):
    """
    resposta_elemento : resposta x N0 --> tuplo(string, coordenada)
    resposta_elemento(res, n) devolve o enesimo elemento da resposta res.
    """
    if n <= 0 or n >= len(res):
            raise ValueError('resposta_elemento: argumentos invalidos')
    return res[n]
    
def resposta_tamanho(res):
    """
    resposta_tamanho : resposta --> N0
    resposta_tamanho(res) devolve o numero de elementos da resposta res.
    """
    return len(res)

def acrescenta_elemento (r,s,c):
    """
    acrescenta_elemento : resposta x string x coordenada --> resposta
    acrescenta_elemento(r, s, c) devolve a resposta r com mais um elemento
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
    respostas_iguais(r1, r2) devolve o valor verdadeiro se as respostas r1 e r2
    contiverem os mesmos tuplos e falso caso contrario.
    """
    return r1==r2

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
    rep_externa_resposta='['
    for a in range (len(res)-1):
        rep_externa_resposta = rep_externa_resposta+'<'+res[a][0]+':'+\
            coordenada_string(res[a][1])+'>, '
    rep_externa_reposta = rep_externa_resposta+'<'+res[len(res)-1][0]+':'+\
            coordenada_string(res[len(res)][1])+'>]'
    return rep_externa_resposta

