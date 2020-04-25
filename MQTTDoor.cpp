#include "MQTTDoor.hpp"
#include <thread>
#include <vector>
#include <string>

using namespace std;

namespace MQTTDoor
{

    void MQTTDoorLoop(MosqMqttWrapper* MQTT)
    {
        MQTT->loop_forever();
    }

    void InitMQTT(MosqMqttWrapper* MQTT)
    {
        mosqpp::lib_init();
        std::thread t = std::thread(MQTTDoorLoop, MQTT);
        t.detach();
    }

    void SendDoorData(Door* d, MosqMqttWrapper* MQTT)
    {
        string isIdle = (d->isIdle?"Да":"Нет");
        string isOn = (d->isOn?"Да":"Нет");
        string isClosed = (d->isClosed?"Да":"Нет");
        MQTT->send_message(("isIdle:" + isIdle).c_str());
        MQTT->send_message(("isOn:" + isOn).c_str());
        MQTT->send_message(("isClosed:" + isClosed).c_str());
        
    }

    void MQTTDoorControlLoop(Door* d, MosqMqttWrapper* MQTT)
    {
        string inputString;
        while (cin >> inputString)
        {
            if (inputString == "@dooron")
            {
                d->TurnOn();
            }
            if (inputString == "@dooroff")
            {
                d->TurnOff();
            }
            if (inputString == "@dooropen")
            {
                d->OpenDoor();
            }
            if (inputString == "@doorclose")
            {
                d->CloseDoor();
            }
            if (inputString == "@exit")
            {
                cout<<"Выход из программы";
                break;
            }
        }
    }

    void ControlDoor(Door* d, MosqMqttWrapper* MQTT)
    {
        cout<<"Начинаю читать команды из mqtt.";
        std::thread t = std::thread(MQTTDoorControlLoop, d, MQTT);
        t.join();
    }
}
