# 10481번: Ternarian Weights - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10481)


<p>Back in the Hellenic era, there was a small island in the Mediterranean Sea known as Ternaria. It was close to Sparta, but because of its mountainous terrain the Spartans found it difficult to conquer and it remained an independent state until the great earthquake of 729BC when it sank beneath the sea. It had a remarkable civilization and some modern historians think it is the basis for the mythological city of Atlantis. Ternaria is still known for its fundamental contributions to science and mathematics, many of which were adopted by the Greeks and later by the Romans. For example, Ternarians were the first group to use the standard weight of pounds, which we still use today. Ternarian mathematics used base 3 for all its calculations. (Historians speculate that this was out of respect for King Ternary who lost two fingers on each hand while battling the Spartans.)</p>

<p>Ternarian trade scales were a standard for many centuries. They were known for their accuracy and ease of use. They were the first to construct a scale with weighing pans on each side and a fulcrum in the middle. The object to be weighed was placed on the left side of the scale and weights were placed on both sides, until balance was obtained. This sounds strange by modern standards, because typically on modern scales we would only place weights on the right side. However, the modern method requires additional weights. The Ternarian method only requires one weight for each power of three pounds, e.g. one weight of 1 pound, one weight of 3 pounds, one weight of 9 pounds, etc.</p>

<p>Say you are weighing a 2-pound Ternarian hen (known for their succulent white meat). You place the hen on the left side. Place the 3-pound weight on the right side. This is too heavy, so you place the 1-pound weight with the hen on the left side to achieve balance. Note that the sum of the weights on the right side minus the sum of the weights on the left side equals the weight of the object.</p>

<p>As another example, consider weighing a 21-pound Ternarian squash. Using the Ternarian system, you would place weights of 27 pounds and 3 pounds in the right pan and a weight of 9 pounds in the left pan (along with the object) again achieving balance.</p>

<p>Write a program that accepts as input the weight of an object in base 10 and outputs the weights to be placed in both pans.</p>



## 입력


<p>The first line contains an integer 1 ≤ n ≤ 100, indicating how many test cases are to be solved. On each of the next n lines there is an integer 0 ≤ x ≤ 10<sup>9</sup> giving the weight of the object placed on the left scale.</p>



## 출력


<p>For each test case the program should produce two lines of output. The first line should contain left pan: followed by a space, followed by the weights to be placed in the left pan in descending order. The second line should contain right pan: followed by a space, followed by the weights to be placed in the right pan in descending order. Print a blank line between each pair of test cases.</p>



## 소스코드

[소스코드 보기](Ternarian%20Weights.cpp)