//C skill Up
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++) //これでiやjを定義しなくていいらしい
using namespace std;

const int INF = 100100100; //ansを高い値段で初期化しておく

int main(){
  int n,m,x;//参考書冊数、アルゴリズム数、理解度の目標値
  int c[12],a[12][12];//参考書価格、能力値
  int ans=INF,cost;

  cin >> n >> m >> x;
  //入力
  rep(i,n){
    cin >> c[i];
    //cout << c[i] << "\t";
    rep(j,m){
      cin >> a[i][j];
      //cout << a[i][j] << " ";
    }
    //cout << "\n";
  }

  //処理
  //ビット全探索
  rep(i,1<<n){
    cost = 0;
    vector<int> d(m);//能力値の合計値を仮置き

    rep(j,n){//何冊目の本を買うパターン？
      if(i>>j&1){//1ビットずつシフト、買う場合は
        cost+=c[j];//書籍代を足し、
        rep(k,m){
          d[k]+=a[j][k];//能力値を増やす
        }
      }
    }//価格と能力値合計が出たら

    bool flag = true;
    rep(j,m){//能力値確認
      if(d[j]<x){//ひとつでもxに達していないアルゴリズムがあったら
        flag = false;
      }
    }//能力値の条件をクリアしたら
    if(flag){//答えを更新
      ans = min(ans,cost);
    }
  }
  //cout << "Main part end\n";
  //出力
  if(ans == INF){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }

  return 0;
}
