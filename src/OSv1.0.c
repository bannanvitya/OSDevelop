
#include "stdafx.h"
#include "string.h"
#include "stdio.h"

unsigned char* mainMemory;
bool *boolMemory;

//=====================================================================================================
//��������� � �������� ������, ���� �������

public static unsigned char Malloc(int n){

	mainMemory = (unsigned char *) malloc(n*sizeof(unsigned char));
	 if( mainMemory != NULL ) {
	   for(int i = 0; i < n; i++ )
		   mainMemory[i] = 0;
	 } else printf("�� ������� �������� ������");

    return mainMemory;
}

public static void Free(unsigned char *m){
    try {
	  free(m); 
	  printf("������ ������ �������");
	} catch { 
		printf("�� ������� �������� ������");
	}
}

public static bool Occupied(int n){
	boolMemory = (bool*) malloc(n*sizeof(bool));
	for (int i = 0; i < n; i++){
	  if  (mainMemory[i] != 0)
		  boolMemory[i]=true;//������ ��� �����
	}
	return boolMemory;
}

//=====================================================================================================
//������

struct Thread{
	int thId;
	int iStart;
	int iEnd;
	unsigned char *mem;
}

public Tread newThread(int i, int str, int end, unsigned char *memor){
	stuct Thead thr;
	thr.thId = i;
	thr.iStart = str;
	thr.iEnd = end;
	thr.mem = memor;

	return thr;
}


public static void getItem(Tread thr){//���?
	int id = thr.thId;
	int startPos = thr.iStart;
	int endPos = thr.iEnd;
	unsigned char *mem = thr.mem;
}
  
//====================================================================================================
//���������� ������� � ��������

//������ ��� ������� ����?
public static void MemoryManager(){
   
   Malloc(100);
   getItem(Thread thr);//���� ������ ��� ������ �������
   
}

   public static Thread ThreadManager(){
	 newThread(1, 0, 200, mainMemory);
	 newThread(2, 300, 400, mainMemory);
     newThread(1, 201, 350, mainMemory);//��� ����� �������� �� ��� ����� "�����������"

}

 //=====================================================================================================


int _tmain(int argc, _TCHAR* argv[])
{
	MemoryManager();
	ThreadManager();
    Occupied(100);
	Free(mainMemory);
	return 0;
}

