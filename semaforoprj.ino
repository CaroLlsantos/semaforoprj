//Biblioteca utilizada para utilização do WiFi no Esp32.
// WiFi vai controlar o Acess Point 
// WiFiCliente permite conectar a um roteador.
#include <WiFi.h>
#include <WiFiClient.h>
//biblioteca para executar um serviço de HTTP, para publicar os arquivo html
#include <WebServer.h>
#include <string.h>

//Instancia a biblioteca WebServer, indicando an porta 80 que é a padrão do HTTP
WebServer server(80);

//Configuração de rede Wifi, Nome, Senha.
const char *ssid = "Semáforo-MIIA";
const char *password= "MIIA0406";

//definição das configuração de rede
IPAddress local_IP(192,168,0,80);
IPAddress gateway(191,168,0,1);
IPAddress subnet(255,255,255,0);


//Declaração de pinos
//Semáforo 01
const int vermelho1 = 2;
const int amarelo1 = 4;
const int verde1 = 5;
//Semáforo 02
const int vermelho2 = 19;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
const int amarelo2 = 21;
const int verde2 =23;
// Variaveis de tempo
int tempoA = 3000; //Tempo Amarelo
int tempoVER = 5000; //Tempo Verde

void setup() {
  
  Serial.begin(115200);
Serial.print("Configuração AP.......");
// Se aparecer "ok" a configuração está certa do local_IP, gateway, subnet.
// Se aparecr "Erro" a configuração de algum deles (local_IP, gateway, subnet) está errado
Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet)?"OK" : "Erro");
Serial.print("Iniciando o Wifi.......");
Serial.println(WiFi.softAP(ssid, password));
Serial.print("Endereço de IP.......");
Serial.println(WiFi.softAPIP());

  //Definindo os pinos como saída
  pinMode(vermelho1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(verde1, OUTPUT);

  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
   Serial.begin(115200);
}

void loop() {
luzSemaforo();
}

  void luzSemaforo () {
    //Vermelho-verde
    //Vermelho-amarelo
    //Verde-vermelho
    //amarelo-vermelho
    //vermelho-verde
    acenderLed(vermelho1);
    acenderLed(verde2);
    delay(tempoVER);
    apagarLed(verde2);
    acenderLed(amarelo2);
    delay(tempoA);
    apagarLed(amarelo2);
    apagarLed(vermelho1);
    acenderLed(verde1);
    acenderLed(vermelho2);
    delay(tempoVER);
    apagarLed(verde1);
    acenderLed(amarelo1);
    delay(tempoA);
    apagarLed(amarelo1);
    apagarLed(vermelho2);
  }



void acenderLed (int led){
  digitalWrite(led, HIGH);
}

void apagarLed (int led){
  digitalWrite(led, LOW);
}
