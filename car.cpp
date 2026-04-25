#include "Car.h"
#include <deque>
#include <string>
using namespace std;

void add_Car(deque<Car> &);
void print_q(deque<Car> &);

int main(){
    // declare dequeue
    deque<Car> line(2);
    cout << "Initial Queue:\n";

    for (int i = 0; i < 6; i++){
        //generating random number to decide if adding or removing
        int n = rand() % (101);
        string op;
        string car;
        cout << "Time" << i + 1;
        if (n <= 45 ) {
            add_Car(line);
            op = "Joined lane";
            cout << " Operation: " << op << ": ";
            line.back().print();
        }
        else{
            op = "Car paid";
            cout << " Operation: " << op << ": ";
            line.front().print();
            line.pop_front();
        }
    }


    return 0;
}

void add_Car(deque<Car> &l){
    // pushing new car to the deque
    Car n = Car();
    l.push_back(n);
}


 