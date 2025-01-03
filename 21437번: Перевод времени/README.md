# 21437번: Перевод времени

## 문제 설명


<p>Как известно, с целью экономии электроэнергии многие страны используют переход на так называемое <em>летнее время</em>. Перевод времени осуществляется два раза в год --- весной и осенью. Весной осуществляется переход на летнее время: часы переводятся на один час вперед. Осенью летнее время отменяется и часы переводятся на один час назад.</p>

<p>Перевод времени осуществляется ночью. При переходе на летнее время через минуту после 01:59 сразу наступает 03:00. При отмене летнего времени час с 02:00 по 02:59 повторяется два раза. А именно, в день перевода, когда первый раз после 02:59 должно стать 03:00, вместо этого снова становится 02:00.&nbsp;</p>

<p>Как одному из разработчиков новой операционной системы &lt;&lt;<em>Mocrosoft Widows 2006</em>&gt;&gt;, вам поручено написать фрагмент ядра операционной системы, который будет осуществлять автоматический перевод системных часов на летнее время и обратно.</p>

<p>По заданным начальному моменту и информации о переводе в текущие и следующие сутки, ваша программа должна вывести показания часов в течение заданного количества минут.&nbsp;</p>



## 입력 형식


<p>Первая строка входного файла содержит целое число $m$ --- количество минут, которое прошло от начала текущих суток, до первого момента времени, который следует вывести. Гарантируется, что оно неотрицательно и строго меньше числа минут в текущих сутках.</p>

<p>На второй строке находятся два целых числа $d_1$ и $d_2$, которые указывают, какой перевод времени осуществляется в текущие и в следующие сутки. Значение $1$ означает, что осуществляется переход на летнее время, $-1$ означает, что осуществляется отмена летнего времени, а $0$ означает, что перевода времени не осуществляется.</p>

<p>На третьей строке записано число $k$ --- количество отсчетов времени, которое ваша программа должна вывести ($1 \le k \le 600$).&nbsp;</p>



## 출력 형식


<p>Выходной файл должен состоять из $k$ строк, $i$-я из которых должна содержать показания часов через $(i-1)$ минут после начального момента времени. Выводите время в формате &lt;&lt;<code>hh:mm</code>&gt;&gt;.</p>



## 예제

### 예제 입력 1

```
118
1 0
4

```

### 예제 출력 1

```
01:58
01:59
03:00
03:01

```
          

### 예제 입력 2

```
190
-1 1
1

```

### 예제 출력 2

```
02:10

```
          

### 예제 입력 3

```
0
-1 0
3

```

### 예제 출력 3

```
00:00
00:01
00:02

```
          

### 예제 입력 4

```
1438
0 1
4

```

### 예제 출력 4

```
23:58
23:59
00:00
00:01

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
  