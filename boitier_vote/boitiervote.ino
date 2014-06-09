#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int boutonRouge = 2;
const int boutonVert = 3;
const int ledRouge = 13;
const int ledVerte = 12; 
const int nbBlinkVote = 3;

#define BoutonRougeOn (digitalRead(boutonRouge)==HIGH)
#define BoutonRouge (digitalRead(boutonRouge))
#define BoutonVertOn  (digitalRead(boutonVert)==HIGH)
#define BoutonVert (digitalRead(boutonVert))
#define LedRougeOn (digitalWrite(ledRouge, LOW))
#define LedRougeOff (digitalWrite(ledRouge, HIGH))
#define LedVerteOn (digitalWrite(ledVerte, LOW))
#define LedVerteOff (digitalWrite(ledVerte, HIGH))

int etatBoutonRouge; int etatBoutonRougeOld;
int etatBoutonVert; int etatBoutonVertOld;

int compteurScrolling;
int compteurVoteOk;
int compteurVoteKo;

String affiche;

void setup()
{
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  pinMode(boutonRouge, INPUT);
  pinMode(boutonVert, INPUT);
  
  etatBoutonRouge = HIGH; //on initialise l'état du bouton comme "relaché"
  etatBoutonVert = HIGH; //on initialise l'état du bouton comme "relaché"
  etatBoutonRougeOld=etatBoutonRouge;
  etatBoutonVertOld=etatBoutonVert;
  
  LedRougeOff;
  LedVerteOff;
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcdHome();
  
  compteurScrolling = 0;
  compteurVoteOk = 0;
  compteurVoteKo = 0;
}

void loop()
{
  delay(50);
  compteurScrolling++;
  if (compteurScrolling > 7) {
    // Scroll ttes les 7x50 ms
    lcd.scrollDisplayLeft();
    compteurScrolling=0;
  }
   
   // détection d'un vote -> flanc montant du bouton
   etatBoutonRouge = BoutonRouge;
   etatBoutonVert = BoutonVert;
   if (etatBoutonRougeOld && !etatBoutonRouge) {
     lcdVote(LOW);
   } else {
     // Détection du front montant bouton vert
     if (etatBoutonVertOld && !etatBoutonVert) {
       lcdVote(HIGH);
     }
   }
   
  etatBoutonRougeOld=etatBoutonRouge;
  etatBoutonVertOld=etatBoutonVert;
}

void lcdHome() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*** BreizhCamp ***");
  lcd.setCursor(0,1);
  if ( (compteurVoteOk == 0) && (compteurVoteKo == 0) ) {
    lcd.print("Votez pour la conf.");
  }
  else {
    affiche = "OK : ";
    affiche = affiche + compteurVoteOk + " - KO : ";
    affiche = affiche + compteurVoteKo + " ";
    lcd.print(affiche);
  }
}

void lcdVoteOk() {
  compteurVoteOk++;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ton vote :");
  lcd.setCursor(0,1);
  lcd.print("Yeah ... +1 !");
  for (int i; i<nbBlinkVote; i++) {
    delay(200);
    lcd.noBacklight();
    LedVerteOn;
    delay(200);
    lcd.backlight();
    LedVerteOff;
  }
}

void lcdVoteKo() {
  compteurVoteKo++;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ton vote :");
  lcd.setCursor(0,1);
  lcd.print("Ouh ... -1 !");
  for (int i; i<nbBlinkVote; i++) {
    delay(200);
    lcd.noBacklight();
    LedRougeOn;
    delay(200);
    lcd.backlight();
    LedRougeOff;
  }
}

void lcdVote(int vote) {
  if (vote==HIGH) {
    lcdVoteOk();
  }
  else {
    lcdVoteKo();    
  }
  lcdHome();
}
