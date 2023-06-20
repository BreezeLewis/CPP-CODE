#include "manager.h"
// Insert an appointment to the smaller Conference Room (1).
bool RoomManager::InsertAppointment(const int& date)
{
    auto ret = _room1.find(date);
    if (ret != _room1.end())
        return 0;
    else
    {
        _room1.insert(date);
        return 1;
    }
}

// Insert an appointment to the bigger Conference Room (2).
bool RoomManager::InsertAppointment(const int& date, const string& event)
{
    auto ret = _room2.find(date);
    if (ret != _room2.end())
        return 0;
    else
    {
        _room2.insert(make_pair(date, event));
        return 1;
    }
}

// Cancel an appointment on designated date.
// If room_id == 1, cancel the corresponding appointment of _room1.
// If room_id == 2, cancel the corresponding appointment of _room2.
bool RoomManager::CancelAppointment(const int& room_id, const int& date)
{
    if (room_id == 1)
    {
        return _room1.erase(date);
    }
    else if (room_id == 2)
    {
        return _room2.erase(date);
    }
}

// Print all existing appointments in chronological order.
// If room_id == 1, just print the date information. Each piece of information is separated by ' '.
// If room_id == 2, print the information in form of "date(event)". Each piece of information is separated by ' '.
// If there is no even one existing appointment yet, print "No Appointment".
void RoomManager::PrintAppointments(const int& room_id) const
{
    if (room_id == 1)
    {
        if (_room1.empty())
        {
            printf("No Appointment\n");
        }
        else
        {
            auto it = _room1.begin();
            while (it != _room1.end())
            {
                cout << *it << " ";
                ++it;
            }
        }
    }
    else if (room_id == 2)
    {
        if (_room2.empty())
        {
            printf("No Appointment\n");
        }
        else
        {
            auto it = _room2.begin();
            while (it != _room2.end())
            {
                cout << it->first << "(" << it->second << ")" << " ";
                ++it;
            }
        }
    }
}