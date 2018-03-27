#include <iostream>
#include <libpq-fe.h>

int main()
{
    PGconn *conn = PQconnectdb("host=localhost port=5432 user=postgres dbname=postgres password=123");
    if (conn) {
        std::cout << "Connection initialized...\n";
        if (PQstatus(conn) != CONNECTION_OK) {
            std::cout << "Got error: " << PQerrorMessage(conn) << std::endl;
        }
    }
    else
        std::cout << "False\n";
    PQfinish(conn);
    return 0;
}

