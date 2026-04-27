#include "Car.h"
#include <deque>
#include <string>
using namespace std;

const int SWITCH = 15;
const int JOIN = 39;
const int PAY = 46;
const int INITIAL_SIZE = 2;
const int LANES = 4;

void add_Car(deque<deque<Car>> &);
void print_q(deque<deque<Car>> &);

int main(){
    srand(time(0));

    //declare dequeue for the lanes 
    deque<deque<Car>> lanes(LANES);

    cout << "Initial Queue:\n";
    print_q(line);

    int i = 0;
    while (!line.empty()){
        // random number between 0-100
        int n = rand() % 100;
        string op;
        string car;
        cout << "\nTime " << i + 1;
        
        if (n < 45 ) {
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
        if (line.empty()){
            cout << "Queue:\n\tEmpty";
            break;
        }
        cout << "Queue:\n";
        print_q(line);
        i++;
    }


    return 0;
}

void add_Car(deque<deque<Car>> &l){
    // pushing new car to the deque
    Car n = Car();
    l.push_back(n);
}

void print_q(deque<deque<Car>> &l){
    for (int i = 0; i < l.size(); i++){
        cout << "\t";
        l[i].print();
    }
}


 