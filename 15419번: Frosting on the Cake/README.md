# 15419번: Frosting on the Cake

## 문제 설명


<p>Iskander the Baker is decorating a huge cake, covering the rectangular surface of the cake with frosting. For this purpose, he mixes frosting sugar with lemon juice and food coloring, in order to produce three kinds of frosting: yellow, pink, and white. These colors are identified by the numbers 0 for yellow, 1 for pink, and 2 for white.</p>

<p>To obtain a nice pattern, he partitions the cake surface into vertical stripes of width A<sub>1</sub>, A<sub>2</sub>, . . . , A<sub>n</sub> centimeters, and horizontal stripes of height B<sub>1</sub>, B<sub>2</sub>, . . . , B<sub>n</sub> centimeters, for some positive integer n. These stripes split the cake surface into n × n rectangles. The intersection of vertical stripe i and horizontal stripe j has color number (i + j) mod 3 for all 1 ≤ i, j ≤ n. To prepare the frosting, Iskander wants to know the total surface in square centimeters to be colored for each of the three colors, and asks for your help.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15419/1.png" style="height:314px; width:311px"></p>



## 입력 형식


<p>The input consists of the following integers:</p>

<ul>
<li>on the first line: the integer n,</li>
<li>on the second line: the values of A<sub>1</sub>, . . . , A<sub>n</sub>, n integers separated with single spaces,</li>
<li>on the third line: the values of B<sub>1</sub>, . . . , B<sub>n</sub>, n integers separated with single spaces.</li>
</ul>

<p>Limits</p>

<p>The input satisfies 3 ≤ n ≤ 100 000 and 1 ≤ A<sub>1</sub>, . . . , A<sub>n</sub>, B<sub>1</sub>, . . . , B<sub>n</sub> ≤ 10 000.</p>



## 출력 형식


<p>The output should consist of three integers separated with single spaces, representing the total area for each color 0, 1, and 2.</p>



## 예제

### 예제 입력 1

```
3
1 1 1
1 1 1

```

### 예제 출력 1

```
3 3 3

```
          

### 예제 입력 2

```
7
6 2 4 5 1 1 4
2 5 1 4 2 3 4

```

### 예제 출력 2

```
155 131 197

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
  