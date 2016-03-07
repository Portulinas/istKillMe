#tipo direcao

direcoes=['N','E','NE','NW','SE','SW','W','S']

def e_direcao(arg):
    """
    e_direcao : universal --> logico
    e_direcao(arg) tem o valor verdadeiro se o arg for do tipo direcao e falso
    caso contrario
    """
    return arg in direcoes

def e_norte(dir):
    """
    e_norte : direcao --> logico
    e_norte(dir) tem o valor verdadeiro se o arg for o elemento 'N' e falso caso
    contrário.
    """
    return dir == 'N'

def e_sul(dir):
    """
    e_sul : direcao --> logico
    e_sul(dir) tem o valor verdadeiro se o arg for o elemento 'S' e falso caso
    contrário.
    """
    return dir == 'S'

def e_leste(dir):
    """
    e_leste : direcao --> logico
    e_leste(dir) tem o valor verdadeiro se o arg for o elemento 'E' e falso caso
    contrário.
    """
    return dir == 'E'

def e_oeste(dir):
    """
    e_oeste : direcao --> logico
    e_oeste(dir) tem o valor verdadeiro se o arg for o elemento 'O' e falso caso
    contrário.
    """
    return dir == 'O'

def e_nordeste(dir):
    """
    e_nordeste : direcao --> logico
    e_nordeste(dir) tem o valor verdadeiro se o arg for o elemento 'NE' e falso
    caso contrário.
    """
    return dir == 'NE'

def e_noroeste(dir):
    """
    e_noroeste : direcao --> logico
    e_noroeste(dir) tem o valor verdadeiro se o arg for o elemento 'NW' e falso
    caso contrário.
    """
    return dir == 'NW'

def e_sudeste(dir):
    """
    e_sudeste : direcao --> logico
    e_sudeste(dir) tem o valor verdadeiro se o arg for o elemento 'SE' e falso
    caso contrário.
    """
    return dir == 'SE'

def e_sudoeste(dir):
    """
    e_sudoeste : direcao --> logico
    e_sudoeste(dir) tem o valor verdadeiro se o arg for o elemento 'SW' e falso
    caso contrário.
    """
    return dir == 'SW'

def direcoes_iguais(dir1, dir2):
    """
    direcoes_iguais : direcao x direcao --> lógico
    direcoes_iguais(dir1, dir2) devolve o valor verdadeiro se as direções dir1 e
    dir2 forem iguais e falso caso contrário.
    """
    return dir1 == dir2

def direcao_oposta(dir):
    """
    direcao_oposta : direcao ! direcao
    direcao_oposta(dir) devolve a direção oposta de dir de acordo com a rosa dos
    ventos.
    """
    for e in range(len(direcoes)):
        if dir == direcoes[e]:
            return direcoes[len(direcoes)-1-e]

    



