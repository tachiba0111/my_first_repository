//D Teleporter
//Doubling
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++) //これでiやjを定義しなくていいらしい
using namespace std;
using ll = long long;

const int D = 60;//ダブリングによる置換の表の行数
const int MAX_N = 200000;//列数
int to[D][MAX_N];

int main(){
  int n;
  ll k;
  cin >> n >> k;

  rep(i,n){
    cin >> to[0][i];//1行目は1回移動の先＝A[i]と同じ
    to[0][i]--;//配列の要素番号に合わせてデクリメントしておく
  }
  //表を作っていく
  rep(i,D-1){//左上から行を進める、i+1行目まで作るのでD-1までで止める。
    rep(j,n){//列を進める
      to[i+1][j] = to[i][to[i][j]];//表の性質より
    }
  }

  int v=0;//出発点は0番の街
  for(int i=D-1;i>=0;i--){//大きい行数の方から辿っていく
    ll x = 1ll<<i;//オーバーフロー対策しつつ,ｘはkを構成する2^nの数（64,32など）
    if(x<=k){
      v = to[i][v];//v番目の街からi回移動したとこをｖに保存
      k -= x;//残り移動回数を更新する
    }
  }
  cout << v+1 << endl;//出力は町の番号に戻すので＋１

  return 0;
}
