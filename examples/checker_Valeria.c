#include <stdio.h>
#include "sqlite3.h"

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i<argc; i++) printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    sqlite3_open("test.db", &db);
    
    printf("--- TABLES ---\n");
    sqlite3_exec(db, "SELECT name FROM sqlite_master WHERE type='table';", callback, 0, 0);
    
    printf("--- SCHEMA COMPANY ---\n");
    sqlite3_exec(db, "SELECT sql FROM sqlite_master WHERE name='COMPANY';", callback, 0, 0);
    
    printf("--- DATA FROM CARS ---\n");
    sqlite3_exec(db, "SELECT * FROM Cars;", callback, 0, 0);
    
    sqlite3_close(db);
    return 0;
}
