#include<iostream>
using namespace std;

class Node{
	public:
		int x;
		Node* prev;
		Node* next;
};
/*void elemanEkle(Node* root,int x){
	Node* iter=root;
	if(root==NULL){
		iter->x;
		iter->next=NULL;
		iter->prev=NULL;
	}
	else{
		Node* iter=root;
		while (iter->next != NULL) {
            iter = iter->next;
        }
		Node* newNode=new Node;
		newNode->x=x;
		iter->next=newNode;
		newNode->prev=iter;
		newNode->next=NULL;
		
	}
}*/
Node* siraliElemanEkle(Node* root,int x){
	 
	if(root==NULL){
		Node* root=new Node;
		root->x;  		
		root->next=NULL;
		root->prev=NULL;
		return root;
	}
	if(root->x > x){
		Node* temp=new Node;
		temp->x=x;
		temp->next=root;
		temp->prev=NULL;
		return temp;
	}
	Node* iter=root;
	while(iter->next!=NULL && iter->next->x < x){
		iter=iter->next;                          //göstericimiz taþýndý eklenecek sayýya göre
	}
	Node* temp=new Node;
	temp->x=x;
	temp->next=iter->next;
	temp->prev=iter;
	iter->next=temp;
	return root;
}
Node* sil(Node* root,int x){
	Node* iter=root;
	Node* temp;
	if(root->x==x){ // silinecek eleman listedeki ilk elemana eþitse
		temp=root;
		root=root->next;
		root->prev=NULL;
		delete temp;
		cout<<"dugum silindi";
		return root;
	}
	while(iter->next!=NULL && iter->next->x !=x){
		iter=iter->next;
	}
	if(iter->next==NULL){
		cout<<"sayi bulunamadi\n";
		return root; // eðer root u return etmezsek root u kaybederiz ve return etmedðimiz için alttaki kod bloðu çalýþýr
	}
	temp=iter->next;
	iter->next=temp->next;
	if(iter->next!=NULL){
		temp->next->prev=iter;
	}
	
	
	delete temp;  // aradaki düðüm silindi
	cout<<"dugum silindi\n";
	return root;
}
void yazdir(Node* root){
	Node* iter=root;
	while(iter!=NULL){
		cout<<iter->x<<endl;
		iter=iter->next;
		}
}
int main()
{
	Node* root=new Node;
	root->x=42;
	root->next=NULL;
	root->prev=NULL;
	root=siraliElemanEkle(root,4);
	root=siraliElemanEkle(root,234);
	root=siraliElemanEkle(root,41);
	root=siraliElemanEkle(root,67);
	yazdir(root);
	sil(root,234);
	yazdir(root);
	sil(root,24);
	sil(root,32);
	yazdir(root);	
	
}
