import sys

input = sys.stdin.readline

seq_fib = [
    1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 
    1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 
    196418, 317811, 514229, 832040
    ]

sucesso = False
qte_monstros = int(input())
elementos = [int(x) for x in input().split()]
tamanho = len(elementos)

qtd_uns = elementos.count(1)
itens = []
indices = []
em_sequencia = False

if qtd_uns > 1:
    idx_primeiro = elementos.index(1)
    indices.append(idx_primeiro + 1) #Soma 1 pra botar o indice em fator de 1 (ao inves de 0 que eh o padrao das listas)
    elementos.pop(idx_primeiro)
    
    idx_segundo = elementos.index(1)
    indices.append(idx_segundo + 2) #Soma 2 para botar o indice em fator de 1 (porem soma 2 porque o primeiro 1 sofreu pop, entao os indices seguintes foram reduzidos em 1)
    
    print(f"{indices[0]} {indices[1]}")
    sucesso = True
else:
    for i in range(2, len(seq_fib)):
        num = seq_fib[i]
        if num in elementos:
            itens.append(num)
            indices.append(elementos.index(num))

            if em_sequencia:
                indices[0] += 1
                indices[1] += 1
                print(f"{indices[0]} {indices[1]}")
                sucesso = True
                break

            em_sequencia = True
        else:
            em_sequencia = False
            indices.clear()
            itens.clear()

if not sucesso:
    print("impossible")