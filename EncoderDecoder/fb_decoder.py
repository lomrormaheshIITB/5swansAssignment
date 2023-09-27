import os
import sys
curr_dir = os.path.abspath(os.path.dirname(__file__))
parent_dir = os.path.dirname(curr_dir)
sys.path.append(parent_dir)
sys.path.append(os.path.join(os.path.dirname(__file__), '../python'))
from flatbuffers.MyNamespace import Client

def read_file(filename):
    with open(os.path.join(os.path.dirname(__file__), filename), 'rb') as f:
        return f.read()
    
def getGender(gen):
    if gen == 0:
        return "Male"
    return "Female"

def binaryToPerson(client):
    name = client.Name().decode('utf-8')
    age = client.Age()
    weight = client.Weight()
    gender = client.Gender()
    print(f'Client: Person')
    print('Name: {}, Age: {}, Weight:{}, Gender: {}'.format(name, age, weight, getGender(gender)))

def binaryToGroup(client):
    groupname = client.Name()
    age = client.Age()
    weight = client.Weight()
    nameList = [client.Members(i).decode('utf-8') for i in range(client.MembersLength())]
    print('Client: Group')
    print('GroupName: {}, Age: {}, Weight: {}, Members: {}'.format(groupname, age, weight, nameList))

if __name__ == "__main__":
    # filename = "client_data.bin"
    if len(sys.argv) < 2:
        print("Insufficient arguments")
    else:
        filename = sys.argv[1]
        buffer_data = read_file(filename)
        client = Client.Client.GetRootAsClient(buffer_data, 0)

        if client.Type():
            binaryToGroup(client)
        else:
            binaryToPerson(client)