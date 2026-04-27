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
        cout << "\nTime " << i+1;
        for (int j = 0; j < LANES; j++){
            int n = rand() % 100;
            string op;
            string car;
            cout << "Lane " << j+1 << ": ";
            if (n < JOIN ) {
                lanes[j].push_back(Car());
                op = "Joined lane";
                lanes[j].back().print();
            }
            else {
                if (lanes[j].empty()){
                    cout << 
                }
                op = "Car paid";
                lanes[j].front().print();
                lanes[j].pop_front();
            }
            cout << op << ": ";
        }
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

/*void add_Car(deque<deque<Car>> &l){
    // pushing new car to the deque
    Car n = Car();
    l.push_back(n);
}*/

void print_q(deque<deque<Car>> &l){
    for (int j = 0; j < LANES; j++){
        cout << "LANE " << j+1 << ": \n";
        for (int i = 0; i < l[j].size(); i++){
            cout << "\t";
            if (l[j].empty()){
                cout << "empty\n";
                break;
            }
            l[j][i].print();
        }
    }
}


 