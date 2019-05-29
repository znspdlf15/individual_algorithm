#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


typedef struct Gem{
  int weight;
  int cost;
}TGem;

bool sortByCost(TGem a, TGem b){
  return a.cost > b.cost;
}
bool sortByWeight(TGem a, TGem b){
  return a.weight < b.weight;
}


int bags[300000] = {0, };
TGem gems[300000];

int main(){
  int N, K;

  cin >> N >> K;
  for ( int n = 0; n < N; n++ ){
    int weight, cost;
    scanf("%d %d", &weight, &cost);
    gems[n].weight = weight;
    gems[n].cost = cost;
  }

  for ( int k = 0; k < K; k++ ){
    scanf("%d", &bags[k]);
  }
  sort(gems, gems+N, sortByWeight);
  sort(gems, gems+N, sortByCost);

  sort(bags, bags+K);

  long long answer = 0;
  for ( int n = 0; n < N; n++ ){
    cout << gems[n].cost << endl;
    for ( int i = 0; i < K; i++ ){
      if ( bags[i] < gems[n].weight ) continue;
      answer += gems[n].cost;
      bags[i] = 0;
      break;
    }
  }

  cout << answer << endl;

  return 0;
}
