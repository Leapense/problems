# 20732번: Proofs

## 문제 설명


<p>You are teaching discrete math. You have done your best to teach your students about axioms and inference rules, proofs and theorems. Sometimes the students write beautiful proofs that Fermat would be proud of but sometimes, also like Fermat, their proofs are not quite right. You are getting a little tired of hunting through some of these so-called "proofs" for the magic tricks that let them prove $1 = 2$ and had the great idea to write a computer program to speed things up!</p>

<p>Because this is the first class in proof-based mathematics, you have started your students off with a simple proof system. All proof lines consist of a list of assumptions, an arrow, and a conclusion. If there are no assumptions, the conclusion is an axiom. A line of the proof is valid if and only if all assumptions were conclusions of previous lines. Sometimes the students derive a conclusion more than once just to be extra sure it is true, and that is perfectly all right!</p>



## 입력 형식


<p>The first line of input consists of an integer $1 \le n \le 400\,000$, the number of lines in the "proof". Then follow the $n$ lines of the "proof". Each line has $0 \le a \le 5$ assumptions, followed by an arrow (the string "<code>-&gt;</code>"), followed by one conclusion. All assumptions and conclusions consist of $1 \le c \le 5$ uppercase alphabetic characters. The assumptions, arrow, and conclusion are all separated by single spaces.</p>



## 출력 형식


<p>If every line is correct output "<code>correct</code>". &nbsp;Otherwise, output the number of the first line with an error (line numbers start at $1$).</p>



## 예제

### 예제 입력 1

```
3
-&gt; ALICE
-&gt; BOB
ALICE BOB -&gt; CARL

```

### 예제 출력 1

```
correct

```
          

### 예제 입력 2

```
1
A -&gt; B

```

### 예제 출력 2

```
1

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
  