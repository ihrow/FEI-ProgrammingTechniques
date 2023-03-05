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
#include <list>
#include <vector>
#include <numeric>
#include <algorithm>
#include <initializer_list>

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati priemernu hodnotu prvkov vstupneho inicializacneho zoznamu.
    Ak inicializacny zoznam neobsahuje ziadne prvky, tak vyhodi vynimku typu 'std::invalid_argument',
    ktorej metoda 'what' vrati textovy retazec: "inicializacny zoznam je prazdny".

    Na vypocet sumy cisiel, v implementacii pouzite 'std::accumulate'.

    PARAMETER:
        [in] data - zoznam prvkov

    NAVRATOVA HODNOTA:
        Priemerna hodnota prvkov vstupneho inicializacneho zoznamu

    VYNIMKA:
        Ak je inicializacny zoznam prazdny, tak funkcia vyhodi vynimku typu 'std::invalid_argument',
        ktorej metoda 'what' vrati vysvetlujuci popis: "inicializacny zoznam je prazdny" (dodrzte presne tento textovy retazec! (ctrl+c, ctrl+v))
*/

double average(const initializer_list<int> & data) {
    if (data.size() == 0) throw invalid_argument("inicializacny zoznam je prazdny");
    return accumulate(data.begin(), data.end(), 0.0) / data.size();
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati iterator na 1. prvok zoznamu 'data' obsahujuci hodnotu 'value'.
    Pozor na pripad, ked 'data' obsahuje viac prvkov s hodnotou 'value'.

    V implementacii pouzite 'std::find'.

    PARAMETRE:
        [in] data - zoznam, v ktorom funkcia hlada 1. vyskyt hodnoty 'value'
        [in] value - hodnota hladaneho prvku

    NAVRATOVA HODNOTA:
        Ak 'data' obsahuje prvok s hodnotou 'value', tak vrati konstantny iterator na 1. takyto prvok.
        Inak vrati iterator za posledny prvok 'data' (iterator 'data.cend()')
*/

list<int>::const_iterator findValue(const list<int> & data, int value) noexcept {
    return find(data.cbegin(), data.cend(), value);
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati iterator na 1. prvok, ktoreho hodnota je v rozsahu <200, 400> (vratane 200 a 400).

    V implementacii pouzite funkciu 'std::find_if'.
    Pri jej volani pouzite ako jeden z argumentov funkciu 'isInRange200to400'.

    PARAMETER:
        [in] data - zoznam, v ktorom sa hlada 1. vyskyt hodnoty v rozsahu <200, 400>

    NAVRATOVA HODNOTA:
        Ak 'data' obsahuje prvok/prvky v rozsahu <200,400>, tak vrati iterator na 1. takyto prvok.
        Inak vrati iterator za posledny prvok (iterator 'data.cend()').
*/

bool isInRange200to400(const int element) noexcept {
    return element >= 200 && element <= 400;
}

list<int>::const_iterator findInRange200to400(const list<int> & data) noexcept {
    return find_if(data.cbegin(), data.cend(), isInRange200to400);
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia v zozname 'data' nahradi vsetky hodnoty v rozsahu <200, 400> (vratane 200 a 400), hodnotou 5.

    V implementacii pouzite funkciu 'std::replace_if'.
    Pri jej volani pouzite ako jeden z argumentov funkciu 'isInRange200to400' (definovanu v zadani predchadzajucej ulohy).

    PARAMETER:
        [in, out] data - zoznam, v ktorom funkcia nahradi vsetky hodnoty v rozsahu <200, 400>, hodnotou 5
*/

void replace200to400by5(list<int> & data) noexcept {
    for (auto it = data.begin(); it != data.end(); it++) {
        if (isInRange200to400(*it)) *it = 5;
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zvysi hodnotu kazdeho prvku vstupneho zoznamu o 1 (ku kazdej hodnote pripocita 1).

    V implementacii pouzite funkciu 'std::transform'.
    Pri jej volani pouzite ako jeden z argumentov funkciu 'increment'.

    PARAMETER:
        [in, out] data - zoznam, v ktorom funkcia zvysi hodnotu kazdeho prvku o 1
*/

int increment(int element) noexcept {
    return element + 1;
}

void incrementAll(list<int> & data) noexcept {
    transform(data.begin(), data.end(), data.begin(), increment);
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//----------------------------------------------------------------------------------------------
/*
    Vstupny zoznam obsahuje celkovy pocet bodov z predmetu, pre kazdeho studenta.
    Ak je pocet bodov teste pod hranicou na lepsiu znamku (do lepsej znamky chyba 1 bod),
    tak funkcia zvysi pocet bodov o 1.
    Inak funkcia nezmeni pocet bodov.

    V implementacii pouzite funkciu 'std::transform'.
    Pri jej volani pouzite ako jeden z argumentov  funkciu 'incrementPointsIfItHelps'.

    PARAMETER:
        [in, out] points - celkovy pocet bodov z predmetu pre kazdeho studenta
                           (niektore mozu byt po vykonani funkcie inkrementovane)

    PRIKLAD:
        vstup:  { 100, 90, 91, 92, 93, 53, 54, 55, 56, 57, 91, 92 }
        vystup: { 100, 90, 92, 92, 93, 53, 54, 56, 56, 57, 92, 92 }
                            ^                   ^           ^
*/

int incrementPointsIfItHelps(int points) noexcept {
    switch (points) {
        case 91 :
            return 92;
        case 82:
            return 83;
        case 73:
            return 74;
        case 64:
            return 65;
        case 55:
            return 56;
        default:
            return points;
    }
}

void helpAfterExam1(list<int> & points) noexcept {
    transform(points.begin(), points.end(), points.begin(), incrementPointsIfItHelps);
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//----------------------------------------------------------------------------------------------
/*
    Implementujte rovnaku funkcionalitu ako v predchadzajucej ulohe,
    ale namiesto 'std::transform' pouzite "range-based for" cyklus, v ktorom budete volat 'incrementPointsIfItHelps'.
*/

void helpAfterExam2(list<int> & points) noexcept {
    for (auto & point : points) {
        point = incrementPointsIfItHelps(point);
    }
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati novy zoznam, v ktorom hodnota kazdeho prvku je dana suctom prvkov v 'data1' a 'data2'
    s rovnakou poziciou.

    V implementacii pouzite 'std::transform'.
    Pri jej volani pouzite ako jeden z argumentov 'std::plus<int>()'.

    PARAMETRE:
        [in] data1 - obsahuje scitance
        [in] data2 - obsahuje scitance

    NAVRATOVA HODNOTA:
        Zoznam, v ktorom hodnota kazdeho prvku je suctom prvkov v 'data1' a 'data2' s rovnakou poziciou.

    VSTUPNA PODMIENKA:
        'data1' a 'data2' maju rovnaky pocet prvkov

    VYSTUPNA PODMENKA:
        Nech 'output' je vystupny zoznam.
        Pocet prvkov 'output' je rovnaky ako pocet prvkov 'data1' a 'data2'.
        Pre kazde i take, ze i >= 0 && i < data1.size() plati: output[i] = data1[i] + data2[i].

    PRIKLAD:
        vstup: data1 = { 2, 1, 1, 4, 5 }
               data2 = { 1, 0, 4, 6, 2 }
        vystup:        { 3, 1, 5,10, 7 }
*/

list<int> add(const list<int> & data1, const list<int> & data2) noexcept {
    list<int> output = data1;
    transform(data1.begin(), data1.end(), data2.begin(), output.begin(), plus<int>());
    return output;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky vektora od najvacsieho po najmensi.

    V implementacii pouzite 'std::sort' alebo 'std::stable_sort' s parametrom 'std::greater<int>()'.

    PARAMETER:
        [in, out] data - vektor, ktory funkcia usporiada
*/

void sort1(vector<int> & data) noexcept {
    sort(data.begin(), data.end(), greater<int>());
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky vektora od najvacsieho po najmensi.

    V implementacii pouzite 'std::sort' alebo 'std::stable_sort' s reverznymi iteratormi.

    PARAMETER:
        [in, out] data - vektor, ktory funkcia usporiada
*/

void sort2(vector<int> & data) noexcept {
    sort(data.rbegin(), data.rend());
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

void print(const list<int> & data) noexcept {
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {

    // tu mozete doplnit testovaci kod

    // TEST 1
    initializer_list<int> data11 = { 1, 2, 3, 4, 5 };
    initializer_list<int> data12 = { 17, 19, 23, 29, 31 };
    cout << "TEST 1" << endl << average(data11) << endl << average(data12) << endl << endl; // 3 23.8


    // TEST 2
    initializer_list<int> data2 = { 1, 2, 3, 4, 5, 6 };
    cout << "TEST 2" << endl << *(findValue(data2, 3)) << endl << *(findValue(data2, 0)) << endl; // 3 6

    // TEST 3
    list<int> data31 = { 1, 401, 400, 4, 5, 6 };
    list<int> data32 = { 1, 199, 200, 4, 5, 6 };
    list<int> data33 = { 1, 300, 3, 4, 5, 6 };
    cout << "TEST 3" << endl << *(findInRange200to400(data31)) << endl; // 400
    cout << *(findInRange200to400(data32)) << endl; // 200
    cout << *(findInRange200to400(data33)) << endl << endl; // 300

    // TEST 4
    list<int> data4 = { 199, 200, 201, 301, 1, 359, 4, 401, 5, 6, 400 };
    replace200to400by5(data4);
    cout << "TEST 4" << endl;
    print(data4); // 199 5 5 5 1 5 4 401 5 6 5
    cout << endl;

    // TEST 5
    list<int> data5 = { 1, 2, 3, 4, 5, 6 };
    incrementAll(data5);
    cout << "TEST 5" << endl;
    print(data5); // 2 3 4 5 6 7
    cout << endl;

    // TEST 6
    list<int> data6 = { 100, 90, 91, 92, 93, 53, 54, 55, 56, 57, 91, 92 };
    helpAfterExam1(data6);
    cout << "TEST 6" << endl;
    print(data6); // 100 90 92 92 93 53 54 56 56 57 92 92
    cout << endl;

    // TEST 7
    list<int> data7 = { 100, 90, 91, 92, 93, 53, 54, 55, 56, 57, 91, 92 };
    helpAfterExam2(data7);
    cout << "TEST 7" << endl;
    print(data7); // 100 90 92 92 93 53 54 56 56 57 92 92
    cout << endl;

    // TEST 8
    list<int> data81 = { 2, 1, 1, 4, 5 };
    list<int> data82 = { 1, 0, 4, 6, 2 };
    list<int> data8 = add(data81, data82);
    cout << "TEST 8" << endl;
    print(data8); // 3 1 5 10 7
    cout << endl;

    // TEST 9
    vector<int> data9 = { 1, 2, 3, 4, 5 };
    sort1(data9);
    cout << "TEST 9" << endl;
    for (int value : data9) {
        cout << value << " ";
    }
    cout << endl << endl; // 5 4 2 1 1

    // TEST 10
    vector<int> data10 = { 1, 2, 3, 4, 5 };
    sort2(data10);
    cout << "TEST 10" << endl;
    for (int value : data10) {
        cout << value << " ";
    }
    cout << endl << endl; // 5 4 2 1 1




    return 0;
}
