#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool char_check(string n){
    int i, j;
    
    while (i < n.size() - 1){
        j = i + 1;
        while (j < n.size()){
            if (tolower(n[i]) == tolower(n[j])){
                return true;
            }
            j++;    
        }
        i++;
    }
    return false; 
}

int main(){
    string n, lst[100], ans;
    int count, i = 0, lst_len = 0, j;
    cout << "Nhap 1 chuoi: ";
    getline(cin, n);
    cout << endl;

    stringstream s(n);
    string word;
    while (s >> word) {
        lst[i] = word;
        i++;
        lst_len++;
        cout << lst[i];
    }
    
    i = 0;
    while (i < lst_len - 1){
        j = i + 1;
        if (lst[i] == lst[j]){
            count++;
            ans += " " + lst[i] + " " + lst[j] + ","; 
        }
        i++;
    }

    i = 0;
        while (i < lst_len){
            if (char_check(lst[i])){
                ans += " " + lst[i] + ",";
                count++;
            }
            i++;
    }
    cout << "So tu trung lap: " << count << endl << "Cac tu trung lap:" << ans << endl;
    system("pause"); 
    return 0;
}