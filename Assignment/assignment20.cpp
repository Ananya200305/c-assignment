#include <iostream>
using namespace std;

void display(int array[],int & size){
    if(size <= 0){
        cout << "Array is empty"<< endl;
        return;
    }

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}

void insertArray(int array[], int & size){
    if(size >= 10){
        cout << "Array is full." << endl;
        return;
    }
    int value;
    cout << "Enter the value you want to insert at end : ";
    cin >> value;
    
    if(size == 0){
        array[0] = value;
        size++;
        return;
    }else{
        array[size] = value;
        size++;
    }
}

void deleteArray(int array[],int& size){
    if(size <= 0){
        cout << "Array is empty. Nothing to delete."<< endl;
        return;
    }
    size--;
    cout << "Last element deleted." << endl;
}

void swapping(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[],int low,int high){
    int pivot = array[high];
    int i = low-1;

    for(int j = low; j < high; j++){
        if(array[j] < pivot){
            i++;
            swapping(array[i],array[j]);
        }
    }
    swapping(array[i+1],array[high]);
    return i+1;
}

void quickSort(int array[],int low, int high){
    if(low < high){
        int i = partition(array,low,high);

        quickSort(array,low,i-1);
        quickSort(array,i+1,high);
    }
}

void merge(int array[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[10];
    int R[10];

    for(int i = 0; i < n1; i++){
        L[i] = array[low+i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0; 
    int k = low;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }
        else{
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

int main(){
    int choice;
    int array[10];
    int size = 0;
    while(true){
        cout << "\nMenu\n" << endl;
        cout << "1. INSERT ARRAY" << endl;
        cout << "2. DELETE ARRAY" << endl;
        cout << "3. QUICK SORT" << endl;
        cout << "4. MERGE SORT" << endl;
        cout << "5. DISPLAY" << endl;
        cout << "6. EXITING" << endl;
        cout << "\nEnter the number : ";
        cin >> choice;
        switch(choice){
            case 1:
            insertArray(array,size);
            display(array,size);
            break;
            case 2:
            deleteArray(array,size);
            display(array,size);
            break;
            case 3:
            if(size > 1){
                quickSort(array,0,size-1);
                cout << "Array is sorted using quick sort." << endl;
            }else{
                cout << "Array is too small to sort." << endl;
            }
            display(array,size);
            break;
            case 4:
            if(size > 1){
                mergeSort(array,0,size-1);
                cout << "Array is sorted using merge sort." << endl;
            }else{
                cout << "Array is too small to sort." << endl;
            }
            display(array,size);
            break;
            case 5:
            display(array,size);
            break;
            case 6:
            cout << "Exiting...."<< endl;
            exit(0);
            break;
            default:
            cout << "Invalid input.";
            break;
        } 
    }
    return 0;
}