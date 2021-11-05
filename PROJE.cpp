#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<locale.h>
#include<conio.h>
#include<unistd.h>
#include <windows.h>


//rastgele kelime ekrana getirmek için yazdýðýmýz fonksiyon
	void kelimecagir(char kelimeler[][20],int secim)
	{
		int a,b,x,temp=0;
		int sayilar[35]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34};
		srand(time(NULL));
		switch(secim)
		{
			case 1:
				system("color F0");
			for(int i=0;i<35;i++)	//sayilar dizimizi karýþtýrýyor
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<7;i++)	//karýþmýþ olan sayýlar dizisine göre kelimelerimizi ekrana getiriyor
				{
				x=sayilar[i];
				printf("%s\n",kelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			case 2:
				system("color F0");
			for(int i=0;i<35;i++)
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<14;i++)
				{
				x=sayilar[i];
				printf("%s\n",kelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			case 3:
				system("color F0");
			for(int i=0;i<35;i++)
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<20;i++)
				{
				x=sayilar[i];
				printf("%s\n",kelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			default:
		
			break;
		}
	}
	
	int kontrol(char kelimeler[][20],int dogru,int secim)
	{
	char cevaplar[30][20];
	FILE *puan; 
	clock_t baslangic, bitis;
	
	switch(secim)
	{
	case 1:
	system("color F0");
	printf("Hadi þimdi hafýzan ne kadar kuvvetli görelim.\n");
	printf("Aklýnda kalan kelimeleri yazmaya baþla.(7 ADET KELÝME YAZMALISIN.HER CEVAPTAN SONRA ENTER'A TUÞLAYINIZ.)\nLütfen Türkçe karakter kullanmayýnýz\n25 saniye süreniz vardýr. Bol þans...\n");
	bitis = clock() + 25 * CLK_TCK;		// süre koymak için kullanýldý
	baslangic = clock();
	gets(cevaplar[0]);	
		for(int i=0;i<7;i++)	// kullanýcýdan cevaplarý alýyor
		{
			printf("%d.)",i+1);
			gets(cevaplar[i]);		
			if(clock() > bitis )
			{
				printf("Sureniz doldu !");
				sleep(2);
				break;
			}
		}
		system("CLS");
		printf("DOÐRULARINIZ\n");
		for(int z=0;z<35;z++)	//kullanýcýnýn girdiði doðru cevaplarý bulur ve ekrana yazar
		{
			for(int i=0;i<7;i++)
			{
				if(strcmp(kelimeler[z],cevaplar[i])==0)
				{
					dogru++;
			
				system("color F2");
					printf("%s\n",cevaplar[i]); //doðrularý yazdýrýr
				}		
			}
		}

	puan=fopen("puan tablosu.txt","a");	// kullanýcýnýn aldýðý puaný dosyaya yazar
		if(puan==NULL)
	{
		printf("dosya bulunamadý");
	}
	
	else
	
	fprintf(puan,"%d/7\n",dogru);
		
	fclose(puan);
		break;
		
	case 2:
		system("color F0");
	printf("Hadi þimdi hafýzan ne kadar kuvvetli görelim.\n");
	printf("Aklýnda kalan kelimeleri yazmaya baþla.(14 ADET KELÝME YAZMALISIN.HER CEVAPTAN SONRA ENTER'A TUÞLAYINIZ)\nLütfen Türkçe karakter kullanmayýnýz.\n35 saniye süreniz vardýr. Bol þans...\n");
	bitis = clock() + 35 * CLK_TCK;
	baslangic = clock();
	gets(cevaplar[0]);
		for(int i=0;i<14;i++)
		{
			printf("%d.)",i+1);
			gets(cevaplar[i]);
			if(clock() > bitis )
			{
				printf("Sureniz doldu !");
				sleep(2);
				break;
			}
		}
		printf("DOGRULARINIZ\n");
		for(int z=0;z<35;z++)
		{
			for(int i=0;i<14;i++)
			{
				if(strcmp(kelimeler[z],cevaplar[i])==0)
				{
					dogru++;
					system("color F2");
					printf("%s\n",cevaplar[i]);
				}
			
			}
		}
		
	puan=fopen("puan tablosu.txt","a");
		if(puan==NULL)
	{
		printf("dosya bulunamadý");
	}
	
	else
	
	fprintf(puan,"%d/14\n",dogru);
		
	fclose(puan);
		break;

	case 3:
		system("color F0");
	printf("Hadi þimdi hafýzan ne kadar kuvvetli görelim.\n");
	printf("Aklýnda kalan kelimeleri yazmaya baþla.(20 ADET KELÝME YAZMALISIN.HER CEVAPTAN SONRA ENTER'A TUÞLAYINIZ)\nLütfen Türkçe karakter kullanmayýnýz.\n50 saniye süreniz vardýr. Bol þans...\n");
	bitis = clock() + 50 * CLK_TCK;
	baslangic = clock();
	gets(cevaplar[0]);	
		for(int i=0;i<20;i++)
		{
			printf("%d.)",i+1);
			gets(cevaplar[i]);
			if(clock() > bitis )
			{
				printf("Sureniz doldu !");
				sleep(2);
				break;
			}
		}
		printf("DOGRULARINIZ\n");
		for(int z=0;z<30;z++)
		{
			for(int i=0;i<20;i++)
			{
				if(strcmp(kelimeler[z],cevaplar[i])==0)
				{
					dogru++;
					system("color F2");
					printf("%s\n",cevaplar[i]);			
				
				}
			
			}
		}
		
	puan=fopen("puan tablosu.txt","a");
		if(puan==NULL)
	{
		printf("dosya bulunamadý");
	}
	
	else
	
	fprintf(puan,"%d/20\n",dogru);
	
	
	fclose(puan);
		break;
	
	default:
	printf("Dostum okuyamýyorsan aklýnda tutmana imkan yok !!!\n");
	dogru=0;
		puan=fopen("puan tablosu.txt","a");
		if(puan==NULL)
	{
		printf("dosya bulunamadý");
	}
	
	else
	
	fprintf(puan,"%d\n",dogru);
	
	
	fclose(puan);
	break;
	}
		
		return dogru;
	}


	void ingKelimecagir(char ingkelimeler[][20],int ingsecim)
	{
		int a,b,x,temp=0;
		int sayilar[35]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34};
		srand(time(NULL));
		switch(ingsecim)
		{
			case 1:
				system("color F0");
			for(int i=0;i<35;i++)
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<7;i++)
				{
				x=sayilar[i];
				printf("%s\n",ingkelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			case 2:
				system("color F0");
			for(int i=0;i<35;i++)
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<14;i++)
				{
				x=sayilar[i];
				printf("%s\n",ingkelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			case 3:
				system("color F0");
			for(int i=0;i<35;i++)
			{
				a=rand()%35;
				temp=sayilar[i];
				sayilar[i]=sayilar[a];
				sayilar[a]=temp;	
			}
			
				for(int i=0;i<20;i++)
				{
				x=sayilar[i];
				printf("%s\n",ingkelimeler[x]);
				sleep(1);
				system("CLS");
			
				}
			break;
			
			default:
			
			break;
		}

	}
		
// kullanýcýdan cevaplarý almak ve verilen cevaplarý kontrol etmek için yazdýðýmýz fonksiyon
int ingkontrol(char ingkelimeler[][20],int ingdogru,int ingsecim)
	{
	char ingcevaplar[30][20];
	FILE *score;
	clock_t ingbaslangic,ingbitis;
	
	switch(ingsecim)
	{
	case 1:
		system("color F0");
	printf("Do you trust your memory??\n");
	printf("Please write the words that you remember. You have 7 words.You have 30 seconds.\nPGood Luck!!\n");	
	ingbitis = clock() + 30 * CLK_TCK;
	ingbaslangic = clock();
	gets(ingcevaplar[0]);
		for(int i=0;i<7;i++)
		{
			printf("%d.)",i+1);
		
			gets(ingcevaplar[i]);
			if(clock() > ingbitis )
			{
				printf("TÝME UP !!!");
				sleep(2);
				break;
			}
		}
		system("CLS");
		printf("TRUE ANSWER\n");
		for(int z=0;z<35;z++)
		{
			for(int i=0;i<7;i++)
			{
				if(strcmp(ingkelimeler[z],ingcevaplar[i])==0)
				{
					ingdogru++;
			
				system("color F2");
					printf("%s\n",ingcevaplar[i]);
				}
				
			}
		}

	score=fopen("score.txt","a");
		if(score==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	else
	
	fprintf(score,"%d/7\n",ingdogru);
	
	fclose(score);
		break;
		
	case 2:
		system("color F0");
	printf("Do you trust your memory??\n");
	printf("Please write the words that you remember. You have 14 words.You have 40 seconds.\nGood Luck!!\n");
	ingbitis = clock() + 40 * CLK_TCK;
	ingbaslangic = clock();
	gets(ingcevaplar[0]);	
		for(int i=0;i<14;i++)
		{
			printf("%d.)",i+1);
		
			gets(ingcevaplar[i]);		//cevaplarý gets ile almak istedim enter tuþunu cevap olarak kabul etsin diye
			if(clock() > ingbitis )
			{
				printf("TÝME UP !!!");
				sleep(2);
				break;
			}
		}
		printf("RÝGHT ANSWER\n");
		for(int z=0;z<35;z++)
		{
			for(int i=0;i<14;i++)
			{
				if(strcmp(ingkelimeler[z],ingcevaplar[i])==0)
				{
					ingdogru++;
					system("color F2");
					printf("%s\n",ingcevaplar[i]);
				}
			
			}
		}

	score=fopen("score.txt","a");
		if(score==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	else
	
	fprintf(score,"%d/14\n",ingdogru);
	
	fclose(score);
		break;

	case 3:
		system("color F0");
	printf("Do you trust your memory??\n");
	printf("Please write the words that you remember. You have 20 words.You have 55 seconds.\nGood Luck!!\n");
		ingbitis = clock() + 55 * CLK_TCK;
		ingbaslangic = clock();
		gets(ingcevaplar[0]);	
		for(int i=0;i<20;i++)
		{
			printf("%d.)",i+1);
		
			gets(ingcevaplar[i]);
			if(clock() > ingbitis )
			{
				printf("TÝME UP !!!");
				sleep(2);
				break;
			}
		}
		printf("RIGHT ANSWER\n");
		for(int z=0;z<35;z++)
		{
			for(int i=0;i<20;i++)
			{
				if(strcmp(ingkelimeler[z],ingcevaplar[i])==0)
				{
					ingdogru++;
					system("color F2");
					printf("%s\n",ingcevaplar[i]);			
				
				}
			
			}
		}
		
	score=fopen("score.txt","a");
		if(score==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	else
	
	fprintf(score,"%d/20\n",ingdogru);
	
	fclose(score);
		break;
	
	default:		//kullanýcý kolay orta zor seçimi yapamazsa dosyaya 0 puan yazýp oyunu bitiriyo.
		printf("Really???... Go away!!");
		ingdogru=0;
		
	score=fopen("score.txt","a");
		if(score==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	else
	
	fprintf(score,"%d\n",ingdogru);
	
	fclose(score);
		break;
	
	break;
	}	
		return ingdogru;
	}

int main()
{
	FILE *puan;
	FILE *score;
	setlocale(LC_ALL,"Turkish");
	system("CLS");
	char kelimeler[35][20]={"terketmek","muhasebe","vagon","tavsiye","klinik","kasa","vestiyer","pencere","tencere","tebrikler","bileklik","para","saadet","kaptan","kukla","cakmak","menfaat","medeniyet","takvim","tarih","zaman","korku","reklam","sandalye","masal","katil","ruhsuz","dandik","kalitesiz","ahenk","merdiven","anadolu","samimiyet","toplumsal","evren"};
	char ingKelimeler[35][20]={"impossible","leave","accounting","carriage","suggestion","clinic","safe","infinity","window","stewpot","congratulations","dignity","money","happiness","captain","puppet","lighter","benefit","fluence","calendar","history","time","horror","hook","chair","tale","murder","soulless","sleazy","harmony","stairs","grace","deserve","universe","cosmos"};
	char isim[25],ingisim[25];
	int dogru,ingdogru;
	int secim,ingsecim,dilsecim;
	system("color F0");
	printf("DÝL SEÇÝNÝZ(SELECT LANGUAGE)\n1.)TURKISH\n2.)ENGLISH\n");
	scanf("%d",&dilsecim);
	switch(dilsecim)
	{
		case 1:
		system("CLS");
		printf("HAFIZA OYUNUNA HOSGELDÝNÝZ.\nBAKALIM EKRANA GELEN KELIMELERDEN KAC TANESINI AKLINDA TUTABILECEKSÝN\n");
		getchar();
		system("color F0");
		
		puan=fopen("puan tablosu.txt","a");
		
			if(puan==NULL)
		{
			printf("dosya bulunamadý");
		}
		
		else
		printf("kullanýcý adýnýzý giriniz: ");
		
		scanf("%s",isim);
		
		fprintf(puan,"%s	",isim);
		
		
		fclose(puan);
	
		printf("Zorluk seviyesini seçiniz.\n(Numaralarýna göre secim yapýnýz.)\n1.Kolay\n2.Orta\n3.Zor\n");
		scanf("%d",&secim);
		
		system("CLS");
		
		kelimecagir(kelimeler,secim);	
		
		printf("puanýnýz:%d\n",kontrol(kelimeler,dogru,secim));
	
		getchar();
	
	   int c;
	   puan = fopen("puan tablosu.txt","r");
	   if (puan == NULL) printf("DOSYA BULUNAMADI\n");
	   else {
		     do {
		       c = getc(puan);
			   if(c==EOF) break;    /* Bir karakter oku  */
		       putchar(c);
	
				} while (c != EOF);    /* Dosya sonuna (END OF FILE) a kadar devam */
			}
	   fclose(puan);
	   break;
	   
	   case 2:
		printf("WELCOME TO THE MEMORY GAME\nHOW MANY WORDS CAN YOU KEEP IN MIND\n");
		getchar();
		system("color F0");
		
		score=fopen("score.txt","a");
		
			if(score==NULL)
		{
			printf("FILE NOT FOUND");
		}
		
		else
		printf("USERNAME?? ");
		
		scanf("%s",ingisim);
		
		fprintf(score,"%s	",ingisim);

		
		fclose(score);
	
	printf("Select game level\n\n1.Easy\n2.Middle\n3.Hard\n");
		scanf("%d",&ingsecim);
		
		system("CLS");
		
		ingKelimecagir(ingKelimeler,ingsecim);	
		
		printf("SCORE:%d\n",ingkontrol(ingKelimeler,ingdogru,ingsecim));
		
		getchar();

	   int d;
	   score = fopen("score.txt","r");
	   if (score == NULL) printf("FILE NOT FOUND \n");
	   else {
	     do {
	       d = getc(score);    /* Bir karakter oku  */
	       if(d == EOF) break;	//son karaktere gelince döngüden çýkarmak için.
	       putchar(d);
	
	     } while (d != EOF);    /* Dosya sonuna (END OF FILE) a kadar devam */
	   }
	   fclose(score);
	break;
	default: 
	printf("Really???... Go away!! You are directed to the main menu.\n");
	sleep(2);
	return main();
	}
 return 0;
}
