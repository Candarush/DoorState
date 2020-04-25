#pragma once

class Door;

class IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class OffState : public IDoorState
{
    public:
    void TurnOff(Door* d);
    void TurnOn(Door* d);
    void OpenDoor(Door* d);
    void CloseDoor(Door* d);
};

class OnState : public IDoorState
{
    public:
    void TurnOff(Door* d);
    void TurnOn(Door* d);
    void OpenDoor(Door* d);
    void CloseDoor(Door* d);
};

class ClosingState : public IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class OpeningState : public IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class OpenState : public IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class CloseState : public IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class ErrorState : public IDoorState
{
    public:
    void virtual TurnOff(Door* d);
    void virtual TurnOn(Door* d);
    void virtual OpenDoor(Door* d);
    void virtual CloseDoor(Door* d);
};

class Door{
    public:
    
    bool isIdle;
    bool isOn;
    bool isClosed;
    IDoorState* state;
    
    Door();
    void TurnOff();
    void TurnOn();
    void OpenDoor();
    void CloseDoor();
    void ChangeState(IDoorState* s);
    ~Door();
    
};
