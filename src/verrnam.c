#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_LEN 64

static char buf[MAX_LEN] = {
  'A', 'B', 'C', 'D',
  'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 
  'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b',
  'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 
  's', 't', 'u', 'v',
  'w', 'x', 'y', 'z',
  '0', '1', '2', '3',
  '4', '5', '6', '7',
  '8', '9', '"', ' '
};

int Mod(int x, int y) {
  return x >= 0 ? x % y : y - 1 - ((-x - 1) % y);
}

typedef enum {
  CIPHER,
  PLAIN
} MODE;

int GetIndex(char c) {
  int i;
  for (i=0; i < MAX_LEN; i++)
    if (buf[i] == c)
      return i;
  return -1;
}

char* Vernam(char *msg, char *key, MODE m) {
  int i, j, k;
  int len = strlen(msg);
  char *res;

  if (len > strlen(key))
    return NULL;

  res = (char *) malloc(len + 1);

  for (i=0; i < len; i++) {
    if ((j = getIndex(msg[i])) == -1 || (k = getIndex(key[i])) == -1) {
      free(res);
      return NULL;
    }
    else { 
        if (m == PLAIN)  
          res[i] = buf[mod(j - k, MAX_LEN)];
        else
          res[i] = buf[mod(j + k, MAX_LEN)];
    }      
  }
  res[len] = '\0';
  return res;
}
