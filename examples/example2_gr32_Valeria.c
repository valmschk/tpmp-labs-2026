#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h" 

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   rc = sqlite3_open("test.db", &db);
   if( rc ) { return(0); }

   sql = "CREATE TABLE IF NOT EXISTS COMPANY(" \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "SALARY         REAL );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,SALARY) VALUES (1, 'Paul', 32, 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,SALARY) VALUES (2, 'Allen', 25, 15000.00 );";

   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "Ошибка SQL: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Таблица создана и данные добавлены успешно\n");
   }

   sqlite3_close(db);
   return 0;
}