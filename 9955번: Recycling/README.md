# 9955번: Recycling - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9955)


<p>Kerbside recycling has come to New Zealand, and every city from Auckland to Invercargill has leapt on to the band wagon. The bins come in 5 different colours — red, orange, yellow, green and blue — and 5 wastes have been identified for recycling — Plastic, Glass, Aluminium, Steel, and Newspaper. Obviously there has been no coordination between cities, so each city has allocated wastes to bins in an arbitrary fashion. Now that the government has solved the minor problems of today (such as reorganising Health, Welfare and Education), they are looking around for further challenges. The Minister for Environmental Doodads wishes to introduce the “Regularisation of Allocation of Solid Waste to Bin Colour Bill” to Parliament, but in order to do so needs to determine an allocation of her own. Being a firm believer in democracy (well some of the time anyway), she surveys all the cities that are using this recycling method. From this she wishes to determine which allocation scheme (if imposed on the rest of the country) would cause the least impact, i.e. would cause the smallest overall number of changes to the current allocations.</p>

<p>Write a program that will read in a series of allocations of wastes to bins and then determine which allocation scheme, out of all possible schemes, will produce the fewest changes if adopted across the country. Note that there will always be a clear winner.&nbsp;</p>



## 입력


<p>Input will consist of a series of blocks. Each block will consist of a series of lines terminated by a line containing only a single #, and each line will contain a series of allocations in the form shown in the example. The entire file will also be terminated by a line consisting of a single #.</p>



## 출력


<p>Output will consist of a series of lines, one for each block in the input. Each line will consist of the allocation scheme that should be adopted as a national example. Bins should be listed in the order shown, i.e. red, orange, yellow, green, blue.</p>



## 소스코드

[소스코드 보기](Recycling.cpp)