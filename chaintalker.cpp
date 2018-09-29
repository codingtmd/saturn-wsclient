#include "chaintalker.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
#include <cpprest/ws_client.h>

using namespace std;
using namespace web;
using namespace web::websockets::client;


websocket_outgoing_message format_send_message(const string& msg) {
    websocket_outgoing_message out_msg;
    out_msg.set_utf8_message(msg);
    cout << msg << endl;
    return out_msg;
}

void chainapi::ChainTalker::open_connection_sync(const string& ws_url) {
    uri address(U(ws_url));
    _client.connect(address).wait();
}

void chainapi::ChainTalker::set_password_sync(const string& pass) {
    // step 1, create password(only need for first call)
    string command = "{\"id\":1,\"method\":\"call\",\"params\":[0,\"set_password\",[\"111111\"]]}";
    _client.send(format_send_message(command)).wait();

    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        cout << body << endl; // or customized logic here to handle error and return
    }).wait();
}

void chainapi::ChainTalker::unlock_sync(const string& pass) {
   // step 2 unlock wallet api
    string command = "{\"id\":1,\"method\":\"call\",\"params\":[0,\"unlock\",[\"111111\"]]}";
    _client.send(format_send_message(command)).wait();

    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        cout << body << endl; // or customized logic here to handle error and return
    }).wait();
}

void chainapi::ChainTalker::import_user_sync(const string& id, const string& key) {
    string command = 
        "{\"id\":1,\"method\":\"call\",\"params\":[0,\"import_key\",[\"" + id + "\", \"" + key + "\"]]}";
    
    _client.send(format_send_message(command)).wait();

    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        cout << body << endl; // or customized logic here to handle error and return
    }).wait();
}

string chainapi::ChainTalker::suggest_brain_key() {
    string command =
        "{\"id\":1,\"method\":\"call\",\"params\":[0,\"suggest_brain_key\",[]]}";

    _client.send(format_send_message(command)).wait();


    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        return body; // or customized logic here to handle error and return
    }).wait();

}

void chainapi::ChainTalker::transfer_sync(const string& from, const string& to, string amount, string memo){
    string command = 
        "{\"id\":1, \"method\":\"call\", \"params\":[0,\"transfer\",[\"" + from + "\", \"" + to + "\", " + amount+", \"BTS\", \""+ memo + "\", true]]}";
    
    _client.send(format_send_message(command)).wait();

    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        cout << body << endl; // or customized logic here to handle error and return
    }).wait();
}

void chainapi::ChainTalker::create_account_with_brain_key_sync(const string& brain_key, const string& account_name) {
    // similar logic as open_connetion.  prepare the command correctly and send ove to ws
    // for api format, plz refer to https://docs.google.com/document/d/1W3KS9Hw_8suqOxqOQBy28-Z_ePBBDI-cRanvQtD_Nfg/edit
    string command =
        "{\"id\":1, \"method\":\"call\", \"params\":[0,\"create_account_with_brain_key\",[\"" + brain_key + "\", \"" + account_name + "\", \"init0\", \"init0\", true]]}";
    _client.send(format_send_message(command)).wait();

    _client.receive().then([](websocket_incoming_message in_msg) {
        return in_msg.extract_string();
    }).then([](string body) {
        cout << body << endl; // or customized logic here to handle error and return
    }).wait();
}
