#include <bits/stdc++.h>
using namespace std;
void gaussian_eliminate(int n, vector<int>& x, vector<int>& y, vector<vector<int>>& m) {
  int row = 0;
  for (int p = 0; p < n; ++p) {
    int q = row;
    while (q < n && !m[q][p]) ++q;
    if (q < n) {
      if (q != row) {
      std::swap(m[row], m[q]);
      std::swap(y[row], y[q]);
      }
      for (int r = row+1; r < n; ++r) {
        if (m[r][p] != 1 && m[r][p] != 0)
            printf("BADDD\n");
        if (m[r][p]) {
          for (int c = p; c < n; ++c) {
            m[r][c]^=m[row][c]; 
          }
          y[r]^=y[p]; 
        }
        assert(!m[r][p]);
      }
      row++;
    }
  }
}

bool upper_triangular_solve(int n, vector<int>& x, vector<int>& y, vector<vector<int>>& m) {
  for (int r = n-1; r >= 0; r--) {
    int pivot = 0;
    while (pivot < n && !m[r][pivot]) pivot++;
    if (pivot == n) {
      if (y[r])
        return false;
      continue;
    }
    int s = 0;
    for (int q = pivot+1; q < n; ++q) {
      if (x[q] != -1)
        s ^= m[r][q]&x[q];
    }
    s ^= y[r];
    x[pivot] = s;
    for (int c = pivot+1; c<n; c++)
      if (x[c] == -1) x[c] = 0;
  }
  return true;
}

bool solve(int n, vector<int>& x, vector<int>& y, vector<vector<int>>& m) {
  x.resize(n, -1);
  gaussian_eliminate(n, x, y, m);
  if (!upper_triangular_solve(n, x, y, m)) return false;
  return true;
}

int n;
vector<int> x, y;
vector<vector<int>> mat;
char buff[10];

int readint(int &i) {
int ans = 0;
while ('0' <= buff[i] && buff[i] <= '9') ans = 10 * ans + (buff[i++]-'0');
return ans;
}

void input() {
  int i, j, v;
  scanf("%d", &n);
  x = vector<int>(n);
  y = vector<int>(n, 1);
  mat = vector<vector<int>>(n, vector<int>(n));
  for (i = 0; i < n; ++i) {
  memset(buff, 0, sizeof buff);
  scanf(" %s", buff);
  mat[i][i] = 1;
  if (buff[0] == '!') {
    j = 1;
    v = readint(j)-1;
    mat[i][v] ^= 1;
  } else {
    j = 0;
    v = readint(j)-1;
    mat[i][v] ^= 1;
    j += 2;
    v = readint(j)-1;
    mat[i][v] ^= 1;
    } 
  }
}

int main() {
  input();
  if (!solve(n, x, y, mat)) return !printf("No perfect solution found\n");
  for (int i = 0; i < n; ++i) {
  if (x[i] == -1){
    while (true){}
  }
  if (x[i]) printf("true\n");
  else printf("false\n");
  }
}