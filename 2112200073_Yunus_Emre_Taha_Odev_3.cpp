#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}n;

n *start=NULL, *temp=NULL , *last=NULL;

void sirala(int veri){
	n *yeni=(n*) malloc(sizeof(n));
	yeni->data=veri;
	yeni->next=NULL;
	if(start==NULL){
		start=last=yeni;
		start->prev=NULL;
		return ;
	}
	if(yeni->data<=start->data){
		yeni->prev=NULL;
		start->prev=yeni;
		yeni->next=start;
		start=yeni;
		return ;
	}
	if(yeni->data>last->data){
		yeni->prev=last;
		last->next=yeni;
		last=yeni;
		return ;
	}
	temp=start->next;
	while(temp->data<yeni->data){
		temp=temp->next;
	}
	temp->prev->next=yeni;
	yeni->prev=temp->prev;
	temp->prev=yeni;
	yeni->next=temp;
}

void yazdir(){
	temp=start;
	while(temp->next!=NULL){
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

int main(){
	int sayi,secim;
	while(1){
		printf("\n1->sayi ekleme\n");
		printf("2->yazdir\n");
		printf("3->cikis\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("sayi: ");
				scanf("%d",&sayi);
				sirala(sayi);
				break;
			case 2: 
				yazdir();
				break;
			case 3:
				return 0;		
		}
		
	}
}





