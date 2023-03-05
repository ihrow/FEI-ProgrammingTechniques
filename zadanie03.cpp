/*
Meno a priezvisko: Ihar Dzehtsiarou

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};


//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()
*/
void insertionSort(int *data, const size_t length) {
    for (size_t i = 1; i < length; i++) {
        int key = data[i], j = i - 1; // j == compare_with
        for (; j >= 0 && key > data[j]; j--) data[j + 1] = data[j];
        data[j + 1] = key;
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        ("Juraj", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", nullptr)
        ("Juraj", "Anabela", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", "Anabela", nullptr)
        ("Andrej", "Juraj", "Andrej", nullptr) -> ("Juraj", "Andrej", "Andrej", nullptr)
        ("Andrej", nullptr) -> ("Andrej", nullptr)
        (nullptr) -> (nullptr)

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
// void insertionSort(const char *data[]) {
//     size_t length = 0;
//     while (data[length]) length++;
//     for (size_t i = 1; i < length; i++) {
//         const char* key = data[i]; 
//         int j = i - 1; // j == compare_with
//         for (; j >= 0 && strcmp(key, data[j]) > 0; j--) data[j + 1] = data[j];
//         data[j + 1] = key;
//     }
// }
void print_array(const char* data[], size_t length) {
    for (size_t i = 0; i < length; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
void insertionSort(const char *data[]) {
    const char *check;
    int previous = 0;
    
    size_t len = 0;
    for (size_t i = 0; data[i] != nullptr; i++, len++);

    for (size_t i = 1; i < len; i++)
    { 
        check = data[i];
        previous = i - 1; 
        while (previous >= 0 && strcmp(check, data[previous]) > 0){ 
            data[previous + 1] = data[previous];
            previous--;
        }
        data[previous + 1] = check; 
    } 
}

void printList(List node)
{
    while (node.first != NULL)
    {
        cout << node.first->data << " ";
        node.first = node.first->next;
    }
    cout << endl;
}
//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Preusporiadajte uzly v zozname (nekopirujte hodnoty v uzloch).
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3,        vystup: 3->2->1
        vstup: 1->2->2->1,     vystup: 2->2->1->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/

void swapNodes(List * list, Node * iter, Node *curr) {
    if (iter == list->first) {
        curr->next = list->first;
        list->first = curr;
    }
    Node *tmp = list->first;
    for (;tmp->next != iter; tmp = tmp->next);
    tmp->next = curr;
    curr->next = iter;
}

void insertionSort(List * list) {
    if (!list->first || !list->first->next) return;
    
    Node *curr = list->first->next;
    Node *prev = list->first;
    Node *iter = list->first;

    for (; curr ; iter = list->first) {
        for (; iter != curr ; iter = iter->next) {
            if (iter->data < curr->data) {
                prev->next = curr->next;
                swapNodes(list, iter, curr);
                break;
            }
        }

        prev = curr;
        curr = curr->next;
    }
}



//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' je nezmeneny.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni.
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli).
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli).

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         (10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10)
        output pred vykonanim funkcie: (20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20)
        output po vykonani funkcie:    (20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20)
*/
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t leftArrayLength = middle - low;
    size_t rightArrayLength = high - middle;

    int* leftArray = new int[leftArrayLength];
    int* rightArray = new int[rightArrayLength];

    for (size_t i = 0; i < leftArrayLength; i++) leftArray[i] = input[low + i];
    for (size_t i = 0; i < rightArrayLength; i++) rightArray[i] = input[middle + i];

    
    size_t i = 0, j = 0;
    for (; i < leftArrayLength && j < rightArrayLength ; ) {
        if (leftArray[i] >= rightArray[j]) {
            output[low + i + j] = leftArray[i];
            i++;
        }
        else {
            output[low + i + j] = rightArray[j];
            j++;
        }
    }

    for (; i < leftArrayLength ; i++) output[low+i+j] = leftArray[i];
    for (; j < rightArrayLength ; j++) output[low+i+j] = rightArray[j];
    
    delete[] leftArray;
    delete[] rightArray;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.
    Vytvorte jedno pomocne pole. Pre alokaciu a dealokaciu pomocneho pola pouzite new[] a delete[].

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()

    POZNAMKA:
        Ak pouzijete pristup top-down, tak
        - v tejto funkcii zabezpecte vytvorenie a kopirovanie dat do pomocneho pola,
        - vytvorte a zavolajte rekurzivnu funkciu, v ktorej implementujete hlavnu cast algoritmu merge sort.
*/

// bottom-to-up
void mergeSort(int *data, const size_t length) {
    int* tmp = new int[length];
    for (size_t i = 0; i < length; i++) tmp[i] = 0;
    size_t high = 0;

    for (size_t size = 1; size < length; size = size * 2) {

        for (size_t low = 0; low < length - size; low += 2 * size) {
            size_t middle = low + size;
            high = min(low + 2 * size, length);
            mergeNeighbours(tmp, data, low, middle, high);
        }
        for (size_t i = 0; i < high; i++) data[i] = tmp[i];
    }
    delete[] tmp;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury


void print_array(const int *data, size_t length) {
    for (size_t i = 0; i < length; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
void appendNode(List *list, const int val) {
    Node* new_node = new Node();
    *new_node = {val, NULL};

    if (list->first == NULL) {
        list->first = new_node;
        return;
    } 

    Node *tmp = list->first;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = new_node;
}

int main() {

    // TEST 1. ULOHA
    // int data[] = {1, 4, 7, 2, 9, 12, -1};
    // insertionSort(data, 7);
    // print_array(data, 7);

    // TEST 2. ULOHA
    const char *mena[] = {"b", "c", "a", "g", "d", "z", "u", "k", "v", nullptr};
    insertionSort(mena);
    print_array(mena, 9);

    // TEST 3. ULOHA
    // List * list = new List();
    // appendNode(list, 5);
    // appendNode(list, 2);
    // appendNode(list, 1);
    // appendNode(list, -6);
    // appendNode(list, 13);
    // appendNode(list, 9);
    // printList(*list);
    // insertionSort(list);
    // printList(*list);

    // TEST 4. ULOHA
    // int output[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
    // int input[] = {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10};
    // mergeNeighbours(output, input, 4, 8, 12);
    // print_array(output, 16);

    // TEST 5. ULOHA
    // int input2[] = {1, 2, 3, 4, 5, 6};
    // mergeSort(input2, sizeof(input2) / sizeof(input2[0]));
    // print_array(input2, sizeof(input2) / sizeof(input2[0]));


    return 0;
}
