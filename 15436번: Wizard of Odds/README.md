# 15436번: Wizard of Odds

## 문제 설명


<p>You have just completed a brave journey to see&nbsp;<em>The Wizard of Odds</em>, who agrees to grant you any wish, so long as you can complete the following puzzle:</p>

<p>The Wizard starts by telling you two integers:&nbsp;<em>N</em>&nbsp;and&nbsp;<em>K</em>. He then secretly selects a number from 1 to&nbsp;<em>N</em>&nbsp;(inclusive), and does not tell you this number.</p>

<p>Your goal is to correctly guess the secret number. Before guessing, you are allowed to ask&nbsp;<em>K</em>&nbsp;"true/false" questions about the number, for example,&nbsp;<em>"Is the number even?"</em>&nbsp;or&nbsp;<em>"Is the number between 7 and 10?"</em>, or&nbsp;<em>"Is the number 17 or 22?"</em>, or&nbsp;<em>"Is the number prime?"</em>. And the Wizard will answer with "true" or "false" to each question. The Wizard will always answer honestly. After answering the&nbsp;<em>K</em>&nbsp;questions, you must guess the number. If you win (guess the number correctly), you will be granted your wish; but if the Wizard wins (you guess incorrectly), you will be turned into a flying monkey.</p>

<p>(Formally, you can think of a "question" as a function from&nbsp;<em>{1, 2, ..., N}</em>&nbsp;to&nbsp;<em>{true, false}</em>, and the Wizard will answer by telling you whether the value of the function is&nbsp;<em>true</em>&nbsp;or&nbsp;<em>false</em>&nbsp;for his secret number.)</p>

<p>Assuming that you have been told&nbsp;<em>N</em>&nbsp;and&nbsp;<em>K</em>, can you always exactly determine the Wizard's secret number (and guarantee that you win) using only&nbsp;<em>K</em>&nbsp;questions?</p>



## 입력 형식


<p>The input consists of a single line containing two integers&nbsp;<em>N</em>&nbsp;and&nbsp;<em>K</em>&nbsp;(<em>2 ≤ N ≤ 10<sup>101</sup></em>,&nbsp;<em>0 ≤ K ≤ N</em>), separated by a single space.</p>

<p><em>Note: These inputs might NOT fit into a 64-bit integer.</em></p>



## 출력 형식


<p>Output&nbsp;<code>"Your wish is granted!"</code>&nbsp;(without the quotes) if it is possible for you to guarantee that you win the game (regardless of the number the Wizard picks). Otherwise, print&nbsp;<code>"You will become a flying monkey!"</code>&nbsp;(without the quotes) if it is not possible.</p>



## 예제

### 예제 입력 1

```
8 3

```

### 예제 출력 1

```
Your wish is granted!

```
          

### 예제 입력 2

```
1234567890987654321 2

```

### 예제 출력 2

```
You will become a flying monkey!

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
  