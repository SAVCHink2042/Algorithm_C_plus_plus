
/*Требуется написать функцию, которая переставляет элементы списка так, что элементы, меньшие x
оказываются расположены перед элементами, большими или равными x. Функция должна сохранять
исходный порядок элементов в каждой из частей.*/



#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next; 
};
void DelNext( ListNode* head ) {
    ListNode *curr=head, *next=NULL;
    while (curr!=NULL) {
    	next=curr->next;
    	delete curr;
    	curr=next;
    }
}
void Print(ListNode *prev) {
    while (prev != nullptr) {
        cout << prev->value << endl;
        prev = prev->next;
    }  
}
void Process(ListNode* node, int x) {
    ListNode  *prev=NULL,  *buf1=NULL, *buf=NULL, *last=NULL,*bufa,  *dangeon=node, *last1;
    if( node->value>=x  ) {
        bufa=node;
        while(node->value>=x && node!=NULL ) {
            last1=node;
            node=node->next;
        }
        dangeon=node;
        last1->next=node->next;
        dangeon->next=bufa;
    }
    node=dangeon;
    while(node!=NULL) {
        if(node->value>=x && prev==NULL) {
            prev=last;
            buf1=node;
        }
        if(prev!=NULL && node->value<x && last!=NULL) {
            buf=node;
            buf1=prev->next;
            last->next=node->next;          //////////
            buf->next=buf1;
            prev->next=buf;
            prev=prev->next;
        }
        last=node;
        node=node->next;
    }
     Print(dangeon);
    //DelNext(dangeon);
   
}

int main(void) {
    ListNode *prev=NULL,  *Now, *New;
    int i, k, l, elem;
    std::cout<<"Введите число элементов списка"<<std::endl;
    std::cin>>k;
    std::cout<<"Введите элементы списка"<<std::endl;
    for (i = 0; i <  k; i++)  {
        std::cin >> elem;
        New = new ListNode;
        New->value = elem;
        New->next = nullptr;
        if (prev == nullptr) {
        	prev = New;
  		}
        else {
            Now = prev;
            while (Now->next != nullptr) {
                Now = Now->next;
            }
            Now->next = New;
        }
    }
    std::cout<<"Введите значение икса"<<std::endl;
    std::cin>>l;
    Process( prev, l);
    DelNext(prev);
}
