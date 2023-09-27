# 5swansAssignment

Follow these steps to serialize and deserialize the data:

Step-1:
cd flatbuffers/
cmake -G "Unix Makefiles"
Note: this command only works in Linux (not in windows)

Step-2:
make -j

Step-3:
./flatc --cpp ../schema/client.bfs => flatbuffers/client_generated.h file is created
./flatc --python ../schema/client.bfs => flatbuffers/MyNamespace/ and flatbuffers/python/ directaries are created

Step-4: ENCODE
cd ../Encoder/
g++ fb_encoder.cpp -o ../Binary/fb_encoder
./fb_encoder client_data.bin 1 => Client is a Person
./fb_encoder client_data.bin 2 => Client is a Group
Note: there are some include errors in some files: fixed

Step-5: DECODE
cd ../Decoder/
python fb_decoder.py client_data.bin
Note: there are some include errors in some files: fixed
