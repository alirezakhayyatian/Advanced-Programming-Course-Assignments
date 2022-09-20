import os
str = input("what is your command:")
func,name = str.split('(')
name,address = name.split(',')
address,four = address.split(')')



def create_dir(name,address):
    #print(f'{name} {address}')
    os.mkdir(address+'\\'+name)

def create_file(name,address):
    f = open(address +'\\'+name , 'w')
def delete(name,address):
    os.remove(address+'\\'+name)
dir=[]
def find(name,address):
    for root, dirs, files in os.walk(address):
        
        for i in files:
            if i==name:
                #print(f'{root}')
                dir.append(root)
    print(f'{dir}')


if func == 'create_dir':
    if os.path.isdir(address +'\\'+name)== False:
        print(os.path.isdir(address) )
        create_dir(name,address)

if func == 'create_file':
    #if os.path.isdir(address +'\\'+name)== False:
     #   print(os.path.isdir(address) )
    create_file(name,address)

if func == 'delete':
    if os.path.isfile(address +'\\'+name)== True:
        delete(name,address)

if func == 'find':
    find(name, address)

