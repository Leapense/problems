# 13693번: Cubos Coloridos

## 문제 설명


<p>Crianças adoram brincar com pequenos cubos. Elas passam horas criando ‘casas’, ‘prédios’, etc. O irmãozinho de Tomaz acabou de ganhar um conjunto de blocos coloridos no seu aniversário. Cada face de cada cubo é de uma cor.</p>

<p>Como Tomaz é uma criança muito analítica, ele decidiu descobrir quantos “tipos” diferentes de cubos o seu irmãozinho ganhou. Você pode ajuda-lo? Dois cubos são considerados do mesmo tipo se for possível rotacionar um deles de forma que as cores nas faces respectivas dos dois blocos sejam iguais.</p>



## 입력 형식


<p>A entrada contém vários casos de teste. A primeira linha do caso de teste contém um inteiro N especificando o número de cubos no conjunto (1 ≤ N ≤ 1000). As próximas 3 x N linhas descrevem os cubos do conjunto. Na descrição as cores serão identificadas pelos números de 0 a 9. A descrição de cada cubo será dada em três linhas mostrando as cores das seis faces do cubo “aberto”, no formato dado no exemplo abaixo. No exemplo abaixo, as faces do cubo tem cores de 1 a 6, a face com cor 1 está no lado oposto da face com a cor 3, e a face com cor 2 é vizinha das faces 1, 3, 4 e 6, e está no lado oposto da face com cor 5.</p>

<p>1<br>
2 4 5 6<br>
3</p>

<p>O final da entrada é indicado por N = 0.</p>



## 출력 형식


<p>Para cada caso de teste seu programa deve imprimir uma linha contendo um único inteiro, correspondente ao numero de tipos de cubos no conjunto dado.</p>



## 예제

### 예제 입력 1

```
3
0
0 7 2 3
1
0
1 2 3 7
0
3
0 0 2 1
7
2
1
1 1 1 1
1
2
2 2 2 2
2
0

```

### 예제 출력 1

```
2
2

```
          




## 추가 테스트 케이스

추가로 테스트 하고 싶은 케이스를 적고 정리해 보세요.

### 추가 입력 1

```
<입력값>
```

### 추가 출력 1

```
<출력값>
```

### 추가 입력 2

```
<입력값>
```

### 추가 출력 2

```
<출력값>
```
  