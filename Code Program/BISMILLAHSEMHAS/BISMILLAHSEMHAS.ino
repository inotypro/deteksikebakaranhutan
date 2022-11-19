#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2   // Pinout Sensor DHT 
#define DHTTYPE DHT11     // Jenis Sensor DHT 11

#define THINGER_SERIAL_DEBUG
#include <ThingerESP8266.h>
#include "arduino_secrets.h" // attach File settingan wifi & Thinger.io
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Deklarasi Data Sensor Hujan
const int pin_interrupt = 4; //  Pinout Sensor Curah Hujan Menggunakan pin interrupt 
long int jumlah_tip = 0;
long int temp_jumlah_tip = 0;
float ch = 0.00;
float milimeter_per_tip = 0.70;
volatile boolean flag = false;
uint32_t delayMS;

DHT_Unified dht(DHTPIN, DHTTYPE); //Deklarasi Pin DHT 11
float su, ku;

const int kt = A0; // Pinout Sensor Soil
float kth;
float Zch1 = 0.00;
float Zch2 = 0.00;
float Zch = 0.00; 
String kondisifuzzy;

#include <TimeLib.h>
#include <TimeAlarms.h>
#define resetuno 13
AlarmId id;



void setup() {
  Serial.begin(9600);
  setupdht();
  setupwifi();

  pinMode(resetuno,OUTPUT);
  digitalWrite(resetuno,HIGH);
 
  setTime(0,0,0,1,1,22); // set time to Saturday 0:00:00am Jan 1 2022
  //Alarm.timerRepeat(20, membuatkosong);
   Alarm.alarmRepeat(24,00,0, membuatkosong);  // 24:00 every day
}

void loop() {
  thing.handle(); //Things.io command
  hujan();
  suhukelembaban();
  tanah();
  fuzzy();
  keterangan();
  Serial.println("-------------------");  
  Serial.print("Time Now:   "); digitalClockDisplay();
  Serial.println("-------------------"); 
  Serial.println();
  printserial();
  kirimdata();
  delay(1000);
  Alarm.delay(1);
}

void printserial(){
  Serial.print(F("Temperature: "));
  Serial.print(su);
  Serial.println(F("°C"));
  Serial.print(F("Humidity: "));
  Serial.print(ku);
  Serial.println(F("%"));
  Serial.print("Tip Count: ");
  Serial.print(jumlah_tip);
  Serial.println(" kali ");
  Serial.print("Rainfall: ");
  Serial.print(ch, 1);
  Serial.println(" mm");
  Serial.print("SoilMoisture: ");
  Serial.print(kth);
  Serial.println(" %");
  Serial.print("Nilai Fuzzy: ");
  Serial.println(Zch);
  Serial.print("Status: ");
  Serial.println(kondisifuzzy);
}

void kirimdata(){
  //Kirim Data Ke Thinger.io
    thing["sensor"] >> [](pson& out){
    out["humidity"] = ku;
    out["celsius"] = su;
    out["soilmoisture"] = kth;
    out["curah_hujan"] = ch, 1;
    out["nilai_fuzzy"] = Zch;
    out["kondisifuzzy"] = kondisifuzzy;
  };
}

void setupwifi(){
  //Setup buat Jaringan Wifi
  pinMode(LED_BUILTIN, OUTPUT); //set builtin led as output
  thing.add_wifi(SSID, SSID_PASSWORD); // add WiFi credentials
  thing["led"] << digitalPin(LED_BUILTIN); // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  //thing["millis"] >> outputValue(millis()); // resource output example (i.e. reading a sensor value)
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void membuatkosong(){
  kirimemail();
  Serial.println("[------------]");
  Serial.println("[ Ganti Hari ]");
  Serial.println("[------------]");
  ch=0;
  jumlah_tip=0;
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void keterangan(){
  if (Zch<= 0.3)
  kondisifuzzy = "Rendah";  
    else if (Zch>0.3 and Zch<=0.66)
   kondisifuzzy = "Normal";
      else if (Zch> 0.66)
      kondisifuzzy = "Rawan";      
}

void kirimemail(){
  if (Zch<= 0.3)
  thing.call_endpoint("status_Rendah");  
    else if (Zch>0.3 and Zch<=0.66)
   thing.call_endpoint("status_Normal");  
       else if (Zch> 0.66)
      thing.call_endpoint("status_Rawan");
}
