#include "TTS.h"

TTS tts(10);

char line[60];
int pos = 0;

void setup(void) {
  Serial.begin(115200);
}

void loop(void) {
  if (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c == '\n') {
      line[pos++] = 0;
      if (line[0] == '+') {
        int p = atoi(line+1);
        tts.setPitch(p);
      } else {
        Serial.println(line);
        tts.sayText(line);
      }
      pos = 0;
    } else
      line[pos++] = c;
  }
}
