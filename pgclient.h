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
    };
    PQClient(const ConnectionParam &params): pgConn(nullptr) {
        connStr = PQClient::ParamToString(params);
        Connected = false;
    };
    bool Connect();
    int ConnectionStatus();
    std::string ErrorMessage();
    ~PQClient();
private:
    bool Connected;
    PGconn *pgConn;
    std::string connStr;
};

#endif // __PGCLIENT_H
