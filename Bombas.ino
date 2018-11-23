//Constantes
#define caudal 100 //investugar el caudal de la bomba utilizada.
#define Bom1a 8  //Pin de la bomba 1 normalmete abierto
#define Bom2a 9  //Pin de la bomba 2 normalmete abierto
#define Bom3a 10  //Pin de la bomba 3 normalmete abierto
#define Bom1c 11  //Pin de la bomba 1 normalmete cerrado
#define Bom2c 12 //Pin de la bomba 2 normalmete cerrado
#define Bom3c 13  //Pin de la bomba 3 normalmete cerrado


 int cantidad,fin=0; //cantidad de liquido en mililitros 
 char chido[3]; //variable donde se almacenaran los datos enviados

void setup()
{
  // put your setup code here, to run once:
   Serial.begin (9600);
  //Configurando control de bombas
  pinMode(Bom1a, OUTPUT);
  pinMode(Bom2a, OUTPUT);
  pinMode(Bom3a, OUTPUT);
  pinMode(Bom1c, OUTPUT);
  pinMode(Bom2c, OUTPUT);
  pinMode(Bom3c, OUTPUT);
 
  
}

    void serialEvent() //El evanto se ejecutara cuando el if se cumpla, que sucede cuando el serial tenga datos
  {
   
    //avalible verifica que existan datos en el buffer del puerto serie
    if(Serial.available()>0)
    {
      for(int i=0;i<4;i++)
      {
        chido[i]=Serial.read(); //Se almacenan los datos enviados por el puerto donde chido 0 es el control, chido 1 es el control de bombas, chido 2 es la cantidad de liquido en ml
      }
      
    
    }
  }
  void loop()
  {
     int volumen=(int)chido[2];
      switch(chido[0])
      {
        case 'a': //El caso en el que los motores esten apagados porque no hay ningun movimiento de motores se envia un caracter "a" 
          digitalWrite(Bom1c, HIGH);
          digitalWrite(Bom2c, HIGH);
          digitalWrite(Bom3c, HIGH);
          break;
        case 'e'://El caso encendido 
            switch(chido[1])//Se define si es el motor 1 2 o 3 
            {
              case '1':
                digitalWrite(Bom1a, HIGH);
                delay((volumen/caudal)*1000);
                digitalWrite(Bom1c,HIGH);
                fin=1;
                Serial.write(fin);
                break;
             case '2':
                digitalWrite(Bom2a, HIGH);
                delay((volumen/caudal)*1000);
                digitalWrite(Bom2c,HIGH);
                fin=1;
                Serial.write(fin);
                break;
              case '3':
                digitalWrite(Bom3a, HIGH);
                delay((volumen/caudal)*1000);
                digitalWrite(Bom3c,HIGH);
                fin=1;
                Serial.write(fin);
                break;
            }
              
          
          break;
      }
      fin=0;
    }
 
