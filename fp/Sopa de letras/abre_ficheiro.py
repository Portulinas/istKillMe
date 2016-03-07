fich = open('capitais.txt','r')
lst_linhas = fich.readlines()

def transforma(lst):
    nova_lista = []
    for e in range(2,(len(lst))):
        nova_lista = nova_lista + [lst_linhas[e]]
    return nova_lista


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
