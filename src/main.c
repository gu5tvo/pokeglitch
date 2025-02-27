#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checksum.h"
#include "apply_patch.h"
#include "change_name.h"

int main(int argc, char *argv[]) {
  //  the checksum first generation is a 8 bits value
  char check;

  //  saving the path, so it doesn't operate in argv all the time

  char path_size = strlen(argv[1]);
  char save_path[32];

  //  copy argv[1] in the save_path
  strncpy(save_path, argv[1], path_size);

  char test_name[] = "testing";

  change_name(argv[1], test_name);

  check = checksum(save_path);

  printf("[%x]\n", check);

  //  the checksum value is inserted at the adress 0x3523
  apply_patch(save_path, check);

  //  printf("%02hhx\n", check);

  return 0;
}
