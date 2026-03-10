#include <stdio.h>
#include "sqlite3.h"
int main(void) {
    sqlite3 *db;
    char *zErrMsg = 0;
    if (sqlite3_open("test.db", &db)) return 1;
    char *sql = "CREATE TABLE COMPANY(ID INT PRIMARY KEY, NAME TEXT, AGE INT);";
    sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    printf("Table created successfully\n");
    sqlite3_close(db);
    return 0;
}
