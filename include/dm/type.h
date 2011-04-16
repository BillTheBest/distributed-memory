#ifndef _DM_TYPE_H_
#define _DM_TYPE_H_

#define DIMBLOCK 128
#define DEFAULT_CONFIG_PATH "dmconfig.yml"
#define TCP_MAX_CONNECTIONS 64
#define TCP_BUFFER_SIZE 1024
#define TCP_TIMEOUT 20
#define LOG_LEVEL LOG_INFO

#include <string>
#include <vector>
#include <map>
using namespace std;


namespace DM {

struct ServerConf {
  string ip;
  string port;
  vector<int> blocks_id;
};

typedef map<string,ServerConf> ServerMap;

enum MessageType {
  MAP    = 1,
  UNMAP  = 2,
  UPDATE = 3,
  WRITE  = 4,
  WAIT   = 5,
  ACK    = 6,
  NACK   = 7,
  UNDEF  = 0
};

enum LogLevel {
  LOG_DEBUG,
  LOG_INFO,
  LOG_ERROR
};

} // namespace DM

#endif /* _DM_TYPE_H_ */
