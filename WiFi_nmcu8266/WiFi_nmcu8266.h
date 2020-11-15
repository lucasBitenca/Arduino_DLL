#ifndef WIFI_NMCU8266_H_INCLUDED
#define WIFI_NMCU8266_H_INCLUDED

class WiFi_nmcu8266 {
  public:
    bool ConectarWiFi();
    void VerificarConexao();
    void ObterIP();
    void Set_SSID(char* ssid);
    void Set_PWD(char* pwd);
    void Set_HOST(char* nm_host);
  private:
    char* Ssid;
    char* Pwd;
    char* Nm_host;
};
#endif //WIFI_NMCU8266_H_INCLUDED
