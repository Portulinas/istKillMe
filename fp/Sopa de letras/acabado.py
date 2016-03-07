# (), Andre Aguas (78854), Goncalo Santos (78093), Goncalo Fialho (79112) () - Grupo 34

from janela_sopa_letras import *
direcoes=['N','E','NE','NW','SE','SW','W','S']

# =============================================================================            
#Tipo Direcao
# =============================================================================
# =============================================================================            
#Reconhecedores
# =============================================================================

def e_direcao(arg):
    """
    e_direcao : universal --> logico
    e_direcao(arg) tem o valor verdadeiro se o arg for do tipo direcao e falso
    caso contrario.
    """
    return arg in direcoes
        
def e_norte(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'N'
    e falso caso contrario.
    """
    return direcao=='N'
    
def e_sul(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'S'
    e falso caso contrario.
    """    
    return direcao=='S'
        
def e_leste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'E'
    e falso caso contrario.
    """      
    return direcao=='E'
   
def e_oeste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'W'
    e falso caso contrario..
    """      
    return direcao=='W'
   
def e_nordeste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'NE'
    e falso caso contrario.
    """      
    return direcao=='NE'
   
def e_noroeste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'NW'
    e falso caso contrario.
    """      
    return direcao=='NW'
   
def e_sudeste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'SE'
    e falso caso contrario.
    """      
    return direcao=='SE'
   
def e_sudoeste(direcao):
    """
    e_norte : direcao --> logico
    e_norte(arg) tem o valor verdadeiro se o arg for o elemento 'SW'
    e falso caso contrario.
    """      
    return direcao=='SW'

# =============================================================================            
#Testes
# =============================================================================   

def direcoes_iguais(d1,d2):
    """
    direcoes_iguais : direcao x direcao --> logico
    direcoes_iguais(d1, d2) devolve o valor verdadeiro se as direcoes d1 e d2
    forem iguais e falso caso contrario.
    """
    return d1==d2

# =============================================================================            
#Outras Operacoes
# =============================================================================

def direcao_oposta(direcao):
    """
    direcao_oposta : direcao --> direcao
    direcao_oposta(d) devolve a direcao oposta de d de acordo com a rosa dos 
    ventos.
    """
    for e in range(len(direcoes)):
        if direcao == direcoes[e]:
            return direcoes[len(direcoes)-1-e]

# =============================================================================            
#Tipo Coordenada
# =============================================================================
# =============================================================================            
#Construtor
# =============================================================================

def coordenada(l,c,d):
    """
    coordenada: N0 x N0 x direcao --> coordenada
    coordenada(l, c, d) tem como valor a coordenada referente a posicao (l,c)
    e direcao d.
    """  
    if (d in direcoes) and isinstance(l,int) and isinstance(c,int) and l>=0 and c>=0 :
        return (l,c,d)
    else:
        raise ValueError('coordenada: argumentos invalidos')

# =============================================================================            
#Seletores
# =============================================================================

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

# =============================================================================            
#Reconhecedores
# =============================================================================

def e_coordenada(arg):
    """
    e_coordenada : universal --> logico
    e_coordenada(arg) tem o valor verdadeiro se o arg for do tipo coordenada e
    falso caso contrario.
    """
    return (isinstance(arg,tuple) and 3==len(arg) and isinstance(arg[0] and arg[1],int) and arg[2] in direcoes)

# =============================================================================            
#Testes
# =============================================================================

def coordenadas_iguais(c1,c2):
    """
    coordenadas_iguais : coordenada x coordenada --> logico
    coordenadas_iguais(c1, c2) devolve o valor verdadeiro se as coordenadas
    c1 e c2 forem iguais e falso caso contrario.
    """
    return c1==c2

# =============================================================================            
#Outras Operacoes
# =============================================================================

def coordenada_string(c):
    """
    coordenada_string : coordenada --> string
    coordenada_string(c) devolve a representacao externa de c: uma cadeia de 
    caracteres iniciada por parentesis esquerdo '(' seguido pelo numero da
    linha e da coluna, separados por virgula e um espaco ',' , seguido por
    parentesis direito e traco ')-', apos os quais se apresenta a direcao.
    """
    return '(' + str(coord_linha(c)) + ', ' + str(coord_coluna(c)) + ')-' + str(coord_direcao(c))


# =============================================================================            
#Tipo Grelha
# =============================================================================
# =============================================================================            
#Construtor
# =============================================================================

def grelha(lst):
    """
    grelha : lista de strings --> grelha
    grelha(lst) tem como valor uma grelha m x n, em que m e o numero de
    elementos da lista lst e n o numero de carateres de cada string na lista.
    """
    if not isinstance(lst, list) or len(lst) == 0:
        raise ValueError('grelha: argumentos invalidos')
    grelha = []
    for e in range(len(lst)):
        if not isinstance(lst[e], str) or lst[e] == '':
            raise ValueError('grelha: argumentos invalidos')
        subgrelha = ''
        for i in lst[e]:
            subgrelha = subgrelha + str(i)
        grelha = grelha + [subgrelha]
    for i in range(len(grelha)):
        if len(grelha[0])!= len(grelha[i]):
            raise ValueError('grelha: argumentos invalidos')        
    return grelha     

# =============================================================================            
#Seletores
# =============================================================================

def grelha_nr_linhas(g):
    """
    grelha_nr_linhas : grelha --> N 
    grelha_nr_linhas(g) devolve o numero de linhas da grelha g.
    """
    return len(g)

def grelha_nr_colunas(g):
    """
    grelha_nr_colunas : grelha --> N 
    grelha_nr_colunas(g) devolve o numero de colunas da grelha g.
    """
    return len(g[0])

def grelha_elemento(g,l,c):
    """
    grelha_elementos : grelha x N0 x N0 --> carater
    grelha_elementos(g,l,c) devolve o carater que esta na posicao(l,c) da grelha g.
    """
    if l > len(g)-1 or l < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    if c > len(g[0])-1 or c < 0:
        raise ValueError('grelha_elemento: argumentos invalidos')
    return g[l][c]

def grelha_linha(g,c):
    """
    grelha_linha : grelha x coordenada --> string
    grelha_linha(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao dada pela coordenada c, e que inclui a posicao
    dada pela mesma coordenada.    
    """
    lin = coord_linha(c)
    col = coord_coluna(c)
    dirc = coord_direcao(c)
    if not e_grelha:
        raise ValueError('grelha_linha: argumentos invalidos')
    if not e_coordenada(c):
        raise ValueError('grelha_linha: argumentos invalidos')
    if not 0 <= lin <= grelha_nr_linhas(g)-1 or not 0 <= col <= grelha_nr_colunas(g)-1:
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
    """
    cadeia_norte : grelha x coordenada --> string
    cadeia_norte(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'N' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.    
    """    
    col = coord_coluna(c)
    cad = ''
    for i in range(grelha_nr_linhas(g)-1,-1,-1):
        for e in range(grelha_nr_colunas(g)):
            if e == col:
                cad = cad + str(grelha_elemento(g,i,e))
    return cad    

def cadeia_sul(g,c):
    """
    cadeia_sul : grelha x coordenada --> string
    cadeia_sul(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'S' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    col = coord_coluna(c)
    cad = ''    
    for i in range(grelha_nr_linhas(g)):
        for e in range(grelha_nr_colunas(g)):
            if e == col:
                cad = cad + str(grelha_elemento(g,i,e))   
    return cad

def cadeia_leste(g,c):
    """
    cadeia_lest : grelha x coordenada --> string
    cadeia_leste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'E' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    cad = ''     
    for e in range(grelha_nr_colunas(g)):
        cad = cad + str(grelha_elemento(g,lin,e))        
    return cad    

def cadeia_oeste(g,c):
    """
    cadeia_oeste : grelha x coordenada --> string
    cadeia_oeste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'W' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    cad = ''     
    for e in range(grelha_nr_colunas(g) -1,-1,-1):
        cad = cad + str(grelha_elemento(g,lin,e))        
    return cad    

def cadeia_nordeste(g,c):
    """
    cadeia_nordeste : grelha x coordenada --> string
    cadeia_nordeste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'NE' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''
    while lin != grelha_nr_linhas(g) - 1 and col != 0:
        lin = lin + 1
        col = col - 1  
    while lin != -1 and col != grelha_nr_colunas(g):
        cad = cad + grelha_elemento(g,lin,col)
        lin = lin - 1
        col = col + 1
    return cad     

def cadeia_noroeste(g,c):
    """
    cadeia_noroeste : grelha x coordenada --> string
    cadeia_noroeste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'NW' dada pela coordenada c, e que inclui a 
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''    
    while lin != grelha_nr_linhas(g) - 1  and col != grelha_nr_colunas(g)- 1:
        lin = lin + 1
        col = col + 1          
    while lin != -1 and col != -1:
        cad = cad + grelha_elemento(g,lin,col)
        lin = lin - 1
        col = col - 1
    return cad     

def cadeia_sudeste(g,c):
    """
    cadeia_sudeste : grelha x coordenada --> string
    cadeia_sudeste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'SE' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''     
    while lin != 0  and col != 0:
        lin = lin - 1
        col = col - 1        
    while lin != grelha_nr_linhas(g) and col != grelha_nr_colunas(g):
        cad = cad + grelha_elemento(g,lin,col)
        lin = lin + 1
        col = col + 1
    return cad    

def cadeia_sudoeste(g,c):
    """
    cadeia_sudoeste : grelha x coordenada --> string
    cadeia_sudoeste(g, c) devolve a cadeia de caracteres que corresponde a linha
    definida segundo a direcao 'SW' dada pela coordenada c, e que inclui a
    posicao dada pela mesma coordenada.
    """
    lin = coord_linha(c)
    col = coord_coluna(c)    
    cad = ''      
    while lin != 0  and col != grelha_nr_colunas(g) - 1:
        lin = lin - 1
        col = col + 1        
    while lin != grelha_nr_linhas(g) and col != -1:
        cad = cad + grelha_elemento(g,lin,col)
        lin = lin + 1
        col = col - 1    
    return cad    

# =============================================================================
#Reconhecedor
# =============================================================================

def e_grelha(arg):
    """
    e_grelha : universal --> logico
    e_grelha(arg) tem o valor verdadeiro se o arg for do tipo grelha e falso 
    caso contrario.
    """
    if isinstance(arg,list) and arg != []:
        for i in range(len(arg)):
            if not isinstance(arg[i],str) or len(arg[0]) != len(arg[i]):
                return False
        return True
    else:
        return False

# =============================================================================
#Teste
# =============================================================================

def grelhas_iguais(g1, g2):
    """
    grelha : grelha --> logico
    grelhas_iguais(g1, g2) devolve o valor verdadeiro se as grelhas forem iguais
    e falso caso contrario.
    """
    return g1 == g2

# =============================================================================            
#Tipo Resposta
# =============================================================================

def tamanho_menor(palavra1, palavra2):
    """
    tamanho_menor: string x string --> N0
    tamanho_menor(palavra1, palavra2) tem o valor do comprimento da palavra com
    menor comprimento.
    """        
    if len(palavra1) > len(palavra2):
        return len(palavra2)
    else:
        return len(palavra1)

def troca(palavra1, palavra2):
    """
    troca: string x string --> logico
    troca(palavra1, palavra2) tem o valor verdadeiro se a palavra1 tem ordem 
    alfabetica inferior a da palavra 2 e falso caso contrario.
    """    
    for i in range (tamanho_menor(palavra1, palavra2)):
        if ord(palavra1[i]) < ord(palavra2[i]):
            return True
        elif ord(palavra1[i]) > ord(palavra2[i]):
            return False

def resposta_ordem_alfabetica(res):
    """
    resposta_ordem_alfabetica: resposta --> resposta
    resposta_ordem_alfabetica(res) tem como valor a resposta res ordenada
    alfabeticamente pelas palavras a procurar
    """    
    if res==[]:
        return []
    tamanho = resposta_tamanho(res)
    primeiro = resposta_elemento(res,0)[0]
    indice=0
    for i in range(tamanho):
        if ord(resposta_elemento(res,i)[0][0]) < ord(primeiro[0]):
            primeiro = resposta_elemento(res,i)[0]
            indice=i
        elif ord(resposta_elemento(res,i)[0][0]) == ord(primeiro[0]):
            if troca(resposta_elemento(res,i)[0], primeiro):
                primeiro = resposta_elemento(res,i)[0]
                indice = i
    resposta_primeiro = [res[indice]]
    del(res[indice])
    return resposta_primeiro + resposta_ordem_alfabetica(res)

# =============================================================================            
#Construtor
# =============================================================================

def resposta(lst):
    """
    resposta : lista de tuplos(string, coordenada) --> resposta
    resposta(lst) tem como valor a resposta que contem cada um dos tuplos que
    compoem a lista lst.
    """
    if lst == []:
        return lst
    else:
        if isinstance (lst, list):
            for a in range (len(lst)):
                if isinstance(lst[a], tuple):
                    if isinstance (lst[a][0], str) and e_coordenada(lst[a][1]):
                        return resposta_ordem_alfabetica(lst)
    raise ValueError('resposta: argumentos invalidos')

# =============================================================================            
#Seletores
# =============================================================================

def resposta_elemento(resposta,n):
    """
    resposta_elemento : resposta x N0 --> tuplo(string, coordenada)
    resposta_elemento(resposta, n) devolve o enesimo elemento da resposta res.
    """
    if resposta == []:
        raise ValueError('resposta_elemento: argumentos invalidos')
    if n < 0 or n >= resposta_tamanho(resposta):
            raise ValueError('resposta_elemento: argumentos invalidos')
    return resposta[n]

def resposta_tamanho(resposta):
    """
    resposta_tamanho : resposta --> N0
    resposta_tamanho(res) devolve o numero de elementos da resposta res.
    """
    return len(resposta)

# =============================================================================            
#Modificador
# =============================================================================

def acrescenta_elemento(r,s,c):
    """
    acrescenta_elemento : resposta x string x coordenada --> resposta
    acrescenta_elemento(r, s, c) devolve a resposta r com mais um elemento
    - o tuplo (s, c).
    """
    mais_resposta = (s,c)
    r = r + [mais_resposta]
    return resposta(r)

# =============================================================================            
#Reconhecedor
# =============================================================================

def e_resposta(arg):
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
    
# =============================================================================            
#Testes
# =============================================================================
    
def respostas_iguais(r1,r2):
    """
    respostas_iguais : resposta x resposta --> logico
    respostas_iguais(r1, r2) devolve o valor verdadeiro se as respostas r1 e r2
    contiverem os mesmos tuplos e falso caso contrario.
    """
    if r1 == [] and r2 == []:
        return True
    if len(r1) != len(r2):
            return False
    for i in range (len(r1)):
        if r1[i][0] != r2[i][0] or  not coordenadas_iguais(r1[i][1],r2[i][1]):
            return False
    return True

# =============================================================================            
#Outras Operacoes
# =============================================================================

def resposta_string (res):
    """
    resposta_string : resposta --> string
    resposta_string(res) devolve a representacao externa da resposta res: uma
    cadeia de caracteres iniciada pelo parentesis recto esquerdo '[' e que 
    contem a descricao de cada elemento da resposta separados por virgulas 
    e espaco ', ', terminando com o parentesis recto direito ']'.
    Cada elemento e representado por: '<'PALAVRA':'COORDENADA'>', em que
    PALAVRA e a palavra encontrada, e COORDENADA a coordenada onde se encontra
    a palavra.
    """
    rep_externa_resposta = '<'+res[0][0]+':'+ coordenada_string(res[0][1]) 
    for a in range (1,len(res)):
        rep_externa_resposta = rep_externa_resposta + '>, <'+res[a][0]+':'+ coordenada_string(res[a][1])
    rep_externa_resposta='['+rep_externa_resposta
    return rep_externa_resposta + '>]'

# =============================================================================            
#procura_palavras_numa_direcao
# =============================================================================

def procura_palavras_numa_direcao(grelha, lst_palavras, direcao):
    """ 
    procura_palavras_numa_direcao: grelha x lista x direcao --> resposta
    procura_palavras_numa_direcao(grelha, lst_palavras, direcao) devolve a 
    resposta correspondente as palavras encontradas numa direcao.
    """    
    if e_norte(direcao) or e_sul(direcao):
        return procura_norte_sul(grelha, lst_palavras, direcao)   
    elif e_leste(direcao) or e_oeste(direcao):
        return procura_leste_oeste(grelha, lst_palavras, direcao)
    elif e_sudeste(direcao) or e_noroeste(direcao):
        return procura_sudeste_noroeste(grelha, lst_palavras, direcao)
    elif e_sudoeste(direcao) or e_nordeste(direcao):
        return procura_sudoeste_nordeste(grelha, lst_palavras, direcao)


def procura_norte_sul(grelha, lst_palavras, direcao):
    """
    procura_norte_sul: grelha x lista x direcao --> resposta
    procura_norte_sul(grelha, lst_palavras, direcao) devolve a 
    resposta correspondente as palavras encontradas na direcao norte ou sul.
    """    
    res = resposta([])
    for palavra in lst_palavras:
        for nr_coluna in range(grelha_nr_colunas(grelha)):
            if e_norte(direcao):
                c = coordenada(grelha_nr_linhas(grelha)-1, nr_coluna , direcao)
                cad_n = grelha_linha(grelha, c)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(grelha_nr_linhas(grelha)-1-a, nr_coluna, direcao)))
            elif e_sul(direcao):
                c = coordenada(0, nr_coluna, direcao)
                cad_n = grelha_linha(grelha, c)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra, (coordenada(a, nr_coluna, direcao)))                
    return res  


def procura_leste_oeste(grelha, lst_palavras, direcao):
    """        
    procura_leste_oeste: grelha x lista x direcao --> resposta
    procura_leste_oeste(grelha, lst_palavras, direcao) devolve a resposta
    correspondente as palavras encontradas na direcao leste ou oeste.
    """        
    res = resposta([])
    for palavra in lst_palavras:
        for nr_linha in range(grelha_nr_linhas(grelha)):
            if e_leste(direcao):
                c = coordenada(nr_linha, 0, direcao)
                cad_n = grelha_linha(grelha, c)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra, (coordenada(nr_linha, a, direcao)))
            elif e_oeste(direcao):
                c = coordenada(nr_linha, 0, direcao)
                cad_n = grelha_linha(grelha, c)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(nr_linha,(grelha_nr_colunas(grelha)-1)-a, direcao)))     
    return res    


def procura_sudeste_noroeste(grelha, lst_palavras, direcao):
    """
    procura_sudeste_noroeste: grelha x lista x direcao --> resposta
    procura_sudeste_noroeste(grelha, lst_palavras, direcao) devolve a resposta
    correspondente as palavras encontradas na direcao sudeste ou noroeste.
    """       
    res = resposta([])
    for palavra in lst_palavras:
        for i in range(1, grelha_nr_linhas(grelha)-1):
            c = coordenada(i, 0, 'SE')
            cad_n = grelha_linha(grelha, c)
            if e_sudeste(direcao):
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(i+a, a, direcao)))
            elif e_noroeste(direcao):
                cad_n = inverte_string(cad_n)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada((grelha_nr_linhas(grelha)-1)-a,(len(cad_n)-1)-a, direcao)))
        for i in range(0,grelha_nr_colunas(grelha)):
            c = coordenada(0, i, 'SE')
            cad_n = grelha_linha(grelha,c)
            if e_sudeste(direcao):
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(a, i+a, direcao)))
            elif e_noroeste(direcao):
                cad_n = inverte_string(cad_n)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada((len(cad_n)-1)-a,i+(len(cad_n)-1)-a, direcao)))
    return res


def procura_sudoeste_nordeste(grelha, lst_palavras, direcao):
    """
    procura_sudoeste_nordeste: grelha x lista x direcao --> resposta
    procura_sudoeste_nordeste(grelha, lst_palavras, direcao) devolve a resposta
    correspondente as palavras encontradas na direcao sudoeste ou nordeste.
    """       
    res = resposta([])
    for palavra in lst_palavras:
        for i in range (0, grelha_nr_linhas(grelha)):
            c = coordenada(i, 0, 'NE')
            cad_n = grelha_linha(grelha, c)
            if e_nordeste(direcao):
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra, (coordenada(i-a, a, direcao)))
            elif e_sudoeste(direcao):
                cad_n = inverte_string(cad_n)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(a,(len(cad_n)-1)-a, direcao)))
        for i in range(1,grelha_nr_colunas(grelha)-1):
            c = coordenada(grelha_nr_linhas(grelha)-1,i, 'NE')
            cad_n = grelha_linha(grelha,c)
            if e_nordeste(direcao):
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra,(coordenada(grelha_nr_linhas(grelha)-1-a, i+a, direcao)))
            elif e_sudoeste(direcao):
                cad_n = inverte_string(cad_n)
                if palavra in cad_n:
                    a = encontra_indice(cad_n, palavra)
                    res = acrescenta_elemento(res, palavra, (coordenada(a, i+len(palavra), direcao)))
    return res


def inverte_string(string):
    """
    inverte_string: string --> string
    inverte_string(string) devolve a string recebida pela ordem inversa.
    """    
    nova_string = ''
    for e in range(len(string)):
        nova_string = string[e] + nova_string 
    return nova_string


def encontra_indice(string,palavra):
    """
    encontra_indice: string x string --> N0
    encontra_indice(string, palavra) devolve o indice da primeira letra da 
    palavra na string.
    """    
    indice = 0
    def encontra_indice_aux(e, string1, palavra1):
        if len(palavra1) == 1 or len(string1)==1:
            if string1[0] == palavra1[0]:
                return e
        if string1[0] == palavra1[0]:
            return encontra_indice_aux(e,string1[1:],palavra1[1:]) 
        else:
            return 0
    for e in range(len(string)-1):
        if string[e] == palavra[0]:
            indice = encontra_indice_aux(e,string[e+1:],palavra[1:])
            if indice!=0:
                break
    return indice


# =============================================================================            
#sopa_letras
# =============================================================================

def sopa_letras(ficheiro):
    """
    sopa_letras: string --> resposta
    sopa_letras(ficheiro) devolve a resposta da sopa de letras no ficheiro.
    """    
    fich = open(ficheiro,'r')
    lst_linhas = fich.readlines()
    fich.close()
    
    g = grelha(transforma(lst_linhas))
    janela = janela_sopa_letras(ficheiro)
    res = resposta([])

    for e in direcoes:
        res1 = procura_palavras_numa_direcao(g, palavras_a_descobrir(lst_linhas[indice_palavras(lst_linhas)]), e)
        for i in range (resposta_tamanho(res1)):
                res = acrescenta_elemento(res, resposta_elemento(res1,i)[0],resposta_elemento(res1,i)[1])
        res1 = resposta([])

    janela.mostra_palavras(res)
    janela.termina_jogo() 
    
    return res

#criamos as funcoes indice_grelha e indice_palavras para sabermos em que linha 
#do ficheiro estam a grelha e a lista de palavras a procurar
def indice_grelha(lst_linhas):
    """
    indice_grelha: lista --> N0
    indice_grelha(lst_linhas) devolve o numero da linha onde comeca a grelha.
    """    
    palavras = indice_palavras(lst_linhas)
    palavras = palavras +1
    for i in range(palavras,len(lst_linhas)):
        if lst_linhas[i]!='\n':
            return i  
        
def indice_palavras(lst_linhas):
    """
    indice_palavras: lista --> N0
    indice_palavars(lst_linhas) devolve o numero da linha onde comecam as 
    palavras a procurar.
    """            
    for i in range(1,len(lst_linhas)):
        if lst_linhas[i]!='\n':
            return i    

def palavras_a_descobrir(linha):
    """
    palavras_a_descobrir: string --> lista
    palavras_a_descobrir(lst_linhas) devolve a lista de palavras a descobrir.
    """        
    linha = linha[10:]
    indice = 0
    palavra = ''
    palavras_descobrir = [ ]
    for e in range(len(linha)):
        if linha[e]==',' or linha[e]=='\n':
            palavras_descobrir = palavras_descobrir + [palavra]
            palavra = ''
        elif linha[e] ==' ':
            palavras_descobrir = palavras_descobrir
        else: 
            palavra = palavra + linha[e]
    palavra_teste = []
    elemento_teste=''
    for elemento in palavras_descobrir:
        for e in range(len(elemento)):
            if 97<=ord(elemento[e])<=122:
                ascii_elemento = ord(elemento[e])-32
                ascii_elemento = chr(ascii_elemento)
                elemento_teste = elemento_teste + ascii_elemento
            else:
                elemento_teste = elemento_teste + elemento[e]
        palavra_teste = palavra_teste + [elemento_teste]
        elemento_teste=''
    palavras_descobrir = palavra_teste
    return palavras_descobrir

            
def transforma(lst):
    """
    transforma: string --> lista
    transforma(lst) devolve uma lista com as linhas da grelha.
    """    
    a = indice_grelha(lst)
    nova_lista = lst[a:]
    lista_final = []
    for string in nova_lista:
        novastr=''
        for j in string:
            if j != ' ' and j != '\n':
                novastr = novastr + j
        lista_final = lista_final + [novastr]
    return lista_final
