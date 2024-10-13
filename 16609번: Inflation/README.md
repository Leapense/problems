# 16609번: Inflation

## 문제 설명


<p>For NWERC 2018, the organisers have done something rather special with the balloons. Instead of buying balloons of equal size, they bought one balloon of every integer size from 1 up to n. A balloon of size s has a capacity of s decilitres.</p>

<p>To avoid inflating the balloons by hand, the organisers also bought n helium gas canisters. Each canister can only be used to inflate one balloon, and must be emptied completely into that balloon (it is not possible to disconnect a canister from a balloon before the canister has been fully used).</p>

<p>Unfortunately the gas canisters were bought at a garage sale, and may contain differing amounts of helium. Some may even be empty! To make the best of this challenging situation, the canisters will have to be paired with the balloons smartly.</p>

<p>The organisers want to assign all of the gas canisters to separate balloons, such that the balloon that is inflated the least (relative to its capacity) still contains the maximum possible fraction of helium inside. What is the maximum such (minimum) fraction that is possible?</p>

<p>Balloons filled beyond their capacity will explode. Explosions are upsetting and must be avoided.</p>



## 입력 형식


<p>The input consists of:</p>

<ul>
<li>One line with the integer n (1 ≤ n ≤ 2 · 10<sup>5</sup>), the number of balloons and gas canisters.</li>
<li>One line with n integers c<sub>1</sub>, . . . , c<sub>n</sub> (0 ≤ c<sub>i</sub> ≤ n for each i), the amounts of helium in the gas canisters, in decilitres.</li>
</ul>



## 출력 형식


<p>If it is possible to fill all the balloons without any exploding, output the maximum fraction f such that every balloon can be filled to at least f of its capacity. Otherwise, output “impossible”.</p>

<p>Your answer should have an absolute or relative error of at most 10<sup>−6</sup>.</p>



## 예제

### 예제 입력 1

```
6
6 1 3 2 2 3

```

### 예제 출력 1

```
0.6

```
          

### 예제 입력 2

```
2
2 2

```

### 예제 출력 2

```
impossible

```
          

### 예제 입력 3

```
5
4 0 2 1 2

```

### 예제 출력 3

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
  