#include <iostream>

using namespace std;

/*
row = 3, col = 5, lst = [9,8,8,6,5,5,5,4,3,3,2,2,1,1,1]

arr = 
1 3 4 9 1
8 2 6 5 3
5 8 5 2 1
*/

void cube(int lst[100], int arr[][100], int r, int c, int i){
    for (;c <= c + 1; c++){
        for (; r <= r + 1; r++){
            arr[r][c] = lst[i];
            i++;
        }
    }
} 


int main(){
    int col, row, lst[100], lst_len = 0, i = 0;
    
    //Nhập số dòng và cột
    cout << "Nhap so dong: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> col;
    
    int arr[row][col];

    //Nhập các phần tử vào mảng 2 chiều và cả 1 chiều
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cin >> arr[r][c];
            lst[i] = arr[r][c];
            i++;
            lst_len++;
        }
    }      
    cout << endl;

    //Sắp xếp mảng 1 chiều
    i = 0;
    int j;
    while (i < lst_len - 1){
        j = i + 1;
        while (j < lst_len){
            if (lst[i] < lst[j]){
                swap(lst[i],lst[j]);
            }
            j++;
        }
        i++;
    }

/*
    //In mảng 1 chiều
    for (i = 0; i < lst_len; i++)
    cout << lst[i] << " ";
*/

    //Sắp xếp mảng 2 chiều
    int times = 0, r = 0, c = 0;
    i = 0;
    while (true){
        if (times < row - (row % 2) - 1){
            int  c2 = c + 1;
            while (true){
                int r2 = r + 1;
                if (c <= c2){
                    while (true){
                        if (r <= r2){
                            //cout << "Arr[" << r << "][" << c << "] trc: " << arr[r][c] << endl;
                            //cout << "Lst[" << i << "] :"  << lst[i] << endl;   
                            arr[r][c] = lst[i];
                            //cout << "Arr[" << r << "]["<< c << "] sau: " << arr[r][c] << endl;
                            i++;
                            r++;
                            //system("pause");
                        }
                        else{
                            r -= 2;
                            break;
                        } 
                    }
                c++;
                }
                else {
                    c -= 2;
                    break;
                }
            }
            r += 2;
            times += 2;
        }
        else break;
    }



    //In mảng 2 chiều
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}

