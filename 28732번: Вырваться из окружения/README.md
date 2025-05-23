# 28732번: Вырваться из окружения

## 문제 설명


<p>Преследуя Джокера, полиция загнала его в квадратную комнату, которую можно представить в виде квадратного клетчатого поля со стороной $n$. Пронумеруем строки от $1$ до $n$ сверху вниз, а столбцы от $1$ до $n$ слева направо. Клетка $(x, y)$ находится на пересечении строки номер $x$ и столбца номер $y$. Джокер находится в клетке $(a, b)$. Для поимки опасного преступника полицией Готэма был разработан особый Манхэттенский план: полицейские должны занять все клетки внутри комнаты, манхэттенское расстояние от которых до клетки с Джокером равно $d$. Манхэттенским расстоянием между двумя клетками называется сумма модулей разностей их координат, то есть манхэттенское расстояние между клетками $(x_1, y_1)$ и $(x_2, y_2)$ равно $|x_1 - x_2| + |y_1 - y_2|$. Помогите полиции посчитать, какое количество клеток потребуется занять сотрудникам полиции.</p>



## 입력 형식


<p>В единственной строке даны четыре целых числа $n$, $a$, $b$ и $d$ ($1 \le a, b \le n \le 10^{18}$; $1 \le d \le 10^{18}$).</p>



## 출력 형식


<p>Выведите одно число --- количество клеток, которые потребуется занять полицейским.</p>



## 예제

### 예제 입력 1

```
5 3 3 2

```

### 예제 출력 1

```
8

```
          

### 예제 입력 2

```
5 2 3 4

```

### 예제 출력 2

```
4

```
          

### 예제 입력 3

```
1000000000000000000 123456789987654321 987654321123456789 543211234567899876

```

### 예제 출력 3

```
679013703432097408

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
  