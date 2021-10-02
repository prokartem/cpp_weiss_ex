#include <iostream>
#include <vector>
using namespace std;

template <typename Comparable>
class OrderedCollection {
    private:
        vector<Comparable> col;
        // vector<int>::iterator find(Comparable x) {
        //     if (this->contains(x)) {
        //         vector<int>::iterator iter;
        //         iter = col.begin;
        //         for(; iter != col.end(); iter++) {
        //             if (*iter == x)
        //                 return iter;
        //         }
        //     }
        //     else return col.cend();
        // }
    public:
        explicit OrderedCollection() {}
        explicit OrderedCollection(vector<Comparable> arr) {
                col = arr;
            }
        
        bool isEmpty() {
            return col.empty();
        }
        bool contains(Comparable x) {
            vector<int>::iterator iter;
            bool flag = false;
            iter = col.begin();
            for(; iter != col.end(); iter++) {
                if(*iter == x)
                    flag = true;
            }
            return flag;
        }
        OrderedCollection makeEmpty() {
            return OrderedCollection();
        }
        OrderedCollection insert(Comparable x) {
            vector<Comparable> temp = col;
            temp.push_back(x);
            return OrderedCollection(temp);
        }
        // OrderedCollection remove(Comparable x) {
        //     return OrderedCollection(col.erase(this->find(x)));
        // }
        // vector<int>::iterator findMax() {
        //     vector<int>::iterator iter;
        //     iter = col.begin;
            
        //     for(; iter != col.end(); iter++) {
        //         if (*iter == x)
        //             return iter;
        //     }
        // }
};

int main(){
    OrderedCollection<int> a;

    cout << boolalpha;
    cout << "a is empty?: " << a.isEmpty() << endl;
    cout << "create b from a by adding 1, 2, 3, 4" << endl;
    OrderedCollection<int> b = a.insert(1).insert(2).insert(3).insert(4);
    cout << "a is empty?: " << a.isEmpty() << endl;
    cout << "b is empty?: " << b.isEmpty() << endl;
    cout << "b contains 3?: " << b.contains(3) << endl;cout << "b contains 5?: " << b.contains(5) << endl;
    cout << "make b empty. b is empty?: " << b.makeEmpty().isEmpty() << endl;
}