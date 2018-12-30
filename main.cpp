#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
class CArray{
private:
    vector<T> arr;
public:
    void add_element(T elem){
        arr.push_back(elem);
    }

    void sort_arr(){
        T temp;
        for(unsigned int i = 0; i < arr.size() - 1; ++i){
            for(unsigned int j = i + 1; j < arr.size(); ++j){
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display(){
        for(unsigned int i = 0; i < arr.size(); ++i){
            cout << "Element[" << i << "] = " << arr[i] << endl;
        }
        cout << std::endl;
    }
};


struct matrix{
    double **matr;
    int rows;
    int columns;
    double norm;
};

int main()
{
    int option;

    cout << "1.Integer." << endl << "2.Char." << endl << "3.Matrix." << endl;
    cin >> option;

    if(option == 1){
        CArray<int> obj;

        do{
        cout << "1.Add integer." << endl << "2.Sort." << endl << "3.Dispaly." << endl << "4.Exit." << endl;
        cin >> option;

        if(option == 1){
            int temp;

            cout << "The integer is:";
            cin >> temp;

            obj.add_element(temp);
        }
        else{
            if(option == 2){
                obj.sort_arr();
            }
            else{
                obj.display();
            }
        }

        }while(option != 4);

    }
    else{
            if(option == 2){
                CArray<char> obj2;

                do{
                cout << "1.Add char." << endl << "2.Sort." << endl << "3.Dispaly." << endl << "4.Exit." << endl;
                cin >> option;

                if(option == 1){
                    char temp;

                    cout << "The char is:";
                    cin >> temp;

                    obj2.add_element(temp);
                }
                else{
                    if(option == 2){
                        obj2.sort_arr();
                    }
                    else{
                        obj2.display();
                    }
                }

                }while(option != 4);
            }
            else{
                vector<matrix> arrOfmatr;
                int it = 0;
                CArray<int> obj3;

                do{
                    cout << "1.Add matrix." << endl << "2.Sort." << endl << "3.Dispaly." << endl << "4.Exit." << endl;
                    cin >> option;

                    if(option == 1){
                        arrOfmatr.push_back(matrix());
                        cout << "The number of rows is:";
                        cin >> arrOfmatr[it].rows;
                        cout << "The number of columns is:";
                        cin >> arrOfmatr[it].columns;

                        arrOfmatr[it].matr = new double* [arrOfmatr[it].rows];
                        for(int i = 0; i < arrOfmatr[it].rows; ++i){
                            arrOfmatr[it].matr[i] = new double[arrOfmatr[it].columns];
                        }

                        for(int i = 0; i < arrOfmatr[it].rows; ++i){
                            for(int j = 0; j < arrOfmatr[it].columns; ++j){
                                cout << "matrix[" << i << "][" << j << "]=";
                                cin >> arrOfmatr[it].matr[i][j];
                            }
                        }

                        arrOfmatr[it].norm = 0;
                        for(int i = 0; i < arrOfmatr[it].rows; ++i){
                            for(int j = 0; j < arrOfmatr[it].columns; ++j){
                                arrOfmatr[it].norm += pow(arrOfmatr[it].matr[i][j],2);
                            }
                        }

                        arrOfmatr[it].norm = sqrt(arrOfmatr[it].norm);

                        obj3.add_element(arrOfmatr[it].norm);

                        it++;
                    }
                    else{
                        if(option == 2){
                            obj3.sort_arr();
                        }
                        else{
                            obj3.display();
                        }
                    }
                }while(option != 4);
                for(int i = 0; i < it; ++i){
                    for (int j = 0; j < arrOfmatr[i].rows; ++j){
                        delete [] arrOfmatr[i].matr[j];
                    }
                    delete [] arrOfmatr[i].matr;
                }
                arrOfmatr.clear();
            }
    }
    return 0;
}
