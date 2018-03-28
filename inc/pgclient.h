// PgClient class - header.
#ifndef __PGCLIENT_H
#define __PGCLIENT_H

#include <string>
#include <libpq-fe.h>

struct ConnectionParam {
    std::string host;
    unsigned short port;
    std::string user;
    std::string dbname;
    std::string password;
};

class PQClient {
public:
    static std::string ParamToString(const struct ConnectionParam &param);
    PQClient(const std::string &connectionString): pgConn(nullptr) {
        connStr = connectionString;
        Connected = false;
        pgRes = nullptr;
    };
    PQClient(const ConnectionParam &params): pgConn(nullptr) {
        connStr = PQClient::ParamToString(params);
        Connected = false;
        pgRes = nullptr;
    };
    bool Connect();
    int ConnectionStatus();
    std::string ErrorMessage();
    bool Exec(const std::string &sqlText);
    std::string ResultErrorMessage();
    ~PQClient();
private:
    bool Connected;
    PGconn *pgConn;
    PGresult *pgRes;
    std::string connStr;
};

#endif // __PGCLIENT_H
