# Relatório de Estudos: DP com Bitmasks para o Contest

Base: guia "Aula 6 — DP com Bitmasks" (Seletiva MaratonaCIn).

## 1. Visão geral: como reconhecer o problema em 5 minutos

Se o enunciado traz N ≤ 20 (ou até 22) e o que importa é *quais itens já foram usados*, o problema é de bitmask. A ordem só importa quando o estado precisa lembrar o último elemento (caso do TSP).

| Sinal no enunciado | Técnica | Complexidade | Limite de N |
| --- | --- | --- | --- |
| "Teste todas as escolhas", dividir em dois grupos, soma de subconjunto | Loop sobre máscaras (força bruta) | O(N · 2^N), ou O(2^N) com soma incremental | ≤ 20 |
| Interruptores, flags, potências de 2, contar bits, bases | Operações de bit puras | O(1) por operação | até 64 |
| Cobrir um conjunto cheio com itens que cobrem subconjuntos, custo mínimo | dp[mask] com transição `mask \| m` | O(2^B · N) | B pequeno (3 no exemplo) ou N ≤ 20 |
| Emparelhar N pessoas com N tarefas | dp[mask], pessoa = popcount(mask) | O(N · 2^N) | ≤ 20 |
| Melhor ordem de visitar/fazer N coisas | dp[mask][last] (TSP) | O(N² · 2^N) | ≤ 20 |
| Cobrir tudo com o mínimo de "grupos" (retas, intervalos) | dp[mask] + truque do menor descoberto | O(N · 2^N) | ≤ 20 |
| Cada elemento com 3 estados | Máscara na base 3 | O(3^N) | ≤ 12 a 14 |

Checklist de decisão, na ordem:

1. Olhe o maior N. Se N ≤ 10 ou 11, `next_permutation` já resolve. Se N ≤ 20, pense em 2^N.
2. Pergunte: o futuro depende só do *conjunto* usado? Então `dp[mask]`.
3. Pergunte: depende também de *onde estou agora*? Então `dp[mask][last]`.
4. Cheque a conta: estados × transições. Para N = 20, 2^20 · 20 ≈ 2·10^7 passa fácil; 2^20 · 20 · 20 ≈ 4·10^8 passa no limite (TSP), com C++ enxuto.
5. Cheque a memória: `int dp[20][1<<20]` = 80 MB; com `long long` = 160 MB.

## 2. Estilo 1: força bruta sobre subconjuntos

É o estilo mais provável de aparecer e o mais barato de acertar: "escolha um subconjunto que maximize/minimize/conte algo" com N ≤ 20. Exemplos clássicos: Apple Division (CSES), contar subconjuntos com soma K, "existe subconjunto com soma/XOR/produto igual a X", dividir em dois grupos com diferença mínima.

**Resolução.** Cada `mask` de 0 a `(1<<n)-1` é uma escolha. O bit i diz se o elemento i entrou. Para cada máscara, calcule o valor e atualize a resposta.

```cpp
// Apple Division: dividir n maçãs em 2 grupos minimizando |soma1 - soma2|
int n; cin >> n;
vector<long long> a(n); long long total = 0;
for (auto &x : a) { cin >> x; total += x; }
long long best = LLONG_MAX;
for (int mask = 0; mask < (1 << n); mask++) {
    long long s = 0;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i)) s += a[i];
    best = min(best, llabs(total - 2 * s));   // grupo2 = total - s
}
cout << best << endl;
```

**Versão O(2^N), sem o fator N.** A soma de uma máscara é a soma da máscara sem o menor bit, mais o valor desse bit:

```cpp
vector<long long> soma(1 << n, 0);
for (int mask = 1; mask < (1 << n); mask++) {
    int i = __builtin_ctz(mask);
    soma[mask] = soma[mask & (mask - 1)] + a[i];
}
```

**Pontos-chave**

- `1 << n` só serve para n ≤ 30. Com mais bits, use `1LL << n`.
- Escreva sempre `mask & (1 << i)` com parênteses.
- Diferença entre dois grupos: `|total - 2·s|`, sem calcular o segundo grupo.
- Se N chegar a 25 ou 30 com tempo apertado, a técnica pedida é *meet in the middle* (veja a seção 8).
- Variante "exatamente 3 escolhidos": `__builtin_popcount(mask) == 3` filtra as máscaras, como em conteste3/H.cpp.

## 3. Estilo 2: manipulação pura de bits

Problemas curtos, sem DP, que testam se você domina os operadores. Aparecem como questão de aquecimento: painel de interruptores, "menor número de potências de 2 que somam N", "N é potência de 2?", contar bits, XOR de um intervalo, escrever N em outra base, palíndromo em binário.

**Operações que você precisa de cabeça**

| Preciso de... | Código |
| --- | --- |
| ler o bit i | `(mask >> i) & 1` |
| ligar / desligar / inverter | `mask \|= 1<<i` / `mask &= ~(1<<i)` / `mask ^= 1<<i` |
| menor bit ligado (valor) | `mask & -mask` |
| índice do menor bit ligado | `__builtin_ctz(mask)` |
| apagar o menor bit ligado | `mask &= mask - 1` |
| contar bits ligados | `__builtin_popcount(mask)` (ou `popcountll`) |
| é potência de 2? | `x > 0 && !(x & (x - 1))` |
| conjunto cheio de n elementos | `(1LL << n) - 1` |

**Resolução típica 1: menor quantidade de potências de 2 que somam N.** A resposta é `popcount(N)`, porque cada bit ligado é uma potência necessária e nenhuma pode ser trocada por menos.

**Resolução típica 2: percorrer só os bits ligados.**

```cpp
for (long long m = x; m; m &= m - 1) {
    int i = __builtin_ctzll(m);   // i está ligado em x
}
```

**Resolução típica 3: base b.** Pegue `N % b` como dígito, divida `N /= b` e repita. Os dígitos saem do menos significativo para o mais. 43 na base 3 é 1121 (1 + 6 + 9 + 27 = 43).

**Pontos-chave**

- `mask & (1 << i)` devolve `1 << i`, não 1. Para 0/1 use `!= 0` ou `(mask >> i) & 1`.
- Potência de 2: `mask = 0` também passa no teste `!(x & (x-1))`; exija `x > 0`.
- `popcount` para `long long` é `__builtin_popcountll`. Usar a versão de int trunca os 32 bits de cima.
- Para usar os 64 bits, use `unsigned long long`.
- XOR é seu amigo em paridade: `a ^ a = 0` e `a ^ 0 = a`. Se o enunciado fala em "aparece um número ímpar de vezes" ou "diferença", pense em XOR.

## 4. Estilo 3: DP de cobertura (Vitamins e variantes)

Forma do enunciado: há N itens, cada um com um custo e um subconjunto de "propriedades" (vitaminas, habilidades, tipos de ingrediente). Qual o menor custo para ter todas as propriedades? Quando o número de propriedades B é pequeno (3 a 20), o estado é o conjunto de propriedades já obtidas, e N pode ser enorme (10^6 no exemplo).

**Resolução.**

1. Estado: `dp[mask]` = menor custo para ter pelo menos as propriedades de `mask`.
2. Base: `dp[0] = 0`, o resto em INF.
3. Transição: para cada item `(custo, m)` e cada estado `j`, `dp[j | m] = min(dp[j | m], dp[j] + custo)`.
4. Resposta: `dp[cheio]`, ou -1 se continuar INF.

```cpp
const long long INF = 1e18;
vector<long long> dp(8, INF);
dp[0] = 0;
for (int i = 0; i < n; i++) {
    long long cost; string s; cin >> cost >> s;
    int m = 0;
    for (char v : s) m |= 1 << (v - 'A');
    for (int j = 0; j < 8; j++) {
        if (dp[j] == INF) continue;
        dp[j | m] = min(dp[j | m], dp[j] + cost);
    }
}
cout << (dp[7] == INF ? -1 : dp[7]) << endl;
```

Complexidade O(2^B · N). Com B = 3, são 8 · 10^6 operações.

**Por que não precisa de dp "fora do lugar".** Em uma mochila comum, atualizar `dp` no próprio vetor usaria o mesmo item duas vezes. Aqui o OR é idempotente: se `j | m == j`, a transição só tenta `dp[j] + custo`, que nunca melhora `dp[j]`. Ainda assim, se o item puder ser comprado só uma vez e o problema não for de OR (por exemplo, contagem de maneiras), copie o vetor ou itere `j` em ordem decrescente.

**Pontos-chave**

- Truque de contest em Vitamins: o ótimo usa no máximo 3 sucos (um por vitamina, no pior caso), então dá para guardar só o menor custo por máscara de suco e combinar. A DP acima é mais segura e igualmente rápida.
- Duas propriedades iguais no mesmo item não mudam a máscara; o OR cuida da repetição.
- Teste mentalmente com os exemplos: `10 ABC, 3 BC, 2 AC, 1 C, 6 AB` dá 5 (BC + AC) e `4 A, 9 BC` dá 13.
- Cuidado com `INF + custo` em `int`. Use `long long` com 1e18 ou teste `dp[j] == INF` antes.

## 5. Estilo 4: emparelhamento (Assignment) com popcount como índice

Forma do enunciado: N pessoas e N tarefas, `c[p][t]` é o custo da pessoa p fazer a tarefa t, cada um faz exatamente uma. Minimize (ou maximize) o custo total, ou conte as atribuições válidas. Também cai disfarçado: alocar N alunos em N salas, N times em N horários, "quantas permutações satisfazem restrições de quem pode ocupar qual posição".

**Resolução.** A ideia central é que a pessoa atual *não precisa ser guardada*: se já usei k tarefas, a próxima pessoa é a de índice k.

```cpp
vector<long long> dp(1 << n, INF);
dp[0] = 0;
for (int mask = 0; mask < (1 << n) - 1; mask++) {
    if (dp[mask] == INF) continue;
    int p = __builtin_popcount(mask);        // próxima pessoa
    for (int t = 0; t < n; t++) {
        if (mask & (1 << t)) continue;       // tarefa já usada
        int nova = mask | (1 << t);
        dp[nova] = min(dp[nova], dp[mask] + c[p][t]);
    }
}
cout << dp[(1 << n) - 1] << endl;
```

Estados: 2^N. Transições por estado: N. Total O(N · 2^N), que é 2·10^7 para N = 20.

**Variantes que podem aparecer**

- **Contar** atribuições: troque `min` por soma, com `dp[0] = 1`, e `c[p][t]` vira um booleano "p pode fazer t". Use módulo se pedirem.
- **Maximizar**: inicialize com -INF e use `max`.
- **Pessoas ≠ tarefas** (N pessoas, M tarefas, M maior): a máscara é sobre o lado *menor*. Percorra as tarefas e use o lado menor como máscara.
- Quando o enunciado dá regras de compatibilidade ("p só pode t se ..."), a checagem entra no `continue` do laço interno.

**Pontos-chave**

- A máscara guarda as *tarefas usadas*; a pessoa é deduzida do `popcount`. Isso economiza uma dimensão de DP.
- Teste mínimo do slide: custos `1 5 / 2 1` dá 2 (diagonal), contra 7 (cruzado).
- Se N passar de 20, o intended não é bitmask; pense em Húngaro ou fluxo de custo mínimo.

## 6. Estilo 5: TSP e "melhor ordem" com dp[mask][last]

Forma do enunciado: visitar N pontos uma vez cada com custo mínimo (ciclo ou caminho), ordenar N tarefas com custo de transição entre elas, montar N peças em ordem ótima, entregar pedidos. Também cai como **contar caminhos hamiltonianos** (CSES Hamiltonian Flights) ou como "menor número de viagens" (CSES Elevator Rides).

**Por que o estado tem dois campos.** Duas rotas que visitam o mesmo conjunto e terminam no mesmo nó têm o mesmo futuro. Então o estado é `(conjunto visitado, último nó)`: n · 2^n estados, até n transições cada, O(n² · 2^n). Contra O(n!) da força bruta: para n = 20 são 4·10^8 contra 2,4·10^18.

**Resolução bottom-up (ciclo, começando e voltando ao nó 0)**

```cpp
int cheia = (1 << n) - 1;
vector<int> dp((1 << n) * n, INF);          // dp[mask*n + last]
dp[1 * n + 0] = 0;                          // só o nó 0 visitado
for (int mask = 1; mask <= cheia; mask++) {
    if (!(mask & 1)) continue;              // todo caminho contém o 0
    for (int last = 0; last < n; last++) {
        int cur = dp[mask * n + last];
        if (!(mask & (1 << last)) || cur >= INF) continue;
        for (int nxt = 0; nxt < n; nxt++) {
            if (mask & (1 << nxt)) continue;
            int &alvo = dp[(mask | (1 << nxt)) * n + nxt];
            alvo = min(alvo, cur + g[last][nxt]);
        }
    }
}
int ans = INF;
for (int last = 0; last < n; last++)
    ans = min(ans, dp[cheia * n + last] + g[last][0]);
```

No grafo do slide (A-B 4, A-C 7, A-D 6, B-C 8, B-D 2, C-D 5), o ciclo mínimo é 18 (A→B→D→C→A) e o caminho mínimo a partir de A é 11.

**Como adaptar ao que o enunciado pedir**

| Variação | O que muda |
| --- | --- |
| Caminho, sem voltar | Resposta = `min(dp[cheia][last])`, sem somar `g[last][0]` |
| Começo livre | Inicialize `dp[1<<i][i] = 0` para todo i e remova a exigência do bit 0 |
| Contar caminhos | `min` vira soma com módulo, o INF vira 0 e a base é `dp[1][0] = 1` |
| Arestas inexistentes | `if (g[last][nxt] == INF) continue;`, com `long long` e INF seguro |
| Maximizar | Troque `min` por `max` e INF por -INF |
| Reconstruir a rota | Guarde `pai[mask][last]` e volte do fim |

**Pontos-chave**

- `int dp[20][1<<20]` ocupa 80 MB; com `long long` 160 MB. Confira o limite de memória antes de escolher o tipo.
- Top-down com memoização usa `-1` como "não calculado". Use só se -1 não for resposta válida, e não esqueça o `memset`.
- Força bruta com `next_permutation` (fixando o nó 0 na frente) basta para n ≤ 10. Se o N for 8 ou 9, não complique.
- Poda no backtracking (`if (cur >= best) return;`) ajuda, mas não muda o pior caso O(n!).

## 7. Estilo 6: cobertura mínima com "o menor descoberto" (Gabmei)

Forma do enunciado: N ≤ 20 objetos; cada "ação" cobre um subconjunto deles (todos os pontos de uma reta, todos os elementos de um intervalo, os vizinhos de um nó); ache o menor número de ações para cobrir tudo. É o *set cover* pequeno. No Gabmei, são balões no plano e cada dardo é uma reta infinita.

**Resolução em 4 passos**

1. **Gerar as ações candidatas como máscaras.** Para cada par (i, j), `linha[i][j]` é a máscara de todos os pontos colineares com i e j. Para a reta de um balão só, `linha[i][i] = 1 << i`.
2. **Teste de colinearidade pelo produto vetorial**, em `long long`: `(xj-xi)*(yk-yi) - (yj-yi)*(xk-xi) == 0`. As coordenadas diferem até 2·10^6, então o produto chega a 4·10^12 e estoura `int`.
3. **Estado:** `dp[mask]` = mínimo de retas para cobrir os balões de `mask`. `dp[0] = 0`.
4. **Truque que derruba a complexidade:** a ordem das retas não importa, então toda transição cobre o *menor balão ainda descoberto*, `i = __builtin_ctz(~mask)`. Em qualquer solução ótima alguma reta cobre i, então nada se perde.

```cpp
for (int mask = 0; mask < cheia; mask++) {
    if (dp[mask] == INF) continue;
    int i = __builtin_ctz(~mask);            // menor balão descoberto
    for (int j = 0; j < n; j++) {
        int nova = mask | linha[i][j];       // j == i: reta só com i
        dp[nova] = min(dp[nova], dp[mask] + 1);
    }
}
```

Sem o truque seriam 2^n · n² transições (≈ 4·10^8). Com ele, 2^n · n ≈ 2·10^7. O pré-cálculo das máscaras custa O(n³).

**Casos de teste para conferir:** (0,0),(1,1),(2,2) dá 1; o quadrado unitário dá 2; três pontos não alinhados dá 2; um balão dá 1.

**Onde mais esse padrão aparece**

- Cobrir pontos com o menor número de retas, círculos ou retângulos.
- Cobrir intervalos ou posições com "pulverizadores" de alcance dado, quando N é pequeno.
- Menor número de grupos de um certo tipo que cubra todos os elementos (dominating set em grafo pequeno).
- Contar maneiras de cobrir: o mesmo truque do menor descoberto evita contar a mesma cobertura em ordens diferentes.

**Pontos-chave**

- Sempre `long long` no produto vetorial.
- O laço vai até `mask < cheia`, então `~mask` sempre tem um bit 0 entre os n primeiros e `__builtin_ctz(~mask)` devolve um índice válido.
- Pontos duplicados quebrariam o teste de reta; o enunciado garante pontos distintos.
- A resposta nunca passa de `ceil(n/2)`, porque dois pontos sempre formam uma reta.

## 8. Estilo 7: variações que podem aparecer

Estas variações não estão resolvidas com código completo no seu PDF, mas usam as mesmas peças. O guia cita Elevator Rides como prática e a base 3 como extensão natural. Iterar submáscaras e meet in the middle são técnicas vizinhas comuns em provas com esse tema; são bônus, escritos de memória.

### 8.1 Elevator Rides: dp[mask] = (corridas, peso)

N pessoas com pesos `w[i]`, elevador com capacidade X. Qual o menor número de viagens? O estado guarda um *par*: `dp[mask] = {viagens usadas, peso na viagem atual}`, e o par é comparado lexicograficamente (menos viagens primeiro, depois menos peso).

```cpp
vector<pair<int,int>> dp(1 << n, {n + 1, 0});
dp[0] = {1, 0};                              // 1 viagem aberta, vazia
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        auto [v, p] = dp[mask];
        if (p + w[i] <= X) p += w[i];        // cabe na viagem atual
        else { v++; p = w[i]; }              // abre nova viagem
        dp[mask | (1 << i)] = min(dp[mask | (1 << i)], make_pair(v, p));
    }
}
cout << dp[(1 << n) - 1].first << endl;
```

Por que guardar só o melhor par basta: menos viagens sempre vence, e com o mesmo número de viagens o menor peso na última deixa mais espaço.

### 8.2 Máscara na base 3

Cada elemento tem 3 estados (não visto, visto uma vez, visto duas vezes). O estado vira um número na base 3, com 3^N estados. Pré-calcule `p3[i]`, leia o dígito com `(m / p3[i]) % 3` e suba o estado com `m += p3[i]`. Serve até N ≈ 12 a 14.

### 8.3 Iterar submáscaras (bônus)

Para combinar `mask` com todos os seus subconjuntos, o laço padrão é:

```cpp
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // sub é um subconjunto não vazio de mask
}
```

Somando sobre todas as máscaras, o custo total é O(3^N), não O(4^N). Aparece em "particione o conjunto em grupos válidos com custo mínimo": `dp[mask] = min(dp[mask ^ sub] + custo[sub])`.

### 8.4 Meet in the middle (bônus)

Quando N está entre 25 e 40, 2^N estoura. Divida o conjunto em duas metades de N/2, enumere as 2^(N/2) máscaras de cada lado, ordene uma delas e combine por busca binária ou dois ponteiros. É a saída natural de uma questão de subconjuntos que "quase" cabe em bitmask.

### 8.5 Outras formas de cair

| Enunciado | Máscara representa | Dica |
| --- | --- | --- |
| Jogo de dois jogadores com itens usados | Itens já tirados | `dp[mask]` = ganha/perde; N ≤ 20 |
| Colorir grafo / conjunto independente máximo | Vértices escolhidos | Verifique `adj[i] & mask` |
| Cobrir N com "turnos" de capacidade (bin packing) | Itens já alocados | Estilo Elevator Rides |
| Interruptores e lâmpadas | Estado das lâmpadas | BFS sobre máscaras |
| Grade pequena com perfil de colunas | Cobertura da coluna atual | Bitmask de perfil (mais difícil) |

## 9. Armadilhas e checklist de implementação

A maior parte dos WA/TLE/MLE em bitmask vem de uma lista curta de erros. Revise-a antes de submeter.

| Erro | Sintoma | Correção |
| --- | --- | --- |
| `1 << n` com n ≥ 31 | Resposta absurda ou laço infinito | `1LL << n` e `popcountll` |
| `mask & 1 << i` sem parênteses | Máscara errada, bug silencioso | `mask & (1 << i)` |
| Tratar o resultado de `&` como 0/1 | `if (x == 1)` falha para i > 0 | `!= 0` ou `(mask >> i) & 1` |
| `INF + custo` estoura | Valores negativos no `dp` | `long long` com 1e18, ou `if (dp == INF) continue;` |
| `memset(dp, -1)` com -1 como resposta válida | Memo "vazando" | Use outro sentinela |
| Esquecer o `memset` ou a reinicialização entre casos de teste | WA em múltiplos testes | Reinicialize `dp` por caso |
| `dp[20][1<<20]` de `long long` | MLE (160 MB) | Use `int`, ou vetor plano com só os estados válidos |
| N = 25 com O(N · 2^N) | TLE (≈ 8·10^8) | Troque por meet in the middle ou otimize |
| `pow(2, n)` | Erro de ponto flutuante | `1LL << n` |
| Produto vetorial em `int` | WA em geometria | Cast para `long long` |
| `__builtin_ctz(0)` | Comportamento indefinido | Teste `mask != 0` antes |

**Rotina de 3 minutos antes de codar**

1. Escreva o estado em uma frase: "dp[mask] = menor custo para ...".
2. Escreva a base e a resposta (`dp[0]` e `dp[cheia]`).
3. Escreva a transição em uma linha. Ela precisa sempre ir de `mask` para uma máscara maior (`mask | x >= mask`), senão a ordem crescente não vale.
4. Calcule estados × transições e a memória.
5. Faça um teste de 2 elementos à mão antes de submeter.

**Estratégia de contest**

- Leia todas as questões. Bitmask com N ≤ 20 é sinal quase certo de que 2^N é esperado.
- Se N ≤ 10, `next_permutation` costuma ser mais rápido de escrever e seguro.
- Se você não enxergar a DP, comece por uma força bruta correta; ela serve de gerador de testes depois.
- Use `ios::sync_with_stdio(false); cin.tie(NULL);` sempre.

## 10. Cola rápida e plano de revisão

**Receita da DP em máscaras.** Estado `dp[mask]` (ou `dp[mask][last]`). Base `dp[0] = 0` (ou o nó inicial). Transição acrescentando um elemento com `mask | (1 << j)`. A ordem crescente de `mask` funciona porque `mask | x >= mask`. Resposta em `dp[cheia]`.

**Template reutilizável (dp[mask] genérico)**

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    const ll INF = 1e18;
    vector<ll> dp(1 << n, INF);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == INF) continue;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) continue;
            int nova = mask | (1 << j);
            dp[nova] = min(dp[nova], dp[mask] + /* custo(mask, j) */ 0);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}
```

**Plano para hoje e amanhã cedo**

- [ ] Releia as seções 2 a 7 uma vez, olhando só o estado, a base e a transição de cada uma.
- [ ] Reescreva do zero, sem olhar, Apple Division com `soma[mask]`, Vitamins e Assignment.
- [ ] Reescreva o TSP bottom-up e confira o ciclo 18 e o caminho 11 do grafo do slide.
- [ ] Reescreva o Gabmei e rode os 4 testes da seção 7.
- [ ] Resolva uma questão nova: CSES Elevator Rides ou Hamiltonian Flights.
- [ ] Durma. Em contest, cabeça descansada vale mais que mais uma questão estudada.

**Ordem sugerida de prática, do guia:** Codeforces 1042B Vitamins, CSES Apple Division em O(2^n), CSES Elevator Rides, CSES Hamiltonian Flights e o Gabmei com seus próprios testes.

**Fonte:** o guia "Aula 6 — DP com Bitmasks" (Seletiva MaratonaCIn, slides de helington e João Henrique) que você enviou. As seções 8.3, 8.4 e a tabela 8.5 são complementos meus, de memória, e não vêm do PDF.
