# 20868번: Fluortanten

## 문제 설명


<p>Björn och $n-1$ andra personer står i kön för att träffa fluortanten. Olika personer tycker att det är olika läskigt att träffa fluortanten. Personerna är numrerade från $1$ till $n$, och person $i$ står på plats $i$ i kön. Person $i$ har också ett värde $a_i$, som visar hur ogärna personen vill träffa fluortanten. Person $i$:s glädje över sin plats i kön är $i \cdot a_i$. Vissa personer kan ha negativ $a_i$, vilket betyder att de egentligen vill träffa fluortanten och sålunda är ledsna över att få vänta.</p>

<p>Björn är den enda personen som är helt likgiltig inför att träffa fluortanten, det vill säga han är den enda personen som har $a_i = 0$. Dessutom är han väldigt godhjärtad, så han bestämmer sig för att lämna kön och sedan gå in i kön igen på någon plats så att den totala glädjen hos alla i kön blir så stor som möjligt. Skriv ett program som givet värdena $a_i$ för alla personer räknar ut den maximala summan av glädjen i kön om Björn ställer sig på en optimal plats.</p>



## 입력 형식


<p>Den första raden innehåller ett heltal $n$, antalet personer i kön. På nästa rad följer $n$ heltal, där det $i$:te talet är $a_i$. $1 \leq n \leq 10^6$, $-1000 \leq a_i \leq 1000$.</p>



## 출력 형식


<p>Skriv ut en rad med ett heltal: den maximala totala glädjen i kön.</p>



## 예제

### 예제 입력 1

```
3
1 0 -2

```

### 예제 출력 1

```
-3

```
          

### 예제 입력 2

```
5
0 -8 1 1 5

```

### 예제 출력 2

```
24

```
          

### 예제 입력 3

```
7
2 -4 5 -3 0 -1 2

```

### 예제 출력 3

```
7

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
  