#include <stdio.h>
#include "sqlite3.h" 

static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   printf("%s:\n", (const char*)data);
   for(i = 0; i < argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   const char* data = "Запись";

   sqlite3_open("test.db", &db);
   char *sql = "SELECT * from COMPANY";

   int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "Ошибка SQL: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Данные успешно получены\n");
   }
   sqlite3_close(db);
   return 0;
}