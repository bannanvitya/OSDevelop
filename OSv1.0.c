
#include "stdafx.h"
#include "string.h"
#include "stdio.h"

unsigned char* mainMemory;
bool *boolMemory;

//=====================================================================================================
//выделение и очищение памяти, учет занятых

public static unsigned char Malloc(int n){

	mainMemory = (unsigned char *) malloc(n*sizeof(unsigned char));
	 if( mainMemory != NULL ) {
	   for(int i = 0; i < n; i++ )
		   mainMemory[i] = 0;
	 } else printf("Не удалось выделить память");

    return mainMemory;
}

public static void Free(unsigned char *m){
    try {
	  free(m); 
	  printf("Память удачно очищена");
	} catch { 
		printf("Не удалось очистить память");
	}
}

public static bool Occupied(int n){
	boolMemory = (bool*) malloc(n*sizeof(bool));
	for (int i = 0; i < n; i++){
	  if  (mainMemory[i] != 0)
		  boolMemory[i]=true;//значит уже занят
	}
	return boolMemory;
}

//=====================================================================================================
//потоки

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


public static void getItem(Tread thr){//тип?
	int id = thr.thId;
	int startPos = thr.iStart;
	int endPos = thr.iEnd;
	unsigned char *mem = thr.mem;
}
  
//====================================================================================================
//управление памятью и потоками

//какого его сделать типа?
public static void MemoryManager(){
   
   Malloc(100);
   getItem(Thread thr);//плюс массив для многих потоков
   
}

   public static Thread ThreadManager(){
	 newThread(1, 0, 200, mainMemory);
	 newThread(2, 300, 400, mainMemory);
     newThread(1, 201, 350, mainMemory);//как вести контроль за вот таким "невлезанием"

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

