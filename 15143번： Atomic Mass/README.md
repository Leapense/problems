# 15143번: Atomic Mass - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15143)


<p>Elements in chemistry are represented by their symbol, which is either one uppercase letter or an uppercase letter followed by a lowercase letter (for example, H is hydrogen and He is helium). A compound is a combination of several elements. Numbers appearing after an element symbol indicate that an element is used multiple times. For example, H<sub>2</sub>O is made up of two hydrogen (H) and one oxygen (O), while CH4 is one carbon (C) and four hydrogen (H). Note that a symbol can appear in multiple locations of a compound. For example, acetic acid is CH<sub>3</sub>COOH.</p>

<p>The atomic mass of an element is the mass of one atom of that element. The molecular mass of a compound is the sum of the atomic masses of the elements in the compound.</p>

<p>For example, the atomic mass of hydrogen (H) is 1.01 and the atomic mass of oxygen (O) is 16.00, which means that the molecular mass of water (H<sub>2</sub>O) is 2 · 1.01 + 16.00 = 18.02.</p>

<p>What is the molecular mass of the given compound?</p>



## 입력


<p>The input starts with a line containing a single integer n (1 ≤ n ≤ 20), which is the number of elements.</p>

<p>The next n lines describe the elements. Each line contains the element’s symbol followed by a real number m (0.01 ≤ m ≤ 500.00), which is the mass of this element. The symbol will be either a single uppercase letter or an uppercase letter followed by a lowercase letter. No two elements will have the same symbol. All masses will be specified to exactly two decimal places.</p>

<p>The last line describes the compound in question. The compound will be a string of element symbols and integers. Each integer will appear directly after the corresponding element symbol, and each integer will be between 2 and 100 inclusive. The compound consists of between 1 and 25 characters inclusive. All elements that appear in the compound are one of the n elements listed above. The molecule will not be a complex molecule such as Al<sub>2</sub>(SO<sub>4</sub>)<sub>3</sub>.</p>



## 출력


<p>Display the molecular mass of the compound. Your answer should have an absolute or relative error of less than 10<sup>−6</sup>.</p>



## 소스코드

[소스코드 보기](Atomic%20Mass.cpp)