#include <esp_sleep.h>
#include <esp_wifi.h>

#define TIME_TO_SLEEP_US 1000*1000 
const int delay_time = 50000;
const int designFreq[] = {1, 0};
//const int designFreq[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1};
//const int designFreq[] = {1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
const int designLength = sizeof(designFreq)/sizeof(int);
int i;

void setup(){
  
}

void loop(){
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP_US);
  for (i = 0; i < designLength; i++) {
      switch(designFreq[i]){
        case 1:
            wifi();
            delay(1000);
            break;
        case 0:
            esp_light_sleep_start();
            break;             
      }      
  }
}

wifi_init_config_t init_config = WIFI_INIT_CONFIG_DEFAULT();
void wifi(){
  esp_wifi_init(&init_config);  
  esp_wifi_set_mode(WIFI_MODE_STA); 
  esp_wifi_start();    
}