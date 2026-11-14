# Aula 7 — Teoria dos Números

Guia de estudos em programação, baseado nos slides da Aula 7 da Seletiva (MaratonaCIn, João Luís e Renan). Todos os códigos deste guia foram compilados e testados com os exemplos dados.

## Como usar este guia

Cada tópico segue a mesma estrutura:

1. **Lógica:** a ideia por trás, só o matemático necessário para programar.
2. **Que tipo de problema resolve:** para você reconhecer o tópico no enunciado.
3. **Como programar:** o código passo a passo, com as armadilhas de implementação.
4. **Exemplo completo:** um problema de maratona, com entrada de exemplo e código pronto para colar.

## Ponte com o que você já aprendeu

| Já visto | Reaparece em |
|---|---|
| Bitmask de subconjuntos (`mask & (1 << i)`, homework2 G, M, O) | Inclusão-Exclusão |
| Prefix sum (Aula 1) | Contar primos em um intervalo com o crivo |
| Overflow e `long long` (Aula 1) | Praticamente tudo desta aula |
| Operadores de bit (`&`, `>>`) | Exponenciação rápida |
| Regra de ouro de ≈10⁸ operações (Aula 1) | Escolher entre O(√n), O(n log n) e O(log n) |

## Mapa da aula

| Tópico | Ideia em uma linha | Complexidade |
|---|---|---|
| MDC e MMC | Algoritmo de Euclides | O(log min(a, b)) |
| Divisores | Divisores vêm em pares (i, n/i) | O(√n) |
| Fatoração prima | Dividir repetidamente por i até √n | O(√n) |
| Crivo | Marcar múltiplos dos primos | O(N log log N) |
| Aritmética modular | Reduzir com `% MOD` a cada operação | O(1) por operação |
| Exponenciação rápida | Elevar ao quadrado e olhar os bits de b | O(log b) |
| Combinatória modular | Fatoriais pré-calculados e inversos | O(N) pré-cálculo, O(1) por consulta |
| Inclusão-Exclusão | Bitmask sobre subconjuntos, sinal alternado | O(2ᵏ · k) |
| Recorrência linear | Exponenciação de matrizes | O(T³ log n) |

---

## 1. MDC e MMC (GCD e LCM)

### Lógica

- MDC(a, b) é o maior número que divide a e b. MMC(a, b) é o menor múltiplo positivo comum.
- **Algoritmo de Euclides:** `gcd(a, b) = gcd(b, a % b)`, parando em `gcd(a, 0) = a`.
- **Por que funciona:** todo divisor comum de a e b também divide `a % b` (que é `a - k·b`), então o conjunto de divisores comuns não muda, mas os números encolhem muito rápido. A cada duas chamadas o valor cai pelo menos pela metade, daí O(log min(a, b)).

Rastreio de `gcd(24, 36)`: gcd(24,36) → gcd(36,24) → gcd(24,12) → gcd(12,0) = 12.

Propriedades dos slides, já pensando em código:

| Propriedade | Uso prático |
|---|---|
| `gcd(a,b) * lcm(a,b) = a * b` | Calcular o MMC a partir do MDC |
| `lcm(a,b) = a / gcd(a,b) * b` | Dividir antes de multiplicar, para não estourar `long long` |
| `gcd(a,b,c,d) = gcd(gcd(gcd(a,b),c),d)` | Para uma lista: acumular com um `for` |
| `lcm(a,b,c,d) = lcm(lcm(lcm(a,b),c),d)` | Idem |
| `gcd(a,b)` divide `lcm(a,b)` | Todo divisor comum divide qualquer múltiplo comum |

### Que tipo de problema resolve

- Simplificar frações, dividir em blocos iguais do maior tamanho possível (MDC).
- "De quanto em quanto tempo dois eventos coincidem?" (MMC).
- Saber se dois números são coprimos (`gcd = 1`), o que aparece em aritmética modular.
- Maior K tal que todos os elementos de um array são divisíveis por K (MDC do array).

### Como programar

No C++17 já existem `gcd` e `lcm` em `<numeric>` (o `#include <bits/stdc++.h>` já inclui). Cuidado: passe os dois argumentos com o mesmo tipo.

```cpp
ll g = gcd(24LL, 36LL);   // 12
ll l = lcm(24LL, 36LL);   // 72
```

Vale saber escrever à mão, pois é curto:

```cpp
ll mdc(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll mmc(ll a, ll b) {
    return a / mdc(a, b) * b;   // divide ANTES de multiplicar
}
```

### Armadilhas

- `a * b / gcd(a, b)` pode estourar mesmo quando o MMC cabe. Use sempre `a / gcd * b`.
- Para acumular sobre uma lista, comece com os elementos neutros: `g = 0` (pois `mdc(0, x) = x`) e `l = 1` (pois `mmc(1, x) = x`).
- O MMC de uma lista cresce rápido. Se o enunciado não garante que cabe em `long long`, ele provavelmente pede o resultado módulo algum número ou usa outra abordagem.

### Exemplo completo

**Problema.** São dados N inteiros positivos. Imprima o MDC e o MMC de todos eles (o MMC cabe em `long long`).

| Entrada | Saída |
|---|---|
| `3`<br>`6 8 12` | `2 24` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mdc(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll mmc(ll a, ll b) {
    return a / mdc(a, b) * b;   // divide ANTES de multiplicar
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll g = 0, l = 1;            // elementos neutros
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        g = mdc(g, x);
        l = mmc(l, x);
    }
    cout << g << " " << l << "\n";
}
```

---

## 2. Divisores

### Lógica

- **Jeito ingênuo:** testar todo i de 1 a n e ver se `n % i == 0`. É O(n). Com n = 10⁹ são 1 bilhão de testes, e o slide mostra o resultado: *Time limit exceeded*.
- **Jeito esperto:** os divisores vêm em pares. Se i divide n, então n / i também divide. Em cada par, um dos dois é ≤ √n. Então basta testar i até √n, e cada i encontrado já entrega dois divisores.

Exemplo com n = 36:

| i | divide? | divisores obtidos |
|---|---|---|
| 1 | sim | 1 e 36 |
| 2 | sim | 2 e 18 |
| 3 | sim | 3 e 12 |
| 4 | sim | 4 e 9 |
| 5 | não | (nenhum) |
| 6 | sim | 6 (só uma vez, pois 6 = 36/6) |

Por isso o código tem o teste `if (i != n / i)`: quadrados perfeitos não devem contar o divisor duas vezes.

**Complexidade:** O(√n). Com n até 10¹², são só 10⁶ iterações.

### Que tipo de problema resolve

- Contar, listar ou somar os divisores de um número grande.
- Testar se n é primo: n é primo se não tem divisor em [2, √n].
- Problemas do tipo "encontre o menor/maior divisor com tal propriedade".

Se forem muitos números pequenos (até uns 10⁶), o crivo do tópico 4 é melhor.

### Como programar

```cpp
vector<ll> getDivisors(ll n) {
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++) {     // i*i <= n em vez de i <= sqrt(n)
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());             // os pares saem fora de ordem
    return d;
}

bool ehPrimo(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
```

### Armadilhas

- Use `i * i <= n` com `i` e `n` em `long long`. Com `int`, `i * i` pode estourar. E evite `i <= sqrt(n)`, pois `sqrt` trabalha com `double` e pode errar por arredondamento.
- Os divisores saem na ordem 1, n, 2, n/2, ... Se o problema pede ordenados, faça o `sort`.

### Exemplo completo

**Problema.** Dado N (até 10¹²), imprima a quantidade de divisores, a soma dos divisores e a lista deles em ordem crescente.

| Entrada | Saída |
|---|---|
| `36` | `9 91`<br>`1 2 3 4 6 9 12 18 36` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> getDivisors(ll n) {
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> d = getDivisors(n);
    cout << d.size() << " " << accumulate(d.begin(), d.end(), 0LL) << "\n";
    for (ll x : d) cout << x << " ";
    cout << "\n";
}
```

---

## 3. Fatoração prima

### Lógica

Todo inteiro n ≥ 2 se escreve de um único jeito como produto de primos. Por exemplo, 360 = 2³ · 3² · 5¹. O algoritmo do slide:

1. Para cada i a partir de 2, divida n por i repetidamente enquanto i dividir n, contando quantas vezes (`cnt`).
2. `cnt` é o expoente do primo i. Só guarde se `cnt > 0`.
3. Pare quando `i * i > n`.
4. Se sobrou `n > 1`, esse resto é um primo (o maior fator). Guarde com expoente 1.

**Por que só aparecem primos?** Quando o laço chega em i, todos os fatores menores já foram removidos por completo. Se i dividisse n e fosse composto, seus fatores primos menores já teriam sido tirados antes. **Por que o resto é primo?** Se fosse composto, teria um fator ≤ √n, que o laço já teria encontrado.

Rastreio com n = 360:

| i | divisões | n depois | guarda |
|---|---|---|---|
| 2 | 360→180→90→45 (3 vezes) | 45 | (2, 3) |
| 3 | 45→15→5 (2 vezes) | 5 | (3, 2) |
| 4 | não divide | 5 | nada |
| (16 > 5, para) | | 5 | resto 5 > 1: (5, 1) |

**Complexidade:** O(√n), e como n encolhe durante o laço, costuma ser bem menos.

### Que tipo de problema resolve

Depois de ter a fatoração n = p₁^e₁ · p₂^e₂ · ..., muita coisa vira fórmula:

| Quero | Fórmula |
|---|---|
| Quantidade de divisores | (e₁+1)·(e₂+1)·... (cada expoente pode ir de 0 a eᵢ, independentemente) |
| Soma dos divisores | (1+p₁+...+p₁^e₁)·(1+p₂+...+p₂^e₂)·... |
| Saber se n é quadrado perfeito | todos os expoentes são pares |
| MDC e MMC de dois números | mínimo e máximo dos expoentes de cada primo |

### Como programar

```cpp
vector<pair<ll, int>> getPrimes(ll n) {          // (primo, expoente)
    vector<pair<ll, int>> primes;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) primes.push_back({i, cnt});
    }
    if (n > 1) primes.push_back({n, 1});         // sobrou um primo grande
    return primes;
}
```

Para percorrer o resultado, use a desestruturação que você viu na Aula 1: `for (auto [p, e] : fat)`.

### Exemplo completo

**Problema.** Dado N (2 ≤ N ≤ 10¹²), imprima a fatoração, a quantidade de divisores e a soma dos divisores.

| Entrada | Saída |
|---|---|
| `360` | `2^3 3^2 5^1`<br>`24`<br>`1170` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, int>> getPrimes(ll n) {
    vector<pair<ll, int>> primes;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) primes.push_back({i, cnt});
    }
    if (n > 1) primes.push_back({n, 1});
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    auto fat = getPrimes(n);

    ll qtd = 1, soma = 1;
    for (auto [p, e] : fat) {
        cout << p << "^" << e << " ";
        qtd *= (e + 1);

        ll termo = 1, pot = 1;   // termo = 1 + p + p^2 + ... + p^e
        for (int k = 1; k <= e; k++) {
            pot *= p;
            termo += pot;
        }
        soma *= termo;
    }
    cout << "\n" << qtd << "\n" << soma << "\n";
}
```

---

## 4. Crivo de Eratóstenes

### Lógica

Fatorar ou testar um número custa O(√n). Mas e se o problema pede "todos os primos até 10⁶" ou lida com muitos números? Repetir O(√n) para cada um é caro. O crivo resolve o conjunto inteiro de uma vez.

Passo a passo (slide):

1. Liste os números de 2 até n.
2. Para cada número ainda não riscado, risque todos os seus múltiplos.
3. Repita até √n.
4. Os que sobraram são primos.

A ideia central: se A é primo, nenhum múltiplo de A (além dele mesmo) é primo.

Exemplo com n = 30: o 2 risca 4, 6, 8, ...; o 3 risca 9, 12, ...; o 5 risca 25, 30. O próximo seria o 7, mas 7² = 49 > 30, então paramos. Sobraram 2, 3, 5, 7, 11, 13, 17, 19, 23, 29.

### 4.1 Crivo ingênuo e a série harmônica

A versão do slide percorre todo i de 2 até o limite e incrementa um contador nos múltiplos de i. No fim, `divisors[x] == 1` significa que só o próprio x o marcou, ou seja, x é primo.

```cpp
const int LIM = 1e6 + 5;
int divisors[LIM];

vector<int> sieve() {
    memset(divisors, 0, sizeof(divisors));
    for (int i = 2; i < LIM; i++)
        for (int j = i; j < LIM; j += i)
            divisors[j]++;

    vector<int> primes;
    for (int i = 2; i < LIM; i++)
        if (divisors[i] == 1) primes.push_back(i);
    return primes;
}
```

O defeito: roda o laço interno para i = 4, 6, 8, 9, ..., mesmo sabendo que não são primos. **Por que O(N log N)?** Para cada i o laço interno roda N/i vezes. A soma total é N/2 + N/3 + N/4 + ... = N · (1/2 + 1/3 + 1/4 + ...). Essa soma entre parênteses é a série harmônica, que cresce como o logaritmo de N. Logo, N log N.

### 4.2 Crivo otimizado

Guarde um vetor de booleanos `isPrime` e rode o laço interno só quando i é primo. Mais duas melhorias:

- o laço externo vai só até √N (os compostos maiores já foram riscados por um fator ≤ √N);
- o laço interno começa em `i * i`, pois os múltiplos `i * k` com k < i já foram riscados por primos menores.

A complexidade cai para O(N log log N), pois agora a soma é N/2 + N/3 + N/5 + N/7 + ..., só sobre os inversos dos primos.

| N = 10⁶ | Operações aproximadas |
|---|---|
| Crivo ingênuo (N · ln N) | ≈ 1,4 · 10⁷ |
| Crivo otimizado (N · ln ln N) | ≈ 2,6 · 10⁶ |

```cpp
const int LIM = 1e6 + 5;
bool isPrime[LIM];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; 1LL * i * i < LIM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < LIM; j += i)
                isPrime[j] = false;
        }
    }
}
```

#### Armadilhas

- Declare o vetor global (Aula 1: arrays grandes na pilha dão *Segmentation Fault*). `memset(isPrime, true, ...)` funciona para `bool` pois ele tem 1 byte.
- Se N for 10⁷ ou mais, o `i * i` em `int` pode estourar. Escreva `1LL * i * i`.
- O crivo só serve se você consegue alocar o vetor de tamanho N. Para n = 10¹², use a fatoração por √n do tópico 3.

### 4.3 Crivos especiais

O mesmo padrão (para cada i, visitar seus múltiplos) calcula, para todos os números de 1 a LIM de uma vez, a quantidade ou a soma dos divisores. Aqui o laço começa em i = 1 e roda para todo i, então é O(N log N), e vale a pena porque você paga uma vez e responde cada consulta em O(1):

```cpp
int numDivisors[LIM];
ll  sumDivisors[LIM];

void sieveEspecial() {
    for (int i = 1; i < LIM; i++)
        for (int j = i; j < LIM; j += i) {
            numDivisors[j]++;      // i é um divisor de j
            sumDivisors[j] += i;
        }
}
```

Compare: 10⁵ consultas com O(√x) cada, para x até 10⁶, dariam 10⁵ · 10³ = 10⁸. O pré-cálculo custa ≈ 1,4 · 10⁷, uma vez.

### Que tipo de problema resolve

- Listar primos até N, ou "qual é o k-ésimo primo".
- Contar primos em intervalos (crivo + prefix sum).
- Quantidade ou soma de divisores de muitos números (crivos especiais).
- Fatorar muitos números rapidamente (bônus abaixo).

### Bônus: menor fator primo (spf)

Uma variação muito usada: guardar, para cada número, seu menor fator primo. Depois, fatorar qualquer x ≤ LIM custa só O(log x), basta ir dividindo.

```cpp
int spf[LIM];                       // spf[x] = menor fator primo de x

void sieveSpf() {
    for (int i = 2; i < LIM; i++)
        if (spf[i] == 0)            // i é primo
            for (int j = i; j < LIM; j += i)
                if (spf[j] == 0) spf[j] = i;
}

// fatorar x:  while (x > 1) { int p = spf[x]; x /= p; /* p é um fator */ }
```

### Exemplo completo 1: primos em intervalo (crivo + prefix sum)

**Problema.** Q consultas `l r` (1 ≤ l ≤ r ≤ 10⁶, Q ≤ 10⁵). Para cada uma, diga quantos primos existem em [l, r].

| Entrada | Saída |
|---|---|
| `3`<br>`1 10`<br>`11 20`<br>`1 100` | `4`<br>`4`<br>`25` |

```cpp
#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e6 + 5;
bool isPrime[LIM];
int pref[LIM];              // pref[i] = quantidade de primos em [1, i]

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; 1LL * i * i < LIM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < LIM; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 1; i < LIM; i++)
        pref[i] = pref[i - 1] + isPrime[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << "\n";   // soma de prefixos da Aula 1
    }
}
```

### Exemplo completo 2: quantidade de divisores (crivo especial)

**Problema.** Q consultas, cada uma com um número x (x ≤ 10⁶, Q ≤ 10⁵). Imprima a quantidade de divisores de cada x.

| Entrada | Saída |
|---|---|
| `3`<br>`16`<br>`17`<br>`18` | `5`<br>`2`<br>`6` |

```cpp
#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e6 + 5;
int numDivisors[LIM];

void sieve() {
    for (int i = 1; i < LIM; i++)
        for (int j = i; j < LIM; j += i)
            numDivisors[j]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << numDivisors[x] << "\n";
    }
}
```

---

## 5. Aritmética modular

### Lógica

Muitos problemas pedem a resposta módulo algum número grande, quase sempre `1e9+7` ou `998244353` (ambos primos). O motivo: a resposta real pode ter milhares de dígitos (um `long long` guarda no máximo ≈ 9,2·10¹⁸, e 21! já passa disso). Trabalhando « módulo MOD », todo número vira um valor em {0, 1, ..., MOD−1} e nunca estoura.

A ideia que torna isso possível: pode-se reduzir com `% MOD` a cada operação, sem mudar o resultado final.

| Propriedade | Exemplo (MOD = 5) |
|---|---|
| `(a + b) % MOD = (a % MOD + b % MOD) % MOD` | (3 + 4) % 5 = 2 = (3 + 4) % 5 |
| `(a * b) % MOD = (a % MOD) * (b % MOD) % MOD` | 27·9 = 243, 243 % 5 = 3; e (27%5)·(9%5) = 2·4 = 8, 8 % 5 = 3 |
| `(a - b) % MOD = (a % MOD - b % MOD) % MOD` | cuidado com negativos (abaixo) |

### Que tipo de problema resolve

Qualquer enunciado que diga "imprima a resposta módulo 10⁹+7": contagens (combinatória, DP), produtos e somas enormes, hashes.

### Como programar

```cpp
const ll MOD = 1e9 + 7;

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD - b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }
```

### Armadilhas (as mais comuns nas provas)

- **Negativos.** Em C++, `-3 % 5` vale `-3`, não `2`. Por isso a subtração soma MOD antes do último `%`.
- **Overflow no produto.** Dois valores menores que MOD multiplicados dão no máximo ≈ 10¹⁸, que cabe em `long long`, mas não em `int`. Use sempre `ll`.
- **Reduza a cada passo.** `a * b * c % MOD` estoura. Escreva `a * b % MOD * c % MOD`.
- **Divisão comum não funciona:** `(a / b) % MOD` é errado. Veja o inverso modular em 5.3.

### Exemplo completo

**Problema.** São dados N inteiros (cada um até 10¹⁸). Imprima, módulo 10⁹+7, a soma, o produto e a soma menos o produto.

| Entrada | Saída |
|---|---|
| `3`<br>`5 10 7` | `22 350 999999679` |

(22 − 350 = −328, e −328 mod (10⁹+7) = 999999679.)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod_add(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD - b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll soma = 0, prod = 1;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        soma = mod_add(soma, x);
        prod = mod_mul(prod, x);
    }
    cout << soma << " " << prod << " " << mod_sub(soma, prod) << "\n";
}
```

### 5.2 Exponenciação rápida (fast exponentiation)

*(Nos slides ela vem depois da divisão, mas precisamos dela para programar o inverso, então aparece antes aqui.)*

**Lógica.** Calcular aᵇ multiplicando b vezes é O(b). Com b até 10¹⁸, impossível. O truque usa a representação binária de b e a regra xᵐ⁺ⁿ = xᵐ · xⁿ.

Exemplo: b = 14 = 8 + 4 + 2 (binário 1110), logo 5¹⁴ = 5⁸ · 5⁴ · 5². E as potências 5¹, 5², 5⁴, 5⁸ saem elevando ao quadrado repetidamente. Como b tem log b bits, são O(log b) multiplicações.

Rastreio do código iterativo com a = 5, b = 14:

| b (binário) | b & 1? | ret | a depois de elevar ao quadrado |
|---|---|---|---|
| 1110 | 0 (não multiplica) | 1 | 5² = 25 |
| 0111 | 1 | 25 | 5⁴ = 625 |
| 0011 | 1 | 25 · 625 = 15625 | 5⁸ = 390625 |
| 0001 | 1 | 15625 · 390625 = 6103515625 = 5¹⁴ | (não importa mais) |

Esta é a mesma mecânica de bits que você usou nos bitmasks: `b & 1` testa o bit mais baixo e `b >>= 1` descarta esse bit.

**Que tipo de problema resolve:** calcular aᵇ mod M com b enorme; inverso modular; contar 2ⁿ subconjuntos; e, no tópico 8, elevar matrizes.

**Como programar:**

```cpp
ll fexp(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a);   // bit aceso: multiplica pela potência atual
        a = mod_mul(a, a);                  // a vira a^2, a^4, a^8, ...
        b >>= 1;
    }
    return ret;
}
```

Existe também a versão recursiva, direto da recorrência do slide (aⁿ = (a^(n/2))², e vezes `a` se n for ímpar):

```cpp
ll fexp(ll a, ll b) {
    if (b == 0) return 1;
    ll h = fexp(a, b / 2);
    h = mod_mul(h, h);
    if (b & 1) h = mod_mul(h, a);
    return h;
}
```

> **Armadilha importante** (slide "Exponenciação"): o expoente **não** se reduz módulo MOD assim como a base. Por exemplo, 5¹⁰ mod 3 = 1, mas 2¹ mod 3 = 2. Reduza a base, nunca o expoente.

**Exemplo completo.** Q consultas `a b`. Imprima aᵇ mod 10⁹+7 (com 0⁰ = 1).

| Entrada | Saída |
|---|---|
| `3`<br>`3 4`<br>`2 8`<br>`123 123` | `81`<br>`256`<br>`921450052` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

ll fexp(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;
        cout << fexp(a, b) << "\n";
    }
}
```

### 5.3 Divisão modular (inverso)

**Lógica.** Nos inteiros, a / b = a · b⁻¹, onde b · b⁻¹ = 1. Em aritmética modular, o inverso de b é o número x tal que `b * x % MOD == 1`. Então dividir vira multiplicar pelo inverso.

Quando MOD = P é primo, o **Pequeno Teorema de Fermat** diz que a^(P−1) ≡ 1 (mod P). Dividindo os dois lados por a, a^(P−2) ≡ a⁻¹ (mod P). Ou seja:

> o inverso de b é `fexp(b, MOD - 2)`

**Por que o slide fala de Lema de Euclides e coprimos.** Se P é primo e divide um produto, ele divide pelo menos um dos fatores (Lema de Euclides). Na prática: em aritmética modular só é permitido cancelar um fator `a` em `a·x ≡ a·y` (concluindo `x ≡ y`) quando `gcd(a, P) = 1`. Contra-exemplo, módulo 6: 2·1 ≡ 2·4 (ambos dão 2), mas 1 ≢ 4. Consequência prática: b não pode ser múltiplo de MOD, senão o inverso não existe.

**Como programar:**

```cpp
ll inv(ll b)           { return fexp(b, MOD - 2); }   // só se MOD for primo
ll mod_div(ll a, ll b) { return mod_mul(a, inv(b)); }
```

Se o módulo não for primo, o inverso exige o Algoritmo de Euclides Estendido, que vai além dos slides desta aula.

**Exemplo completo.** Q consultas `a b`. Imprima a / b mod 10⁹+7.

| Entrada | Saída |
|---|---|
| `3`<br>`1 2`<br>`6 3`<br>`10 4` | `500000004`<br>`2`<br>`500000006` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

ll fexp(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ret;
}

ll inv(ll b) { return fexp(b, MOD - 2); }   // Fermat: só vale com MOD primo

ll mod_div(ll a, ll b) { return mod_mul(a, inv(b)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        cout << mod_div(a, b) << "\n";
    }
}
```

---

## 6. Combinatória modular

### Lógica

Contagem explode rápido: C(50, 5) > 10¹⁹, 2¹⁰⁰ > 10³⁰ subconjuntos de um array de tamanho 100, 52! maior que o número de átomos do universo. Por isso essas respostas vêm « mod 10⁹+7 ».

A fórmula: C(n, k) = n! / (k! · (n−k)!). Tem divisão, então usamos o inverso modular. A estratégia é pré-processar uma vez:

- `fact[i] = i! mod MOD`, para todo i até MAXN;
- `invFact[i] = (i!)⁻¹ mod MOD`.

Depois, cada consulta C(n, k) é O(1): `fact[n] * invFact[k] * invFact[n-k]`.

O slide calcula `invFact[i] = inv(fact[i])` para cada i, que custa O(MAXN · log MOD), aceitável. Existe uma versão O(MAXN) que usa o fato 1/(i−1)! = i / i!. Calcula-se uma só `fexp` para o último fatorial e desce-se multiplicando por i:

```cpp
invFact[MAXN-1] = fexp(fact[MAXN-1], MOD - 2);
for (int i = MAXN - 1; i >= 1; i--)
    invFact[i-1] = mod_mul(invFact[i], i);
```

### Que tipo de problema resolve

- Escolher k itens de n (grupos, comissões, quantidade de subconjuntos de tamanho k).
- Caminhos em grade só para direita/baixo: C(linhas + colunas, linhas).
- Distribuir n itens iguais em k caixas (estrelas e barras): C(n + k − 1, k − 1).
- Permutações com repetição: n! / (a! · b! · c!).

### Como programar

```cpp
const int MAXN = 1e6 + 5;
ll fact[MAXN], invFact[MAXN];   // globais

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mod_mul(fact[i - 1], i);

    invFact[MAXN - 1] = fexp(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i >= 1; i--)
        invFact[i - 1] = mod_mul(invFact[i], i);
}

ll binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mod_mul(mod_mul(fact[n], invFact[k]), invFact[n - k]);
}
```

**Armadilhas.** MAXN precisa ser maior ou igual ao maior n da entrada. Esse método exige n < MOD (senão algum fatorial vira 0 e não tem inverso). Lembre do `if (k > n) return 0`.

### Exemplo completo

**Problema.** Q consultas `n k` (n ≤ 10⁶). Imprima C(n, k) mod 10⁹+7.

| Entrada | Saída |
|---|---|
| `3`<br>`5 3`<br>`8 1`<br>`9 5` | `10`<br>`8`<br>`126` |

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll fact[MAXN], invFact[MAXN];

ll mod_mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

ll fexp(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ret;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mod_mul(fact[i - 1], i);

    invFact[MAXN - 1] = fexp(fact[MAXN - 1], MOD - 2);   // UMA única fexp
    for (int i = MAXN - 1; i >= 1; i--)
        invFact[i - 1] = mod_mul(invFact[i], i);
}

ll binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mod_mul(mod_mul(fact[n], invFact[k]), invFact[n - k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        cout << binomial(n, k) << "\n";
    }
}
```

---

## 7. Inclusão-Exclusão (Inc-Exc)

### Lógica

Queremos o número de elementos na união de n conjuntos. Somar |A| + |B| + |C| conta duas vezes quem está em dois conjuntos e três vezes quem está nos três. A correção, com sinais alternando:

$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

A regra geral: some as interseções de 1 conjunto, subtraia as de 2, some as de 3, e assim por diante. **Interseção de tamanho ímpar soma, de tamanho par subtrai.** (Por que funciona: um elemento que está em exatamente m conjuntos é contado C(m,1) − C(m,2) + C(m,3) − ... = 1 vez.)

**Exemplo do slide.** Quantos números de 1 a 10 são divisíveis por 2 ou por 5?

- M₂ = múltiplos de 2 em [1, 10] → 10/2 = 5.
- M₅ = múltiplos de 5 → 10/5 = 2.
- Somar dá 7, mas o 10 foi contado duas vezes. Os múltiplos de 2 e 5 são os múltiplos de 10: 10/10 = 1.
- Resposta: 5 + 2 − 1 = 6 (2, 4, 5, 6, 8, 10).

A contagem de múltiplos de x em [1, n] é `n / x` (divisão inteira).

### Que tipo de problema resolve

- "Quantos números em [1, n] são divisíveis por pelo menos um dentre estes?"
- Contar o que tem "pelo menos uma propriedade" (ou, pelo complemento, "nenhuma").
- Com a fatoração do tópico 3: quantos números de [1, n] são coprimos com m? Resposta: n menos a união dos múltiplos dos primos de m.

### Como programar

O truque de implementação: enumerar todos os subconjuntos não vazios com bitmask, exatamente como você fez em `homework2/G.cpp`, `M.cpp` e `O.cpp`:

1. Para cada `mask` de 1 a 2ᵏ − 1, calcule o produto dos números escolhidos. Como os números são primos distintos, o MMC deles é o produto, e `n / produto` conta os múltiplos comuns. (Se não forem primos, use o MMC do tópico 1.)
2. Se `popcount(mask)` é ímpar, some; se é par, subtraia.

**Armadilha de overflow.** Com n até 10¹⁸ e até 20 primos, o produto passa de `long long` facilmente. Mas se o produto já é maior que n, `n / produto = 0` e o termo não contribui. Então, antes de multiplicar, teste `prod > n / p[i]` (equivale a `prod * p[i] > n` sem estourar) e pule a máscara.

**Complexidade:** O(2ᵏ · k) = cerca de 2·10⁷ para k = 20, tranquilo.

### Exemplo completo

**Problema.** São dados k primos distintos e um inteiro n (n ≤ 10¹⁸, k ≤ 20). Conte quantos dos n primeiros inteiros positivos são divisíveis por pelo menos um dos primos.

| Entrada | Saída |
|---|---|
| `20 2`<br>`2 5` | `12` |

Conferência: {2} soma 10, {5} soma 4, {2, 5} (produto 10) subtrai 2, dando 12.

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; int k;
    cin >> n >> k;
    vector<ll> p(k);
    for (auto &x : p) cin >> x;

    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll prod = 1;
        bool estourou = false;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                if (prod > n / p[i]) { estourou = true; break; }   // prod*p[i] > n
                prod *= p[i];
            }
        }
        if (estourou) continue;          // n/prod seria 0

        ll cnt = n / prod;
        if (__builtin_popcount(mask) % 2 == 1) ans += cnt;   // tamanho ímpar: soma
        else                                   ans -= cnt;   // tamanho par: subtrai
    }
    cout << ans << "\n";
}
```

---

## 8. Recorrência linear e exponenciação de matrizes

### Lógica

- **Combinação linear:** soma de termos em que cada um é um elemento multiplicado por uma constante. Exemplo: x = 3y − 5z. Fibonacci, F(n) = F(n−1) + F(n−2), é F(n) como combinação linear de F(n−1) e F(n−2).
- **Recorrência linear:** sequência em que cada termo é combinação linear dos anteriores.

O problema: se pedem F(n) com n até 10¹⁸, a DP em O(n) não roda. A saída: a transição de um termo para o próximo é uma multiplicação de matriz por vetor, e aplicar a transição n vezes é elevar a matriz a n. Isso a exponenciação rápida do tópico 5.2 faz em O(log n) multiplicações de matrizes. A mudança é só que o "1" neutro vira a matriz identidade.

Para Fibonacci (slide):

$$
\begin{pmatrix} F(n) \\ F(n-1) \end{pmatrix}
=
\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}
\cdot
\begin{pmatrix} F(n-1) \\ F(n-2) \end{pmatrix}
$$

Elevando M = [[1,1],[1,0]] a n, obtém-se Mⁿ = [[F(n+1), F(n)], [F(n), F(n−1)]]. Logo F(n) = Mⁿ[0][1].

**Complexidade:** cada multiplicação de matrizes T×T custa O(T³), e são O(log n) delas, total O(T³ · log n).

### Como montar a matriz (a parte que dá trabalho)

Receita:

1. Defina o vetor de estado com tudo de que o próximo termo precisa.
2. Cada linha da matriz diz como obter um componente do novo estado a partir do estado antigo.
3. Constante somada → inclua um componente fixo `1`. Termo x ou x² → inclua componentes que evoluem (x+1 vira x+2, e assim por diante). Termo 2ˣ → componente que dobra a cada passo.

Os exercícios do slide, resolvidos (a linha 1 é sempre "F(x+1) = ..."):

| Recorrência | Estado S(x) | Matriz (linha por linha) |
|---|---|---|
| F(x) = 2F(x−1) + 3F(x−2) | [F(x), F(x−1)] | [2,3] / [1,0] |
| ... + 5F(x−3) + 1 | [F(x), F(x−1), F(x−2), 1] | [2,3,5,1] / [1,0,0,0] / [0,1,0,0] / [0,0,0,1] |
| ... + x | [F(x), F(x−1), x+1, 1] | [2,3,1,0] / [1,0,0,0] / [0,0,1,1] / [0,0,0,1] |
| ... + x² | [F(x), F(x−1), (x+1)², x+1, 1] | [2,3,1,0,0] / [1,0,0,0,0] / [0,0,1,2,1] / [0,0,0,1,1] / [0,0,0,0,1] |
| ... + 2ˣ | [F(x), F(x−1), 2^(x+1)] | [2,3,1] / [1,0,0] / [0,0,2] |

Como ler a linha de (x+1)² na recorrência com x²: (x+2)² = (x+1)² + 2(x+1) + 1, por isso a linha `[0,0,1,2,1]`.

### Que tipo de problema resolve

- N-ésimo termo de Fibonacci ou de qualquer recorrência linear com n gigante.
- Contar maneiras (de preencher um tabuleiro, de formar strings) quando a contagem segue uma recorrência e n vai até 10¹⁸.
- Caminhos de comprimento exato k em um grafo pequeno (matriz de adjacência elevada a k).

### Como programar

Segue o código dos slides. Ajuste a constante `T` para o tamanho do seu estado.

```cpp
const ll MOD = 1e9 + 7;
const int T = 2;                         // tamanho da matriz

struct Matriz {
    ll mat[T][T];
};

Matriz matMul(const Matriz &a, const Matriz &b) {          // O(T^3)
    Matriz ans = {};                     // tudo zerado
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            for (int k = 0; k < T; k++)
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
    return ans;
}

Matriz matPow(Matriz base, ll p) {                         // O(T^3 log p)
    Matriz ans = {};
    for (int i = 0; i < T; i++) ans.mat[i][i] = 1;         // identidade
    while (p) {
        if (p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}
```

**Armadilhas.** Zerar a matriz resultado (`= {}`), pois acumulamos com `+=` e lixo de memória dá resposta errada. Reduzir `% MOD` a cada acumulação. A ordem importa: multiplicação de matrizes não é comutativa.

### Exemplo completo

**Problema.** Dado n (0 ≤ n ≤ 10¹⁸), imprima o n-ésimo número de Fibonacci mod 10⁹+7 (F(0) = 0, F(1) = 1).

| Entrada | Saída |
|---|---|
| `10` | `55` |

Para n = 10¹⁸ a saída é 209783453.

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int T = 2;

struct Matriz {
    ll mat[T][T];
};

Matriz matMul(const Matriz &a, const Matriz &b) {
    Matriz ans = {};
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            for (int k = 0; k < T; k++)
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
    return ans;
}

Matriz matPow(Matriz base, ll p) {
    Matriz ans = {};
    for (int i = 0; i < T; i++) ans.mat[i][i] = 1;
    while (p) {
        if (p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    Matriz M = {};
    M.mat[0][0] = 1; M.mat[0][1] = 1;
    M.mat[1][0] = 1; M.mat[1][1] = 0;

    Matriz R = matPow(M, n);
    cout << R.mat[0][1] << "\n";   // M^n = [[F(n+1), F(n)], [F(n), F(n-1)]]
}
```

### Exemplo completo 2: com termo extra (F(x) = 2F(x−1) + 3F(x−2) + x)

**Problema.** F(0) = F(1) = 1 e F(x) = 2F(x−1) + 3F(x−2) + x. Imprima F(n) mod 10⁹+7. Os valores começam 1, 1, 7, 20, 65, 195, 591, ... (conferidos por força bruta).

Use as mesmas `matMul` e `matPow` acima com `T = 4`. Só muda o `main`: monte a matriz da tabela e aplique M^(n-1) ao estado inicial S(1) = [F(1), F(0), 2, 1].

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    if (n <= 1) { cout << 1 << "\n"; return 0; }

    ll lin[4][4] = {{2, 3, 1, 0},    // F(x+1) = 2F(x) + 3F(x-1) + (x+1)
                    {1, 0, 0, 0},    // novo F(x) = F(x)
                    {0, 0, 1, 1},    // x+2 = (x+1) + 1
                    {0, 0, 0, 1}};   // constante 1
    Matriz M = {};
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++) M.mat[i][j] = lin[i][j];

    Matriz R = matPow(M, n - 1);     // leva S(1) até S(n)
    ll S1[4] = {1, 1, 2, 1};         // S(1) = [F(1), F(0), 2, 1]
    ll ans = 0;
    for (int j = 0; j < T; j++) ans = (ans + R.mat[0][j] * S1[j]) % MOD;
    cout << ans << "\n";
}
```

---

## Resumo final

| Tópico | Quando usar | Função-chave | Complexidade |
|---|---|---|---|
| MDC / MMC | frações, coincidência de ciclos, coprimos | `a / gcd(a,b) * b` | O(log) |
| Divisores | listar/contar/somar divisores de um n | laço `i*i <= n` com par (i, n/i) | O(√n) |
| Fatoração | fórmulas com expoentes dos primos | dividir até √n; resto > 1 é primo | O(√n) |
| Crivo | primos ou divisores de muitos números até ~10⁶ a 10⁷ | `j = i*i; j += i` | O(N log log N) |
| Modular | "resposta mod 1e9+7" | `mod_add`, `mod_sub`, `mod_mul` | O(1) |
| Exp. rápida / inverso | aᵇ mod M; divisão modular | `fexp`, `fexp(b, MOD-2)` | O(log b) |
| Combinatória | C(n, k) mod p | `fact`, `invFact` | O(N) + O(1) |
| Inc-Exc | "pelo menos um", contar união | bitmask + sinal por popcount | O(2ᵏ · k) |
| Recorrência linear | n até 10¹⁸ | `matPow` | O(T³ log n) |

## Checklist antes de enviar

- [ ] Tudo que pode passar de 2·10⁹ está em `long long`? (inclusive `i * i`, produtos e o `1LL *` nos laços)
- [ ] Subtração modular soma MOD antes do último `%`?
- [ ] Reduzi `% MOD` depois de cada multiplicação?
- [ ] O expoente ficou intacto (só a base é reduzida)?
- [ ] Divisão modular usa inverso, e o módulo é primo?
- [ ] Arrays grandes (crivo, `fact`) são globais?
- [ ] MMC feito como `a / gcd * b`?
- [ ] Inc-Exc corta o produto quando passa de n?

## Para praticar

Sugestões de problemas do CSES que casam com cada tópico (procure pelo nome): **Counting Divisors**, **Common Divisors**, **Exponentiation**, **Exponentiation II** (desafio: usa a observação de que o expoente se reduz módulo MOD−1 por Fermat), **Binomial Coefficients**, **Creating Strings II**, **Distributing Apples**, **Prime Multiples** (exatamente o exemplo da Inc-Exc) e **Fibonacci Numbers**.

---

*Fim da Aula 7.*
