#include <bits/stdc++.h>
using namespace std;

uint32_t rotl(uint32_t x, uint32_t r) { return (x << r) | (x >> (32 - r)); }

uint32_t rotr(uint32_t x, uint32_t r) { return (x >> r) | (x << (32 - r)); }

uint32_t mix(uint32_t x) {
  x ^= rotl(x, 7);
  x += 0x9e3779b9;
  x ^= rotr(x, 11);
  x *= 0x85ebca6b;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  uint32_t acc = 0x12345678;

  for (int i = 0; i < n; i++) {
    uint32_t x;
    cin >> x;
    acc ^= mix(x + i);
    acc = rotl(acc, (i % 31) + 1);
  }

  cout << acc << "\n";
  return 0;
}
