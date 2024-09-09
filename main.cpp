#include <iostream>
#include "priorityqueue.h"
#include "dynamicpriorityqueue.h"

using namespace std;

int main()
{
    dynamicpriorityqueue *pq = new dynamicpriorityqueue();
    
    char op;
    int value;
    int priority;
    
    do 
    {
        cout << "OP (e: enqueue, d: dequeue, p: print, h: peek, u: update, s: size, c: clear, a: average, x: exit): ";
        cin >> op;
        
        switch(op)
        {
            case 'e':
                cout << "Enter value and priority: ";
                cin >> value >> priority;
                pq->enqueue(value, priority);
                break;
            
            case 'd':
                if (pq->getSize() > 0)
                    cout << "Dequeued: " << pq->dequeueHighestPriority() << endl;
                else
                    cout << "Queue is empty." << endl;
                break;
                
            case 'p':
            	pq->printQueue();
            	break;
            	
            case 'h':
                if (pq->getSize() > 0)
                        cout << "Highest Priority Element: " << pq->peekHighestPriority() << endl;
                else
                        cout << "Queue is empty." << endl;
                break;
                
            case 'u':
                cout << "Enter value and new priority: ";
                cin >> value >> priority;
                pq->updatePriority(value, priority);
                break;
                
            case 's':
                cout << "Size: " << pq->getSize() << endl;
                break;
                
            case 'c':
                pq->clear();
                cout << "Queue cleared" << endl;
                break;
                
            case 'a':
                cout << "Average priority: " << pq->getAveragePriority() << endl;
                break;
                
            case 'x':
                cout << "Exiting..." << endl;
                return 0;
                
            default:
                cout << "Invalid operation" << endl;
        }
        
    } while (op != 'x');
    
    return 0;
}
