#include "MQTTDoor.hpp"

#include <iostream>
#include <string>


int main()
{
    MosqMqttWrapper* MyMQTT = new MosqMqttWrapper("door", "localhost", 1883);
    MQTTDoor::InitMQTT(MyMQTT);
    
    Door door;
    
    MQTTDoor::ControlDoor(&door,MyMQTT);
    
    return 0;
}
