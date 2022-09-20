import threading
import logging
from time import sleep
logging.basicConfig(format='%(threadName)s %(message)s',
                  level=logging.DEBUG)


def worker():
    sleep(1)
    logging.debug('worker')

#treads=[]
#for i in range(5):
#    t=threading.Thread(target=worker,name=f'T{i}')
#    treads.append(t)
#    treads[-1].start()

[threading.Thread(target=worker,name=f'Tt{i}').start() for i in range(6)]

for t in threading.enumerate():
    print(t)
    #print(t.getName())
    if t.getName()=='MainThread':
        print(t.getName())
    #if t.getName()=='Tt2':
    #    'MainThread'.join()

