/**
 * Text To Speech synthesis library
 * Copyright (c) 2008 Clive Webster.  All rights reserved.
 *
 * Nov. 29th 2009 - Modified to work with Arduino by Gabriel Petrut:
 * The Text To Speech library uses Timer1 to generate the PWM
 * output on digital pin 10. The output signal needs to be fed
 * to an RC filter then through an amplifier to the speaker.
 * http://www.tehnorama.ro/minieric-modulul-de-control-si-sinteza-vocala/
 *
 * Modified to allow use of different PWM pins by Stephen Crane.
 */
#include <TTS.h>

// Media pins
#define PWM 10

TTS text2speech(PWM);  // default is digital pin 10

void setup() {
}

void loop() {  
  text2speech.setPitch(6);
  decirString("Hola Amo! como estas?");
  delay(500); 
  text2speech.setPitch(1);  
  decirString("Estoy bien, gracias."); 
  delay(1000);
}  

void decirString(String str){
  char line[60];
  str.toCharArray(line, 60);
  text2speech.sayText(line);
}