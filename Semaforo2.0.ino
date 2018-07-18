// Semaforo_Bryan_UNEMAT
// 
// Made by Bryan Duarte, Natanael Pião
// License: LGPL

int sensor_1 = 52;
int sensor_2 = 53;

int semaforo_1[2] = {24,25};//avenida
int semaforo_2[2] = {30,31};//avenida
int semaforo_3[2] = {26,27};
int semaforo_4[2] = {28,29};

void verde(int, int);//pinos do led
void vermelho(int, int);//pinos do led
void fecha_tudo();
void abre_lado(int);//porta do sensor

//pedestres
int pd_verde = 22;
int pd_vermelho = 23;
int pd_buzzer = 4;
int pd_botao = 5;

void pd_parar();
void pd_aberto();

void controle_manual();//controle manual no Painel
void inverte(int, int);//inverte os semaforo

//botoes controle manual
int sensor_btn_ativa = 51;
int btn_sem_1 = 50;
int btn_sem_2 = 49;
int btn_sem_3 = 48;
int btn_sem_4 = 46;
int control_ativ = 41;
int control_desligado = 40;

void setup()
{
  for(int i=0;i<2;i++)
  {
    pinMode(semaforo_1[i], OUTPUT);
    pinMode(semaforo_2[i], OUTPUT);
    pinMode(semaforo_3[i], OUTPUT);
    pinMode(semaforo_4[i], OUTPUT);
  }
  
  pinMode(sensor_1, INPUT_PULLUP);
  pinMode(sensor_2, INPUT_PULLUP);

  pinMode(pd_verde, OUTPUT);
  pinMode(pd_vermelho, OUTPUT);
  pinMode(pd_buzzer, OUTPUT);
  pinMode(pd_botao, INPUT_PULLUP);

  pinMode(sensor_btn_ativa, INPUT_PULLUP);
  pinMode(btn_sem_1, INPUT_PULLUP);
  pinMode(btn_sem_2, INPUT_PULLUP);
  pinMode(btn_sem_3, INPUT_PULLUP);
  pinMode(btn_sem_4, INPUT_PULLUP);
  pinMode(control_ativ, OUTPUT);
  pinMode(control_desligado, OUTPUT);

  
  pd_parar();
  fecha_tudo();
  digitalWrite(control_desligado, HIGH);
  digitalWrite(control_ativ, LOW);
  
  Serial.begin(9600);
}

void loop()
{
  /*Serial.print("Sensor 1: ");
  Serial.println(digitalRead(sensor_1));
  Serial.print("Sensor 2: ");
  Serial.println(digitalRead(sensor_2));*/

  if(!digitalRead(sensor_btn_ativa))
  {
    controle_manual();
  }
  
  if(!digitalRead(pd_botao))
    {
      delay(700);
      pd_aberto();
      delay(1000);
      pd_parar();
      verde(semaforo_1[0],semaforo_1[1]);
      delay(2000);
        
      vermelho(semaforo_1[0],semaforo_1[1]);
      verde(semaforo_2[0],semaforo_2[1]);
      delay(2000);  
    }
  
    
    if(!digitalRead(sensor_1))
    {
      abre_lado(sensor_1);
      verde(semaforo_1[0],semaforo_1[1]);
      delay(2000);
      
      vermelho(semaforo_1[0],semaforo_1[1]);
      verde(semaforo_2[0],semaforo_2[1]);
      delay(2000);
    }
    else
    {
      vermelho(semaforo_2[0],semaforo_2[1]);
      verde(semaforo_1[0],semaforo_1[1]);
      delay(2000);
      
      vermelho(semaforo_1[0],semaforo_1[1]);
      verde(semaforo_2[0],semaforo_2[1]);
      delay(2000);
    }

    if(!digitalRead(sensor_2))
    {
      abre_lado(sensor_2);
      verde(semaforo_1[0],semaforo_1[1]);
      delay(2000);
      
      vermelho(semaforo_1[0],semaforo_1[1]);
      verde(semaforo_2[0],semaforo_2[1]);
      delay(2000);
    }    
}

void verde(int verde, int verm)
{
  digitalWrite(verde,HIGH);
  digitalWrite(verm,LOW);
}
void vermelho(int verde, int verm)
{
  digitalWrite(verde,HIGH);
  digitalWrite(verm,HIGH);
  delay(1000);
  
  digitalWrite(verde,LOW);
  digitalWrite(verm,HIGH);
}
void fecha_tudo()
{
    vermelho(semaforo_2[0], semaforo_2[1]);
    digitalWrite(semaforo_1[1], HIGH);
    digitalWrite(semaforo_3[1], HIGH);
    digitalWrite(semaforo_4[1], HIGH); 
}
void abre_lado(int pin)
{
  vermelho(semaforo_2[0], semaforo_2[1]);
  if(pin == 52)
  {
    verde(semaforo_3[0],semaforo_3[1]);
    delay(2000);
    vermelho(semaforo_3[0],semaforo_3[1]);
  }
  else
  {
    verde(semaforo_4[0],semaforo_4[1]);
    delay(2000);
    vermelho(semaforo_4[0],semaforo_4[1]);
  }
}

void pd_parar()
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(pd_vermelho,HIGH);
    tone(pd_buzzer, 20000);
    delay(500);
    
    noTone(pd_buzzer);
    digitalWrite(pd_vermelho,LOW);
    delay(500);
  }
  digitalWrite(pd_vermelho,HIGH);
  digitalWrite(pd_verde,LOW);
}
void pd_aberto()
{
  fecha_tudo();
  digitalWrite(pd_vermelho,LOW);
  digitalWrite(pd_verde,HIGH);
  delay(500);
}

void controle_manual()
{
  fecha_tudo();
  digitalWrite(control_desligado, LOW);
  digitalWrite(control_ativ, HIGH);
  delay(1000);//delay para nao sair da funcao, pois o botao estara pressionado
  while(true)
  {    
    if(!digitalRead(sensor_btn_ativa))//retorna ao funcionamento normal
      break;

    if(!digitalRead(btn_sem_1))
    {
      inverte(semaforo_1[0],semaforo_1[1]);
      delay(1000);
    }
    else
    {
      if(!digitalRead(btn_sem_2))
      {
        inverte(semaforo_2[0],semaforo_2[1]);
        delay(1000);
      }
      else
      {
        if(!digitalRead(btn_sem_3))
        {
          inverte(semaforo_3[0],semaforo_3[1]);
          delay(1000);
        }
        else
        {
          if(!digitalRead(btn_sem_4))
          {
            inverte(semaforo_4[0],semaforo_4[1]);
            delay(1000);
          }
        }
      }
    }
  }

    //antes de retornar, todos os semaforos ficam vermelhos
    digitalWrite(semaforo_1[0], LOW);
    digitalWrite(semaforo_2[0], LOW);
    digitalWrite(semaforo_3[0], LOW);
    digitalWrite(semaforo_4[0], LOW);
    digitalWrite(semaforo_1[1], HIGH);
    digitalWrite(semaforo_2[1], HIGH);
    digitalWrite(semaforo_3[1], HIGH);
    digitalWrite(semaforo_4[1], HIGH);

    digitalWrite(control_desligado, HIGH);
    digitalWrite(control_ativ, LOW);
}

void inverte(int p1, int p2)
{
  if(digitalRead(p1))
  {
    vermelho(p1,p2);
    return;
  }
  if(digitalRead(p2))
  {
    verde(p1,p2);
    return;
  }
}

