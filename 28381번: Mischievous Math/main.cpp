//=====================================================================
//   28381번:    Mischievous Math                   
//   @date:   2024-10-31              
//   @link:   https://www.acmicpc.net/problem/28381  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

bool can_form_d(vector<double> numbers, double target) {
    if (numbers.size() == 1)
        return abs(numbers[0] - target) < 1e-6;
    for(int i=0;i<numbers.size();i++) {
        for(int j=0;j<numbers.size();j++) {
            if(i == j) continue;
            vector<double> next_numbers;
            for(int k=0;k<numbers.size();k++) {
                if(k !=i && k !=j)
                    next_numbers.push_back(numbers[k]);
            }
            double a = numbers[i];
            double b = numbers[j];
            next_numbers.push_back(a + b);
            if(can_form_d(next_numbers, target)) return true;
            next_numbers.pop_back();
            next_numbers.push_back(a - b);
            if(can_form_d(next_numbers, target)) return true;
            next_numbers.pop_back();
            next_numbers.push_back(b - a);
            if(can_form_d(next_numbers, target)) return true;
            next_numbers.pop_back();
            next_numbers.push_back(a * b);
            if(can_form_d(next_numbers, target)) return true;
            next_numbers.pop_back();
            if(b !=0){
                next_numbers.push_back(a / b);
                if(can_form_d(next_numbers, target)) return true;
                next_numbers.pop_back();
            }
            if(a !=0){
                next_numbers.push_back(b / a);
                if(can_form_d(next_numbers, target)) return true;
                next_numbers.pop_back();
            }
        }
    }
    return false;
}

int main(){
    int d;
    cin>>d;
    for(int a=1;a<=100;a++){
        if(a ==d) continue;
        for(int b=a+1;b<=100;b++){
            if(b ==d) continue;
            for(int c=b+1;c<=100;c++){
                if(c ==d) continue;
                vector<double> numbers = {a, b, c};
                if(!can_form_d(numbers, d)){
                    cout<<a<<" "<<b<<" "<<c;
                    return 0;
                }
            }
        }
    }
}