/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Queue
* Tgl : 08 05 2019
*/

#include<iostream>
using namespace std;

const int maxElemen=5; // Batas Maksimal Antrian
struct node{
	char info;
	node *next;
};
struct queue{
	node *head;
	node *tail;
};

void createQueue(queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}
void createNode(node* &newNode){
	newNode=new node;
	cin>>newNode->info;
	newNode->next=NULL;
}
void push(queue &Q, node* &newNode){
	if(Q.head==NULL){
		Q.head=newNode;
		Q.tail=newNode;
	}
	else{
		Q.tail->next=newNode;
		Q.tail=newNode;
	}
}
void pop(queue &Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}
	else{
		node *delNode;
		delNode=Q.head;
		Q.head=Q.head->next;
		delNode->next=NULL;
	}
}
void print(queue Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		node *travNode=Q.head;
		cout<<endl<<"Q = [";
		while(travNode!=NULL){
			cout<<travNode->info;
			if(travNode->next!=NULL){
				cout<<", ";
			}
			travNode=travNode->next;
		}
		cout<<"]"<<endl;
	}
}

int main(){
	queue Q;
	node *p;
	int n,pil;
	char lagi;
	createQueue(Q);
	do{
		cout<<"Masukkan Banyak Data : ";cin>>n;
	}while(n>maxElemen);
	cout<<"Masukkan Data : ";
	for(int i=0; i<n; i++){
		createNode(p);
		push(Q,p);
	}
	do{
		cout<<"\n1. Tambah Antrian\n2. Hapus Antrian\n3. Print Antrian\nMasukkan pilihan : "; cin >> pil;
		switch(pil){
			case 1:
				if(n<5){
					cout<<"Masukkan Data : ";
					createNode(p);
					push(Q,p);
					n++;
				}else{
					cout<<"Antrian Penuh";
				}
				break;
			case 2:
				pop(Q);
				if(n>0){
					n--;
				}
				break;
			case 3:
				print(Q);
				break;
		}cout<<endl<<"Kembali ke menu? (Y/N) "; cin >> lagi;
	}while(lagi == 'Y' || lagi == 'y');
	
	
	return 0;
}