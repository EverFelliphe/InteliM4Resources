int laststate = 0;
int level = 1;
const int MAX_LEVEL=100;
int velocidade=2000;
int sequencia[MAX_LEVEL];
int minha_sequencia[MAX_LEVEL];
void setup(){
  Serial.begin(115200);
  Serial.println("foi");
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);



}
void loop(){
  Serial.println(digitalRead(34));
;
  if(level ==1){
          gerar_sequencia();
        }
  if(digitalRead(34)==1 || level!= 1 ){
    mostrar_sequencia();
    reconhecer_sequencia();
  }

}
void gerar_sequencia(){
  randomSeed(millis());
  for(int i =0; i<MAX_LEVEL;i++){
    sequencia[i] = random(16,20);
  }

}

void mostrar_sequencia(){
  digitalWrite(16,0);
  digitalWrite(17,0);
  digitalWrite(18,0);
  digitalWrite(19,0);
  for (int i; i<level;i++){
    digitalWrite(sequencia[i],1);
    delay(velocidade);
    digitalWrite(sequencia[i],0);
    delay(200);
  }

}
void reconhecer_sequencia(){
    
    for(int i = 0;i<level ; i++){
      int jogou = 0;
      while(jogou==0){
        if(digitalRead(35) == 0){
          digitalWrite(16,1);
          jogou=1;
          minha_sequencia[i]=16;
          delay(200);
          if(minha_sequencia[i] != sequencia[i]){
            codigo_errado();
            return;
          }
          digitalWrite(16,0);
        }
        if(digitalRead(32) == 0){
          digitalWrite(17,1);
          jogou=1;
          minha_sequencia[i]=17;
          delay(200);
          if(minha_sequencia[i] != sequencia[i]){
            codigo_errado();
            return;
          }
          digitalWrite(17,0);
        }
        if(digitalRead(33) == 0){
          digitalWrite(18,1);
          jogou=1;
          minha_sequencia[i]=18;
          delay(200);
          if(minha_sequencia[i] != sequencia[i]){
            codigo_errado();
            return;
          }
          digitalWrite(18,0);
        }
        if(digitalRead(25) == 0){
          digitalWrite(19,1);
          jogou=1;
          minha_sequencia[i]=19;
          delay(200);
          if(minha_sequencia[i] != sequencia[i]){
            codigo_errado();
            return;
          }
          digitalWrite(19,0);
        }

      }
    }
codigo_certo();    
}
void codigo_errado(){
  for (int i = 0; i < 3;  i++)
{
digitalWrite(16, HIGH);
digitalWrite(17, HIGH);
digitalWrite(18,  HIGH);
digitalWrite(19, HIGH);
delay(250);
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);
delay(250);
}
level  = 1;
velocidade = 1000;
}
void codigo_certo(){
digitalWrite(16, HIGH);
digitalWrite(17, HIGH);
digitalWrite(18,  HIGH);
digitalWrite(19, HIGH);
delay(250);
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);
delay(250); 
velocidade -= 200;
level ++;
}