# 5swansAssignment


Step-1:
cd flatbuffers/
cmake -G "Unix Makefiles"

Step-2:
make -j

Step-3:
./flatc --cpp ../schema/client.bfs

Step-4:
cd ../Encoder/
g++ fb_encoder.cpp -o ../Binary/fb_encoder

Step-5:
cd ../Decoder/
python fb_decoder.py