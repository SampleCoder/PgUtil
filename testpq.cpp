#include <iostream>
#include "pgclient.h"

const std::string q1{ "CREATE DATABASE Dummy_Test;" };
const std::string q2{ "DROP DATABASE Dummy_Test;" };

int main()
{
    PQClient pgClient("host=localhost port=5432 user=postgres dbname=postgres password=123");
    if (pgClient.Connect()) {
		bool ok;
		std::cout << "Connection OK.\n";
		ok = pgClient.Exec(q1);
		if (ok) {
			ok = pgClient.Exec(q2);
		}
		if (!ok) {
			std::cout << pgClient.ResultErrorMessage();
		}
    }
    else
		std::cout << "Got error: " << pgClient.ErrorMessage();
    return 0;
}

