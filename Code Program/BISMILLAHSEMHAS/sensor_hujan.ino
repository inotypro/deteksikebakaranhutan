void ICACHE_RAM_ATTR hitung_ch()
{
  flag = true;
}

  
void hujan(){  
  if (flag == true) // don't really need the == true but makes intent clear for new users
  {
    ch += milimeter_per_tip; // Akan bertambah nilainya saat tip penuh
    jumlah_tip++;
    delay(500);
    flag = false; // reset flag
  }
  ch = jumlah_tip * milimeter_per_tip;
  temp_jumlah_tip = jumlah_tip;
    

// Setup Sensor CURAH_HUJAN
pinMode(pin_interrupt, INPUT);
attachInterrupt(digitalPinToInterrupt(pin_interrupt), hitung_ch, FALLING);
}
