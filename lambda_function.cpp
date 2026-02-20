// anonymous functions  
// often passed to another function/ algorithm 
#include <iostream>
using namespace std;

int main(){
    // below the "var_name" isn't the functions name we are 
    // assigning the function to a variable, auto automatically 
    // detects and assigns to it the required datatype, syntax - 
    // [capture] (parameters) { code };
    auto var_name = [] () {
        cout << "hello, world!" << endl;
    };

    var_name();

    int x = 10;
    // [] -> 'capture', it's used to use a variable that's out of the scope 
    // of the function 
    auto lambda_function = [x] () {
        cout << x << endl;
    };

    lambda_function();

    int y = 5;
    // 'capture by reference'
    auto lambda_function2 = [&y] () {
        cout << y << endl;
    };

    y = 10;
    lambda_function2();

    return 0;
}
