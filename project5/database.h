#ifndef DATABASE_H
#define DATABASE_H
#include <sqlite3.h>

void find_by_id(sqlite3 *db, int id);
void find_by_pattern(sqlite3 *db, const char *column, const char *pattern);
void extract_photo_to_file(sqlite3 *db, int id, const char *out_path);
void test_insertion_modes(sqlite3 *db);

#endif