#include <iostream>
#include <thread>

using namespace std;

// dummy function
void foo(int Z){
    for(int i = 0; i < Z; i++){
        cout << "Thread using function pointer as callable "<< endl;    
    }
}

// thread_obj
class thread_obj{
public:
    void operator()(int x){
        for(int i = 0; i < x ; i++){
            cout << "Thread using function object as callable "<< endl;    
    
        }
    }

};

int main(){
    cout << "thread 1,2,3 oprating independently " << endl; 

    //thread using function pointer as callable

    thread th1(foo,3);

    // thread using object as callable

    thread th2(thread_obj(), 3);

    // lamda expression
    auto f = [](int x){
        for(int i = 0; i < x; i++){
            cout <<"thread using lambda expression as callable" << endl;
        }
    };
    thread th3(f,3);

    th1.join();

    th2.join();

    th3.join();
}
