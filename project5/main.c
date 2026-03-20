#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main() {
    sqlite3 *db;
    if (sqlite3_open("../my_database.db", &db)) return 1;

    int choice, id;
    while(1) {
        printf("\n--- MENU (Project 5) ---\n1. Поиск по ID\n2. Выгрузить фото в файл\n3. Тест транзакций\n0. Выход\nВыбор: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) { printf("ID: "); scanf("%d", &id); find_by_id(db, id); }
        if (choice == 2) { printf("ID объекта: "); scanf("%d", &id); extract_photo_to_file(db, id, "result.jpg"); }
        if (choice == 3) { test_insertion_modes(db); }
    }
    sqlite3_close(db);
    return 0;
}