//=====================================================================
//   15419번:    Frosting on the Cake                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/15419  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> A(n);
  ll sumA[3] = {0, 0, 0};

  for (int i=1; i<=n; i++) {
    cin >> A[i-1];
    sumA[i%3] += A[i-1];
  }

  vector<int> B(n);
  ll sumB[3] = {0, 0, 0};

  for (int i=1; i<=n; i++) {
    cin >> B[i-1];
    sumB[i%3] += B[i-1];
  }

  ll result[3];
  for (int c=0; c<3; c++) {
    ll res = sumA[0] * sumB[c];
    res += sumA[1] * sumB[(c+2)%3];
    res += sumA[2] * sumB[(c+1)%3];
    result[c] = res;
  }

  cout << result[0] << " " << result[1] << " " << result[2] << "\n";


  return 0;
}