#include <iostream>

using namespace std;

/*
row = 3, col = 5, lst = [9,8,8,6,5,5,5,4,3,3,2,2,1,1,1]

arr = 
1 3 4 9 1
8 2 6 5 3
5 8 5 2 1
*/

int main(){
    int col, row, lst[100], i = 0;
    double  lst_len = 0;
    
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
    int time_r = 0, time_c = 1, r = 0, c = 0;
    i = 0;
    int timeloop_check = double(lst_len/4 + 0.5);

    for (int timeloop = 1; timeloop < timeloop_check; timeloop++){
        if (time_r < row - (row % 2) - 1){
            int  c2 = c + 1;
            while (true){
                int r2 = r + 1;
                if (c <= c2){
                    while (true){
                        if (r <= r2){
                            cout << "timeloop: " << timeloop << endl << "Timeloop_Check " << (int)(timeloop_check + 0.5) << endl;
                            cout << "r = " << r << endl << "r2 = " << r2 << endl;
                            cout << "c = " << c << endl << "c2 = " << c2 << endl;
                            cout << "Arr[" << r << "][" << c << "] trc: " << arr[r][c] << endl;
                            cout << "Lst[" << i << "] :"  << lst[i] << endl;   
                            arr[r][c] = lst[i];
                            cout << "Arr[" << r << "]["<< c << "] sau: " << arr[r][c] << endl << endl;
                            i++;
                            r++;
                            system("pause");
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
            time_r += 2;
        }
        
        if ((row % 2) == 1 && (r == row - 1)){
            int c2 = c + 2;
            while (c < c2){
                cout << "timeloop: " << timeloop << endl << "Timeloop_Check " << (int)(timeloop_check + 0.5) << endl;
                cout << "c = " << c << endl << "c2 = " << c2 << endl;
                cout << "Arr[" << r << "][" << c << "] trc: " << arr[r][c] << endl;
                cout << "Lst[" << i << "] :"  << lst[i] << endl;
                arr[r][c] = lst[i];
                cout << "Arr[" << r << "]["<< c << "] sau: " << arr[r][c] << endl << endl;
                system("pause");
                c++;
                i++;    
            }
            cout << "c = " << c << " " << "col - col % 2 = " << col - col % 2 << endl;
            if (c == col - col % 2){
                if (col % 2 == 1){
                    r = 0;
                    while (r < row){
                        cout << "r = " << c << endl << "row - 1 = " << row - 1 << endl;
                        cout << "Arr[" << r << "][" << c << "] trc: " << arr[r][c] << endl;
                        cout << "Lst[" << i << "] :"  << lst[i] << endl;
                        arr[r][c] = lst[i];
                        cout << "Arr[" << r << "]["<< c << "] sau: " << arr[r][c] << endl << endl;
                        system("pause");
                        i++;
                        r++;
                    }
                }
            }            
            else{
                c -= 2;
                r = 0;
            }
        }

        if ((time_c < col - (col % 2) - (col / 2)) && (time_r >= row - (row % 2) - 1)){
            c += 2;
            time_r = 0;
            r = 0;
            cout << "Time_c = " << time_c << endl << "col - (col % 2) - (col / 2) = " << col - (col % 2) - (col / 2) << endl;
            time_c++;
        }
    }

    //Tính chiều cao cây chống lọng và số cây chống lọng cần dùng
    int rc;
    if (row % 2 != 0) rc = row;
    else if (col % 2 != 0) rc = col;
    else if (col % 2 == row % 2) rc = row; 
    
    int i = 0, j = 0;
    while (i <= rc){
        for (; i <= rc % 2; i++){
        }
    }

    //In mảng 2 chiều
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

