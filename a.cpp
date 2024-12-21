#include <iostream>

using namespace std;

class Passenger 
{
public:
    double time; 
    Passenger* next;
};

class Taxi 
{
public:
    double time; 
    int count; 
    Taxi* next; 
};

class classs 
{
private:
    double time1;
    double time2; 
    bool type; 
    int max; 
    Passenger* queue;
    Taxi* taxiqueue; 

public:

    void function(double time) 
    {
        Passenger* newPassenger = new Passenger{ time };
        if (!queue) 
        {
            queue = newPassenger;
        }
        else 
        {
            Passenger* temp = queue;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newPassenger;
        }
    }

    void function2(double time, int biba) 
    {
        Taxi* neww = new Taxi{ time, biba };
        if (!taxiqueue) 
        {
            taxiqueue = neww;
        }
        else {
            Taxi* temp = taxiqueue;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = neww;
        }
    }

    void function3(double duration) 
    {
        double time = 0.0;
        double next = 0.0;
        double nexttaxi = 0.0;

        while (time < duration) 
        {
            
            if (time >= next) 
            {
                function(time);
                next += time1;
            }

         
            if (time >= nexttaxi)
            {
                int gig = rand() % 5 + 1;
                function2(time, gig);
                nexttaxi += time2;
            }

            if (taxiqueue && queue) 
            {
                Taxi* taxi = taxiqueue;
                taxiqueue = taxiqueue->next;

                int number = taxi->count;
                while (number > 0 && queue) 
                {
                    Passenger* passenger = queue;
                    queue = queue->next;
                    number--;
                    delete passenger;
                }
                delete taxi;
            }

            time += 1;
        }


        while (queue) 
        {
            Passenger* temp = queue;
            queue = queue->next;
            delete temp;
        }
        while (taxiqueue) 
        {
            Taxi* temp = taxiqueue;
            taxiqueue = taxiqueue->next;
            delete temp;
        }
    }
};

