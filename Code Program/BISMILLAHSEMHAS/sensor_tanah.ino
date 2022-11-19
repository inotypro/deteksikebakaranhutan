void tanah(){
//Setup Sensor Kelembaban Tanah
float kt;
int resultSoil = analogRead(kt); // sensor soil
kth =(100-((resultSoil/1023.00)*100));
}
