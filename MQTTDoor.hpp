#pragma once

#include "MosqMQTTWrapper.hpp"
#include "MyDoor.hpp"
#include <thread>
#include <iostream>

using namespace MQTTW;

namespace MQTTDoor
{
    void MQTTDoorLoop(MosqMqttWrapper* MQTT);

    void InitMQTT(MosqMqttWrapper* MQTT);

    void SendDoorData(Door* d,MosqMqttWrapper* MQTT);

    void MQTTDoorControlLoop(Door* d, MosqMqttWrapper* MQTT);

    void ControlDoor(Door* d, MosqMqttWrapper* MQTT);
}
