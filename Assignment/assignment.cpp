#include <iostream>
using namespace std;
void printArray(int array[], int size) {
    if (size <= 0) {
        cout << "Array is empty.";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void addStart(int array[],int& size,int element){
    if (size >= 10){
        cout << "Array is full.";
        return;
    }
    for(int i = size; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = element;
    size++;
    printArray(array,size);
}
void addEnd(int array[], int &size, int element){
    if(size >= 10){
        cout << "Array is full.";
        return;
    }
    array[size] = element;
    size++;
    printArray(array,size);
}

void addPosition(int array[], int &size, int element, int position){
    cout << "Enter the element you want to enter : ";
    cin >> element;
    cout << "Enter the position you want to enter the element : ";
    cin >> position;
    if(position < 0 || position > size){
        cout << "Invalid Position";
        return;
    }
    if(size >= 10){
        cout << "The array is full.";
        return;
    }
    for(int i = size; i > position ; i--){
        array[i] = array[i-1];
    }
    array[position] = element;
    size++;
    printArray(array,size);
}

void delStart(int array[], int &size){
    for(int i = 0; i < size-1; i++){
        array[i] = array[i+1];
    }
    size--;
    printArray(array,size);
}

void delEnd(int array[],int &size){
    size--;
    printArray(array,size);
}

void delPosition(int array[], int &size, int position){
    if(size == 0){
        cout << "Array is empty";
        return;
    }
    cout << "Enter the position you want to delete : ";
    cin >> position;
    if(position<0 || position>= size){
        cout << "Invalid Input";
        return;
    }
    for(int i = position ; i < size -1 ; i++){
        array[i] = array[i+1];
    }
    size--;
    printArray(array,size);
}

void delRange(int array[], int &size, int start, int end){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    cout << "Enter the range."<< endl;
    cout << "Enter the start of range : ";
    cin >> start;
    cout << "Enter the end of range : ";
    cin >> end;
    if(start < 0 || end >= size  || start > end){
        cout << "Invalid range";
        return;
    }
    for(int i = end +1 ; i < size; i++){
        array[i - (end - start + 1)] = array[i];
    }
    size -= (end - start +1);
    printArray(array,size);
}

int search(int array[],int &size, int key){
    if(size == 0){
        cout << "Array is empty."<< endl;
        return -1;
    }
    cout << "Enter the element you want to search : ";
    cin >> key;
    for (int i = 0; i < size; i++){
        if(array[i] == key){
            return i;
            break;
        }
    }
    return -1;
    // printArray(array,size);
}

void update(int array[], int &size, int position, int newelement){
    cout << "Enter the element you want to replace : ";
    cin >> newelement;
    cout << "Enter the position you want to replace : ";
    cin >> position;
    array[position] = newelement;
    cout << "Element at position " << position << " is being updated to " << newelement << endl;
    printArray(array, size);
}

void addmultistart(int array[],int &size, int number){
    cout << "Enter the number of elements you want to enter : ";
    cin >> number;
    if(number + size > 10){
        cout << "Array is full."<< endl;
        return;
    }
    int elements[number];
    cout << "Enter the elements you want to enter : "<< endl;
    for(int i = 0 ; i < number; i++){
        cout << "Element["<<i<<"] : ";
        cin >> elements[i];
    }
    for(int i = size -1; i >= 0; i--){
        array[i + number] = array[i];
    }
    for(int i = 0; i < number; i++){
        array[i] = elements[i];
    }
    size += number;
    printArray(array,size);
}

void addmultiEnd(int array[],int &size, int number){
    cout << "Enter the number of elements you want to enter : ";
    cin >> number;
    if(number + size > 10){
        cout << "Array is full."<< endl;
        return;
    }
    int elements[number];
    cout << "Enter the elements you want to enter : "<< endl;
    for(int i = 0 ; i < number; i++){
        cout << "Element["<<i<<"] : ";
        cin >> elements[i];
    }
    for(int i = 0; i < number; i++){
        array[size + i] = elements[i];
    }
    size += number;
    printArray(array,size);
}

void addMultiPosition(int array[], int &size, int number,int position){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    cout << "Enter the position where you want to enter elements : ";
    cin >> position;
    if(position < 0 || position > size){
        cout << "Invalid Position";
        return;
    }
    cout << "Enter the number of elements you want to enter : ";
    cin >> number;
    if(number + size > 10){
        cout << "Array is full."<< endl;
        return;
    }
    int elements[number];
    cout << "Enter the elements you want to enter : "<< endl;
    for(int i = 0 ; i < number; i++){
        cout << "Element["<<i<<"] : ";
        cin >> elements[i];
    }
    for(int i = size -1; i >= position; i--){
        array[i+number] = array[i];
    }
    for(int i = 0; i < number; i++){
        array[position+i] = elements[i];
    }
    size += number;
    printArray(array,size);
}

void delMultiStart(int array[],int &size, int position){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    cout << "Enter the number of element you want to delete : ";
    cin >> position;
    if(position > 10 || position < 0 || position > size){
        cout << "Invalid Input";
        return;
    }
    for(int i = 0; i < size; i++){
        array[i] = array[i+position];
    }
    size -= position;
    printArray(array,size);
}

void delMultiEnd(int array[], int &size, int position){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    cout << "Enter the number of element you want to delete : ";
    cin >> position;
    if(position > 10 || position < 0 || position > size){
        cout << "Invalid Input";
        return;
    }
    size -= position;
    printArray(array,size);
}

void delMultiPosition(int array[], int &size,int number,int position){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    cout << "Enter the position of element you want to delete : ";
    cin >> position;
    if(position > 10 || position < 0 || position > size){
        cout << "Invalid Input";
        return;
    }
    cout << "Enter the number of element you want to delete : ";
    cin >> number;
    if(number > 10 || number < 0 || number > size){
        cout << "Invalid Input";
        return;
    }
    for(int i = size -1; i>size-number; i--){
        array[position] = array[i];
    }
    size -= number;
    printArray(array,size);
}

void sortAsc(int array[], int &size){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    for(int i = 0; i < size-1 ; i++){
        for(int j = 0 ; j < size - i- 1; j++){
            if(array[j] > array [j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    printArray(array,size);
}

void sortDsc(int array[], int &size){
    if(size == 0){
        cout << "Array is empty.";
        return;
    }
    for(int i = 0; i < size-1 ; i++){
        for(int j = 0 ; j < size - i- 1; j++){
            if(array[j] < array [j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    printArray(array,size);
}

void inserSort(int array[],int &size){
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
}
printArray(array,size);
}

int main(){
    int array[10];
    int size = 0;
    int element;
    int position;
    int start;
    int end;
    int key;
    int newelement;
    int number;
    cout << "You can choose the following operation that you can perfom on array : " << endl;
    cout << "1. Choose 1 to ADD a number at the START of the array. " << endl;
    cout << "2. Choose 2 to ADD a number at the END of the array. " << endl;
    cout << "3. Choose 3 to ADD a number at the ANY POSITION of the array. " << endl;
    cout << "4. Choose 4 to DELETE a number from START of the array. " << endl;
    cout << "5. Choose 5 to DELETE a number from END of the array. " << endl;
    cout << "6. Choose 6 to DELETE a number at ANY POSITION of the array. " << endl;
    cout << "7. Choose 7 to DELETE from RANGE the array. " << endl;
    cout << "8. Choose 8 to SEARCH the ELEMENT in the array. " << endl;
    cout << "9. Choose 9 to UPDATE the array. "<< endl;
    cout << "10. Choose 10 to ADD MULTIPLE elements at START of the array. "<< endl;
    cout << "11. Choose 11 to ADD MULTIPLE elements at END of the array. "<< endl;
    cout << "12. Choose 12 to ADD MULTIPLE elements at ANY POSITION of the array. "<< endl;
    cout << "13. Choose 13 to DELETE MULTIPLE elements at START of the array. "<< endl;
    cout << "14. Choose 14 to DELETE MULTIPLE elements at END of the array. "<< endl;
    cout << "15. Choose 15 to DELETE MULTIPLE elements at ANY POSITION of the array. "<< endl;
    cout << "16. Choose 16 to SORT the elements in ASCENDING ORDER of the array. "<< endl;
    cout << "17. Choose 17 to SORT the elements in DESCENDING ORDER of the array. "<< endl;
    cout << "18. Choose 18 to INSERTION SORT the elements in DESCENDING ORDER of the array. "<< endl;
    cout << "19. Choose 19 to PRINT the array. "<< endl;
    cout << "20. Choose 20 to EXIT "<< endl;


    while (true)
    {
        int choose;
        cout << "\n Choose number : ";
        cin >> choose;
        if(choose == 1){
            cout << "Add the element at start of array : ";
            cin >> element;
            addStart(array, size, element);
        }else if(choose == 2){
            cout << "Add the element at the end of array : ";
            cin >> element;
            addEnd(array,size,element);
        }else if(choose == 3){
            addPosition(array,size,element,position);
        }else if(choose == 4){
            delStart(array,size);
        }else if(choose == 5){
            delEnd(array,size);
        }else if(choose == 6){
            delPosition(array,size,position);
        }else if(choose == 7){
            delRange(array, size, start,end);
        }else if(choose == 8){
            int search1 = search(array,size,key);
            if(search1 == -1){
                cout << "Not found.";
            }else{
                cout << "Found at " << search1;
            }
        }else if(choose == 9){
            update(array, size, position,newelement);
        }else if(choose == 10){
            addmultistart(array,size,number);
        }else if(choose == 11){
            addmultiEnd(array,size,number);
        }else if(choose == 12){
            addMultiPosition(array,size,number,position);
        }else if(choose == 13){
            delMultiStart(array,size,position);
        }else if(choose == 14){
            delMultiEnd(array,size,position);
        }else if(choose == 15){
            delMultiPosition(array,size,number,position);
        }else if(choose == 16){
            sortAsc(array,size);
        }else if(choose == 17){
            sortDsc(array,size);
        }else if(choose == 18){
            inserSort(array,size);
        }else if(choose == 19){
            printArray(array, size);
        }else if(choose == 20){
            cout << "YOU EXIT !";
            break;
        }else{
            cout << "Invalid input.";
        }
    }
    
}