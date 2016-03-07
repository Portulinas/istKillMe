# =============================================================================
# Direções/coordenadas
# =============================================================================

direcoes = ['N','S','E','W','NW','SE','SW','NE']
f = open('capitais.txt','r')
lst = f.readlines()

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

def coord_linha(c):
    """
    coord_linha : coordenada --> N0
    coord_linha(c) tem como valor a linha da coordenada.
    """
    return c[0]    

def direcoes_iguais(d1,d2):
    return d1==d2


def direcao_oposta(direcao):
    rosa_ventos={'N':'S','S':'N','E':'W','W':'E','NE':'SW','SW':'NE','NW':'SE','SE':'NW'}
    return rosa_ventos[direcao]

def e_coordenada(c):
    """
    e_coordenada : universal --> logico
    e_coordenada(arg) tem o valor verdadeiro se o arg for do tipo coordenada e falso caso contrario.
    """
    return (isinstance(c,tuple) and 3==len(c) and isinstance(c[0] and c[1],int) and c[2] in direcoes)

# =============================================================================
#Grelha
# =============================================================================
#Construtor

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
            if len(len[0]) != len(lst[i]):
                return False
        return True
    else:
        return False
    

# =============================================================================
#Teste
# =============================================================================

def grelhas_iguais(g1, g2):
    return g1 == g2