#include<stdio.h> 
#define MAX 50

typedef struct{
	char num[20];
	char name[20];
	int age;	
}Student;


typedef struct{
	Student data[MAX];
	int length;	
}Sqlist1;


typedef struct{
	Student *data;
	int length;
	int maxSize; 
}Sqlist2;


int createSqlist2(Sqlist2 *sq){
	sq->data = (Student*)malloc(sizeof(Student)*MAX); 
	if(sq->data == NULL){
		printf("Failure!!");
		return 0;
	}
	sq->maxSize = MAX;
	sq->length = 0;
	return 1;
}

int insertSqlist(Sqlist2 *sq,int num,Student s){
	int temp;
	if(num > sq->length+1 || num > sq->maxSize || num < 1){
		printf("Insert ERROR!!!\n"); 
		return 0; 
	}
	if(sq->length >= sq->maxSize){
		printf("ERROR,The Sqlist is FULL!!");
		return 0; 
	}
	for(temp = sq->length;temp >= num;temp--){
		sq->data[temp] = sq->data[temp-1];
	}
	sq->data[num-1] = s;
	sq->length++;
	return 1;
}

int deleteSqlist(Sqlist2 *sq,Student *s,int i){
	int temp;
	if(i < 1 || i > sq->length){
		printf("Failure!!!");
		return 0;
	}
	*s = sq->data[i-1];
	for(temp = i;i<sq->length;temp++){
		sq->data[temp-1] = sq->data[temp];	
	}
	sq->length--;
	return 1;
}

void showSqlist(Sqlist2 sq){
	int i = 0;
	while(i<sq.length){
		printf("ID:%s  NAME:%s  AGE:%d\n",sq.data[i].num,sq.data[i].name,sq.data[i].age);
		i++;
	}
}

int findSqlist(Sqlist2 sq,Student s){
	int i;
	for(i = 0;i < sq.length;i++){
		if(compareStudent(sq.data[i],s) == 1){
			return i+1;
		}
	}	
	return 0;
}

int compareStudent(Student s1,Student s2){
	if(s1.num == s2.num || s1.name == s2.name || s1.age == s2.age)
		return 1;
	else return 0;
	
}


int main(void){
	Sqlist1 sq1;
	Sqlist2	sq2;
	Student s;
	int i = 1;
	createSqlist2(&sq2);
	while(i <= 3){
		printf("Please Input StudentID:");
		scanf("%s",s.num);
		printf("Please Input StudentName:");
		scanf("%s",s.name);
		printf("Please Input StudentAge:");
		scanf("%d",&s.age);
		insertSqlist(&sq2,i,s);
		i++;
	}
	showSqlist(sq2); 
	
	printf("%d",findSqlist(sq2,s));
}