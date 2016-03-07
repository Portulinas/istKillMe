def encontra_indice(string,palavra):
    indice = 0
    def encontra_indice_aux(e,string,palavra):
        if len(palavra) == 1 or len(string)==1:
            if string[0] == palavra[0]:
                return e
        if string[0] == palavra[0]:
            return encontra_indice_aux(e,string[1:],palavra[1:])        

    for e in range(0,len(string)-1):
        if string[e] == palavra[0]:
            indice = encontra_indice_aux(e,string[e+1:],palavra[1:])
  
    return indice

