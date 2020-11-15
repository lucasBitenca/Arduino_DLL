#ifndef MQTT_NMCU8266_H_INCLUDED
#define MQTT_NMCU8266_H_INCLUDED


class MQTT_nmcu8266 {
  public:
    bool ReconectarMQTT();
    void PublicarMQTT(char* payload);
    void IniciarMQTT();
    void Set_Broker(char* broker);
    void Set_PortBroker(int port);
    void Set_IDMQTT(char* id_mqtt);
    void Set_Topico(char* topico);
  private:
    char* Broker;
    int Port;
    char* ID_MQTT;
    char* Topico;
};
#endif //MQTT_NMCU8266_H_INCLUDED
