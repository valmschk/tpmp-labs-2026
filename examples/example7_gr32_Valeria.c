#include <stdio.h>
#include "sqlite3.h"
int main(void) {
    sqlite3 *db;
    sqlite3_stmt *res;
    sqlite3_open("test.db", &db);
    sqlite3_exec(db, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);", 0,0,0);
    sqlite3_exec(db, "INSERT INTO Cars VALUES(3, 'Skoda', 9000);", 0,0,0);
    sqlite3_prepare_v2(db, "SELECT Name FROM Cars WHERE Id = ?", -1, &res, 0);
    sqlite3_bind_int(res, 1, 3);
    if (sqlite3_step(res) == SQLITE_ROW) printf("Car Name: %s\n", sqlite3_column_text(res, 0));
    sqlite3_finalize(res);
    sqlite3_close(db);
    return 0;
}
