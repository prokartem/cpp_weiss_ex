#include <iostream>
#include <sstream>
using namespace std;

template <typename Object>
class Collection{
    private:
        int index = 0;
        const int N;
        Object *col = new Object[N];
        bool go(Object x1, int i) {
                if (col[i] == x1)
                    return true;
                else {
                    if (i < index)
                        return go(x1, i+1);
                    else
                        return false;
                }
            }
    public:
        explicit Collection() : N(32) {}
        explicit Collection(int n) : N(n) {}
        explicit Collection(int ind, Object arr[]) : index(ind), N(sizeof(&arr)) {
            col = arr;
        }
        
        bool isEmpty() {
            return index == 0;
        }
        bool contains(Object x) {
            return go(x, 0);
        }
        Collection makeEmpty() {
            return Collection(N);
        }
        Collection insert(Object x) {
            if(index < N){
                col[index] = x;
                return Collection(index+1, col);
            }
            else return Collection(index, col);
        }
        // Collection remove(Object x) {
        //     if (this->contains(x))
        //     ???
        //     else this;
        // }
};

int main(){
    Collection<int> a;

    cout << boolalpha;
    cout << "a is empty?: " << a.isEmpty() << endl;
    cout << "create b from a by adding 1, 2, 3, 4" << endl;
    Collection<int> b = a.insert(1).insert(2).insert(3).insert(4);
    cout << "a is empty?: " << a.isEmpty() << endl;
    cout << "b is empty?: " << b.isEmpty() << endl;
    cout << "b contains 3?: " << b.contains(3) << endl;
    cout << "b contains 5?: " << b.contains(5) << endl;
    cout << "make b empty. b is empty?: " << b.makeEmpty().isEmpty() << endl;
}