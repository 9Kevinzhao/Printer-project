//Include standard files and other header files (aka h files to your other files).
#include <stdlib.h>
#include <stdio.h>
#include "paperTray.h"
#include "copyJob.h"
#include "user.h"



//Define the printer
struct Printer{
  char name[32];
  PaperTray trays[6];
  User userDB[3];
  int totalPagesPrinted;

};

int trayStatus(struct Printer* pPrinter,int traynum){

    PaperTray current =  *(pPrinter.trays[traynum-1]);
    return *(current.quantity);

}

int reloadTray(struct Printer* pPrinter,int num){
  if(num==2 || num==6){
  *pPrinter->trays[num-1]->total=1000;
}
else{
  *pPrinter->trays[num-1]->total=2000;
}
}

int printerStatus(struct Printer* pPrinter){
  int totalPage;
  for(short i=0;i<*pPrinter.trays.length;i++){
    total += *pPrinter.trays[i].total;
  }
  return totalPage;
}

int print(Printer *pPrinter,User *pUser,copyJob *pCopyJob){
  int num = *pCopyJob.pages;
  *pPrinter.totalPagesPrinted+=num;
  *pUser.pageCount+=num;
  for(short i=0;i<*pPrinter.trays.length;i++){
    if(*pPrinter.trays[i]>=num){
      *pPrinter.trays[i]-=num;
      break;
    }
    else{
      *pPrinter.trays[i]=0;
      num-=*pPrinter.trays[i];
    }
  }
  return 1;
}

int main(){
  //make users
User u1={"kevin",5};
User u2={"kevin",5};
User u3={"kevin",5};
int u1_ptr=&u1;
int u2_ptr=&u2;
int u3_ptr=&u3;


  //make copyJobs
copyJob job1={"essay",2,2,"my name is kevin"}


  //make trays

PaperTray T1={1,500,1000};
PaperTray T2={1,500,2000};
PaperTray T3={1,500,1000};
PaperTray T4={1,500,1000};
PaperTray T5={1,500,2000};
PaperTray T6={1,500,1000};
PaperTray pTray = {&T1,T2,T3,T4,T5,T6};

  //make printer
Printer P1={"kevin's_Printer", pTray,[*u1_ptr,*u2_ptr,*u3_ptr],0 }

  //begin printing


  //print user page counts and total print page count.


  //print printer status


  //reload a tray


  //ask again for a printerStatus

}
