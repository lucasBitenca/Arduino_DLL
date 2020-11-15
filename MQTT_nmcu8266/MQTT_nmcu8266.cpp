

#include <PubSubClient.h>
#include <WiFi_nmcu8266.h>
#include <MQTT_nmcu8266.h>
#include <WiFiClient.h>

WiFiClient mqttwifi;
PubSubClient MQTT(mqttwifi);
//Propriedades
void MQTT_nmcu8266::Set_Broker(char* broker){
  this->Broker = broker;
}
void MQTT_nmcu8266::Set_PortBroker(int port){
  this->Port = port;
}
void MQTT_nmcu8266::Set_IDMQTT(char* id_mqtt)
{
    this->ID_MQTT = id_mqtt;
}
void MQTT_nmcu8266::Set_Topico(char* topico){
    this->Topico = topico;
}


//Funções
void MQTT_nmcu8266::PublicarMQTT(char* payload){
    MQTT.publish(Topico, payload);
}
void MQTT_nmcu8266::IniciarMQTT(){
    MQTT.setServer(Broker, Port);
}
bool MQTT_nmcu8266::ReconectarMQTT()
{
    int tentativas = 0;
    int lim_tentativas = 10;
    if(!MQTT.connected()){
        while (!MQTT.connected() && tentativas <= lim_tentativas)
        {
            Serial.print("* Tentando se conectar ao Broker MQTT: ");
            Serial.println(Broker);
            if (MQTT.connect(ID_MQTT))
            {
                Serial.println("Conectado com sucesso ao broker MQTT!");
                MQTT.subscribe(Topico);
                return true;
            }
            else
            {
                Serial.print("Tentativa ");
                Serial.print(tentativas);
                Serial.print(" de ");
                Serial.println(lim_tentativas);
                tentativas++;
                delay(50);
            }
        }
        return false;
    }
    else{
        return true;
    }
}
