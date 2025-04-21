#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <numeric>   // for std::accumulate
using namespace std;

int main() {
    // Declare a vector to store daily sales.
    std::vector<int> dailySales;
    
    // TO-DO: Add seven daily sales values to the vector: 
    //         120, 200, 150, 80, 90, 220, 100
    dailySales.push_back(120);
    dailySales.push_back(200);
    dailySales.push_back(150);
    dailySales.push_back(80);
    dailySales.push_back(90);
    dailySales.push_back(220);
    dailySales.push_back(100);


    // TO-DO: Print all sales values by using an iterator
    int total = 0;
    for(auto i : dailySales){
        cout << i << endl;
        total += i;
    }
    cout << endl;

    
    // TO-DO: Calculate the average of the sales values and print it
    cout << total/dailySales.size() << endl;
    cout << endl;

    

    // TO-DO: Sort the vector in ascending order using std::sort.
    sort(dailySales.begin(), dailySales.end());

    
    // TO-DO: Print all the sorted sales values by using an iterator
    for(auto i : dailySales){
        cout << i << endl;
    }
    
    
    return 0;
}
