#include <ModbusSerial.h>




// C++ code
// Diritivas defines pinagem do arduino

#define led_1 4
#define led_2 5
#define led_3 6
#define inp_7 7
#define inp_8 8

//registro de offsets

const int led_val = 0;

// modbus serial objeto
ModbusSerial mb;

//variavel global aux

int aux=0;
int aux_1=0;
int aux_2=0;



void setup()
{
  //modbus serial

 mb.config(&Serial,9600,SERIAL_8N1);

 //slave (1-247)

 mb.setSlaveId(1);

 //registre
 mb.addCoil(led_val);

 //setup inicialização de inputs e outputs
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(inp_7, INPUT);
  pinMode(inp_8, INPUT);
  Serial.begin(19600);  
}

void loop()
{

// TESTE

digitalWrite(led_1,mb.Coil(led_val));


// MODBUS


//leitura da entrada 7 junto a um laço condicional if
  
  
  
  if(digitalRead(inp_7)==1)
  {
    delay(1200);/*esse delay e usado para espera alguns milis
    segundos para releitura dos estados dos botões.*/
    
    aux=aux+1; 

    for(int i=1;i<=3;i++)
    {
    digitalWrite(led_1, HIGH);
    delay(200);
    digitalWrite(led_1, LOW); 
      
    digitalWrite(led_2, HIGH);
    delay(200);
    digitalWrite(led_2, LOW);
      
    digitalWrite(led_3, HIGH);
    delay(200);
    digitalWrite(led_3, LOW);
    }
    
    // se verdadeiro o valor 0 e passado para var aux
    
    
    if (aux==2){
    aux=0;
    digitalWrite(led_1, LOW); 
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW); }
  }
 
  
  
  //retire os comentarios e veja oque acontece no monitor serial 
  
  //Serial.println(aux_1);
  //Serial.println(digitalRead(inp_8));
  //Serial.println(aux);
  //Serial.println(digitalRead(inp_7));
  
  // se verdadeiro o bloco abaixo e executado
  
  if(aux==1)
  { 
  
  digitalWrite(led_1, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(led_1, LOW); 
    
     
    if(digitalRead(inp_7)==1)
  {
    delay(1200);/*esse delay e usado para espera alguns milis
    segundos para releitura dos estados dos botões.*/
   
    aux=0;
            
    }
    else{
        aux_2=1;
      digitalWrite(led_2, HIGH);
      delay(2000); // Wait for 1000 millisecond(s)
      digitalWrite(led_2, LOW);}
    
    if(aux_2==1)
    {
         
    if(digitalRead(inp_7)==1)
  {
    delay(1000);/*esse delay e usado para espera alguns milis
    segundos para releitura dos estados dos botões.*/
    
    aux=0;
        aux_2=0;
    
    }
    else{
  aux_2=0;
  digitalWrite(led_3, HIGH);
  delay(4000); // Wait for 1000 millisecond(s)
  digitalWrite(led_3, LOW);}
    }
    
  }  // fim do condicional if 
  
  /*estrutura de codigo para contagem de pulso
  ligando cada led quando o contador e icrementado
  e resetando quando o valor 4 e atigindo.*/
  
    
  if(digitalRead(inp_8)==1)
  {
    aux_1=aux_1+1;
    
     delay(150);/*esse delay e usado para espera alguns milis
   segundos para releitura dos estados dos botões.*/
    
    if(aux_1==1)
    {
      digitalWrite(led_1, HIGH);
    }
    else if(aux_1==2)
    {
    digitalWrite(led_2, HIGH);

    }
    
    else if(aux_1==3)

    {

    digitalWrite(led_3, HIGH);

    }

    else if(aux_1>=4)

    {

    aux_1=0;
    digitalWrite(led_1, LOW); 
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW); 

    }

  } 

}
