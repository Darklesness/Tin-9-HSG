#include <iostream>

using namespace std;

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
    cout << "Mang vua nhap: " << endl;
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

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
                            arr[r][c] = lst[i];
                            i++;
                            r++;
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
                arr[r][c] = lst[i];
                c++;
                i++;    
            }
            if (c == col - col % 2){
                if (col % 2 == 1){
                    r = 0;
                    while (r < row){
                        arr[r][c] = lst[i];
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
            time_c++;
        }
    }

    //Tính chiều cao cây chống lọng và số miếng che cần
    i = 0;
    string chieucao;
    while (i < lst_len - 4){
        chieucao += (string)(lst[i] + 1);
        i += 4;
    }
    
    //In mảng 2 chiều
    cout << endl;
    cout << "Mang sau sap xep: " << endl;
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << "So cay chong long can dung: " << timeloop_check << endl << "Chieu cao cac cay: " << chieucao << endl;
    system("pause");
    return 0;
}

