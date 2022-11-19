void setupdht() {
  //Setup Sensor DHT11
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor); 
  delayMS = sensor.min_delay / 1000;
}

void suhukelembaban(){
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  
  dht.temperature().getEvent(&event);
  su = event.temperature;
  dht.humidity().getEvent(&event);
  ku = event.relative_humidity;
}
