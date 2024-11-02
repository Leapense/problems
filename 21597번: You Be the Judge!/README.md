# 21597번: You Be the Judge!

## 문제 설명


<p>Congratulations! You are now the judge of a programming contest! You’ve been put in charge of a problem, and since your problem may not have unique correct output, you’ve got to write an output checker for it.</p>

<p>Your problem is called “Good as Goldbach”, and it’s based on the Goldbach Conjecture (that any positive even integer greater than 3 can be expressed as the sum of two primes). A solving program’s output should have three numbers separated by whitespace: First, a positive even integer greater than 3 and less than or equal to 10<sup>9</sup>, and then two (positive) prime numbers which sum to the even number.</p>

<p>You must write a checker for this problem. Your checker should take the output of a contestant’s program, and determine whether or not it could possibly be correct. That is, determine if the contestant’s output consists only of three tokens separated by whitespace, the first of which is a positive even integer greater than 3 and less than or equal to 10<sup>9</sup>, and the next two are positive prime integers which sum to the first. The integers should be in base ten, with no signs or leading zeros. Any amount of white space anywhere except within an integer, including blank lines, is OK. Any other output, extra characters, missing numbers, etc. should be considered incorrect.</p>



## 입력 형식


<p>The input will consist of from 0 to 1,000 lines. Each line consists of from 0 to 100 printable ASCII characters (with codes 32 through 126), or tabs.</p>



## 출력 형식


<p>Output a single integer, which is 1 if the input could possibly be a correct output for the “Good as Goldbach” problem, or 0 if the input could not possibly be a correct output for the “Good as Goldbach” problem.</p>



## 예제

### 예제 입력 1

```
10 3 7

```

### 예제 출력 1

```
1

```
          

### 예제 입력 2

```
10   3   7

```

### 예제 출력 2

```
1

```
          

### 예제 입력 3

```
314
159 265
358

```

### 예제 출력 3

```
0

```
          

### 예제 입력 4

```
22 19 3

```

### 예제 출력 4

```
1

```
          

### 예제 입력 5

```

   60
  
  29
  
      31
	  
	  
	  
	  

```

### 예제 출력 5

```
1

```
          

### 예제 입력 6

```
fred!
sam!
george!

```

### 예제 출력 6

```
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
  