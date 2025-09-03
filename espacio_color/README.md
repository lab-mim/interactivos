Espacio Color
=============

* ## openframeworks
  - código para Kinect 1
  - openCV para trackear
  - manda datos por OSC -> Pure Data
    
* ## Pure Data
  - recibe OSC de openframeworks
  - manda datos por puerto serial a ENTTEC DMX USB PRO -> Philips Color Kinetics
  - manda RGB por RS-485 -> ESP32
    
* ## ESP32
  - código para [ESP32-C3 Super Mini](https://afel.cl/products/placa-esp32-c3-supermini-wifi-y-bluetooth)
  - recibe RGB por RS-485
  - matrices led
  
