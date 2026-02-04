
int btn1 = 6;     // Declara que o botão 1 está conectado ao pino digital 6
int btn2 = 4;     // Declara que o botão 2 está conectado ao pino digital 4
int btn3 = 2;     // Declara que o botão 3 está conectado ao pino digital 2

int rele1 = 8;    // Declara que o relé 1 está conectado ao pino digital 8
int rele2 = 10;   // Declara que o relé 2 está conectado ao pino digital 10

int btnstate = 0;   // Cria variável para armazenar a leitura atual do botão 1
int btnstate2 = 0;  // Cria variável para armazenar a leitura atual do botão 2
int btnstate3 = 1;  // Cria variável para armazenar a leitura atual do botão 3 (iniciada em 1)

int relestate = 1;  // Variável para controlar se o relé 1 está ligado ou desligado
int relestate2 = 1; // Variável para controlar se o relé 2 está ligado ou desligado

int before = 0;     // Variável para guardar o estado anterior e detectar se o botão foi clicado
 

void setup() {
 
pinMode(btn1, INPUT);  // Configura o pino do botão 1 como entrada de sinal
pinMode(btn2,INPUT);   // Configura o pino do botão 2 como entrada de sinal
pinMode(btn3,INPUT);   // Configura o pino do botão 3 como entrada de sinal

pinMode(rele1, OUTPUT); // Configura o pino do relé 1 como saída de energia
pinMode(rele2, OUTPUT); // Configura o pino do relé 2 como saída de energia
}

void loop() {
 
btnstate = digitalRead(btn1);           // Lê o estado atual do botão 1 (HIGH ou LOW)
if(btnstate == HIGH && before == LOW){  // Se o botão está apertado E antes estava solto (clique)
  relestate = !relestate;               // Inverte o valor do estado do relé (liga/desliga)
}

digitalWrite(rele1,relestate);          // Aplica o valor da variável relestate ao pino físico 8
before = btnstate;                      // Atualiza a variável 'before' com o estado atual do botão 1
delay(50);                              // Aguarda 50 milissegundos (ajuda a evitar leituras falsas/ruído)
 

 btnstate2 = digitalRead(btn2);         // Lê o estado atual do botão 2
if(btnstate2 == HIGH && before == LOW){ // Se o botão 2 está apertado E a variável 'before' está LOW
  relestate2 = !relestate2;             // Inverte o valor do estado do relé 2
}
digitalWrite(rele2,relestate2);         // Aplica o valor da variável relestate2 ao pino físico 10
before = btnstate2;                     // Atualiza a variável 'before' com o estado atual do botão 2
delay(50);                              // Aguarda mais 50 milissegundos

btnstate3 = digitalRead(btn3);          // Lê o estado atual do botão 3
  if (btnstate3 == HIGH) {              // Se o botão 3 for pressionado (sinal HIGH)
    
    relestate = 1;                      // Define a variável do relé 1 como 1 (geralmente desligado)
    relestate2 = 1;                     // Define a variável do relé 2 como 1 (geralmente desligado)
    
    digitalWrite(rele1, HIGH);          // Envia sinal HIGH fisicamente para o pino do relé 1
    digitalWrite(rele2, HIGH);          // Envia sinal HIGH fisicamente para o pino do relé 2
  }
 
}
