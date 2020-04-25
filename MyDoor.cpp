#include "MyDoor.hpp"
#include <unistd.h>
#include <iostream>

using namespace std;

Door :: Door()
{
    state = new OffState();
    isIdle = true;
    isOn = false;
    isClosed = true;
}

Door :: ~Door()
{
    delete state;
}

void Door :: TurnOff()
{
    state->TurnOff(this);
}

void Door :: TurnOn()
{
    state->TurnOn(this);
}

void Door :: OpenDoor()
{
    state->OpenDoor(this);
}

void Door :: CloseDoor()
{
    state->CloseDoor(this);
}

void IDoorState :: TurnOff(Door* d)
{
    cout<<"Ошибка"<<endl;
}

void IDoorState :: TurnOn(Door* d)
{
    cout<<"Ошибка"<<endl;
}

void IDoorState :: OpenDoor(Door* d)
{
    cout<<"Ошибка"<<endl;
}

void IDoorState :: CloseDoor(Door* d)
{
    cout<<"Ошибка"<<endl;
}

void Door :: ChangeState(IDoorState* s)
{
    delete state;
    state = s;
}

void OffState :: TurnOff(Door *d)
{
    cout<<"Дверь уже выключена."<<endl;
}

void OnState :: TurnOff(Door *d)
{
    d->isOn = false;
    d->ChangeState(new OffState());
    cout<<"Дверь выключена."<<endl;
}

void OpeningState :: TurnOff(Door *d)
{
    cout << "Аварийное выключение двери." << endl;
    d->isOn = false;
    d->ChangeState(new OffState());
}

void ClosingState :: TurnOff(Door *d)
{
    cout << "Аварийное выключение двери." << endl;
    d->isOn = false;
    d->ChangeState(new OffState());
}

void OpenState :: TurnOff(Door *d)
{
    d->isOn = false;
    d->ChangeState(new OffState());
    cout<<"Дверь выключена."<<endl;
}

void CloseState :: TurnOff(Door *d)
{
    d->isOn = false;
    d->ChangeState(new OffState());
    cout<<"Дверь выключена."<<endl;
}

void OffState :: TurnOn(Door *d)
{
    d->isOn = true;
    d->ChangeState(new OnState());
    cout<<"Дверь включена."<<endl;
}

void OnState :: TurnOn(Door *d)
{
    cout<<"Дверь уже включена."<<endl;
}

void OpeningState :: TurnOn(Door *d)
{
    cout<<"Дверь уже включена."<<endl;
}

void ClosingState :: TurnOn(Door *d)
{
    cout<<"Дверь уже включена."<<endl;
}

void OpenState :: TurnOn(Door *d)
{
    cout<<"Дверь уже включена."<<endl;
}

void CloseState :: TurnOn(Door *d)
{
    cout<<"Дверь уже включена."<<endl;
}

void OffState :: OpenDoor(Door *d)
{
    cout<<"Невозможно открыть выключенную дверь."<<endl;
}

void OnState :: OpenDoor(Door *d)
{
    if (d->isIdle && d->isClosed)
    {
        d->isIdle = false;
        cout<<"Открываю дверь"<<endl;
        sleep(2);
        cout<<"Дверь открыта"<<endl;
        d->isIdle = true;
        d->isClosed = false;
        d->ChangeState(new OpenState());
    }
    else
    {
        cout<<"Дверь уже открыта."<<endl;
    }
}

void OpeningState :: OpenDoor(Door *d)
{
    cout<<"Дверь уже открывается."<<endl;
}

void ClosingState :: OpenDoor(Door *d)
{
    cout<<"Невозможно открыть дверь во время закрывания."<<endl;
}

void OpenState :: OpenDoor(Door *d)
{
    cout<<"Дверь уже открыта"<<endl;
}

void CloseState :: OpenDoor(Door *d)
{
    d->isIdle = false;
    cout<<"Открываю дверь"<<endl;
    sleep(2);
    cout<<"Дверь открыта"<<endl;
    d->isIdle = true;
    d->isClosed = false;
    d->ChangeState(new OpenState());
}

void OffState :: CloseDoor(Door *d)
{
    if (d->isClosed)
    {
        cout<<"Дверь уже закрыта."<<endl;
    }
    else
    {
        cout<<"Невозможно закрыть выключенную дверь."<<endl;
    }
}

void OnState :: CloseDoor(Door *d)
{
    if (d->isIdle && !d->isClosed)
    {
        d->isIdle = false;
        cout<<"Закрываю дверь"<<endl;
        sleep(2);
        cout<<"Дверь закрыта"<<endl;
        d->isIdle = true;
        d->isClosed = true;
        d->ChangeState(new CloseState());
    }
    else
    {
        cout<<"Дверь уже закрыта."<<endl;
    }
}

void OpeningState :: CloseDoor(Door *d)
{
    cout<<"Невозможно закрыть дверь во время отрывания."<<endl;
}

void ClosingState :: CloseDoor(Door *d)
{
    cout<<"Дверь уже закрывается."<<endl;
}

void OpenState :: CloseDoor(Door *d)
{
    d->isIdle = false;
    cout<<"Закрываю дверь"<<endl;
    sleep(2);
    cout<<"Дверь закрыта"<<endl;
    d->isIdle = true;
    d->isClosed = true;
    d->ChangeState(new CloseState());
}

void CloseState :: CloseDoor(Door *d)
{
    cout<<"Дверь уже закрыта."<<endl;
}
