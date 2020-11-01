byte nbAlea;
byte ledHautGauche=3;
byte ledBasGauche=2;
byte ledCentre=6;
byte ledHautDroite=5;
byte ledBasDroite=4;
byte bouton=8;

//fonction d'initialisation
void setup() {
  randomSeed(analogRead(0));
  
  for (int t=2;t<7;t++){
    pinMode(t,OUTPUT);
    digitalWrite(t,LOW);
  }

  pinMode(bouton,INPUT_PULLUP);
}


void loop() {

  if(!digitalRead(bouton)){ 
    nbAlea = random(0,5);
    
    int delai = 500;
    
    for (byte tour=0;tour<10;tour++){ 
        for (byte nb=0;nb<6;nb++){
          affichage(nb);
          delay(delai);
        }
        delai=delai-50;
      }
  
    for (byte cli=0;cli<10;cli++){
      affichage(5);
      delay(50);
      for (byte pin=2;pin<7;pin++){
        digitalWrite(pin,LOW);
      }
      delay(50);
    }
  
    for (byte w=0;w<4;w++){
      affichage(nbAlea);
      delay(300);
      for (byte pin=2;pin<7;pin++){
        digitalWrite(pin,LOW);
      }
      delay(300);
  }

affichage(nbAlea);
delay(4000);
  }
  
}

void setZero(){
  for (int t=2;t<7;t++){
    digitalWrite(t,LOW);
  }
}

void affichage(int nombre){
  
  setZero();
    
  if (nombre==1){
    digitalWrite(ledCentre,HIGH);
    return;
  }
  if (nombre==2){
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    return;
  }
  if (nombre==3){
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledCentre,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    return;
  }
  if (nombre==4){
    digitalWrite(ledHautGauche,HIGH);
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    digitalWrite(ledBasDroite,HIGH);
    return;
  }
  if (nombre==5){
    digitalWrite(ledHautGauche,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledBasDroite,HIGH);
    digitalWrite(ledCentre,HIGH);
    return;
  }
  return;
}
