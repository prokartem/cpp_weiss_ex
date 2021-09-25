#include <iostream>
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
            else this;
        }
        // Collection remove(Object x) {
        //     if (this->contains(x))
        //     ???
        //     else this;
        // }
};

int main(){
    Collection<int> a;

    cout << a.isEmpty();
    Collection<int> b = a.insert(1).insert(2).insert(3).insert(4);
    cout << a.isEmpty() << endl;
    cout << b.isEmpty() << endl;
    cout << b.contains(3) << endl;
    cout << b.contains(5) << endl;
    cout << b.makeEmpty().isEmpty() << endl;
}