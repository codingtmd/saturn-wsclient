import asyncio
import sys, json
import asyncio
import websockets
import random
import string

class chaintalker:
    async def open(self, url):
        self.websocket = await websockets.connect(url)    
        return self

    async def is_new(self):
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"is_new\",[]]}'
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result'] == True

    async def set_password(self, pwd):
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"set_password\",[\"%s\"]]}' % pwd
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result'] == None

    async def unlock(self, pwd) :
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"unlock\",[\"%s\"]]}' % pwd
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result'] == None
    
    async def import_key(self, account_name_or_id, wif_key) :
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"import_key\",[\"%s\", \"%s\"]]}' % (account_name_or_id, wif_key)
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result'] == None
    
    async def suggest_brain_key(self) :
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"suggest_brain_key\",[]]}'
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result']['brain_priv_key'], json_msg['result']['wif_priv_key'], json_msg['result']['pub_key']

    async def create_account_with_brain_key(self, brain_key, account_name, registrar_account, referrer_account) :
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"create_account_with_brain_key\",[\"%s\", \"%s\", \"%s\", \"%s\", true]]}' % (brain_key, account_name, registrar_account, referrer_account)
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result']

    async def transfer(self, from_account, to_account, amount, memo) :
        command = '{\"id\":1,\"method\":\"call\",\"params\":[0,\"transfer\",[\"%s\", \"%s\", %s, \"BTS\", \"%s\", true]]}' % (from_account, to_account, amount, memo)
        await self.send(command)
        raw_msg = await self.receive()
        json_msg = json.loads(raw_msg)
        return json_msg['result']

    async def send(self, message):
        print("send: " + message)
        await self.websocket.send(message)

    async def receive(self):
        raw_msg = await self.websocket.recv()
        print("receive: " + raw_msg)
        return raw_msg

    def id_generator(self, size=6, chars=string.ascii_lowercase ):
        return ''.join(random.choice(chars) for _ in range(size))
