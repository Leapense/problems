//=====================================================================
//   19957번:    Шахматная головоломка                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/19957  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    string pos;
    cin >> pos;
    int knight_x = pos[0] - 'a';
    int knight_y = pos[1] - '1';
    vector<pair<int,int>> knight_moves = {
        {knight_x + 2, knight_y + 1}, {knight_x + 2, knight_y -1},
        {knight_x -2, knight_y +1}, {knight_x -2, knight_y -1},
        {knight_x +1, knight_y +2}, {knight_x +1, knight_y -2},
        {knight_x -1, knight_y +2}, {knight_x -1, knight_y -2}
    };
    auto is_valid = [&](int x, int y) -> bool{
        return x >=0 && x <8 && y >=0 && y <8;
    };
    vector<pair<int,int>> knight_attacks;
    for(auto &[x,y]: knight_moves){
        if(is_valid(x,y)) knight_attacks.emplace_back(x,y);
    }
    auto attacks_knight = [&](int x, int y) -> bool{
        for(auto &[kx,ky]: knight_attacks){
            if(kx ==x && ky == y) return true;
        }
        return false;
    };
    vector<pair<int,int>> rook_positions;
    for(int i=0;i<8;i++){
        if(i != knight_x && !attacks_knight(i, knight_y)) rook_positions.emplace_back(i, knight_y);
        if(i != knight_y && !attacks_knight(knight_x, i)) rook_positions.emplace_back(knight_x, i);
    }
    vector<pair<int,int>> bishop_positions;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(abs(i - knight_x) == abs(j - knight_y) && !(i == knight_x && j == knight_y) && !attacks_knight(i,j)){
                bishop_positions.emplace_back(i,j);
            }
        }
    }
    for(auto &[rx, ry]: rook_positions){
        for(auto &[bx, by]: bishop_positions){
            if(rx != bx && ry != by && abs(rx - bx) != abs(ry - by)){
                string rook = "";
                rook += ('a' + rx);
                rook += ('1' + ry);
                string bishop = "";
                bishop += ('a' + bx);
                bishop += ('1' + by);
                cout << rook << "\n" << bishop;
                return 0;
            }
        }
    }
    return 0;
}