#nas direcoes mudar len(g) para grelha_nr_linhas(g) , o mesmo para as colunas
#procura_string tem alguns bugs (por vezes retorna False numa coordenada)

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
        if direcao == direcoes[e]:
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
                        return resposta_ordem_alfabetica(lst)
    raise ValueError('resposta: argumentos invalidos')

def resposta_ordem_alfabetica(res):
    tamanho=resposta_tamanho(res)
    muda=1
    while muda != 0:
        muda=0
        for a in range (tamanho-1):
            if ord((res[a][0][0]).upper())>ord((res[a+1][0][0]).upper()):
                res[a], res[a+1]=res[a+1], res[a]
                muda=1
            elif ord((res[a][0][0]).upper())==ord((res[a+1][0][0]).upper()):
                for i in range (tamanho_menor(res[a][0], res[a+1][0])):
                    if ord((res[a][0][i]).upper())>ord((res[a+1][0][i]).upper()):
                        res[a], res[a+1]=res[a+1], res[a]
                        muda=1
    return res

def tamanho_menor(palavra1, palavra2):
    if palavra1 > palavra2:
        return len(palavra2)
    else:
        return len(palavra1)

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
        if r1[i] not in r2:
            return False
        if r2[i] not in r1:
            return False
    return True

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
    rep_externa_resposta = '<'+res[0][0]+':'+\
                coordenada_string(res[0][1]) 
    for a in range (1,len(res)):
        rep_externa_resposta = rep_externa_resposta + '>, <'+res[a][0]+':'+\
            coordenada_string(res[a][1])
    rep_externa_resposta='['+rep_externa_resposta
    return rep_externa_resposta + '>]'


def procura_palavras_numa_direcao(g, p, d):
    res = []
    if e_norte(d):
        return procura_norte(g,p)
    elif e_sul(d):
        return procura_sul(g,p)    
    elif e_leste(d):
        return procura_leste(g,p)
    elif e_oeste(d):
        return procura_oeste(g,p)   
    elif e_sudeste(d) or e_noroeste(d):
        return procura_sudeste_noroeste(g,p,d)
    elif e_sudoeste(d) or e_nordeste(d):
        return procura_sudoeste_nordeste(g,p,d)
        

def procura_norte(g,p):
    res = []
    for m in p: #Ciclo de palavras a pesquisar
        for i in range(len(g[0])):#Corre todas as colunas
            c = coordenada(len(g)-1,i,'N')
            cad_n = grelha_linha(g,c)
            if m in cad_n:
                a = procura_string(cad_n,m)
                res = res + [(m, (coordenada(len(g)-1-a,i,'N')))]
    return resposta(res)   



def procura_sul(g,p):
    res = []
    for m in p: #Ciclo de palavras a pesquisar
        for i in range(len(g[0])):#Corre todas as colunas
            c = coordenada(0,i,'S')
            cad_n = grelha_linha(g,c)
            if m in cad_n:
                a = procura_string(cad_n,m)
                res = res + [(m, (coordenada(a,i,'S')))]
    return resposta(res)    

def procura_leste(g,p):
    res = []
    for m in p: #Ciclo de palavras a pesquisar
        for i in range(len(g)):#Corre todas as linhas
            c = coordenada(i,0,'E')
            cad_n = grelha_linha(g,c)
            if m in cad_n:
                a = procura_string(cad_n,m)
                res = res + [(m, (coordenada(i,a,'E')))]
    return resposta(res)    

def procura_oeste(g,p):
    res = []
    for m in p: #Ciclo de palavras a pesquisar
        for i in range(len(g)):#Corre todas as linhas
            c = coordenada(i,len(g[0])-1,'W')
            cad_n = grelha_linha(g,c)
            if m in cad_n:
                a = procura_string(cad_n,m)
                res = res + [(m, (coordenada(i,len(g[0])-1-a,'W')))]
    return resposta(res)      

def procura_sudeste_noroeste(g,p,d):
    res = []
    for m in p:
        for i in range(1,grelha_nr_linhas(g)-1):
            c = coordenada(i,0,'SE')
            cad_n = grelha_linha(g,c)
            if d=='SE':
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(i+a,a,'SE')))]
            elif d=='NW':
                cad_n = inverte_string(cad_n)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada((grelha_nr_linhas(g)-1)-a,(len(cad_n)-1)-a,'NW')))]
        for i in range(0,len(g[0])):
            c = coordenada(0,i,'SE')
            cad_n = grelha_linha(g,c)
            if d=='SE':
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(a,i+a,'SE')))]
            elif d=='NW':
                cad_n = inverte_string(cad_n)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada((len(cad_n)-1)-a,i+(len(cad_n)-1)-a,'NW')))]
    return resposta(res)

def procura_sudoeste_nordeste(g,p,d):
    res = []
    for m in p:
        for i in range(0,grelha_nr_linhas(g)):
            c = coordenada(i,0,'NE')
            cad_n = grelha_linha(g,c)
            if d=='NE':
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(i-a,a,'NE')))]
            elif d=='SW':
                cad_n = inverte_string(cad_n)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(grelha_nr_linhas(g)-(len(g)-a),(len(cad_n)-1)-a,'SW')))]
        
        for i in range(1,grelha_nr_colunas(g)-1):
            c = coordenada(grelha_nr_linhas(g)-1,i,'NE')
            cad_n = grelha_linha(g,c)
            if d=='NE':
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(grelha_nr_linhas(g)-1-a,i+a,'NE')))]
            elif d=='SW':
                cad_n = inverte_string(cad_n)
                if m in cad_n:
                    a = procura_string(cad_n,m)
                    res = res + [(m, (coordenada(a,i+len(m),'SW')))]
            
    return resposta(res)

def inverte_string(string):
    nova_string = ''
    for e in range(len(string)):
        nova_string = string[e] + nova_string 
    return nova_string




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



#fich = open('capitais.txt','r')
#lst_linhas = fich.readlines()
        
#def transforma(lst):
 #   nova_lista = []
  #  for e in range(2,(len(lst))):
   #     nova_lista = nova_lista + [lst_linhas[e]]
    #return nova_lista