#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "list.h"

#define SIZE 100000

using namespace std;

void order(List<int, SIZE>&, List<int, SIZE>&, const int&);

int main() {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0,1000000);
    auto dice = bind(distribution,generator);

    List<int, SIZE> messyList;
    int value;

    for (int i(0); i < SIZE; i++) {
        value = dice();
        messyList.insertData(value, messyList.getLastPos());
        }

    List<int, SIZE> orderedList(messyList);

    cout << "Ordenamiento burbuja" << endl;
    order(messyList, orderedList, 1);
    cout << endl;

    cout << "Ordenamiento inserccion" << endl;
    order(messyList, orderedList, 2);
    cout << endl;

    cout << "Ordenamiento seleccion" << endl;
    order(messyList, orderedList, 3);
    cout << endl;

    cout << "Ordenamiento shell" << endl;
    order(messyList, orderedList, 4);
    cout << endl;

    cout << "Ordenamiento merge" << endl;
    order(messyList, orderedList, 5);
    cout << endl;

    cout << "Ordenamiento quick" << endl;
    order(messyList, orderedList, 6);
    cout << endl;

    return 0;
    }

void order(List<int, SIZE>& messyList, List<int, SIZE>& orderedList, const int& type) {
    cout << "Iniciando..." << endl;
    auto startTime = chrono::system_clock::now();
    switch (type) {
        case 1:
            orderedList.sortDataBubble();
            break;
        case 2:
            orderedList.sortDataInsert();
            break;
        case 3:
            orderedList.sortDataSelect();
            break;
        case 4:
            orderedList.sortDataShell();
            break;
        case 5:
            orderedList.sortDataMerge();
            break;
        case 6:
            orderedList.sortDataQuick();
            break;
        }
    auto endTime = chrono::system_clock::now();
    cout << "Finalizado..." << endl;
    orderedList = messyList;
    chrono::duration<double> duration = endTime - startTime;
    cout << "El proceso tardo " << duration.count() << " segundos" << endl;
    }
