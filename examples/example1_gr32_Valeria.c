#include <stdio.h>
#include "sqlite3.h" 

int main(int argc, char* argv[]) {
   sqlite3 *db;
   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ) {
      fprintf(stderr, "Ошибка открытия БД: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "База данных открыта успешно\n");
   }

   sqlite3_close(db);
   return 0;
}