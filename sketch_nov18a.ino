#define tmp 1100

const int buzzer = 11; 

int cont= 9;

int disp_pinos[8]= {2,3,4,5,6,7,8,9};
int digitos[10] [8]= {
  {1,1,1,1,1,1,0,0},//0
  {0,1,1,0,0,0,0,0},//1
  {1,1,0,1,1,0,1,0},//2
  {1,1,1,1,0,0,1,0},//3
  {0,1,1,0,0,1,1,0},//4
  {1,0,1,1,0,1,1,0},//5
  {1,0,1,1,1,1,1,0},//6
  {1,1,1,0,0,0,0,0},//7
  {1,1,1,1,1,1,1,0},//8
  {1,1,1,0,0,1,1,0},//9
};

void setup(){
  for(int i=0;i<8;i++){
    pinMode(disp_pinos[i], OUTPUT);
    pinMode(buzzer, OUTPUT);
  }
}

void loop(){
  digito(cont);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  cont--;
  delay(1300);
  digitalWrite(buzzer, LOW);
  delay(1000);
  if(cont == 0){
    for(int i = 0; i< 50; i++){
      delay(50);
      digitalWrite(buzzer, HIGH);
      cont = 9;
      delay(50);
      cont = 0;
      digitalWrite(buzzer, LOW);
    }
    cont = 9;
  }
}

void digito(int d){
  for(int i=0;i<8;i++){
    digitalWrite(disp_pinos[i], digitos[d][i]);
  }
}