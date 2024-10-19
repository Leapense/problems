# 23595번: Quadratic equation

## 문제 설명


<p>Ted has just been accepted to the university, afer passing the exams successfully. During his preparation for the exams, Ted solved several thousands of similar problems. For instance, he solved tons of quadratic equations, again and again and again. He's decided to make up his own problems, because after the exams, he's free to do anything! Ted is wondering - why does one always have to find the roots of the equation, and not vice versa - to find the equation for a root? First, he decided to experiment with what has been his favorite type of equations since the ninth grade --- the quadratic equations. But he discovered a new problem here -- he is not knowledgeable enough, because this problem is not typical.</p>

<p>Help Ted solve this new task!</p>



## 입력 형식


<p>The first line of the input file contains an integer $T$ --- the number of test cases ($1 \le T \le 100$). It is followed by $T$ lines -- one per each case.</p>

<p>Each line contains one non-zero integer $Y$ --- the root of a quadratic equation ($1 \le |Y| \le 10^6$).</p>



## 출력 형식


<p>The output file must contain $T$ lines, and the $i$-th line must have the answer to the $i$-th test case. The answer must contain three space-separated <strong>integers</strong> $A_i$, $B_i$, $C_i$, such that the $i$-th input number is a root of the quadratic equation $A_iX^2+B_iX+C_i = 0$.&nbsp;</p>

<p>All coefficients must be <strong>non-zero</strong> and <strong>not greater than $10^6$ in absolute value</strong>. If the required equation is not unique, print the coefficients of any one of them. It is guaranteed that at least one equation exists in each case.</p>



## 예제

### 예제 입력 1

```
2
1
-2

```

### 예제 출력 1

```
2 -3 1
3 2 -8

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
  