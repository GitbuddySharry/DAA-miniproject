// C++ program for Naive Pattern Searching algorithm and Rabin Karp Pattern Searching algorithm
#include <bits/stdc++.h>
using namespace std;
#define d 256
/* pat -> pattern
txt -> text
q -> A prime number
*/
void search_RK(char pat[], char txt[], int q)
{
int M = strlen(pat);
int N = strlen(txt);
int i, j;
int p = 0;
int t = 0;
int h = 1;
for (i = 0; i < M - 1; i++) h = (h * d) % q;
for (i = 0; i < M; i++) {
p = (d * p + pat[i]) % q;
t = (d * t + txt[i]) % q;
}
for (i = 0; i <= N - M; i++)
{
if (p == t)
{
for (j = 0; j < M; j++) if (txt[i + j] != pat[j]) break;
if (j == M) cout << "Pattern found at index " << i << endl;
}
if (i < N - M)
{
t = (d * (t - txt[i] * h) + txt[i + M]) % q;
if (t < 0) t = (t + q);
}
}
}
void search_NS(char* pat, char* txt)
{
int M = strlen(pat);
int N = strlen(txt);
for (int i = 0; i <= N - M; i++) {
int j;
for (j = 0; j < M; j++) if (txt[i + j] != pat[j]) break;
if (j == M) cout << "Pattern found at index " << i << endl;
}
}
int main()
{
char txt[] = "AABAACAADAABAAABAA";
char pat[] = "AABA";
cout<<"Naive approach: "<<endl;
search_NS(pat, txt);
cout<<endl;
cout<<"Rabin Karp approach: "<<endl;
search_RK(pat, txt, INT_MAX);
return 0;
}
