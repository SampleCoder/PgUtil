// PgClient - class implementation.
#include "pgclient.h"

std::string PQClient::ParamToString(const struct ConnectionParam &param)
{
    std::string connstr{"host="};
    connstr += param.host + " ";
    connstr += "port=" + std::to_string(param.port) + " ";
    connstr += "user=" + param.user + " ";
    connstr += "dbname=" + param.dbname + " ";
    connstr += "password=" + param.password;
    return connstr;
}

PQClient::~PQClient()
{
    if (pgConn) {
        PQfinish(pgConn);
    }
}

bool PQClient::Connect()
{
    pgConn = PQconnectdb(connStr.c_str());
    Connected = PQstatus(pgConn) == CONNECTION_OK;
    return Connected;
}

int PQClient::ConnectionStatus()
{
    int status = -1;
    if (pgConn)
        status = PQstatus(pgConn);
    return status;
}

std::string PQClient::ErrorMessage()
{
	std::string msg(PQerrorMessage(pgConn));
	return msg;
}
