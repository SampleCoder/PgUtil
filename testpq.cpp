#include <iostream>
#include "pgclient.h"

const std::string q1{ "CREATE DATABASE Dummy_Test;" };
const std::string q2{ "DROP DATABASE Dummy_Test;" };

int main(int argc, char *argv[])
{
    if (argc > 1) {
        ConnectionParam connParam{ "localhost", 5432, "postgres", "postgres", argv[1] };
        PQClient pgClient(connParam);
        if (pgClient.Connect()) {
            bool ok;
            std::cout << "Connection OK.\n";
            std::cout << "Running " << q1 << std::endl;
            ok = pgClient.Exec(q1);
            if (ok) {
                std::cout << "Running " << q2 << std::endl;
                ok = pgClient.Exec(q2);
            }
            if (!ok) {
                std::cout << pgClient.ResultErrorMessage();
            }
        }
        else
            std::cout << "Got error: " << pgClient.ErrorMessage();
    }
    return 0;
}

