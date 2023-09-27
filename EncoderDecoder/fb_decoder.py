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



if __name__ == "__main__":
    filename = "client_data.bin"
    buffer_data = read_file(filename)
    client = Client.Client.GetRootAsClient(buffer_data, 0)
    binaryToPerson(client)