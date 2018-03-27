#include <iostream>
#include "pgclient.h"

int main()
{
    PQClient pgClient("host=localhost port=5432 user=postgres dbname=postgres password=123");
    if (pgClient.Connect()) {
		std::cout << "Connection OK.\n";
    }
    else
		std::cout << "Got error: " << pgClient.ErrorMessage() << std::endl;
    return 0;
}

