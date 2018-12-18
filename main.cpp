#include <iostream>
#include <vector>

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
    int matr[10][10];
    int no_elem;
    int norm;
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
                        cout << "The size of the matrix is:";
                        cin >> arrOfmatr[it].no_elem;

                        for(int i = 0; i < arrOfmatr[it].no_elem; ++i){
                            for(int j = 0; j < arrOfmatr[it].no_elem; ++j){
                                cout << "matrix[" << i << "][" << j << "]=";
                                cin >> arrOfmatr[it].matr[i][j];
                            }
                        }

                        arrOfmatr[it].norm = 0;
                        for(int i = 0; i < arrOfmatr[it].no_elem; ++i){
                            arrOfmatr[it].norm += arrOfmatr[it].matr[i][i];
                        }

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
            }
    }
    return 0;
}
