#include <iostream>
#include <sqlite3.h>

// Callback function for SELECT queries
static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

int main() {
    sqlite3* db;
    char* errMsg = 0;

    // Open a database connection (creates a new database if it doesn't exist)
    int rc = sqlite3_open("example.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return rc;
    } else {
        std::cout << "Opened database successfully\n";
    }

    // Create a table
    const char* createTableSQL = "CREATE TABLE COMPANY("
                                "ID INT PRIMARY KEY     NOT NULL,"
                                "NAME           TEXT    NOT NULL,"
                                "AGE            INT     NOT NULL,"
                                "ADDRESS        CHAR(50),"
                                "SALARY         REAL);";

    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully\n";
    }

    // Insert data
    const char* insertDataSQL = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
                                "VALUES (1, 'Paul', 32, 'California', 20000.00);";

    rc = sqlite3_exec(db, insertDataSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    } else {
        std::cout << "Records created successfully\n";
    }

    // Select data
    const char* selectDataSQL = "SELECT * FROM COMPANY;";

    rc = sqlite3_exec(db, selectDataSQL, callback, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}
