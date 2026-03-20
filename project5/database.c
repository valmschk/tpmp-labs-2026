#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void find_by_id(sqlite3 *db, int id) {
    sqlite3_stmt *res;
    sqlite3_prepare_v2(db, "SELECT * FROM Cars WHERE Id = ?;", -1, &res, 0);
    sqlite3_bind_int(res, 1, id);
    if (sqlite3_step(res) == SQLITE_ROW) {
        printf("Найдено: %s\n", sqlite3_column_text(res, 1));
    } else {
        printf("ID не найден.\n");
    }
    sqlite3_finalize(res);
}

void extract_photo_to_file(sqlite3 *db, int id, const char *out_path) {
    sqlite3_stmt *res;
    sqlite3_prepare_v2(db, "SELECT Image FROM Cars WHERE Id = ?;", -1, &res, 0);
    sqlite3_bind_int(res, 1, id);
    if (sqlite3_step(res) == SQLITE_ROW) {
        FILE *fp = fopen(out_path, "wb");
        fwrite(sqlite3_column_blob(res, 0), sqlite3_column_bytes(res, 0), 1, fp);
        fclose(fp);
        printf("Фото выгружено в %s\n", out_path);
    }
    sqlite3_finalize(res);
}

void test_insertion_modes(sqlite3 *db) {
    // Демонстрация транзакции
    sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, 0);
    for(int i=0; i<3; i++) {
        sqlite3_exec(db, "INSERT INTO Cars(Name, Price) VALUES('NewCar', 5000);", 0, 0, 0);
    }
    sqlite3_exec(db, "COMMIT;", 0, 0, 0);
    printf("Данные вставлены успешно в режиме транзакции.\n");
}