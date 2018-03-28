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
    if (pgRes) {
        PQclear(pgRes);
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
    std::string msg("");
    if (pgConn) {
        msg.assign(PQerrorMessage(pgConn));
    }
    return msg;
}

bool PQClient::Exec(const std::string &sqlText)
{
    bool b = false;
    if (Connected) {
        if (pgRes) PQclear(pgRes);
        pgRes = PQexec(pgConn, sqlText.c_str());
        auto status = PQresultStatus(pgRes);
        b = ((status != PGRES_BAD_RESPONSE) && (status != PGRES_NONFATAL_ERROR) && (status != PGRES_FATAL_ERROR));
    }
    return b;
}

std::string PQClient::ResultErrorMessage()
{
    std::string msg("");
    if (pgRes) {
        msg.assign(PQresultErrorMessage(pgRes));
    }
    return msg;
}
