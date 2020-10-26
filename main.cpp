#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "list.h"

using namespace std;

int main()
{
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0,1000000);
    auto dice = bind(distribution,generator);

    List<int, 100000> messyList;
    int value;

    for (int i(0); i < 100000; i++) {
        value = dice();
        messyList.insertData(value, i - 1);
    }

    List<int, 100000> orderedList(messyList);

    cout << "Ordenamiento burbuja" << endl;
    cout << "Iniciando..." << endl;
    auto startTime = chrono::system_clock::now();
    orderedList.sortDataInsert();
    auto endTime = chrono::system_clock::now();
    cout << "Finalizado..." << endl;
    chrono::duration<double> duration = endTime-startTime;
    cout << "El proceso tardo " << duration.count() << " segundos" << endl;

    cout << endl << endl;

    return 0;
}
