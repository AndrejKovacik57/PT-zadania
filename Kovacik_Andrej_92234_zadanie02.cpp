/*
Meno a priezvisko:

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie02.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnovali popis pri ich deklaraciach.
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

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};


//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na zaciatok zoznamu

    PRIKLADY:
        list={} a val=0 ... zoznam po vykonani funkcie ... {0}
        list={-3} a val=1 ... zoznam po vykonani funkcie ... {1,-3}
        list={6,6,6,8} a val=10 ... zoznam po vykonani funkcie ... {10,6,6,6,8}
*/


void prependNode(List* list, const int val) {
    // TODO
    Node *NewFirstNode = new Node();
    NewFirstNode->data=val;
    NewFirstNode->next = list->first;
    list->first = NewFirstNode;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na koniec zoznamu

    PRIKLADY:
        list={} a val=7 ... zoznam po vykonani funkcie ... {7}
        list={0} a val=1 ... zoznam po vykonani funkcie ... {0,1}
        list={1,2,3,4,5} a val=6 ... zoznam po vykonani funkcie ... {1,2,3,4,5,6}
*/

void appendNode(List* list, const int val) {

    if (list->first==nullptr) {
        list->first = new Node();
        list->first->data = val;
        list->first->next = nullptr;
    }
    else {
        Node *tmp = list->first;
        while (tmp->next!=nullptr) {
            tmp = tmp->next;
        }
        tmp->next =new Node();
        tmp->next->data = val;
        tmp->next->next = nullptr;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),
    ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.

    PARAMETRE:
        [in] data - vstupne pole cisiel
        [in] n - dlzka vstupneho pola

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci vsetky hodnoty zo vstupneho pola 'data' (v zachovanom poradi).
        V pripade prazdneho pola (dlzka 0), funkcia vrati prazdny zoznam (prazdny zoznam je taky, kde smernik 'first'
        ukazuje na 'nullptr'). V pripade neplatnej dlzky (ak je parameter 'n' zaporny), funkcia vrati 'nullptr'.

    PRIKLADY:
        data={1} a n=1 ... vrati zoznam ... {1}
        data={7,6,41,2} a n=4 ... vrati zoznam ... {7,6,41,2}
        data={3,2,1} a n=0 ... vrati zoznam ... {}
        data={6,3,9,10} a n=-7 ... vrati ... 'nullptr'
*/

List* createListFromArray(const int* data, const int n) {
    if(n<0){
        return nullptr;
    }
    else {
        if(n==0){
            List *list = new List();
            list->first = nullptr;
            return list;
        }
        else {
            List *list = new List();
            list->first = nullptr;
            for (int i = 0; i < n; i++) {
                appendNode(list, data[i]);
            }
            return list;
        }
    }
}
//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'. Symetricky zoznam ma
    tvar 0,1,2,...val...2,1,0.

    PARAMETRE:
        [in] val - hodnota uzla podla, ktoreho sa vytvori novy symetricky zretazeny zoznam (uzol v strede zoznamu).

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci prvky v takom poradi, aby bol symetricky. V pripade 'val'<0, funkcia vrati
        'nullptr'.

    PRIKLADY:
        val=-31 ... vrati ... nullptr
        val=0 ... vrati zoznam ... {0}
        val=1 ... vrati zoznam ... {0,1,0}
        val=2 ... vrati zoznam ... {0,1,2,1,0}
        val=3 ... vrati zoznam ... {0,1,2,3,2,1,0}
        val=4 ... vrati zoznam ... {0,1,2,3,4,3,2,1,0}
        val=6 ... vrati zoznam ... {0,1,2,3,4,5,6,5,4,3,2,1,0}
*/

List* createSymmetricList(const int val) {
    if(val<0){
        return nullptr;
    }

    else {
        if(val==0){
            List *list = new List();
            list->first= nullptr;
            appendNode(list,0);
            return list;
        }
        else{
            List *list = new List();
            list->first= nullptr;
            for (int i=0; i < val; i++) {
                appendNode(list, i);
            }

            for ( int i=val; i <= val*2; i++) {
                appendNode(list, (val*2)-i);
            }
            return list;
        }
    }


}


//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    RETURN:
        Result::SUCCESS, ak bol prvy uzol vymazany
        Result::FAILURE, ak nebol prvy uzol vymazany (vstupny zoznam bol prazdny)

    PRIKLADY:
        list={} ... funkcia vrati Result::FAILURE
        list={5} ... zoznam po vykonani funkcie ... {} a vrati Result::SUCCESS
        list={10,10,10} ... zoznam po vykonani funkcie ... {10,10} a vrati Result::SUCCESS
        list={3,2,1} ... zoznam po vykonani funkcie ... {2,1} a vrati Result::SUCCESS
*/

Result removeFirstNode(List* list) {
    if (list == nullptr) {
        return Result::FAILURE;
    }
    if (list->first == nullptr) {
        return Result::FAILURE;
    }
    Node *temp = list->first->next;
    delete list->first;
    list->first=temp;

    return Result::SUCCESS; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla, ktory sa hlada

    RETURN:
        Funkcia vrati prvy uzol, ktory obsahuje hodnotu 'val'. Ak sa taky uzol v zozname nenachadza alebo je vstupny
        zoznam prazdny, vtedy funkcia vrati 'nullptr'.

    PRIKLADY:
        list={}, val=10 ... funkcia vrati 'nullptr'
        list={2}, val=3 ... funkcia vrati 'nullptr'
        list={1,2,3,4,5,6}, val=-1 ... funkcia vrati 'nullptr'
        list={1}, val=1 ... funkcia vrati uzol s hodnotou 1
        list={5,9,18}, val=9 ... funkcia vrati uzol s hodnotou 9
*/

Node* findNodeInList(List* list, const int val) {
    if (val < 0) {
        return nullptr;
    }
    if (list == nullptr) {
        return nullptr;
    }


    Node *temp = list->first;
    while (temp) {
        if (temp->data == val) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;

}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
    rovnake hodnoty uzlov v rovnakom poradi).

    PARAMETRE:
        [in] list1 - prvy zretazeny zoznam
        [in] list2 - druhy zretazeny zoznam

    RETURN:
        'true' - ak su vstupne zoznamy rovnake
        'false' - ak vstupne zoznamy nie su rovnake

    PRIKLADY:
        list1={1}
        list2={}
        Funkcia vrati 'false'.

        list1={}
        list2={5,3}
        Funkcia vrati 'false'.

        list1={}
        list2={}
        Funkcia vrati 'true'.

        list1={1}
        list2={1}
        Funkcia vrati 'true'.

        list1={4,-9,2}
        list2={4,-9,2}
        Funkcia vrati 'true'.

        list1={3,2,1}
        list2={1,2,3}
        Funkcia vrati 'false'.

        list1={2}
        list2={7,4,5}
        Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
    if (list1 == nullptr) {
        return false;
    }
    if (list2 == nullptr) {
        return false;
    }
    Node *List1 = list1->first;
    Node *List2 = list2->first;

    while (List1 != nullptr || List2 != nullptr) {
        if ((List1 == nullptr && List2 != nullptr) || (List1 != nullptr && List2 == nullptr)) {
            return false;
        }

        if (List1->data != List2->data) {
            return false;
        }
        List1= List1->next;
        List2 = List2->next;
    }
    return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam prekopirovanim vsetkych hodnot uzlov vstupneho zoznamu 'list' v obratenom
    poradi.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam

    RETURN:
        Zretazeny oznam, ktory vznikne prekopirovanim hodnot uzlov vstupneho zoznamu 'list' v obratenom poradi.

    PRIKLADY:
        list={} ... funkcia vrati ... {} t.j. prazdny zoznam
        list={1} ... funkcia vrati ... {1}
        list={5,6} ... funkcia vrati ... {6,5}
        list={8,14,2,3} ... funkcia vrati ... {3,2,14,8}
*/

List* copyListReverse(List* list) {
    if (list == nullptr) {
        return nullptr;
    }
    if (list->first == nullptr) {
        return list;
    }

    List *NewList = new List();
    Node *OrigList = list->first;
    while (OrigList != nullptr) {
        prependNode(NewList, OrigList->data);
        OrigList= OrigList->next;
    }
    return NewList; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vyhlada predchodcu zadaneho uzla 'node' vo vstupnom zretazenom zozname 'list'. Uzol 'node' je vzdy
    existujucim uzlom vstupneho zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] node - uzol zretazeneho zoznamu 'list', ktoreho predchodcu hladame

    RETURN:
        Uzol, ktory je predchodcom uzla 'node' v zozname 'list'. V pripade hladania predchodcu prveho uzla zoznamu,
        funkcia vrati 'nullptr'.

    PRIKLADY:
        list={4}
        node=4
        Funkcia vrati 'nullptr'.

        list={1,2,3,4,5}
        node=1
        Funkcia vrati 'nullptr'.

        list={-2,-3,56,4,41}
        node=-3
        Funkcia vrati uzol s hodnotou -2.

        list={10,54,69,82,6}
        node=6
        Funkcia vrati uzol s hodnotou 82.
*/

Node* findPreviousNode(List* list, Node* node) {


    if (list == nullptr) {
        return nullptr;
    }
    if (node == nullptr) {
        return nullptr;
    }


    Node *temp = list->first;;
    while (temp != nullptr) {
        if (temp->next == node) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zduplikuje vsetky uzly vstupneho zoznamu 'list', ktore obsahuju kladnu hodnotu.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    PRIKLADY:
        list={} ... po vykonani funkcie ... {}
        list={3} ... po vykonani funkcie ... {3,3}
        list={-1,1} ... po vykonani funkcie ... {-1,1,1}
        list={-8,-9,-13} ... po vykonani funkcie ... {-8,-9,-13}
        list={1,0,-2,3,-4} ... po vykonani funkcie ... {1,1,0,-2,3,3,-4}
*/

void duplicatePositiveNodes(List* list) {
    if (list == nullptr) return;
    if (list->first == nullptr) return;

    Node *cur = list->first;
    while (cur != nullptr) {
        if (cur->data > 0) {
            Node *newNode = new Node();
            newNode->next = cur->next;
            newNode->data = cur->data;
            cur->next = newNode;
            cur = cur->next;
        }
        cur = cur->next;
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------
/*void printList(List *start) {
    if (start == nullptr) {
        cout << "List invalid!" << endl;
        return;
    }
    Node *current = start->first;
    cout << "{";
    while (current != nullptr) {
        if (current != start->first) cout << " ";
        cout << current->data;
        current = current->next;
    }
    cout << "}" << endl;
}

void printNode(Node *node) {
    if (node == nullptr) {
        cout << "nullptr" << endl;
        return;
    }
    cout << node->data << endl;
}

void printResult(Result res) {
    if (res == Result::SUCCESS) {
        cout << "SUCCESS" << endl;
    }
    else {
        cout << "FAILURE" << endl;
    }
}*/

// tu mozete doplnit pomocne funkcie a struktury

int main(int argc, char** argv) {
    /*const int data[] = {1,0,-2,3,-4};
    List *z = createListFromArray(data,5)*/

    /*
    3.
    PRIKLADY:
    data={1} a n=1 ... vrati zoznam ... {1}
    data={7,6,41,2} a n=4 ... vrati zoznam ... {7,6,41,2}
    data={3,2,1} a n=0 ... vrati zoznam ... {}
    data={6,3,9,10} a n=-7 ... vrati ... 'nullptr'*/
    /*
    printList(z);*/
//----------------------------------------------------------------------------------------------------------------------
    /*
    4.
    PRIKLADY:
    val=-31 ... vrati ... nullptr
    val=0 ... vrati zoznam ... {0}
    val=1 ... vrati zoznam ... {0,1,0}
    val=2 ... vrati zoznam ... {0,1,2,1,0}
    val=3 ... vrati zoznam ... {0,1,2,3,2,1,0}
    val=4 ... vrati zoznam ... {0,1,2,3,4,3,2,1,0}
    val=6 ... vrati zoznam ... {0,1,2,3,4,5,6,5,4,3,2,1,0}*/
    /*
    List *z2 = createSymmetricList(3);
    printList(z2);*/
//----------------------------------------------------------------------------------------------------------------------
    /*
    5.
    PRIKLADY:
    list={} ... funkcia vrati Result::FAILURE
    list={5} ... zoznam po vykonani funkcie ... {} a vrati Result::SUCCESS
    list={10,10,10} ... zoznam po vykonani funkcie ... {10,10} a vrati Result::SUCCESS
    list={3,2,1} ... zoznam po vykonani funkcie ... {2,1} a vrati Result::SUCCESS */
    /*

    Result r1 = removeFirstNode(z);
    printResult(r1);
    printList(z);*/
//----------------------------------------------------------------------------------------------------------------------
    /*
    6.
    PRIKLADY:
    list={}, val=10 ... funkcia vrati 'nullptr'
    list={2}, val=3 ... funkcia vrati 'nullptr'
    list={1,2,3,4,5,6}, val=-1 ... funkcia vrati 'nullptr'
    list={1}, val=1 ... funkcia vrati uzol s hodnotou 1
    list={5,9,18}, val=9 ... funkcia vrati uzol s hodnotou 9*/

    //printNode(findNodeInList(z, 9));
//----------------------------------------------------------------------------------------------------------------------
    /*
    5.
    PRIKLADY:
        list1={1}
        list2={}
        Funkcia vrati 'false'.

        list1={}
        list2={5,3}
        Funkcia vrati 'false'.

        list1={}
        list2={}
        Funkcia vrati 'true'.

        list1={1}
        list2={1}
        Funkcia vrati 'true'.

        list1={4,-9,2}
        list2={4,-9,2}
        Funkcia vrati 'true'.

        list1={3,2,1}
        list2={1,2,3}
        Funkcia vrati 'false'.

        list1={2}
        list2={7,4,5}
        Funkcia vrati 'false'. */
    /*const int data2[] = {2};
    List *l1 = createListFromArray(data2,1);
    const int data3[] = {7,4,5};
    List *l2 = createListFromArray(data3,3);
    cout << "Are lists equal?: " << areListsEqual(l1,l2) << endl;
    printList(l1);
    printList(l2);*/
//----------------------------------------------------------------------------------------------------------------------
    /*
    8.
    PRIKLADY:
    list={} ... funkcia vrati ... {} t.j. prazdny zoznam
    list={1} ... funkcia vrati ... {1}
    list={5,6} ... funkcia vrati ... {6,5}
    list={8,14,2,3} ... funkcia vrati ... {3,2,14,8}*/
    /*printList(z);
    printList(copyListReverse(z))*/;
//----------------------------------------------------------------------------------------------------------------------
    /*
    9.
    PRIKLADY:
        list={4}
        node=4
        Funkcia vrati 'nullptr'.

        list={1,2,3,4,5}
        node=1
        Funkcia vrati 'nullptr'.

        list={-2,-3,56,4,41}
        node=-3
        Funkcia vrati uzol s hodnotou -2.

        list={10,54,69,82,6}
        node=6
        Funkcia vrati uzol s hodnotou 82.*/

    //printNode(findPreviousNode(z, z->first));
//----------------------------------------------------------------------------------------------------------------------
    /*
    10.
    PRIKLADY:
    list={} ... po vykonani funkcie ... {}
    list={3} ... po vykonani funkcie ... {3,3}
    list={-1,1} ... po vykonani funkcie ... {-1,1,1}
    list={-8,-9,-13} ... po vykonani funkcie ... {-8,-9,-13}
    list={1,0,-2,3,-4} ... po vykonani funkcie ... {1,1,0,-2,3,3,-4}*/

    /*duplicatePositiveNodes(z);
    printList(z);*/

return 0;
}