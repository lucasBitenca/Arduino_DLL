
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFi_nmcu8266.h>

ESP8266WiFiMulti WiFiMulti;

void WiFi_nmcu8266::Set_SSID(char* ssid){
  this->Ssid = ssid;
}

void WiFi_nmcu8266::Set_PWD(char* pwd){
  this->Pwd = pwd;
}

void WiFi_nmcu8266::Set_HOST(char* nm_host){
  this->Nm_host = nm_host;
}

bool WiFi_nmcu8266::ConectarWiFi(){

  int tentativas = 0;
  int lim_tentativas = 10;

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(Ssid, Pwd);

  delay(1500);
  Serial.println();
  Serial.println();
  Serial.print("Esperando por conexão... ");

  while (WiFiMulti.run() != WL_CONNECTED && tentativas <= lim_tentativas) {
    Serial.print("Tentativa ");
    Serial.print(tentativas);
    Serial.print(" de ");
    Serial.println(lim_tentativas);
    tentativas++;
    delay(50);
  }
  if(WiFiMulti.run() == WL_CONNECTED){
    ObterIP();
    return true;
  }
  return false;

}

void WiFi_nmcu8266::ObterIP(){
  Serial.print("Conectado. IP: ");
  Serial.println(WiFi.localIP());
  delay(25);
}

void WiFi_nmcu8266::VerificarConexao(){
  if(WiFiMulti.run() != WL_CONNECTED){
    ConectarWiFi();
  }

}
