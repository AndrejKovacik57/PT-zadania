/*
Meno a priezvisko:

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie03.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
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
    Usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}
*/

void insertionSort(int *data, const size_t length) {
    for(size_t i = 1; i < length; i++ ) { // 'i' oznacuje hranicu usporiadanej casti pola
        int current = data[i];
        size_t j = i;
        while(j > 0 && data[j-1] <current) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = current;
    }
}


//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
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
        {"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
        {"Juraj", "Anabela", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", "Anabela", nullptr}
        {"Andrej", nullptr} -> {"Andrej", nullptr}
        {nullptr} -> {nullptr}

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/

void insertionSort(const char *data[]) {
    if(data[0]==nullptr){
        return;
    }
    for(size_t i = 1; data[i] != nullptr; i++ ) { // 'i' oznacuje hranicu usporiadanej casti pola
        const char *current=data[i];
        size_t j = i;
        while(j > 0 && strcmp(data[j-1],current) < 0){
            data[j] = data[j-1];
            j--;
        }
        data[j] = current;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3, vystup: 3->2->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/


void insertionSortHelper(struct Node** head_ref, struct Node* new_node)
{
    // TODO
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data <= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data > new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(List * list) {
    // TODO
    struct Node *sorted = NULL;
    struct Node *current = list->first;;

    while (current != NULL)
    {
        struct Node *next = current->next;
        insertionSortHelper(&sorted, current);
        current = next;
    }

    list->first = sorted;
}
//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
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
        Obsah 'input' sa nemeni.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli)
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli)

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         {10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10}
        output pred vykonanim funkcie: {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20}
        output po vykonani funkcie:    {20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20}
*/

void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high)
{
    size_t first = low;     // index prvku v lavej  casti vstupneho pola, ktory sa bude porovnavat
    size_t second = middle; // index prvku v pravej casti vstupneho pola, ktory sa bude porovnavat
    size_t out = low;       // index do vystupneho pola kam sa bude kopirovat mensi z prvkov input[first] a input[second]

    // do casti vystupneho pola sa skopiruju prvky s casti vstupneho pola tak, aby boli usporiadane
    while (first < middle && second < high) {
        if (input[first] >= input[second]) { // stabilne triedenie
            output[out] = input[first];
            ++first;
        }
        else {
            output[out] = input[second];
            ++second;
        }
        ++out;
    }
    while (first < middle) {
        output[out] = input[first];
        ++first;
        ++out;
    }
    while (second < high) {
        output[out] = input[second];
        ++second;
        ++out;
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        {1,3,2} -> {3, 2, 1}
        {1} -> {1}
        {} -> {}

    POZNAMKA:
        Pri implementacii top-down bude vhodne vytvorit a zavolat rekurzivnu funkciu.
*/
void swapPointers(int **a, int **b)
{
    int *c = (*a);
    (*a) = (*b);
    (*b) = c;
}

void mergeSort(int *data, const size_t length) {
    // TODO
    int* tmpArray = new int [length];

    int * input = data;
    int * output = tmpArray;
    bool needCopyToOrigin = false;
    for (size_t step = 1; step < length; step *= 2) {
        for (size_t i = 0; i < length; i += 2 * step) {
            size_t low = i;
            size_t middle = min(i + step, length);
            size_t high = min(i + 2 * step, length);
            merge(output, input, low, middle, high);
        }
        swapPointers(&input, &output);
        needCopyToOrigin = ! needCopyToOrigin;
    }

    if (needCopyToOrigin) {
        memcpy(data, tmpArray, length * sizeof(int));
    }

    delete[] tmpArray;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------
void printArray(const int *data, int length) {
    // TODO
    cout << "(";
    for (int i = 0; i < length; i++) {
        if (i != 0) cout << " ";
        cout << data[i];
    }
    cout << ")" << endl;
}

void printArrayStr(const char *data[]) {
    // TODO
    cout << "(";
    int i = 0;
    const char *key = data[i];
    while (key) {
        if (i != 0) cout << " <|> ";
        cout << data[i];
        i++;
        key = data[i];
    }

    if (key == nullptr) {
        if (i > 0) cout << " <|> ";
        cout << "NULLPOINTER";
    }

    cout << ")" << endl;
}

void printList(List *start) {
    if (start == nullptr) {
        cout << "List invalid!" << endl;
        return;
    }
    Node *cur = start->first;
    cout << "{";
    while (cur != nullptr) {
        if (cur != start->first) cout << " ";
        cout << cur->data;
        cur = cur->next;
    }
    cout << "}" << endl;
}

void prependNode(List* list, int val) {
    // TODO
    Node *first = list->first;
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = first;
    list->first = newNode;
}
// tu mozete doplnit pomocne funkcie a struktury

int main() {
    /*int data[] = {1,3,2};
    printArray(data, 3);

    insertionSort(data, 3);
    printArray(data, 3);*/

    /*const char *data2[] = {"Andrej",nullptr};
    printArrayStr(data2);
    insertionSort(data2);
    printArrayStr(data2);*/

    /*List *list1 = new List();

    prependNode(list1, 9);
    prependNode(list1, 8);
    prependNode(list1, 7);
    prependNode(list1, 6);
    prependNode(list1, 5);
    prependNode(list1, 4);
    prependNode(list1, 3);
    prependNode(list1, 2);
    prependNode(list1, 1);
    printList(list1);

    insertionSort(list1);
    printList(list1);*/
    //low: 4
    //middle: 8
   // hight: 12
   /* int data3[]  = {1,3,2};
    printArray(data3, 3);

    mergeSort(data3, 3);
    printArray(data3, 3);*/
    return 0;
}