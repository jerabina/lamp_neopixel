# Neopixel lampičky
Táborové lampičky pro MDDM

## 3D tisk
[ABS průhledný kryt](stl/top.stl)
[PETG nebo PLA střední část](stl/middle.stl)
[PETG nebo PLA spodní část](stl/bottom.stl)

Tisk vrstvou 0,2mm. 

Spodní a stření část jsou spojeny šrouby 2x M3x12mm a matkou 2x M3 vloženou do otvoru spodní části. Horní část je pouze "nacvaklá".

## Elektronika
[Arduino Nano](https://store.arduino.cc/arduino-nano), [Mikrospínač TC-0106](https://www.gme.cz/tc-0108-t), [WS2812 RGB Led pásek, 6 neopixelů](https://www.aliexpress.com/item/2036819167.html?spm=a2g0s.9042311.0.0.31244c4dEEOILY)

## Připojení pinů
Tlačítko je připojena na pin D7 a spíná proti GND. Led pásek je připojen pinem Din na pin Arduina D7, +5V a GND na významově stejný pin Arduina.

```
#define PIN_LEDS 6
#define PIN_BTN  7
```

## Software
Ukázkové programy lze nahrát v prostředí Arduino, které si stáhnete na adrese [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software).
Po instalaci je potřeba přidat dvě knihovny [FastLED](https://github.com/FastLED/FastLED) a [JC_Button](https://github.com/JChristensen/JC_Button).
V prostředí Arduino menu: projekt -> Přidat knihovnu -> spravovat knihovny, otevře se správce a do vyhlédávacího pole nejprve zadáte FastLED a pak JC_Button, u nalezené knihovny kliknete na tlačítko instalovat.



### [Sekvencer](kod_sekvencer/)
Program přehrává postupně jednolivé sekvence, které se mění zmáčknutím tlačítka.
Skládá se ze dvou souborů:
[kod_sekvencer.ino](kod_sekvencer/kod_sekvencer.ino) - obsluha pásku, tlačítka a přehrávač sekvencí
[animation.h](kod_sekvencer/animation.h) - definice sekvenci