import argparse
import json
import asyncio  
from chaintalker import chaintalker

def main():
    parser = argparse.ArgumentParser(description="saturn chain tester")
    parser.add_argument("--ws",
                        default='ws://13.229.98.54:8090',
                        help="URL of web socket")
    parser.add_argument("--pwd",
                        default='111111',
                        help="wallet password")

    FLAGS = parser.parse_args()
    tester = chaintalker()

    print(FLAGS.ws)
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    loop.run_until_complete(tester.open(FLAGS.ws))
    #if loop.run_until_complete(tester.is_new()) :
    loop.run_until_complete(tester.set_password(FLAGS.pwd))

    loop.run_until_complete(tester.unlock(FLAGS.pwd))

    # import a pre-setting user 
    loop.run_until_complete(tester.import_key("shxyan", "5Jrh8UV5JLXAbGsVZDvK2ytq6HtfLghoEyLCnBp8dtA23kfhFh4"))

    brain_key, wif_key, pub_key = loop.run_until_complete(tester.suggest_brain_key())
    new_id = tester.id_generator()
    loop.run_until_complete(tester.create_account_with_brain_key(brain_key, new_id, "init1", "init1"))
    
    # transfer money from pre-setting user to new user
    loop.run_until_complete(tester.transfer("shxyan", new_id, "100", "test trasnaction"))


if __name__ == "__main__":
    main()
