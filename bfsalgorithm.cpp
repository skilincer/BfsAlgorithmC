#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

int graph[6][6];
int ziyaret[5];

struct dugum{
	int data;
	struct dugum *ileri;
};

struct dugum* ilk = NULL;
struct dugum* son = NULL;

struct dugum* yenidugum(int x){
	struct dugum* yenidugum = (struct dugum*)malloc(sizeof(struct dugum));
	yenidugum->ileri = NULL;
	yenidugum->data = x;
	return yenidugum;
}

void kuyrugaekle(int x){
	struct dugum* yenidugum2 = yenidugum(x);
	if(ilk == NULL){
		ilk = yenidugum2;
		son = yenidugum2;
	}
	else{
		son->ileri = yenidugum2;
		yenidugum2 = son;
	}
}

void kuyruktancikar(){
	if(ilk == NULL){
		printf("Kuyruk zaten bos. Eleman ekleyip oyle dene...!");
		return;
	}
	if(ilk->ileri==NULL){
		ilk = NULL;
		son = NULL;
	}
	else{
		struct dugum* gecici = ilk->ileri;
		free(ilk);
		ilk = gecici;
	}
}

bool kuyrukbosmu(){
	if(ilk == NULL)
		return true;
	else
	return false;
}

int ilkeleman(){
	return ilk->data;
}

void BFS(int root){
	int i;
	for(i = 0; i < 6; i++){
		ziyaret[i] = false;
	}
	ziyaret[root] = true;
	kuyrugaekle(root);
	while(kuyrukbosmu() == false){
		root = ilkeleman();
		printf("%d ",root);// girilen ilk eleman kontrol edilen
		kuyruktancikar();
		for(i = 0; i < 6; i++){
			if(graph[root][i] == 1 && ziyaret[i] == false){
				ziyaret[i] = true;
				kuyrugaekle(i);
			}
		}
	}
}

void graphokuma(){
	int i = 0;
    FILE *fp = fopen("bfs.txt", "r");
    while(fscanf(fp, "%d %d %d %d %d %d",
                 &graph[i][0],
                 &graph[i][1],
                 &graph[i][2],
                 &graph[i][3],
                 &graph[i][4],
                 &graph[i][5]) !=EOF){
        i = i + 1;
    }
}

main(){
	graphokuma();
	BFS(2);  // girilen dügüm numarasýna göre kendisi de dahil sýralamayý verir
	getch();
}
