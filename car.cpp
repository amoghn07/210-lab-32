#include "Car.h"
#include <deque>
#include <string>
using namespace std;

const int SWITCH = 15;
const int JOIN = 50;
const int PAY = 50;
const int INITIAL_SIZE = 2;
const int LANES = 4;

void add_Car(deque<deque<Car>> &);
void print_q(deque<deque<Car>> &);

int main(){
    srand(time(0));

    //declare dequeue for the lanes 
    deque<deque<Car>> lanes(LANES);

    //populating deque with 2 intial cars per lane with nested for loop
    for (int i = 0; i < LANES; i++){
        for(int j = 0; j < INITIAL_SIZE; j++){
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial Queue:\n";
    print_q(lanes);

    for (int i = 0; i < 20; i++){
        cout << "\nTime " << i+1 << ":\n";
        for (int j = 0; j < LANES; j++){
            int n = rand() % 100;
            string op;
            cout << "LANE " << j+1 << ": ";
            if (n < JOIN ) {
                lanes[j].push_back(Car());
                op = "Joined lane";
                cout << op << ": ";
                lanes[j].back().print();
            }
            else {
                if (lanes[j].empty()){
                    cout << "No operation\n";
                    continue;
                }
                op = "Car paid";
                cout << op << ": ";
                lanes[j].front().print();
                lanes[j].pop_front();
            }
            cout << endl;
        }
        print_q(lanes);
    }   
    /*while (!line.empty()){
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
    }*/


    return 0;
}

void print_q(deque<deque<Car>> &l){
    for (int j = 0; j < LANES; j++){
        cout << "LANE " << j+1 << " QUEUE: \n";
        if (l[j].empty()){
            cout << "\tempty\n";
            continue;
        }
        for (int i = 0; i < l[j].size(); i++){
            cout << "\t";
            l[j][i].print();
        }
    }
}


 