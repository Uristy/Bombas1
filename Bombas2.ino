//Constantes
#define caudal 100 //investugar el caudal de la bomba utilizada.
#define B1 5 //Pin del boton 1
#define B2 6 //Pin del boton 1
#define B3 7 //Pin del boton 1

#define Bom1a 8  //Pin de la bomba 1 normalmete abierto
#define Bom1c 9  //Pin de la bomba 2 normalmete abierto
#define Bom2a 10  //Pin de la bomba 3 normalmete abierto
#define Bom2c 11  //Pin de la bomba 1 normalmete cerrado
#define Bom3a 12 //Pin de la bomba 2 normalmete cerrado
#define Bom3c 13  //Pin de la bomba 3 normalmete cerrado

void setup()
{
  // put your setup code here, to run once:
   Serial.begin (9600);
   //configurando control de botones
   pinMode(B1, INPUT);
   pinMode(B2, INPUT);
   pinMode(B3, INPUT);
  //Configurando control de bombas
  pinMode(Bom1a, OUTPUT);
  pinMode(Bom2a, OUTPUT);
  pinMode(Bom3a, OUTPUT);
  pinMode(Bom1c, OUTPUT);
  pinMode(Bom2c, OUTPUT);
  pinMode(Bom3c, OUTPUT);
 
  
}
void loop()
{
  if(B1==HIGH)
    {
      digitalWrite(Bom1a, HIGH);
    }
   else
   {
     digitalWrite(Bom1c, HIGH);
   }
   if(B2==HIGH)
    {
      digitalWrite(Bom2a, HIGH);
    }
   else
   {
     digitalWrite(Bom2c, HIGH);
   }
   if(B3==HIGH)
    {
      digitalWrite(Bom3a, HIGH);
    }
   else
   {
     digitalWrite(Bom3c, HIGH);
   }
}

    
