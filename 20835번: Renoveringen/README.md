# 20835번: Renoveringen

## 문제 설명


<p>Johanna håller på att renovera hemma i sin lägenhet. Eftersom Johanna inte gillar att lämna saker åt slumpen har hon planerat in i detalj precis hur många spikar hon behöver under renoveringen. Totalt sett behöver hon $N$ spikar med längderna $x_1, x_2, \dots, x_N$. I hennes spiklåda har hon $M$ spikar av längderna $y_1, y_2, \dots, y_M$.</p>

<p>Om Johanna behöver en spik med längd $x_i$ kan hon använda en spik med längd $y_j$ om $x_i \le y_j$ eftersom hon kan kapa av den längre spiken tills den är precis så lång som behövs. Däremot kan hon inte kombinera två korta spikar till en längre spik, eller kapa en spik flera gånger (den har ju bara ett spikhuvud).</p>

<p>Innan Johanna ska börja med renoveringen vill hon veta:</p>

<ul>
<li>hur många spikar hon behöver köpa, och</li>
<li>vilka längder spikarna hon behöver köpa ska ha.</li>
</ul>

<p>Hon vill köpa så få spikar som möjligt, och vill dessutom köpa spikar av så kort total längd som möjligt.</p>



## 입력 형식


<p>På den första raden står två heltal $1 \le N \le 15$ och $1 \le M \le 15$ -- antalet spikar Johanna behöver och antalet spikar Johanna har. På den andra raden står $N$ heltal $1 \le x_1, x_2, \dots, x_N \le 100$, längderna på de spikar Johanna behöver. På den tredje raden står $M$ heltal $1 \le y_1, y_2, \dots, y_M \le 100$, längderna på de spikar Johanna har.</p>



## 출력 형식


<p>Programmet ska först skriva ut ett heltal: det minsta antalet spikar Johanna behöver köpa. På nästa rad ska programmet skriva ut längderna på spikarna Johanna ska köpa, i stigande ordning.</p>



## 예제

### 예제 입력 1

```
6 3
64 13 45 28 82 77
45 82 64

```

### 예제 출력 1

```
3
13 28 77

```
          

### 예제 입력 2

```
3 2
11 50 45
45 100

```

### 예제 출력 2

```
1
11

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
  