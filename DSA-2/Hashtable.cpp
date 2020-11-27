#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable{
    private:
        static const int hashgroup=10;
        list<pair<int, string>> table[hashgroup]; 


    public:
        bool isEmpty() const;
        int hashFunction (int key);
        void insertItem(int key,string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();



};

bool HashTable::isEmpty() const{
    int sum{};
    for(int i{};i<hashgroup; i++){
        sum+= table[i].size();
    }

    if(!sum){
        return true;
    }
    return false;


}

int HashTable::hashFunction(int key){
    return key % hashgroup;
}

void HashTable::insertItem(int key, string value){
    int hashValue =hashFunction(key);
    auto& cell =table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr!= end(cell); bItr++){
        if(bItr->first== key){
            keyExists=true;
            bItr->second =value;
            cout << "key exists"<<endl;
            break;
        }
    }
    if(!keyExists){
        cell.emplace_back(key, value);
    }
    return;

}

void HashTable::removeItem(int key){
    int hashValue= hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr=begin(cell);
    bool keyExists= false;
    for(; bItr!= end(cell); bItr++){
        if(bItr->first== key){
            keyExists= true;
            bItr=cell.erase(bItr);
            cout << "pair removed " << endl;
            break;
        }
    }

    if(!keyExists){
        cout << "key not found" << endl;

    }
    return;
}

void HashTable::printTable(){
    for(int i{}; i <hashgroup;i++){
        if(table[i].size()== 0) continue;

        auto bItr = table[i].begin();
        for(; bItr != table[i].end(); bItr++){
            cout << "key: " << bItr->first << "value" <<bItr-> second<<endl;     
        }
    }
    return;
}

int main(){
    HashTable HT;

    if (HT.isEmpty()){
        cout << "correct" <<endl ;
    }else {
        cout << "should check code" << endl;
    }

    HT.insertItem(905, "Jim");
    HT.insertItem(216, "Jason");
    HT.insertItem(452, "tim");
    HT.insertItem(134, "Jim");
    HT.insertItem(933, "rob");
    HT.insertItem(4409, "john");
    HT.insertItem(4409, "cena");
    
    HT.removeItem(134);
    HT.removeItem(135);

    HT.printTable();

    
    
    if (HT.isEmpty()){
        cout << "should check code" <<endl ;
    }else {
        cout << "okayy" << endl;
    }


    return 0;
}
