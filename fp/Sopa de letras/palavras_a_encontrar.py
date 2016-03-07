fich = open('capitais_v2.txt','r')
lst_linhas = fich.readlines()



correcto = ['LISBOA','BRASILIA','PARIS','LONDRES','MOSCOVO','ROMA','CARACAS','TOQUIO','CAIRO','BERLIM']


palavras_descobrir = []

def palavras_a_descobrir(linha):
    linha = linha[10:]
    indice = 0
    palavra = ''
    palavras_descobrir = []    
    
    for e in range(len(linha)):
        if linha[e]==',' or linha[e]=='\n':
            palavras_descobrir = palavras_descobrir + [palavra]
            palavra = ''
        elif linha[e] ==' ':
            palavras_descobrir = palavras_descobrir
        else: 
            palavra = palavra + linha[e]
    print(palavras_descobrir)

