# 28844번: Ослабление флота

## 문제 설명


<p>Кэрол Дэнверс, известная как Капитан Марвел противодействует флоту Скруллов. Каждый из кораблей Скруллов имеет определенную мощность, выраженную натуральным числом.</p>

<p>Кэрол считает, что настолько сильна, что может не только вывести из строя флот, но и немного развлечься. Внимательно изучив мощность корабля, она решила, что будет выводить их из строя в следующем порядке: каждый раз Кэрол будет атаковать тот корабль из неатакованных ранее, мощность которого является медианой мощностей оставшихся кораблей.</p>

<p>Медиану ряда чисел Кэрол вычисляет следующим образом:</p>

<ul>
<li>Если количество чисел в ряду нечетно, то медиана --- число, стоящее посередине   упорядоченного по возрастанию данного ряда. </li>
<li>Если количество чисел в ряду чётно, то медианой ряда является:
<ul>
<li>Меньшее из двух стоящих посередине чисел упорядоченного по возрастанию данного ряда, если два средних различны.</li>
<li>Любое из двух стоящих посередине чисел упорядоченного по возрастанию данного ряда, если два средних равны.</li>
</ul>
</li>
</ul>

<p>Помогите Капитану Марвел посчитать порядок, в котором нужно атаковать корабли.</p>



## 입력 형식


<p>В первой строке дано одно натуральное число $n$ --- число кораблей во флоте Скруллов ($1 \le n \le 10^5$).</p>

<p>Во второй строке содержатся $n$ натуральных чисел $a_i$ --- мощность $i$-го корабля ($1 \le a_i \le 10^9$).</p>



## 출력 형식


<p>Выведите $n$ чисел --- мощности кораблей в том порядке, в котором Кэрол будет их атаковать.</p>



## 예제

### 예제 입력 1

```
3
8 3 19

```

### 예제 출력 1

```
8 3 19

```
          

### 예제 입력 2

```
4
4 2 2 1

```

### 예제 출력 2

```
2 2 1 4

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
  