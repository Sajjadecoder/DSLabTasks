#include<iostream>
#include<string>
using namespace std;
#define size 20
class hashTableEntry{
    public:
    string word;
    int value;
    hashTableEntry *next;

    hashTableEntry(string w,int v){
        word = w;
        value = v;
        next = nullptr;
    }
};
class hashTable{
    public:
    int currentSize;
    hashTableEntry **table;
    hashTable(){
        table = new hashTableEntry*[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
        currentSize = 0;
    }
    int hashFunction(int key){
        return key%size;
    }
    
    void Insert(string k, int v) {
        int cnt = 0;
        for (int i = 0; i < k.length(); i++)
        {   
            cnt+=int(k[i]);
        }
        cnt+= 2+3+7+5+4; //23K-0754
        int hash = hashFunction(cnt);

        hashTableEntry* newEntry = new hashTableEntry(k, v);

        if (table[hash] == nullptr) {
            table[hash] = newEntry;
            return;
        }   
        
            //collision detected,insertatend of Linked list
            hashTableEntry* current = table[hash];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newEntry;
        

        currentSize++; 
    }
    void PrintTable() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            hashTableEntry* current = table[i];
            while (current != nullptr) {
                cout << "(Key: " << current->word << ", Value: " << current->value << ") -> ";
                current = current->next;
            }
            cout << "Null" << endl;
        }
    }
    void countNodes(){
        for (int i = 0; i < size; ++i) {
            int cnt = 0;
            hashTableEntry* current = table[i];
            while (current != nullptr) {
                current = current->next;
                cnt++;
            }
            cout << "Index " << i << " count: "<<cnt<<endl;
        }
    }
    int SearchKey(string k) {
         int cnt = 0;
        for (int i = 0; i < k.length(); i++)
        {   
            cnt+=int(k[i]);
        }
        cnt+= 2+3+7+5+4; //23K-0754
        int hash = hashFunction(cnt);

        hashTableEntry* current = table[hash];
        while (current != nullptr) {
            if (current->word == k) {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }

};



int main(){
    string n[] = {"Kindness","Politeness","Understandable","Empathy","Knowledge","Gratitude","Patience","Righteous","Appreciate","Easy"};
    hashTable h;
    for (int i = 0; i < 10; i++)
    {
        h.Insert(n[i],1);
    }
    if( h.SearchKey("knowledge")==1){
        cout<<"exists";

    }else{
        cout<<"does not exists";
    }

    //h.PrintTable();
    //h.countNodes();
    return 0;
}