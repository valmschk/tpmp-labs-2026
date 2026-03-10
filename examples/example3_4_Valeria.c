#include <stdio.h>
#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i<argc; i++) printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    printf("\n");
    return 0;
}

int main(void) {
    sqlite3 *db;
    char *zErrMsg = 0;
    sqlite3_open("test.db", &db);
    // Вставляем данные
    char *sql_ins = "INSERT INTO COMPANY VALUES (1, 'Paul', 32); "                     "INSERT INTO COMPANY VALUES (2, 'Allen', 25);";
    sqlite3_exec(db, sql_ins, 0, 0, &zErrMsg);
    // Выбираем данные
    sqlite3_exec(db, "SELECT * FROM COMPANY;", callback, 0, &zErrMsg);
    sqlite3_close(db);
    return 0;
}
