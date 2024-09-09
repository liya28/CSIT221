#include "priorityqueue.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class dynamicpriorityqueue : public priorityqueue
{
    private:
        Elements *arr;
        int capacity;
        int size;
        
        int findIndex(int value)
        {
            for (int i = 0; i < size; i++)
            {
            	if (arr[i].num == value)
            	{
            		return i;
				}
			}
			
			return -1;
        }
        
        void resizeUp()
        {
            capacity = capacity + ceil(capacity * 0.75);
            Elements *new_arr = new Elements[capacity];
            for (int i = 0; i < size; i++)
            {
            	new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
        }
        
        void resizeDown()
        {
        	capacity = capacity - floor(capacity * 0.25);
            Elements *new_arr = new Elements[capacity];
            for (int i = 0; i < size; i++)
            {
            	new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr; 
		}
        
        void shiftElementRight(int index)
        {
            for (int i = size; i > index; i--)
            {
            	arr[i] = arr[i - 1];
			}
        }
        
        void shiftElementLeft(int index)
        {
            for (int i = index; i < size - 1; i++)
            {
            	arr[i] = arr[i + 1];
			}
        }
        
        void reorder()
        {
            for (int i = 0; i < size - 1; i++)
            {
            	if (arr[i].priority > arr[i + 1].priority)
            	{
            		swap(arr[i], arr[i + 1]);
				}
			}
        }
    
    public:
        
        dynamicpriorityqueue() : capacity(8), size(0)
        {
            arr = new Elements[capacity];
        }
        
        ~dynamicpriorityqueue()
        {
            delete[] arr;
        }
        
        void enqueue(int value, int priority)
        {
            if (size == capacity)
            {
            	resizeUp();
			}
			
			int i = 0;
			while (i < size && arr[i].priority >= priority)
			{
				++i;
			}
			
			shiftElementRight(i);
			
			size++;
			
			arr[i].num = value;
			arr[i].priority = priority;
        }
        
        int dequeueHighestPriority() 
        {
            int top = arr[0].num;
            shiftElementLeft(0);
            size--;
            
            if (size < (capacity / 3.0))
            {
            	resizeDown();
			}
			
            return top;
        }
        
        int peekHighestPriority() 
        {
            return arr[0].num;
        }
        
        void updatePriority(int value, int new_priority) 
        {
            int index = findIndex(value);
            if (index == -1) cout << "Value not found." << endl; return;
            
            arr[index].priority = new_priority;
            reorder();
        }
        
        int getSize()
        {
            return size;
        }
        
        void clear()
        {
        	size = 0;
        }
        
        double getAveragePriority()
        {
            double sum = 0.0;
            for (int i = 0; i < size; i++)
            {
            	sum += arr[i].priority;
			}
			
			return sum / size;
        }
        
        void printQueue()
        {
        	cout << "QUEUE\n";
        	cout << "SIZE: " << size << "/" << capacity << endl;
            cout << "ELEMENTS\n";
            for (int i = 0; i < size; i++)
            {
            	cout << "Value " << (i + 1) << ": " << arr[i].num << " - " << arr[i].priority << endl;           	
			}
        }
};
