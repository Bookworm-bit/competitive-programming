#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("mixmilk");
	
  int amount[3];
  int size[3];
  
  for (int i=0; i<3; i++) {
    cin >> size[i] >> amount[i];
  }
  
  for (int i=0; i<100; i++) {
    int pour = min(amount[i%3], size[(i+1) % 3] - amount[(i+1) % 3]);
    amount[i % 3] -= pour;
    amount[(i+1) % 3] += pour;
  }
  
  cout << amount[0] << '\n';
  cout << amount[1] << '\n';
  cout << amount[2] << '\n';
}
