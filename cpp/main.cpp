#include "chaintalker.hpp"

#include <assert.h>
#include <stdio.h>
#include <string>

using chainapi::ChainTalker;

int main()
{
    ChainTalker talker;
    talker.open_connection_sync("ws://x.x.x.x");
    talker.import_user_sync("id", "key");
    //talker.transfer_sync("shxyan", "lzh", "11", "lunch split");
    string msg = talker.suggest_brain_key();
    cout << msg <<endl;
    return 0;
}
