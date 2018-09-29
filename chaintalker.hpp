#include <string>
#include <queue>
#include <cpprest/ws_client.h>

using namespace std;
using namespace web;
using namespace web::websockets::client;

namespace chainapi {
class ChainTalker {
  private:
    websocket_client _client;

    void add_command(const string& command);

  public:
    void open_connection_sync(const string& ws_url);

    void set_password_sync(const string& pass);

    void unlock_sync(const string& pass);

    void import_user_sync(const string& id, const string& key);

    void transfer_sync(const string& from, const string& to, string amount, string memo);

    string suggest_brain_key(); 
    
    void create_account_with_brain_key_sync(const string& brain_key, const string& account_name);

    void send_and_receive();
    
    ~ChainTalker() { 
        _client.close().wait();
    }

};

} // namespace chainapi
