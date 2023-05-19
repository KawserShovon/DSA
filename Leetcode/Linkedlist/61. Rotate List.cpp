#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
#include <map>
#include<limits>
#include <cfloat>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)



using namespace std;


void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}



struct Node
{
    int data {};
    Node* next {};

    Node(int data):data(data){}
    ~Node()
    {
        // cout<<"Destroy value: "<<data<<endl;
    }

};

class LinkedList
{
private:
    Node *head {};
    Node *tail {};
    int length = 0;
public:

    ~LinkedList()
    {
        while(head)
        {
            Node* current = head->next;
            delete head;
            head = current;
        }
    }

  
    void print()
    {
        Node* temp_head = head;
        cout<<"values: ";
        while(temp_head != nullptr)
        {
            cout<<temp_head->data<<" ";
            temp_head = temp_head->next;
        }
        cout<<endl;
        cout<<"length: "<<length<<endl;
    }
    void insert_end(int value)
    {
        Node* item = new Node(value);
        if(!head)
        {
            head = tail = item;
        }
        else 
        {
            tail->next=item;
            tail = item;
        }
        length++;
    }

    void getAddress()
    {
        cout<<"head address; "<<&head<<endl;
        cout<<"tail address: "<<&tail<<endl;
    }

    void swap_headandtail()
    {
        Node* curr = head;
        Node* preserve = head->next;
        Node* prev;
        while(curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        head->next = nullptr;
        prev->next = head;

        tail->next = preserve;

        head = tail;
        tail = prev->next;

    }

    void left_rotate(int k)
    {
        Node* curr = head;
        Node* prev;
        Node* preserve = head;
        k = k%length;

        while(k--)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = nullptr;
        head = curr;
        tail->next = preserve;
        tail = prev; 
    }

    //leetcode way
    Node* rotateRight(Node* head, int k) {
        if(head == nullptr) return nullptr;
        if(k==0) return head;
        if(head ->next == nullptr) return head;

        Node* curr = head;
        Node* prev;
        Node* preserve = head;
        Node* tail;

        int length = 0;
        while(curr != nullptr)
        {
            tail = curr;
            curr = curr->next;
            length++;
        }
        
        
        

        if(k>=length)
        {
            k = k%length;
            k = length -k;
        }
        else 
        {
            k = length -k;
        }
        if(k==length) return head;

        

        curr = head;
        while(k--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        head = curr;
        tail->next = preserve;
        tail = prev;

        return head;
    }

};


int main()
{
    file_in_out();

    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(10);

    list.print();

    // /*homework 1*/   
    // list.getAddress();
    // list.swap_headandtail();
    // list.getAddress();
    // list.print();


    list.left_rotate(3);
    list.print();
    
}
