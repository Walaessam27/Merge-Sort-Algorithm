//Wala' Essam Ashqar 12027854

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printing(const vector<int>& k) {
    cout << "[";
    if (!k.empty()) {
        cout << k[0];
        for (size_t i = 1; i < k.size(); i++) {
            cout << "," << k[i];}}
    cout << "]";}
void merging(vector<int>& k, int l, int o, int r) {
    int a = o - l + 1;
    int b = r - o;
    vector<int> L(a), R(b);
    for (int i = 0; i < a; i++) {
        L[i] = k[l + i];}
    for (int j = 0; j < b; j++) {
        R[j] = k[o + 1 + j];}
    int i = 0;
    int j = 0;
    int c = l;
    while (i < a && j < b) {
        if (L[i] <= R[j]) {
            k[c] = L[i];
            i++;}
        else {
            k[c] = R[j];
            j++;}
            c++;}
    while (i < a) {
        k[c] = L[i];
        i++;
        c++;}
    while (j < b) {
        k[c] = R[j];
        j++;
        c++;}}
void sorting(vector<int>& k, int l, int r) {
    if (l < r) {
        int o = l + (r - l) / 2;
        sorting(k, l, o);
        sorting(k, o + 1, r);
        merging(k, l, o, r);}}
int main() {
    int w;
    cin >> w;
    vector<int> k(w);
    for (int i = 0; i < w; i++) {
        cin >> k[i];}
    sorting(k, 0, w - 1);
    printing(k);
    return 0;}