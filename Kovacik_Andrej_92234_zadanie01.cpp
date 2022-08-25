/*
Meno a priezvisko:

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_zadanie01.cpp (pouzite vase udaje bez diakritiky).
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
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Bod v rovine
struct Point {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Usecka v rovine
struct Line {
    Point start; // zaciatocny bod
    Point end;   // koncovy bod
};

// Student
struct Student {
    char* name; // meno studenta
    int year;   // rocnik studia
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

// Matematicka funkcia
enum class Operation {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};

// Vstup pre matematicky vypocet funkcie s dvoma parametrami
struct CalculationInput {
    int operand1; // prvy parameter
    int operand2; // druhy parameter
    Operation operation; // funkcia
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytlaci obsah pola na standardny vystup.
    V implementacii musi byt pouzity 'std::cout'.

    Format tlace:
    - prvky pola (cisla) su oddelene jednou medzerou
    - pred prvym prvkom je gulata otvaracia zatvorka (medzi zatvorkou a cislom nesmie byt medzera)
    - za poslednym prvkom je gulata zatvaracia zatvorka (medzi cislom a zatvorkou nesmie byt medzera)

    PARAMETRE:
        [in] data   - pole cisiel
        [in] length - dlzka pola 'data'

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        prazdne pole: ()
        jednoprvkove pole: (10)
        2 prvkove pole:    (10 20)
        10 prvkove pole:   (8 -5 100000 2 1 2 4 5 -20 345)
*/
void printArray(const int* data, size_t length) {
    // TODO (pouzite std::cout)
    std::cout << "(";

    for (size_t i = 0; i < length; i++) {
        if (i > 0 && i < length) {
            std::cout <<" ";
        }
        std::cout << data[i];
    }
    std::cout << ")";
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Zo standardneho vstupu nacita dve cele cisla (typu 'int') a vrati ich sucet.
    V implementacii musi byt pouzity 'std::cin'.

    NAVRATOVA HODNOTA:
        sucet cisiel nacitanych zo standardneho vstupu

    VSTUPNE PODMIENKY:
        Textovy vstup zadany na standardny vstup programu obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov zadanych na standardny vstup.

    PRIKLADY:
        Ak je na standardny vstup zadany text "10 20\n" (bez uvodzoviek), tak funkcia vrati 30.
        Ak je na standardny vstup zadany text " 10 \n 20 \n" (bez uvodzoviek), tak funkcia vrati 30.
*/
int sumOfTwoNumbersFromConsole() {
    // TODO (pouzite std::cin)
    int a, b;
    std::cin >> a >> b ;
    return a+b;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'text' obsahuje velke pismeno, inak vrati 'false'.

    PARAMETER:
        [in] text - textovy retazec ukonceny '\0'

    NAVRATOVA HODNOTA:
        'true'  - ak 'text' obsahuje aspon jedno velke pismeno
        'false' - ak 'text' neobsahuje ani jedno velke pismeno (plati aj pre prazdny retazec)

    POZNAMKA:
        Pri implementacii pouzite funkciu 'std::isupper'.
*/
bool containsUpperCase(const char* text) {
    for (size_t i = 0; text[i] != '\0'; i++) {
        if(isupper(text[i])){
            return true;
        }
    }
    return false;
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'data' obsahuje stupajucu postupnost, inak vrati 'false'.

    PARAMETRE:
        [in] data   - pole hodnot
        [in] length - pocet prvkov pola 'data'

    NAVRATOVA HODNOTA:
        'true' - ak 'data' obsahuje stupajucu postupnost hodnot, alebo pocet prvkov pola je mensi ako 2
        'false' - v opacnom pripade

    PRIKLADY:
        data = {10, 11, 15, 20} => vysledok je 'true'
        data = {10, 15, 15, 20} => vysledok je 'false'
        data = {10, 11, 15, 12} => vysledok je 'false'
        data = {10}             => vysledok je 'true'
        data = {}               => vysledok je 'true'
*/
bool isAscending(const int* data, size_t length) {
    // TODO
    int lastnumber=data[0];
    for (size_t i=1; i < length; i++) {
        if (data[i] <= lastnumber) {
            return false;
        }
        lastnumber = data[i];
    }
    return true;
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Posunie hodnoty pola 'data' o 1 miesto vyssie. Hodnotu posledneho prvku presunie na zaciatok.

    PARAMETRE:
        [in,out] data - pole hodnot, ktore bude preusporiadane
        [in] length   - pocet prvkov pola 'data'

    PRIKLADY:
        {10, 20, 30, 40, 50} => {50, 10, 20, 30, 40}
        {10} => {10}
        {} => {}
*/
void shiftUp(int* data, size_t length) {
    int temp = data[length - 1];

    for(int i = length - 2; i >= 0; i--) {
        data[i + 1] = data[i];

    }
    data[0] = temp;
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Preusporiada pole 'data' tak, ze jeho prvky budu v opacnom poradi.

    PARAMETRE:
        [in, out] data - pole hodnot, ktore bude preusporiadane
        [in] lenght    - pocet prvkov pola 'data'

    PRIKLADY:
        {10, 20, 30, 40, 50} => {50, 40, 30, 20, 10}
        {10, 20, 30, 40} => {40, 30, 20, 10}
        {10} => {10}
        {} => {}
*/
void reverse(int* data, size_t length) {
    int x = length - 1;
    int number;
    for (size_t i = 0; i < length/2; i++) {
        number = data[i];
        data[i] = data[x];
        data[x] = number;
        x--;
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati dlzku usecky 'line'

    PARAMETER:
        [in] line - usecka

    NAVRATOVA HODNOTA:
        dlzka usecky 'line'

    PRIKLAD:
        line:
            start:
                x = 10
                y = 20
            end:
                x = 100
                y = 50
        return 94.868329805
*/
double length(const Line* line) {
    int x,y;
    x = line->end.x - line->start.x;
    y = line->end.y - line->start.y;

    return sqrt((x*x)+(y*y));
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vrati dlzku usecky 'line'

    PARAMETER:
        [in] line - usecka

    NAVRATOVA HODNOTA:
        dlzka usecky 'line'

    PRIKLAD:
        line:
            start:
                x = 10
                y = 20
            end:
                x = 100
                y = 50
        return 94.868329805
*/
double length(const Line& line) {
    // TODO
    int x, y;
    x = line.end.x - line.start.x;
    y = line.end.y - line.start.y;

    return sqrt((x * x) + (y * y));
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvori noveho studenta s menom 'name' a rocnikom studia 'year'.
    Vrati smernik na vytvoreneho studenta.

    PARAMETRE:
        [in] name - meno studenta (textovy retazec ukonceny '\0')
        [in] year - rocnik v ktorom student studuje

    NAVRATOVA HODNOTA:
        vytvoreny student
*/
Student* createStudent(const char* name, int year) {
    // TODO
    Student* newstudent=new Student;
    newstudent->name = new char[strlen(name)];
    strcpy(newstudent->name, name);
    newstudent->year = year;
    return newstudent; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vypocita celociselny matematicky vypocet zadany parametrom 'input'.
    Vysledok ulozi do 'output'.

    PARAMETRE:
        [in] input   - vstupne udaje pre matematicky vypocet
        [out] output - vystupna hodnota vypoctu (v pripade moznosti vypoctu)

    NAVRATOVA HODNOTA:
        Result::SUCCESS - ak je mozne vypocitat vyslednu hodnotu
        Result::FAILURE - ak nie je mozne vypocitat vyslednu hodnotu (v pripade delenia nulou)

    VYSTUPNE PODMIENKY:
        - Vysledok vypoctu je celociselny.
        - Ak je mozne vykonat vypocet, tak sa vysledok ulozi do 'output' a funkcia vrati 'Result::SUCCESS',
          inak (v pripade delenia nulou) sa hodnota 'output' nemeni a funkcia vrati 'Result::FAILURE'.
*/
Result calculate(int* output, const CalculationInput* input) {
    Operation currentoperation = input->operation;
    if (currentoperation == Operation::PLUS) {
        *output = input->operand1 + input->operand2;
    }

    else if (currentoperation == Operation::MINUS){
        *output = input->operand1 - input->operand2;
    }

    else if (currentoperation == Operation::MULTIPLY) {
        *output = input->operand1 * input->operand2;
    }

    else if (currentoperation == Operation::DIVIDE) {
        if (input->operand2 == 0) {
            return  Result::FAILURE;
        }

        else {
            *output = input->operand1 / input->operand2;
        }

    }
    else {
        return Result::FAILURE;
    }
    return Result::SUCCESS; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main(int argc, char** argv) {

    // #1
   /*
    const int data[] = {1,2,3,4,5,6};
    printArray(data, (sizeof(data)/sizeof(*data)));*/

    // #2
    /*
    cout << sumOfTwoNumbersFromConsole();*/

    // #3

    //const char text[] = "aaEaa";
    //cout << containsUpperCase(text);*/

    // #4
    //const int data2[] = {1,2,3,4,2,5};
    //cout << isAscending(data2, (sizeof(data2)/sizeof(*data2)));*/

    // #5
    //int data3[] = {};
    //shiftUp(data3, (sizeof(data3)/sizeof(*data3)));
    //printArray(data3, (sizeof(data3)/sizeof(*data3)));

    // #6
    //int data4[] = {};
    //reverse(data4, (sizeof(data4)/sizeof(*data4)));
    //printArray(data4, (sizeof(data4)/sizeof(*data4)));

    // #7 & #8
    //Point point1;
    //point1.x = 10;
    //point1.y = 20;

   // Point point2;
   // point2.x = 100;
   //point2.y = 50;

    //Line line1;
    //line1.start = point1;
    //line1.end = point2;

    //cout << length(line1);
    //9
    //Student *student1 = createStudent("Janko Mrkvicka", 22);
    //cout << student1->name << " " << student1->year << endl;
    //delete student1->name;
    //delete student1;
    return 0;
}

