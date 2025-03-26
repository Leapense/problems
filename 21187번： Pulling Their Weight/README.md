# 21187번: Pulling Their Weight - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21187)


<p>To save money, Santa Claus has started hiring other animals besides reindeer to pull his sleigh via short term 'gig' contracts. &nbsp;As a result, the actual animals that show up to pull his sleigh for any given trip can vary greatly in size.</p>

<p>Last week he had $2$ buffalo, $37$ voles and a schnauzer. Unfortunately, both buffalo were hitched on the left side and the entire sleigh flipped over in mid-flight due to the weight imbalance.</p>

<p>To prevent such accidents in the future, Santa needs to divide the animals for a given trip into two groups such that the sum of the weights of all animals in one group equals the sum of the weights of all animals in the other. To make the hitching process efficient, Santa is seeking an integer target weight $t$ such that all animals that are lighter than $t$ go in one group and those heavier than $t$ go into the other. If there are multiple such $t$, he wants the smallest one. There's one small wrinkle: what should be done if there some animals have weight exactly equal to $t$? Santa solves the problem this way: if there are an even number of such animals, he divides them equally among the two groups (thus distributing the weight evenly). But if there are an odd number of such animals, then one of those animals is sent to work with the elves to make toys (it is not put in either group), and the remaining (now an even number) are divided evenly among the two groups.</p>



## 입력


<p>Input describes a list of animals' weights. The first line contains an integer $m$ ($2 \le m \le 10^5$), indicating the number of animals. The next $m$ lines each have a positive integer. These are the weights of the animals (in ounces). Animals weighing more than $20\,000$ ounces are too big to pull the sleigh so no given weight will exceed this maximum.</p>



## 출력


<p>Output the smallest integer target weight $t$, as described above. It's guaranteed that it is possible to find such an integer.</p>



## 소스코드

[소스코드 보기](Pulling%20Their%20Weight.py)