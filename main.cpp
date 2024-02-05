//Robots.cpp
//CISP 400,Esther Dara
//5/18/2021

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;


class Robots {
  
  public:
  int XSpot, YSpot,MaxEnergy, CalcEnergy,
  ActivateAllGenes,Spins,CheckRobot;

  int MAP[10][10];// the Map
  int GENES[16][5];// for number of genes
  int TERRITORY[4];// area surrounding for map
  
  //void functions for Map
  void MakeMap();
  void ProduceGenes();
  void GeneCheck();
  void PlaceBatts();
  void TerritoryArray();
  void ViewTerritory();
  void MatchGenes();
  void CopyRobotLife();
  void InitializeGain();
  void ExperimentPlace();
  void RobotSpot (int XSpot,int YSpot);

  
    Robots() {

      MaxEnergy = 5; //max energy set to 5
      
      CalcEnergy=0;

      XSpot=(rand()%8)+1; YSpot=(rand()%8)+1;
      
        ProduceGenes(); // For producing genes

        MakeMap(); //in order to create the map
        
        PlaceBatts();//in order to place the batteries
        
        RobotSpot (XSpot,YSpot);// Variables for X an Y spot on map

        TerritoryArray();//Array for the Territory

        MatchGenes();// For the any gene matches

        CopyRobotLife(); //Copying
        
    }
};


void Robots::InitializeGain(){
  CalcEnergy=0;MaxEnergy=5;XSpot=(rand()%8)+1;YSpot=(rand()%8)+1;
}
void Robots::ExperimentPlace(){

}
void Robots::CopyRobotLife(){
  int RobotTurn=5; 
  while(MaxEnergy>1)  //energy set to higher than 1
  {
    if (ActivateAllGenes==0 and TERRITORY[0]!=2 and TERRITORY[0]==0){
     //moving North to a free spot
        MAP[XSpot][YSpot]=0;
        XSpot-=1;
    }
    else if(ActivateAllGenes==0 and TERRITORY[0]!=2 and TERRITORY[0]==1){  //moving toward North
      
        MAP[XSpot][YSpot]=0;
        XSpot=XSpot-1; 
        RobotTurn+=5;
        MaxEnergy+=5;CalcEnergy+=1;
    } 
      else if(ActivateAllGenes==1 and TERRITORY[1]!=2 and TERRITORY[1]==0){  //moving East to a free spot
        
          MAP[XSpot][YSpot]=0;
          YSpot+=1;
      }
      else if(ActivateAllGenes==1 and TERRITORY[1]!=2 and TERRITORY[1]==1){ //  moving East
        
          MAP[XSpot][YSpot]=0;
          YSpot+=1;
          RobotTurn+=5;
          MaxEnergy+=5;CalcEnergy+=1;
        }
        else if(ActivateAllGenes==2 and TERRITORY[2]!=2 and TERRITORY[2]==0){ // moving South into a free spot
          
          MAP[YSpot][YSpot]=0;
          XSpot+=1;
        }
        else if(ActivateAllGenes==2 and TERRITORY[2]!=2 and TERRITORY[2]==1){
          // moving North again
          MAP[XSpot][YSpot]=0;
          XSpot=YSpot+1;
          RobotTurn+=5;
          MaxEnergy+=5;CalcEnergy+=1;
        }
          else if(ActivateAllGenes==3 and TERRITORY[3]!=2 and TERRITORY[3]==0){
            // moving West into a free spot 
            MAP[XSpot][YSpot]=0;
            YSpot-=1;
          }
          else if(ActivateAllGenes==3 and TERRITORY[3]!=2 and TERRITORY[3]==1){
            // moving toward West 
            MAP[XSpot][YSpot]=0;
            YSpot-=1;
            RobotTurn+=5;
            MaxEnergy+=5;CalcEnergy+=1;
          }
      RobotSpot (XSpot, YSpot);
      TerritoryArray();
      MaxEnergy=-1;
      
  }
  
}

void Robots::MatchGenes(){
 for(int i=0;i<16;i++){
  if(TERRITORY[0]==MAP[i][0] and TERRITORY[1]==MAP[i][1] and TERRITORY[2]==MAP[i][2] and TERRITORY[3]==MAP[i][4]){
    ActivateAllGenes=MAP[i][4]; //placing the Activation all genes
    
  }
 }
 if(ActivateAllGenes==4){
   ActivateAllGenes=rand()%3;//the random number is 4
 }
}
void Robots::TerritoryArray(){
  
TERRITORY[0]=MAP[XSpot-1][YSpot]; //territory-north
  
TERRITORY[1]=MAP[XSpot][YSpot+1]; //territory-east

TERRITORY[2]=MAP[XSpot+1][YSpot]; //territory-south
 
TERRITORY[3]=MAP[XSpot][YSpot-1]; //territory-west

}
void Robots::ViewTerritory(){
  for(int i=0;i<4;i++){
    cout<<TERRITORY[i]<<"";;
  }cout<<endl;
}

void Robots::PlaceBatts(){
  int i=0,j=0;
  int Battery=0;
  
  while(Battery<40){//battery less than 40
    i= (rand()%8)+1;
    j= (rand()%8)+1; 
      while(MAP[i][j]==1){
        i= (rand()%8)+1;j=(rand()%8)+1;
      }
    MAP[i][j]=1;
    Battery++;
  }
}

void Robots::ProduceGenes(){

for(int i=0;i<16;i++){
  for(int g=0;g<4;g++){
GENES[i][g]=rand()%3;
  }
 //action gene movement
  for(int z=0;z<16;z++){
    GENES[z][4]=rand()%4;
  }
}
}

void Robots:: RobotSpot(int XSpot,int YSpot){
  MAP[XSpot][YSpot]=9;

}


void Robots :: GeneCheck(){ //to look at genes are matched 
for(int i=0;i<16;i++){
  for(int j=0;j<5;j++){
  cout<<GENES[i][j]<<" ";
  }
    cout<<endl;
}
}

void Robots::MakeMap(){ //making Pop for Map
int e=0,f=0,
j=0,k=0, 
x=0,y=0,
c=0,d=0;
  
   for (int i=0;i<10;i++){
    for(int j=0;j<10;j++){
    MAP[j][i]=0;
    }
}
  
  for(int f=0;e<10;e++){ //Building wall
    MAP[e][f]=2;
  }

 
  for(int d=0;c<10;c++){  //to get left side of the map
    MAP[c][d]=2;
  }
  
  for(int y=9;x<10;x++){ //to get right side of the map
    MAP[x][y]=2;
  }


  for(int j=9;k<10;k++){ //to get bottom of the map
    MAP[j][k]=2;
  }
}

void Temp_P(Robots POPArray[],Robots TEMP[]); // for the Temp_P function

int main() {
int GENER = 50; //amount of generations
srand(time(NULL)); //for getting random values


Robots POP[200]; //Population Array

do{

Robots TEMP[200]; //Temp variable
Robots TemporaryTemp; 


float KeepCount;
  for(int i=0;i<200;i++){
    KeepCount+=POP[i].CalcEnergy;
  }

  cout<<" Robot Gen (Ave Batteries): "<<KeepCount/200<<endl; //population 200
    
  
  
  for(int i = 0; i<200; i++) {
   for(int j = i+1; j<200; j++)
   {
      if(POP[j].CalcEnergy< POP[i].CalcEnergy) {
       
         TemporaryTemp=POP[i];
         
         POP[i]=POP[j];
        
         POP[j]=TemporaryTemp;
      }
   }
  }
    
    for(int i=100;i<200;i++){ //highest temp 100,less than 200
     TEMP[i] =POP[i];
    }
      
      Temp_P(POP,TEMP);
      
     
      for(int l=0;l<200;l++){
        POP[l]=TEMP[l];
      }

        
        GENER-=1;
}while( GENER>0);


}

void Temp_P(Robots POP[],Robots TEMP[]){
for(int j=0;j<100;j++){
for(int i=0;i<8;i++){
 TEMP[i]= POP[i];
}
for(int i=8;i<16;i++){
  TEMP[i]=POP[i];
}
}
}