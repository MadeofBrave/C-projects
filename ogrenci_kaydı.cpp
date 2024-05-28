#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// öðrenci numarasý ,öðrenci adý ,vize notu,finasl notu,ortamlamasý en yðsek alaný ortalmalaý öðrenxi

struct ogrenci {
	        int no;
			char ad[50];
	        int vize ,final;
			double ortalama;
			struct ogrenci *next;                                                                             
};

typedef struct ogrenci node ;

node *ekle (node *start){

   node *ogr=(node *)malloc(sizeof(node ));
   printf("OGRENCI ADI : ");  scanf("%s",&ogr->ad);
   printf("OGRENCI NO:  : ");  scanf("%d",&ogr->no);
   printf("OGRENCI VISESI: ");  scanf("%d",&ogr->vize);
   printf("OGRENCI FINALI : ");  scanf("%d",&ogr->final);
     
   ogr->ortalama= ogr->vize*0.4+ogr->final*0.6;
   
   if(start==NULL){
   	 start=ogr;
   	 start->next=NULL;
   	printf("LISTE OLUSTURULDU !!!");
   }
   else{
   	ogr->next=start;
   	start=ogr;
   	printf("OGRENCI KAYDI YAPILDI");
   }
   return start;
}
node *silinecek( node *start){
	bool sonuc=false;
	if(start==NULL){
		printf("SILINECEK KAYIT YOK...");
		return start;
		sonuc= true;
	}
	else
	{
		int ogrNo;
		printf("SILINECEK OGRENCININ NUMARASININ GIRINIZ : ");   scanf("%d",&ogrNo);
		if(start->no==ogrNo && start->next==NULL){
			free(start);
			start=NULL;
			printf("LISTEDEKI SON ELEMAN SILINDI!!!");
		    sonuc = true;
		}
		else if(start->no==ogrNo && start->next!=NULL){
			node *temp=start->next;
			free(start);
			start=temp;
			printf("%d NUMARALI OGRENCI SILINDI!!!",ogrNo);
			sonuc = true ;
		}
		else{
			node *temp,*temp2;
			temp=start;
			temp2=temp;
			while(temp->next!=NULL){
				
				if(temp->no==ogrNo ){
					temp2->next=temp->next;
					free(temp);
				    printf("%d NUMARALI OGRENCI SILINDI ",ogrNo);
					sonuc= true ;
					break;
				}
				temp2=temp;
				temp=temp->next;
			}
				if(temp->no==ogrNo ){
				 temp2->next=NULL;
					free(temp);
				  printf("%d NUMARALI OGRENCI SILINDI ",ogrNo);
					sonuc= true ;}
			if(!sonuc){
				printf("%d NUMARALI OGRENCI BULUNAMADI ",ogrNo);
			}
	}
	return start;
}
node *EnyuksekPuan (node *start){
	int buyukOrt=start->ortalama;
	node *buyukDugum= start;
	
	if(start==NULL){
	printf("LISTEDE OGRENCI KAYDI YOK...");	
	}
	else{
		node *temp=start;
		while(temp!=NULL){
		    if( buyukOrt < temp->ortalama ){
                  buyukOrt=	temp->ortalama;
				  buyukDugum=temp;		
			}	
			temp=temp->next;
		}
		printf("EN YUKSEK ORTALAMAYA SAHIP OGRENCI \n ");
		printf("ADI : %s",buyukDugum->ad);
		printf("NUMARASI : %d",buyukDugum->ad);
		printf("VIZE : %d",buyukDugum->ad);
		printf("FINAL : %d",buyukDugum->ad);
		printf("ORTALAMASI : %.2f",buyukDugum->ortalama);
	}
	return start;
}
node *yaz (node *start)
{
	system("cls");
	if(start==NULL){
		printf("LISTEDE OGRENCI YOK !!");	
	}
	else
     {
     	node *temp;
		temp= start;
		while(temp!=NULL){
			   printf("\nADI :%s\nNO :%d\nVIZE:%d\nFINAL:%d \nORTALAMA :%.2f\n  ",temp->ad,temp->no,temp->vize,temp->final,temp->ortalama);
			   temp=temp->next;			
		}		
	}
	return start;
}

int main(){
	int secim,sayi;
	node *start=NULL;
	while(1){
	printf("\nOGRENCI EKLEME ICIN 1'E BAS\n");	
	printf("OGRENCI SILMA ICIN 2'E BAS\n");	
	printf("YAZDIRMAK ICIN 3'E BAS\n");
	printf("EN YUKSEK ORTLAMALI OGRENCI ICIN 4'E BAS\n");
	printf("CIKIS ICIN 5'E BAS\n");
    printf("SECIM YAPINIZ : ");  scanf("%d",&secim);
    
    switch(secim){
    case 1: start= ekle(start);	
    break;
    /*case 2: start= silinecek(start);
    break;*/
    case 3: start= yaz(start);
    break;
    /*case 4: start= ort( start);
    break;*/
    case 5: exit(0);
    default : printf("HATALI ISLEM YAPTINIZ!!!");
	}
  }
  return 0;
}
