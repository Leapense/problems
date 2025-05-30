# 21741번: Ожерелье

## 문제 설명


<p>В витрине ювелирного магазина стоит манекен, на шею которого надето ожерелье. Оно состоит из N колечек, нанизанных на замкнутую нить. Все колечки имеют разные размеры. В зависимости от размера &nbsp;колечки пронумерованы числами от 1 до N, начиная с самого маленького и до самого большого. Колечки можно передвигать вдоль нити и протаскивать &nbsp;одно через другое, но только в том случае, если номера этих колечек отличаются более чем на единицу.&nbsp;</p>

<p>Продавец хочет упорядочить колечки так, чтобы они располагались по возрастанию номеров вдоль нити по часовой стрелке. Снимать ожерелье с манекена нельзя.</p>

<p>Требуется написать программу, которая по заданному начальному расположению колечек находит последовательность протаскиваний колечек одно через другое, приводящую исходное расположение колечек в желаемое.</p>



## 입력 형식


<p>В первой строке входного файла записано число N (2 ≤ N ≤ 50).&nbsp;</p>

<p>Во второй строке через пробел следуют N различных чисел от 1 до N — номера колечек, расположенных вдоль нити по часовой стрелке.&nbsp;</p>



## 출력 형식


<p>Выходной файл должен содержать описание процесса упорядочения.</p>

<p>В каждой строке, кроме последней, должны быть записаны через пробел два числа, указывающие номера колечек, протаскиваемых друг через друга. В последней строке должен стоять ноль.</p>

<p>Количество строк выходного файла не должно превышать 50000.</p>

<p>Если требуемого упорядочения колечек достичь не удается, в выходной файл нужно вывести одно число &nbsp;–1.</p>



## 예제

### 예제 입력 1

```
4
3 2 4 1

```

### 예제 출력 1

```
1 3
2 4
1 4
0

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
  