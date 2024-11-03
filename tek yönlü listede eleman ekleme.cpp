#include <iostream>

using namespace std;

class Node {
    public:
		int x;
   		Node* next;
};

void elemanEkle(Node* root, int x) {
    Node* iter = root; 

    if (root== NULL) {  // E�er listemiz bo�sa listeye eleman ekleriz
        root->x = x;
        root->next = NULL; 
    } else {
       
        while (iter->next != NULL) { // Listenin sonuna kadar gitmek i�in
            iter = iter->next;
        }
        Node* yeniDugum = new Node;
        yeniDugum->x = x;  
        yeniDugum->next = NULL; 
        iter->next = yeniDugum; // Son d���m�n next'ini yeni d���me ata
    }
}

void yazdir(Node* root) {  
    Node* iter = root;
    while (iter != NULL) {
        cout << iter->x << endl;
        iter = iter->next;
    }
}

void bellekTemizle(Node* root) { 
    Node* iter = root;
    while (iter != NULL) {
        Node* temp = iter;		//D���mler teker teker bellekten silindi
        iter = iter->next;
        delete temp; 
    }
}

int main() {
    Node* root = new Node; 
    root->x=0;
    root->next = NULL; 
    elemanEkle(root, 10);
    elemanEkle(root, 20);
    elemanEkle(root, 40);
    elemanEkle(root, 50);

    yazdir(root);
    
    bellekTemizle(root); 
    return 0;
}
