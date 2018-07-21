#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numofitems, gameison, hardness;

int ishumanwin(){
	if (numofitems == 0) {
		printf("!!! SİZ KAZANDINIZ AMAN NE BÜYÜK BAŞARI !!!\n");
		gameison = 0;
		return 1;
	} else if (numofitems < 0) {
		printf("Fatal Error!");
		return -1;
	}
	return 0;
}

int ispcwin(){
	if (numofitems == 0) {
		printf("!!! BİLGİSAYAR KAZANDI !!! NİHAHAHAHAH !!!\n");
		gameison = 0;
		return 1;
	} else if (numofitems < 0) {
		printf("Fatal Error!");
		return -1;
	}
	return 0;
}

void draw(int values[], int numofgroups) {
	int i, j, copy[numofgroups], max = 0;
	for(i = 0; i < numofgroups; i++)
		copy[i] = values[i];
		
	for(i = 0; i < numofgroups; i++)
		printf("_________");
		
	printf("\n\n");	
	
	for(i = 0; i < numofgroups; i++)
		printf("    %d    ", i + 1);

	printf("\n\n");
	
	for(j = 0; j < numofgroups + 1; j++){
		for(i = 0; i < numofgroups; i++){
			printf("   ");
			if (copy[i] < 1){
				printf("   ");
			} else if (copy[i] == 1) {
				printf(" * ");
				copy[i] = copy[i] - 1;
			} else if (copy[i] > 1) {
				printf("* *");
				copy[i] = copy[i] - 2;
			}
			printf("   ");
		}
		printf("\n");
	}
	for(i = 0; i < numofgroups; i++)
		printf("_________");
		
	printf("\n\n");
}

void humanmakemove(int values[], int numofgroups){
	int whichgroup, howmuchitem;
	printf("Bir hamle giriniz: ");
	while(1){
		scanf("%d %d", &whichgroup, &howmuchitem);
		getchar();
		if(whichgroup <= numofgroups && whichgroup > 0 && howmuchitem <= values[whichgroup - 1] && howmuchitem >= 1){
			break;
		} else {
			printf("Lütfen geçerli bir hamle giriniz:");
		}
	}
	printf("%d. gruptan %d tane silinecek. Devam etmek için lütfen ENTERa basınız.", whichgroup, howmuchitem);
	getchar();
	values[whichgroup -1] = values[whichgroup - 1] - howmuchitem;
	numofitems = numofitems - howmuchitem;
	draw(values, numofgroups);
}

void pcmakemove(int values[], int numofgroups){
	int whichgroup, howmuchitem;
	if(hardness == 1){
		do{
			whichgroup = rand() % numofgroups + 1;
			printf("PC %d grubu seçti\n", whichgroup);
			howmuchitem = rand() % (values[whichgroup - 1] + 1);
			printf("PC %d tane taş seçti\n", howmuchitem);
		} while (howmuchitem > values[whichgroup - 1] || howmuchitem < 1);
		printf("Bilgisayar %d. gruptan %d tane siliyor.\n", whichgroup, howmuchitem);
	} else if (hardness == 2) {
		
	} else if (hardness == 3) {
		
	} else {
		printf("Fatal Error");
		return;
	}
	values[whichgroup -1] = values[whichgroup - 1] - howmuchitem;
	numofitems = numofitems - howmuchitem;
	draw(values, numofgroups);
}

void main(){
/*
	int hardness = -1, numofgroups = -1, ilkkim = -1, i;
	
//intro and info	
	printf("\n\n!!!NİM OYUNUNA HOŞ GELDİNİZ!!!\nHazırlayan: Ömer Can Yavuzyılmaz - omercanyy@gmail.com\n\nKurallar: Sırası gelen oyuncu bir önceki hamledeki seçiminden bağımsız olarak istediği bir gruptan istediği kadar taş alabilmektedir.\n\nHedef: Karşıdakine alacak taş bırakmayan oyuncu oyunu kazanır.\n\nHamle: Hamle sırası geldiğinde kaçıncı gruptan  kaç tane taş silmek istediğinizi sırası ile aralarında boşluk bırakarak yazınız örneğin 3. gruptan 5 taş silmek için 3 5 yazınız veya 5. gruptan 9 taş silmek için 5 9 yazınız.\n\nDevam etmek için lütfen ENTERa basınız.");
	getchar();
	printf("\n\n");
	
//zorluk seviyesi
	while(!(hardness == 1 || hardness == 2 || hardness == 3)){
		printf("1) Kolay\n2) Normal\n3) Zor\nOyunun zorluk derecesini seçin: ");	
		scanf("%d", &hardness);
		getchar();
		if(!(hardness == 1 || hardness == 2 || hardness == 3)){
			printf("Lütfen 1'den ile 3'e kadar geçerli bir tam sayı giriniz!\n");
			getchar();
		}
	}	
		
	printf("Zorluk derecesi olarak ");
	if(hardness == 1)printf("KOLAY");
	if(hardness == 2)printf("NORMAL");
	if(hardness == 3)printf("ZOR");
	printf(" seçildi. ");
	
	printf("Devam etmek için lütfen ENTERa basınız.");
	getchar();
	printf("\n\n");
	
//grup sayısı
	while(!(numofgroups == 3 || numofgroups == 4 || numofgroups == 5)){
		printf("Grup sayısı en az 3 en fazla 5 olabilir ve ilk grupun taş sayısı 1 olmak üzere diğer grupların taş sayıları artan ardışık tek sayılar olacaktır.\nOyunda kaç grup olmasını istediğinizi seçin: ");	
		scanf("%d", &numofgroups);
		getchar();
		if(!(numofgroups == 3 || numofgroups == 4 || numofgroups == 5)){
			printf("Lütfen 3'den 5'e kadar geçerli bir tamsayı giriniz!\n");
			getchar();
		}
	}
	
	printf("Grup sayısı %d olarak seçildi. ", numofgroups);
	numofitem = numofgroups * numofgroups;
	
	printf("Devam etmek için lütfen ENTERa basınız.");
	getchar();
	printf("\n\n");
	
//ilk kim başlıcak
	while(!(ilkkim == 1 || ilkkim == 2)){
		printf("1) Siz\n2) Bilgisayar\nİlk hamleyi kimin yapacağını seçin: ");	
		scanf("%d", &ilkkim);
		getchar();
		if(!(ilkkim == 1 || ilkkim == 2)){
			printf("Lütfen 1 ya da 2 giriniz!\n");
			getchar();
		}
	}	
		
	printf("İlk hamleyi ");
	if(ilkkim == 1)printf("SİZ yapacaksınız. ");
	if(ilkkim == 2)printf("BİLGİSAYAR yapacak. ");
	ilkkim = ilkkim-1;
	
	printf("Devam etmek için lütfen ENTERa basınız.");
	getchar();
	printf("\n\n");
*/
	
//prepare the values
	int numofgroups = 5, i, ilkkim = 0; numofitems = numofgroups * numofgroups, hardness = 3;// comment out later for control
	int values[numofgroups];
	for(i = 0; i < numofgroups; i++){
		values[i] =2*i + 1;
	}

//draw the initial situation
	gameison = 1;
	draw(values, numofgroups);
	
//plays
	for(i = 0; i < numofgroups; i++)
		printf("%d ", values[i]);
	printf("%d\n", numofitems);

	if(ilkkim == 1){
		while(gameison == 1){
			//pc make a move
			//insan make a move
		}
	} else if (ilkkim == 0) {
		while(gameison == 1){
			//insan make a move
			humanmakemove(values, numofgroups);
			for(i = 0; i < numofgroups; i++)
				printf("%d ", values[i]);
			printf("%d\n", numofitems);
			if(ishumanwin() == 1) break;
			
			//pc make a move
			pcmakemove(values, numofgroups);
			for(i = 0; i < numofgroups; i++)
				printf("%d ", values[i]);
			printf("%d\n", numofitems);
			if(ispcwin() == 1) break;
		}
	}
	
	
	return;
}
